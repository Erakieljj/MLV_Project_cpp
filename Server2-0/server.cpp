/**
 * @file server.cpp
 * @brief le serveur qui représente la maîtresse qui envoie
 * les corrections de dessins et assemble la fresque finale
 * @author Huy HUYNH
 * @version 0.1
 */

#include <iostream>
#include <string.h>
#include <sys/types.h>
#ifdef __WIN32__
# include <winsock2.h>
# include <ws2tcpip.h>
#else
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
#endif
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <QtCore>
#include <thread>
#include <mutex>
#include <QJsonObject>
#include <QByteArray>
#include <QString>
#include "dataJSON.h"
#include "fresque.h"
#define MAX_DRAWING 3

std::mutex mtx;
map<int, string> map_drawing;
std::atomic<int> nb_drawing(1);
Fresque *fresqueServer = new Fresque();

/**
 * @brief La fonction call_from_thread sera la fonction exécutée lors de la
 * création d'une thread
 * @param client_socket numéro de la socket du client
 * @return rien à l'arrêt de la fonction
 */

void call_from_thread(int client_socket)
{

    int bufsize = 3000;
    char buffer[bufsize];

    strcpy(buffer, "Server connected...\n");
    send(client_socket, buffer, bufsize, 0);
    cout << ">> Connected, starting ..." << endl;

    int size_read = 0;
    int totalsize = 0;
    int size_cum = 0;
    bool drawing_finished = false;

    //process client
    cout << "Drawing from student:\n";
   // do {
        //on lit l'id
        recv(client_socket, buffer, bufsize, 0);
        int id = atoi(buffer);
        cout << "id read:" << id << endl;

        //on lit la taille
        recv(client_socket, buffer, bufsize, 0);
        totalsize = atoi(buffer);
        cout << "size read: " << totalsize << endl;

        //on reçoit le dessin
        memset(buffer, 0, bufsize);
        while(size_cum != totalsize) {
            size_read=recv(client_socket, buffer, totalsize, 0);
            size_cum = size_cum + size_read;
            cout << "total size: " << totalsize << endl;
            cout << "size_cum: " << size_cum << endl;
        }
        cout << "buffer: " << buffer << " " << endl;


        /*on met le json du dessin dans la map (moins lourd) avant décodage, ainsi si la connexion avec le client s'interrompt on gardera le dernier dessin
          et la maîtresse peut accéder à n'importe quel moment à la map */
        mtx.lock();
        map_drawing[id] = buffer;
        mtx.unlock();


        //analyse du dessin (lecture du buffer et analyse a faire et mettre ici)
        //si le dessin convient aux critères on l'envoie au client et on l'ajoute à la fresque
        QJsonParseError error;
        QJsonObject objDrawing = QJsonDocument::fromJson(QString::fromUtf8(buffer, size_cum).toUtf8(), &error).object();
        if (objDrawing.isEmpty())
        {
            cout<<"Error : " +  error.errorString().toStdString()<<endl;
        }

        QJsonObject annotation;

        DataJSON::readDrawingAndCheck(objDrawing, annotation);
        string strNotation = DataJSON::readJsonAnnotation(annotation);
        cout<<"Notation Server :" + strNotation<<endl;
        if(strNotation == "perfect") { //a remplacer
            memset(buffer, 0, bufsize);
            strcpy(buffer,"perfect");
            //add to big fresque here

            Fresque *fresque = DataJSON::read(objDrawing);
            fresqueServer->add(*fresque);
            drawing_finished = true;
            nb_drawing++;
        }
        //ajout de la réponse avec la liste des annotations
        else {
            cout << "=> Message Sent: you have to work again" << endl;
            memset(buffer, 0, bufsize);
            strcpy(buffer,strNotation.c_str());
            // ecriture dans le buffer
            //json here for the answer..
        }

        /*renvoie de la réponse avec un perfect pour finir le client ou la liste des annotations pour lui
          faire modifier son dessin */
        send(client_socket, buffer, bufsize, 0);
        cout << "Message sent!" << endl;

    //si on a reçu tout les dessins on affiche la grande fresque
    //} while (!drawing_finished);

    /* ----------------- Close --------------- */
    cout << "=> Connection ended with: " << client_socket << "\n" << endl;
    close(client_socket);

}

/**
 * @brief La fonction main du serveur
 * @param aucun paramètre
 * @return -1 s'il y a une erreur de binding, 1 lors d'une erreur à l'établissement d'une socket,
 * 0 si le programme s'est déroulé correctement
 */

int main()
{

    /* ---------- INITIALIZING VARIABLES ---------- */

    int ListeningSocket , NewConnectionSocket;
    int portNum = 1500;

    struct sockaddr_in server_addr;
    socklen_t size;

    /* to Store threads */
    std::thread t[MAX_DRAWING];
    /* for the thread join */
    int i = 0;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/

    #if defined (WIN32)
        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif

    ListeningSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (ListeningSocket  < 0)
    {   cout << ListeningSocket  << endl;
        cout << "\n>> Error on establishing socket..." << endl;
        exit(1);
    }

    cout << "\n>> Socket server has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    /* ---------- BINDING THE SOCKET ---------- */

     if (::bind(ListeningSocket , (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        cout << ">> Error on binding connection" << endl;
        return -1;
    }

    size = sizeof(server_addr);
    cout << ">> Waiting for clients to connect..." << endl;

    /* ------------- LISTENING ------------- */

    // En général, on met le nombre maximal de connexions pouvant être mises en attente à MAX_DRAWING
    listen(ListeningSocket , MAX_DRAWING);

    while (nb_drawing < MAX_DRAWING) {

        /* ------------- ACCEPTING CLIENTS  ------------- */

        /* accept est bloquant jusqu'à l'arrivée d'un client, NewConnectionSocket est le numéro de socket du client */
        NewConnectionSocket = accept(ListeningSocket,(struct sockaddr *)&server_addr,&size);

        // first check if it is valid or not
        if (NewConnectionSocket < 0)
            continue;
        else if(nb_drawing == MAX_DRAWING) {
            break;
        }
        else  {
            t[i] = std::thread(call_from_thread, NewConnectionSocket);
            i++;
        }
    }

    //on attend que tout les opérations soient finies
    for(i=0;i<MAX_DRAWING-1;i++) {
        t[i].join();
    }
    cout << "map size:" << map_drawing.size() << endl;

    fresqueServer->draw();
    cout << ">> Enjoy the nice work from all students: " << endl;

    // showing contents of the map
    std::map<int, string>::iterator it = map_drawing.begin();
    std::cout << "\n>> drawing_map contains:\n";
    for (it=map_drawing.begin(); it!=map_drawing.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';


    close(ListeningSocket);
    #if defined (WIN32)
        WSACleanup();
    #endif


    return 0;
}
