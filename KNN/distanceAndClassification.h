// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef DISTANCE_AND_CLASSIFICATION_H
#define DISTANCE_AND_CLASSIFICATION_H

#include <string>
#include <vector>
#include "../CSV/fileDatabase.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

/**
 * distanceAndClassification class.
 */
class distanceAndClassification {
public:
    double distance;
    string classification;

    /**
    * Calculates all distances from the given vector and arranges in an Info array.
    * @param v - given vector
    * @param data - all data from the file
    * @param distanceType - given distance type
    * @return array of type Info.
    */
    static distanceAndClassification *
    calculatesAllDistances(vector<double> v, fileDatabase database, string distanceType);

    /**
    * Sorts the given array by distances (ascending order).
    * @param info - given info array
    * @param len - size of info array
    */
    static void bubbleSort(distanceAndClassification *info, int len);

    /**
    * Finds the K smallest distances and returns them as an info array.
    * @param info - given info
    * @param k - given number
    * @param len - size of info array
    * @return info array include the closest vectors to input vector
    */
    static distanceAndClassification *findK(distanceAndClassification *info, int k, int len);

    /**
    * Finds the most common label in info array.
    * @param info - given info array
    * @param n - size of info array
    * @return
    */
    static string findTheCommonType(distanceAndClassification *info, int k);

    /**
    * This function returns the classification according the given params.
    * @param k - for closest K
    * @param inputV - given vector
    * @param distanceType - metric
    * @param data - file database
    * @return
    */
    static string returnClassification(int k, vector<double> inputV, string distanceType, fileDatabase data);
};

#endif // DISTANCE_AND_CLASSIFICATION_H
