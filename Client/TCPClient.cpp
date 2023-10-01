// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "TCPClient.h"
#include "../CSV/fileHandler.h"
#include <string>
#include <utility>
#include <sstream>

using namespace std;
using namespace Networking;
using namespace files;

TCPClient::TCPClient(int port, string ip_address) : port(port), _ip_address(move(ip_address)) {
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    // if not succeed to create socket
    if (_sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin{AF_INET, htons(this->port), inet_addr(_ip_address.c_str())};

    // if the client cant connect to server
    if (connect(_sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

string TCPClient::readMessage() const {
    // reads from the server.
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = (int) recv(_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        return "";
    } else if (read_bytes < 0) { //read all message, if there is no information return error
        perror("Error reading client message");
        close(_sock);
        exit(0);
    }
    return {buffer};
}

void TCPClient::sendMessage(const string &message) const {
    int sent_bytes = (int) send(_sock, message.c_str(), message.length(), 0);

    if (sent_bytes < 0) { // if there is a problem then error
        cout << "Error sending the data to the server" << endl;
    }
}

void TCPClient::connectToServer() const {
    // receive message.
    while (true) {
        string wholeMessage = readMessage();
        // because messages are separated by \n.
        vector<string> messages = files::fileHandler::stringToLines(wholeMessage);
        for (int i = 0; i < messages.size(); i++) {
            int len = (int) messages[i].length();
            if (len > 5 && messages[i].substr(0, 5) == "print") {
                // simply print the message.
                cout << messages[i].substr(5, messages[i].length()) << endl;
            } else if (len > 5 && messages[i].substr(0, 5) == "write") {
                // print the message and send console input.
                cout << messages[i].substr(5, messages[i].length()) << endl;
                string toSend{};
                getline(cin, toSend);
                if (toSend.empty()) {
                    toSend = "empty";
                }
                sendMessage(toSend);
            } else if (len > 2 && messages[i] == "end") {
                // connection has ended.
                close(_sock);
                return;
            }
        }
    }
}
