// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "Command5.h"
#include "../CSV/fileHandler.h"
#include<iostream>
#include<string>
#include <thread>

using size_type = std::vector<string>::size_type;
using namespace std;

Command5::Command5(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, fileDatabase &results,
                   bool &isClassified) :
        Command(dio), _classified(classified), _unclassified(unclassified), _results(results),
        _isClassified(isClassified) {
    _description = "download results";
}

void Command5::toFile(string path) {
    size_type i;
    ofstream fout(path);
    for (i = 0; i < _results.data.size(); i++) {
        fout << i + 1 << "," << _results.data[i][_results.data[0].size() - 1] << endl;
    }
    fout.close();
    return;
}

void Command5::execute() {
    // checks if results database is empty- if so, prints message and return.
    if ((!_isClassified) && (_unclassified.data.empty() || _classified.data.empty())) {
        _dio.write("printplease upload data.\nplease upload data.\n");
    }
    if (!_isClassified) {
        _dio.write("printplease classify the data.\n");
        return;
    }

    // checks if the user upload the data, otherwise- prints message and return
    if (_unclassified.data.empty() || _classified.data.empty()) {
        _dio.write("printplease upload data.\n");
        return;
    }
    vector<thread> threadsV;
    _dio.write("writePlease upload path.\n");
    string path = _dio.read();
    if (files::fileHandler::validPath(path)) {
        std::thread thread(&Command5::toFile, this, path);
        thread.detach();
        threadsV.push_back(move(thread));
        _dio.write("printdownload complete.\n");
        return;
    }
    _dio.write("printinvalid input.\n");
}
