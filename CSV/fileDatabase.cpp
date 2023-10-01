// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "fileDatabase.h"
#include <fstream>

bool fileDatabase::createFileDatabase(string fileName) {
    vector<string> row;
    string line, word;
    ifstream MyFile;
    data.clear();
    MyFile.open(fileName);
    if (MyFile.is_open()) {
        // Takes a row from file
        while (getline(MyFile, line)) {
            row.clear();
            stringstream str(line);
            // Splits each row to "words"
            while (getline(str, word, ',')) {
                if (!word.empty() && word != "\"\"") {
                    row.emplace_back(word);
                } else {
                    row.emplace_back("NaN");
                }
            }
            // Push vector into data
            data.push_back(row);
        }
    } else {
        return false;
    }
    return true;
}

void fileDatabase::clear() {
    data.clear();
}

bool fileDatabase::classifiedCheck() {
    size_type i;
    for (i = 0; i < data.size(); i++) {
        if (isNumber(data[i][data[i].size() - 1]) || data[i][data[i].size() - 1].empty() ||
            data[i][data[i].size() - 1] == "/r") {
            return false;
        }
    }
    return true;
}

void fileDatabase::printFileData(void) {
    size_type i, j;
    for (i = 0; i < data.size(); i++) {
        for (j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}

bool fileDatabase::isValidFile() {
    size_type i, j;
    for (i = 0; i < data.size(); i++) {
        for (j = 0; j < data[i].size() - 1; j++) {
            if (!isNumber(data[i][j])) {
                return false;
            }
        }
    }
    return true;
}

bool fileDatabase::isUnclassifiedFile() {
    size_type i, j;
    for (i = 0; i < data.size(); i++) {
        for (j = 0; j < data[i].size(); j++) {
            // removes "/r"
            if (!data[i][j].empty() && data[i][j][data[i][j].size() - 1] == '\r') {
                data[i][j].erase(data[i][j].size() - 1);
            }
            if (!isNumber(data[i][j])) {
                return false;
            }
        }
    }
    return true;
}
