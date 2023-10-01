// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "fileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace files;
using namespace std;

vector<string> fileHandler::stringToLines(const string &data,char separator) {
    vector<string> result{};
    stringstream str(data);
    string line;
    while(getline(str,line,separator)){
        // removes possible '\r'
        if(!line.empty()) {
            if (line[line.length() - 1] == '\r') {
                line.pop_back();
            }
            result.push_back(line);
        }
    }
    return result;
}

bool fileHandler::validPath(const string& path) {
    ofstream test(path);
    return test.is_open();
}