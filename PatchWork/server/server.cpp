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
#include "../fresque.h"
#include <QtCore>



int main()
{

    /* ---------- INITIALIZING VARIABLES ---------- */

    int client, server;
    int portNum = 1500;
    int bufsize = 3000;
    char buffer[bufsize];
    int max_drawing = 4;
    int nb_drawing;
    int clientCount = 0;

    struct sockaddr_in server_addr;
    socklen_t size;

    //map<int, Fresque> map_drawing;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/

    #if defined (WIN32)
        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {   cout << client << endl;
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    /*
        The socket() function creates a new socket.
        It takes 3 arguments,
            a. AF_INET: address domain of the socket.
            b. SOCK_STREAM: Type of socket. a stream socket in
            which characters are read in a continuous stream (TCP)
            c. Third is a protocol argument: should always be 0. The
            OS will choose the most appropiate protocol.
            This will return a small integer and is used for all
            references to this socket. If the socket call fails,
            it returns -1.
    */

    cout << "\n=> Socket server has been created..." << endl;

    /*
        The variable serv_addr is a structure of sockaddr_in.
        sin_family contains a code for the address family.
        It should always be set to AF_INET.
        INADDR_ANY contains the IP address of the host. For
        server code, this will always be the IP address of
        the machine on which the server is running.
        htons() converts the port number from host byte order
        to a port number in network byte order.
    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    /* ---------- BINDING THE SOCKET ---------- */
    /* ---------------- bind() ---------------- */



     if (::bind(client, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }

    /*
        The bind() system call binds a socket to an address,
        in this case the address of the current host and port number
        on which the server will run. It takes three arguments,
        the socket file descriptor. The second argument is a pointer
        to a structure of type sockaddr, this must be cast to
        the correct type.
    */

    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;

    /* ------------- LISTENING CALL ------------- */
    /* ---------------- listen() ---------------- */

    // En général, on met le nombre maximal de connexions pouvant être mises en attente à 5 (comme les clients FTP)
    listen(client, 5);

    /*
        The listen system call allows the process to listen
        on the socket for connections.
        The program will be stay idle here if there are no
        incomming connections..
    */



    while (max_drawing!=nb_drawing) {
        clientCount++;
        /* ------------- ACCEPTING CLIENTS  ------------- */
        /* ----------------- listen() ------------------- */

        /*
            The accept() system call causes the process to block
            until a client connects to the server. Thus, it wakes
            up the process when a connection from a client has been
            successfully established. It returns a new file descriptor,
            and all communication on this connection should be done
            using the new file descriptor. The second argument is a
            reference pointer to the address of the client on the other
            end of the connection, and the third argument is the size
            of this structure.
        */
        server = accept(client,(struct sockaddr *)&server_addr,&size);

        // first check if it is valid or not
        if (server < 0)
            cout << "=> Error on accepting..." << endl;

        while (server > 0)
        {
            strcpy(buffer, "Server connected...\n");
            send(server, buffer, bufsize, 0);
            cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;

            int size_read = 0;
            int totalsize = 0;
            int size_cum = 0;
            boolean drawing_finished = false;

            cout << "Drawing from student: ";
            do {

                //on lit la taille
                recv(server, buffer, bufsize, 0);
                totalsize = atoi(buffer);
                cout << "size read: " << totalsize << endl;

                //on reçoit le dessin
                memset(buffer, 0, bufsize);
                while(size_cum != totalsize) {
                    size_read=recv(server, buffer, totalsize, 0);
                    size_cum = size_cum + size_read;
                    cout << "total size: " << totalsize << endl;
                    cout << "size_cum: " << size_cum << endl;
                }
                cout << "buffer: " << buffer << " " << endl;

                //analyse du dessin (lecture du buffer et analyse a faire et mettre ici)
                //si le dessin convient aux critères on l'envoie au client et on l'ajoute à la fresque
                if(true==true) { //a remplacer
                    memset(buffer, 0, bufsize);
                    strcpy(buffer,"perfect");
                    //add to big fresque here / add to map when the drawing is finished? prevent to always actualize on the map modifications are required

                    //update the number of drawing finished
                    nb_drawing++;
                    drawing_finished = true;
                }
                //ajout de la réponse avec la liste des annotations
                else {
                    cout << "=> Message Sent: you have to work again" << endl;
                    // ecriture dans le buffer
                }

                /*renvoie de la réponse avec un perfect pour finir le client ou la liste des annotations pour lui
                  faire modifier son dessin */
                send(server, buffer, bufsize, 0);

            //si on a reçu tout les dessins on affiche la grande fresque
            } while (!drawing_finished);

            /* ---------------- CLOSE CALL ------------- */
            /* ----------------- close() --------------- */

            // inet_ntoa converts packet data to IP, which was taken from client
            cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr) << endl;
            close(server);

        }
    }
    //affichage de la grande fresque ici
    cout << "Enjoy the nice work from all students: " << endl;

    close(client);
    #if defined (WIN32)
        WSACleanup();
    #endif

    return 0;
}
