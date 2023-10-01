// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "Command1.h"

Command1::Command1(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, bool &isClassified) :
        Command(dio), _classified(classified), _unclassified(unclassified), _isClassified(isClassified) {
    _description = "upload an unclassified csv data file";
}

void Command1::execute() {
    fileDatabase test, train;
    // saves previous files.
    if (!_classified.data.empty() && !_unclassified.data.empty()) {
        test = _unclassified;
        train = _classified;
    }
    _dio.write("writePlease upload your local train CSV file.\n");
    string path = _dio.read();
    if (_classified.createFileDatabase(path)) {
        if (!_classified.classifiedCheck() || !_classified.isValidFile()) {
            _classified.clear();
            _unclassified.clear();
            if (!test.data.empty() && !train.data.empty()) {
                _unclassified = test;
                _classified = train;
            }
            _dio.write("printInvalid input.\n");
            return;
        }
        _isClassified = false;
        _dio.write("printUpload complete.\n");
        _dio.write("writePlease upload your local test CSV file.\n");
    } else {
        _classified.clear();
        _unclassified.clear();
        if (!test.data.empty() && !train.data.empty()) {
            _unclassified = test;
            _classified = train;
        }
        _dio.write("printInvalid input.\n");
        return;
    }
    path = _dio.read();
    if (_unclassified.createFileDatabase(path)) {
        if (_unclassified.data[0].size() != _classified.data[0].size() - 1 || !_unclassified.isUnclassifiedFile()) {
            _classified.clear();
            _unclassified.clear();
            if (!test.data.empty() && !train.data.empty()) {
                _unclassified = test;
                _classified = train;
            }
            _dio.write("printInvalid input.\n");
            return;
        }
        _isClassified = false;
        _dio.write("printUpload complete.\n");
    } else {
        _classified.clear();
        _unclassified.clear();
        if (!test.data.empty() && !train.data.empty()) {
            _unclassified = test;
            _classified = train;
        }
        _dio.write("printInvalid input.\n");
    }
}