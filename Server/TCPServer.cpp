// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <sys/socket.h>
#include <functional>
#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include "../SocketIO.h"
#include "../CLI.h"
#include "TCPServer.h"

#define TIMEOUT_SECONDS 300

using namespace std;

TCPServer::TCPServer(int port) : _stop(false), _port(port), _threads(),
                                 _sock(socket(AF_INET, SOCK_STREAM, 0)) {
    if (_sock < 0) {
        perror("Error creating socket");
    }
    // tries to bind the socket to the port.
    struct sockaddr_in sin{AF_INET, htons(_port), INADDR_ANY};
    if (bind(_sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error binding socket");
    }
}

void TCPServer::newClient(int client_sock) {
    SocketIO sio{client_sock};
    CLI cli{sio};
    cli.start();
}

void TCPServer::start() {
    int client_sock;
    // starts listening to the socket.
    if (listen(_sock, 5) < 0) {
        perror("Error listening to a socket");
    }
    while (!_stop) {
        struct sockaddr_in _client_sin{};
        unsigned int addr_len = sizeof(_client_sin);
        client_sock = accept(_sock, (struct sockaddr *) &_client_sin, &addr_len);
            if (client_sock < 0) {
                perror("Error accepting client");
            } else {
                // new client.
                thread newThread(&TCPServer::newClient, client_sock);
                _threads.push_back(std::move(newThread));
            }
        }
    }