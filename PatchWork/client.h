#ifndef CLIENT_H
#define CLIENT_H

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


/**
 * @brief La classe client permet de créer un client qui est un élève qui veut envoyer son dessin.
 */
class Client
{
public:

    /**
     * @brief Client Constructeur par défaut.
     */
    Client(int id);
    /**
     * @brief Start Débute le client avec l'envoi et la réception des dessins.
     */
    void start(std::string json);

private:
    /**
     * @brief json Le dessin encodé sous le format json.
     */
    std::string json;
    int id;
};



#endif // CLIENT_H
