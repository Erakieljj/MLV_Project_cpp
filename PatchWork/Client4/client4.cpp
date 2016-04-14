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

    /*
       1. client is a file descriptor to store the values
       returned by the socket system call and the accept
       system call.
       2. portNum is for storing port number on which
       the accepts connections
       3. exit is bool variable which will be used to
       end the loop
       4. The client reads characters from the socket
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
    */

    int client;
    int portNum = 1500; // NOTE that the port number is same for both client and server
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
    /* --------------- socket() function ------------------*/

    if (client < 0)
    {
        cout << "\n>> Error on establishing socket..." << endl;
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

    cout << "\n>> Socket client has been created..." << endl;

    /*
        The variable serv_addr is a structure of sockaddr_in.
        sin_family contains a code for the address family.
        It should always be set to AF_INET.
        htons() converts the port number from host byte order
        to a port number in network byte order.
    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    server_addr.sin_addr.s_addr = inet_addr(ip);


    /* ---------- CONNECTING THE SOCKET ---------- */
    /* ---------------- connect() ---------------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        cout << ">> Connection error" << endl;
        close(client);
        #if defined (WIN32)
            WSACleanup();
        #endif
        exit(-1);
    }

    else {
        cout << ">> Connection to the server port number: " << portNum << endl;
    }

    /*
        The connect function is called by the client to
        establish a connection to the server. It takes
        three arguments, the socket file descriptor, the
        address of the host to which it wants to connect
        (including the port number), and the size of this
        address.
        This function returns 0 on success and -1
        if it fails.
        Note that the client needs to know the port number of
        the server but not its own port number.
    */

    cout << ">> Awaiting confirmation from the server..." << endl; //line 40
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
    /* ----------------- close() --------------- */
    cout << "\n>> Connection terminated.\n";

    close(client);
    #if defined (WIN32)
        WSACleanup();
    #endif
    return 0;
}
