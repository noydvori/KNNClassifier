// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef A_OUT_NUMBERS_H
#define A_OUT_NUMBERS_H

/**
 * Checks if the given string is an integer.
 * @param s - given string
 * @return true if the string is an integer, otherwise return false.
 */
bool isInteger(const std::string &s);

/**
 * This function returns the absolute value of the given number.
 * @param number - given number
 * @return the absolute value of the number
 */
double absolute(double number);

/**
 * This function checks if the given string is a double number.
 * @param s - given string
 * @return true if the string is number. otherwise return false.
 */
bool isNumber(const std::string &s);

#endif //A_OUT_NUMBERS_H
