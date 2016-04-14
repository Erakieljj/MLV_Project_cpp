/**
 * @file client4.cpp
 * @brief le client qui représente un élève qui envoie son dessin au professeur
 * et attend les annotations et attend les annotations en retour afin de corriger
 * le dessin et de lui renvoyer jusqu'à qu'il soit parfait aux yeux du professeur
 * @author Huy HUYNH
 * @version 0.1
 */

#include <iostream>
#include <string.h>
#include <sys/types.h>
#ifdef __WIN32__
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif
#include <stdlib.h>
#include <unistd.h>
#include <QtCore>

using namespace std;


/**
 * @brief La fonction main du client
 * @param aucun paramètre
 * @return -1 s'il y a une erreur de connexion au serveur, 1 lors d'une erreur à l'établissement d'une socket,
 * 0 si le programme s'est déroulé correctement
 */

int main()
{
    /* ---------- INITIALIZING VARIABLES ---------- */

    int client;
    int portNum = 1500; // le port est le même pour le client et le serveur
    bool finished = false;
    int bufsize = 3000;
    char buffer[bufsize];
    const char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    #if defined (WIN32)
        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif

    client = socket(AF_INET, SOCK_STREAM, 0);

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/

    if (client < 0)
    {
        cout << "\n>> Error on establishing socket..." << endl;
        exit(1);
    }

    cout << "\n>> Socket client has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    server_addr.sin_addr.s_addr = inet_addr(ip);


    /* ---------- CONNECTING THE SOCKET ---------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        cout << ">> Connection error" << endl;
        close(client);
        #if defined (WIN32)
            WSACleanup();
        #endif
        exit(-1);
    }

    else {
        cout << ">> Connection to the server port number: " << portNum << " with socket: " << client << endl;
    }

    cout << ">> Awaiting confirmation from the server..." << endl;
    recv(client, buffer, bufsize, 0);
    cout << ">> message from the server:" << buffer << endl;
    cout << ">> Connection confirmed, starting..." << endl;

    // Once it reaches here, the client can send a message first.

    do {
        cout << "Student: ";

        //c'est ici qu'on doit envoyer le json dans le buffer on remplace le cin
        //cin >> buffer;

        //send size buffer
        string size = std::to_string(strlen("put json here\n"));
        char const* schar = size.c_str();

        cout << "size of buffer: " << schar << endl;
        strcpy(buffer, schar);
        cout << "buffer before send: " << buffer << endl;
        send(client, buffer, bufsize, 0);

        strcpy(buffer, "put json here\n");
        //then send drawing
        send(client, buffer, bufsize, 0);
        cout << "draw sent!" << endl;

        cout << "Response from the teacher: ";
        recv(client, buffer, bufsize, 0);
        cout << buffer << " " << endl;
        if (strcmp (buffer,"perfect") == 0) {
            finished = true;
        }
        else {
            //traitement sur le dessin
            cout << "working on the drawing again.." << endl;
        }
    } while (!finished);

    /* ---------------- CLOSE CALL ------------- */
    cout << "\n>> Connection terminated.\n";

    close(client);
    #if defined (WIN32)
        WSACleanup();
    #endif
    return 0;
}
