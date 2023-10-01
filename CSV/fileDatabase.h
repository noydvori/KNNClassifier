// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../KNN/numbers.h"

using size_type = std::vector<std::string>::size_type;
using namespace std;

#ifndef A_OUT_FILEDATABASE_H
#define A_OUT_FILEDATABASE_H

/**
 * fileDatabase class.
 */
class fileDatabase {
public:
    vector<vector<string>> data;

    /**
    * Create fileDatabase (initializer).
    * @param fileName - given file name
    */
    bool createFileDatabase(string fileName);

    /**
     * clear database.
     */
    void clear();

    /**
    * Checks if the file is classified.
    * @param data - given data
    */
    bool classifiedCheck();

    /**
    * Prints all data from the file.
    * @param data - given data vectors
    */
    void printFileData();

    /**
    * Checks if theres missing values in the file.
    * @param data - given data file.
    */
    bool isValidFile();

    /**
    * Checks if theres missing values in the file.
    * @param data - given data file.
    */
    bool isUnclassifiedFile();
};

#endif //A_OUT_FILEDATABASE_H
