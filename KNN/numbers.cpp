// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <cmath>
#include <string>
#include <cstdlib>
#include "numbers.h"

using namespace std;

bool isInteger(const std::string &s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')) || s.size() >= 10) {
        return false;
    }
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

double absolute(double number) {
    if (number < 0) {
        return number * (-1);
    }
    return number;
}

bool isNumber(const std::string &s) {
    char *end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

