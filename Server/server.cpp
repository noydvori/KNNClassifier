#include "TCPServer.h"
#include "../inputValidity.h"

int main(int argc, char *argv[]) {
    isValidArgcS(argc);
    string string_port = argv[1];
    // Checks if the inputted port is valid, otherwise prints error message and end program.
    int server_port = isValidPort(string_port);
    TCPServer server(server_port);
    server.start();
}