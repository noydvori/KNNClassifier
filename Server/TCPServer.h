// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef SIMPLE_EXAMPLE_TCPSERVER_HPP
#define SIMPLE_EXAMPLE_TCPSERVER_HPP

#include "../SocketIO.h"
#include <thread>
#include <pthread.h>
#include <vector>
#include <atomic>

class TCPServer {
private:
    const int _port;
    const int _sock;
    // boolean to let the server know after timeout whether to close the server or to send new clients a message that
    // the server isn't accepting new clients (while it waits for current clients to finish).
    std::atomic<bool> _stop;
    // vector of client threads.
    std::vector<std::thread> _threads;

    /**
     * creates a new CLI for the client.
     * @param client_sock socket of client to read from and write to.
     */
    static void newClient(int client_sock);

public:
    /**
     * creates a new TCP server.
     * @param port port to open the server on.
     */
    explicit TCPServer(int port);

    /**
     * start listening to the socket and accepting clients.
     */
    void start();
};


#endif //SIMPLE_EXAMPLE_TCPSERVER_HPP