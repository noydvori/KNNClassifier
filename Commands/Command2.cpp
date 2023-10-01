// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "Command2.h"
#include "../KNN/distances.h"

Command2::Command2(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, int &k, string &distanceType, bool &isClassified) :
        Command(dio), _classified(classified), _unclassified(unclassified), _k(k), _distanceType(distanceType), _isClassified(isClassified) {
    _description = "algorithm settings";
}

void Command2::execute() {
    string newDistance, word, answer;
    _dio.write("writeThe current KNN parameters are: K = " + to_string(_k) + ", distance metric = " + _distanceType +
               "\n");
    answer = _dio.read();
    if (answer == "empty") {
        return;
    }
    while (true) {
        stringstream str(answer);
        vector<string> words{};
        // creates vector from the input (splits it by words)
        while (getline(str, word, ' ')) {
            words.push_back(word);
        }
        if (answer == "empty") {
            return;
        }
        // checks there's exactly 2 arguments, otherwise prints message and continue.
        if (words.size() != 2) {
            _dio.write("writeinvalid arguments!\n");
            answer = _dio.read();
            continue;
        }
        // checks validity of metric & K, otherwise prints message and continue.
        if (!isInteger(words[0]) && !checkDistanceType(words[1])) {
            _dio.write("writeinvalid value for K\ninvalid value for metric\n");
            answer = _dio.read();
            continue;
        }
        // checks validity of K, otherwise prints message and continue.
        if (!isInteger(words[0])) {
            _dio.write("writeinvalid value for K\n");
            answer = _dio.read();
            continue;
        }
        // checks validity of metric, otherwise prints message and continue.
        if (!checkDistanceType(words[1])) {
            _dio.write("writeinvalid value for metric\n");
            answer = _dio.read();
            continue;
        }
        _distanceType = words[1];
        _k = stoi(words[0]);
        _isClassified = false;
        return;
    }
}