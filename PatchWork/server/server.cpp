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

using namespace std;

int main()
{

    /* ---------- INITIALIZING VARIABLES ---------- */

    /*
       1. client/server are two file descriptors
       These two variables store the values returned
       by the socket system call and the accept system call.
       2. portNum is for storing port number on which
       the accepts connections
       3. isExit is bool variable which will be used to
       end the loop
       4. The server reads characters from the socket
       connection into a dynamic variable (buffer).
       5. A sockaddr_in is a structure containing an internet
       address. This structure is already defined in netinet/in.h, so
       we don't need to declare it again.
        DEFINITION:
        struct sockaddr_in
        {
          short   sin_family;
          u_short sin_port;
          struct  in_addr sin_addr;
          char    sin_zero[8];
        };
        6. serv_addr will contain the address of the server
        7. socklen_t  is an intr type of width of at least 32 bits
    */
    int client, server;
    int portNum = 1500;
    int bufsize = 1024;
    char buffer[bufsize];
    int max_drawing = 4;
    int nb_drawing;

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


    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
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

    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);

    // first check if it is valid or not
    if (server < 0)
        cout << "=> Error on accepting..." << endl;

    while (server > 0)
    {
        strcpy(buffer, "Server connected...\n");
        send(server, buffer, bufsize, 0);
        cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;

        /*
            Note that we would only get to this point after a
            client has successfully connected to our server.
            This reads from the socket. Note that the read()
            will block until there is something for it to read
            in the socket, i.e. after the client has executed a
            the send().
            It will read either the total number of characters
            in the socket or 1024
        */

        cout << "Drawing from student: ";
        do {
            //on reçoit le dessin
            recv(server, buffer, bufsize, 0);
            cout << buffer << " " << endl;

            //analyse du dessin (lecture du buffer et analyse a faire et mettre ici)
            //si le dessin convient aux critères on l'envoie au client et on l'ajoute à la fresque
            if(true==false) { //a remplacer
                strcpy(buffer,"perfect");
                //add to big fresque here / add to map when the drawing is finished? prevent to always actualize on the map modifications are required

                //update the number of drawing finished
                nb_drawing++;
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
        } while (nb_drawing != max_drawing);

        //affichage de la grande fresque ici


        /* ---------------- CLOSE CALL ------------- */
        /* ----------------- close() --------------- */

        // inet_ntoa converts packet data to IP, which was taken from client
        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
        exit(1);
    }

    close(client);
    #if defined (WIN32)
        WSACleanup();
    #endif
    return 0;
}
