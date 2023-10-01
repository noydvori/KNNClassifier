#include "TCPClient.h"
#include "../inputValidity.h"

using namespace std;
using namespace Networking;

/**
 * Creates a TCP client, and connects to the server.
 * @return
 */
int main(int argc, char *argv[]) {
    // Checks validity num of arguments - if invalid exit.
    isValidArgcC(argc);
    char *ip_address = argv[1];
    // Checks IP validity
    isValidIpAddress(ip_address);
    string string_port = argv[2];
    // Checks if the inputted port is valid, otherwise prints error message and end program.
    int port_no = isValidPort(string_port);
    TCPClient client(port_no, ip_address);
    client.connectToServer();
}