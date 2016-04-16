#include "client.h"
#include "dataJSON.h"
#include <QJsonDocument>
#include <QJsonObject>

using namespace std;


Client::Client(int id) {
    this->id = id;
}

int IndexOf(const char *s, const char c)
{
    const char * const p = s;
    while(*s && *s != c) s++;
    return (*s) ? s-p : -1;
}

void Client::start(string json) {
    /* ---------- INITIALIZING VARIABLES ---------- */

    int client;
    int portNum = 1500; // le port est le même pour le client et le serveur
    bool finished = false;
    int bufsize = 3000;
    char buffer[bufsize];
    int size_read;
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
        cout << ">> Connection to the server port number: " << portNum << endl;
    }


    cout << ">> Awaiting confirmation from the server..." << endl;
    recv(client, buffer, bufsize, 0);
    cout << ">> message from the server:" << buffer << endl;
    cout << ">> Connection confirmed, starting..." << endl;


    //do {
        cout << "Student: ";
        memset(buffer, 0, bufsize);
        std::string s = std::to_string(id);
        char const *pchar = s.c_str();
        strcpy(buffer, pchar);
        send(client, buffer, bufsize, 0);
        cout << "id sent!" << endl;

        //send size buffer json a envoyer
        string size = std::to_string(json.size());
        char const* schar = size.c_str();

        cout << "size of buffer: " << schar << endl;
        strcpy(buffer, schar);
        cout << "buffer before send: " << buffer << endl;
        send(client, buffer, bufsize, 0);

        strcpy(buffer, json.c_str());
        //then send drawing
        send(client, buffer, bufsize, 0);
        cout << "draw sent!" << endl;

        cout << "Response from the teacher: ";
        size_read = recv(client, buffer, bufsize, 0);
        cout << buffer << " " << endl;
        size_read = IndexOf(buffer, '\0') + 1;
        if (strcmp (buffer,"perfect") == 0) {
            finished = true;
            /*cout << "taille buffer : " << size_read <<endl;
            QJsonObject annotationJson = QJsonDocument::fromJson(QString::fromUtf8(buffer, size_read).toUtf8()).object();
            string annotation = DataJSON::readJsonAnnotation(annotationJson);
            cout << "Annotation : " + annotation <<endl;
            retourne parfait */
        }
        else {
            //traitement sur le dessin

            /*QJsonObject annotationJson = QJsonDocument::fromJson(QString::fromUtf8(buffer, size_read).toUtf8()).object();
            string annotation = DataJSON::readJsonAnnotation(annotationJson);*/

            finished = true;
            //modifier la variable json après avoir pris en compte les annotations

            cout << "working on the drawing again.." << endl;
        }
    //} while (!finished);

    /* ---------------- CLOSE CALL ------------- */
    cout << "\n>> Connection terminated.\n";

    close(client);
    #if defined (WIN32)
        WSACleanup();
    #endif
}
