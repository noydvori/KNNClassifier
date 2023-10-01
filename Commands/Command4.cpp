// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "Command4.h"
using size_type = std::vector<string>::size_type;

Command4::Command4(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, fileDatabase &results, bool &isClassified) :
        Command(dio), _classified(classified), _unclassified(unclassified), _results(results), _isClassified(isClassified) {
    _description = "display results";
}

void Command4::execute() {
    size_type i;
    // checks if results database is empty- if so, prints message and return.
    if((!_isClassified) && (_unclassified.data.empty() || _classified.data.empty())) {
        _dio.write("printplease upload data.\nplease upload data.\n");
    }
    if (!_isClassified) {
        _dio.write("printplease classify the data.\n");
        return;
    }
    // checks if the user upload the data, otherwise-prints message and return.
    if (_unclassified.data.empty() || _classified.data.empty()) {
        _dio.write("printplease upload data.\n");
        return;
    }
    // prints line number & the classification from results database.
    for (i = 0; i < _results.data.size(); i++) {
        _dio.write("print" + to_string(i + 1) + "\t" + _results.data[i][_results.data[i].size() - 1] + "\n");
    }
    _dio.write("printDone.\n");
}
