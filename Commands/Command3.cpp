// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "Command3.h"

Command3::Command3(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, fileDatabase &results, int &k,
                   string &distanceType, bool &isClassified) :
        Command(dio), _classified(classified), _unclassified(unclassified), _results(results), _k(k),
        _distanceType(distanceType), _isClassified(isClassified) {
    _description = "classify data";
}

void Command3::execute() {
    vector<string> v;
    vector<double> u;
    // clear results database.
    _results.clear();
    // checks if results database is empty- if so, prints message and return.
    if (_unclassified.data.empty() || _classified.data.empty()) {
        _dio.write("printPlease upload data.\n");
        return;
    }

    // checks validity of k, if out of range takes the maximum.
    if (_k > _classified.data.size() || _k <= 0) {
        _k = _classified.data.size();
    }
    // for each vector in test file, calculates the classification and saves in results database.
    for (int i = 0; i < _unclassified.data.size(); i++) {
        v = _unclassified.data[i];
        u = convertToDoubleVector(v);
        v.push_back(distanceAndClassification::returnClassification(_k, u, _distanceType, _classified));
        _results.data.push_back(v);
    }
    _isClassified = true;
    _dio.write("printComplete data classifying.\n");
}