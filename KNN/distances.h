// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include "numbers.h"

using namespace std;


#ifndef EXERCISE1_EX1_H
#define EXERCISE1_EX1_H

const int BIT = 1;
const int BYTE = 8 * BIT;

/**
 * This function calculates the GENERAL Minkowski distance between two vectors.
 * @param V - first vector
 * @param U - second vector
 * @param p - variable p
 * @return Minkowski distance between two vectors with placement of the P value in the formula.
 */
double pMinkowskiDistance(vector<double> V, vector<double> U, double p);

/**
 * This function calculates the Euclidean distance between two vectors (using GENERAL Minkowski distance with p = 1)
 * @param V - first vector
 * @param U - second vector
 * @return Euclidean distance between two vectors.
 */
double euclideanDistance(vector<double> V, vector<double> U);

/**
* This function calculates the Manhattan distance between two vectors (using GENERAL Minkowski distance with p = 2)
* @param V - first vector
* @param U - second vector
* @return Manhattan distance between two vectors.
*/
double manhattanDistance(vector<double> V, vector<double> U);

/**
 * his function calculates the Minkowski distance between two vectors (using GENERAL Minkowski distance with p = 100)
 * @param V - first vector
 * @param U - second vector
 * @return Minkowski distance between two vectors.
 */
double minkowskiDistance(vector<double> V, vector<double> U);

/**
* This function calculates the Chebyshev distance between two vectors
* @param V - first vector
* @param U - second vector
* @return Chebyshev distance between two vectors.
*/
double chebyshevDistance(vector<double> V, vector<double> U);

/**
 * This function calculates the Canberra distance between two vectors
 * @param V - first vector
 * @param U - second vector
 * @return Canberra distance between two vectors.
 */
double canberraDistance(vector<double> V, vector<double> U);

/**
* Takes a labeled vector, reduces its size by one and converts all its values to doubles.
* @param v - given vector.
* @return double vector
*/
vector<double> convertToDoubleVector(vector<string> v);

/**
 * This function prints the given vector.
 * @param V - given vector
 */
void printVector(const std::vector<double> &V);

/**
 * Takes the vector from input line
 * @param line - given input
 * @return
 */
std::vector<double> takeVector(string line);

/**
 * This function checks if the vector's sizes are equal.
 * @param V - first vector
 * @param U - second vector
 * @return true when the sizes are equal, false otherwise.
 */
bool isEqualVectors(std::vector<double> V, std::vector<double> U);

/**
 * Splits each word in line into different vector value cell
 * @param line - given line
 * @return
 */
std::vector<string> stringToVector(string line);

/**
* Checks validity of distance type.
* @param str - given distance type
*/
bool checkDistanceType(string str);

/**
 * Calculates the distance according to the given distance type.
 * @param V - given vector
 * @param U  - given vector
 * @param distanceType - valid distance type
 * @return accurate distance.
 */
double returnDistance(vector<double> v, vector<double> u, string distanceType);

#endif //EXERCISE1_EX1_H
