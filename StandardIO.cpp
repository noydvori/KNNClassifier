// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "StandardIO.h"
#include <iostream>

using namespace std;

void write(const string &message) {
    cout << message <<endl;
}

string read() {
    string message;
    getline(cin,message);
    return message;
}