// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef A_OUT_INPUTVALIDITY_H
#define A_OUT_INPUTVALIDITY_H

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "KNN/numbers.h"

using namespace std;

/**
 * Checks if the string is not containing numerical chars.
 * @param str - given string
 * @return true/false
 */
bool isString(const std::string &str);

/**
 * Checks if argc == 3, otherwise exit from program.
 * @param argc - given argc
 */
void isValidArgcC(int argc);

/**
 * Checks if argc == 2, otherwise exit from program.
 * @param argc - given argc
 */
void isValidArgcS(int argc);

/**
 * Checks if the given port is valid, otherwise exit from program.
 * @param string_port - given port
 * @return
 */
int isValidPort(string string_port);

/**
 * Checks if the given IP is valid, otherwise exit from program.
 * @param ipAddress - given IP
 * @return
 */
void isValidIpAddress(char *ipAddress);

#endif //A_OUT_INPUTVALIDITY_H
