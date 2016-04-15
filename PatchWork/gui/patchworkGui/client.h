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



class Client
{
public:
    Client(){}
    void start(std::string json);

private:
    std::string json;
};



#endif // CLIENT_H
