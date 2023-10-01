// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "distances.h"

using namespace std;
using size_type = std::vector<double>::size_type;

/**
 * Distances array with all distance types.
 */
const string distances[5] = {"AUC", "MAN", "CHB", "CAN", "MIN"};

double returnDistance(vector<double> v, vector<double> u, string distanceType) {
    if (distanceType == distances[0]) {
        return euclideanDistance(v, u);
    }
    if (distanceType == distances[1]) {
        return manhattanDistance(v, u);
    }
    if (distanceType == distances[2]) {
        return chebyshevDistance(v, u);
    }
    if (distanceType == distances[3]) {
        return canberraDistance(v, u);
    }
    return minkowskiDistance(v, u);

}

bool checkDistanceType(string str) {
    int i;
    for (i = 0; i < 5; i++) {
        if (str == distances[i]) {
            return true;
        }
    }
    return false;
}

double pMinkowskiDistance(std::vector<double> V, std::vector<double> U, double p) {
    double sum = 0;
    for (size_type i = 0; i < V.size(); i++) {
        sum += pow(absolute(V[i] - U[i]), p);
    }
    return pow(sum, 1 / p);
}

double euclideanDistance(std::vector<double> V, std::vector<double> U) {
    return pMinkowskiDistance(V, U, 1);
}

double manhattanDistance(std::vector<double> V, std::vector<double> U) {
    return pMinkowskiDistance(V, U, 2);
}

double minkowskiDistance(std::vector<double> V, std::vector<double> U) {
    return pMinkowskiDistance(V, U, 100);
}

double chebyshevDistance(std::vector<double> V, std::vector<double> U) {
    double max = 0, temp;
    // we are checking the absolute subtraction value for each parameter in the vector and
    // returning the maximum between them.
    for (size_type i = 0; i < V.size(); i++) {
        temp = absolute(V[i] - U[i]);
        if (temp >= max) {
            max = temp;
        }
    }
    return max;
}

double canberraDistance(std::vector<double> V, std::vector<double> U) {
    double diff, sum = 0;
    for (size_type i = 0; i < V.size(); i++) {
        // for each parameter of each vector we'll calculate the absolute subtraction value
        // then, we'll divide it by the result of adding the absolute value of each parameter
        // only in case these result is not zero. if it is, we'll print an error message and
        // return HUGE_VAL.
        diff = absolute(V[i] - U[i]);
        if ((absolute(V[i]) + absolute(U[i]) == 0)) {
            std::cout << "Cannot be divided by zero.\n";
            return HUGE_VAL;
        }
        sum += diff / (absolute(V[i]) + absolute(U[i]));
    }
    return double(sum);
}

vector<double> convertToDoubleVector(vector<string> v) {
    vector<double> newVector;
    size_type i;
    for (i = 0; i < v.size() - 1; i++) {
        newVector.push_back(stod(v[i]));
    }
    return newVector;
}

void printVector(const std::vector<double> &V) {
    std::cout << "The numbers in the vector are: " << std::endl;
    for (size_type i = 0; i <= V.size() - 1; i++) {
        std::cout << V[i] << " ";
    }
    std::cout << "\n";
}

std::vector<double> takeVector(string line) {
    std::string string;
    double number;
    std::vector<double> newV;
    std::istringstream stream(line);
    while (stream >> string) {
        // if the input is a double number, adds it to the vector, otherwise - return error message:
        if (isNumber(string)) {
            number = std::stod(string);
            newV.push_back(number);
        } else {
            return newV;
        }
    }

    return newV;
}

bool isEqualVectors(std::vector<double> V, std::vector<double> U) {
    if (V.size() == U.size()) {
        return true;
    }
    return false;
}

std::vector<string> stringToVector(string line) {
    std::string string;
    std::vector<std::string> newV;
    // gets string of vector and return the vector
    while (true) {
        std::istringstream stream(line);
        while (stream >> string) {
            // if the input is a double number, adds it to the vector, otherwise - return error message
            newV.push_back(string);
        }
        return newV;
    }
}




