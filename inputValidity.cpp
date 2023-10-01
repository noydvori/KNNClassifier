// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include "inputValidity.h"

using namespace std;

bool isString(const std::string &str) {
    return str.find_first_of("0123456789") == std::string::npos;
}

void isValidArgcC(int argc) {
    if (argc != 3) {
        cout << "invalid number of values in command line" << endl;
        exit(0);
    }
    return;
}
void isValidArgcS(int argc) {
    if (argc != 2) {
        cout << "invalid number of values in command line" << endl;
        exit(0);
    }
    return;
}

int isValidPort(string string_port) {
    if (isNumber(string_port)) {
        if (stoi(string_port) >= 0 && stoi(string_port) <= 65535) {
            return stoi(string_port);
        }
        cout << "invalid port" << endl;
        exit(0);
    }
    cout << "invalid port" << endl;
    exit(0);
}

void isValidIpAddress(char *ipAddress) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    if(result == 0){
        cout << "invalid ip" << endl;
        exit(0);
    }
}