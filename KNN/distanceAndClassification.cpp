// Avigail Danesh 213372063
// Noy Dvori 211908256

#include <string>
#include <vector>
#include "distanceAndClassification.h"
#include "distances.h"

using size_type = std::vector<string>::size_type;
using namespace std;

distanceAndClassification *
distanceAndClassification::calculatesAllDistances(vector<double> v, fileDatabase database, string distanceType) {
    distanceAndClassification *info = new distanceAndClassification[database.data.size()];
    vector<double> tmp;
    double d;
    size_type i;
    for (i = 0; i < database.data.size(); i++) {
        // Convert to double vector
        tmp = convertToDoubleVector(database.data[i]);
        // Calculate the distance and save in Info array
        d = returnDistance(v, tmp, distanceType);
        info[i].distance = d;
        info[i].classification = database.data[i][database.data[i].size() - 1];
    }
    return info;
}

void distanceAndClassification::bubbleSort(distanceAndClassification *info, int len) {
    int i, j;
    // Pass of the array and compare between 2 numbers per loop
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            // If the bigger number is left then swap between them
            if (info[j].distance > info[j + 1].distance) {
                distanceAndClassification temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
}

distanceAndClassification *distanceAndClassification::findK(distanceAndClassification *info, int k, int len) {
    int i;
    // Array of info to keep the names, for function findTheCommonType
    distanceAndClassification *closestK = new distanceAndClassification[k];
    // Sorting the array distance and take the smallest k in there
    bubbleSort(info, len);
    for (i = 0; i < k; i++) {
        closestK[i].classification = info[i].classification;
        closestK[i].distance = info[i].distance;
    }
    // We want to use it in function findTheCommonType
    return closestK;
}

string distanceAndClassification::findTheCommonType(distanceAndClassification *info, int k) {
    int max = 0, c = 0;
    int i;
    // As long as we still don't finish the array
    for (i = 0; i < k; i++) {
        int j = 0;
        while (j != i && info[j].classification != info[i].classification) ++j;
        if (j == i) {
            int count = 1;
            while (++j != k) {
                if (info[j].classification == info[i].classification) ++count;
            }
            if (c < count) {
                max = i;
                c = count;
            }
        }
    }
    // Return the string that repeat the most
    return info[max].classification;
}

string distanceAndClassification::returnClassification(int k, vector<double> inputV, std::string distanceType,
                                                       fileDatabase data) {
    distanceAndClassification *allInfo = calculatesAllDistances(inputV, data, distanceType);
    // Call function findK to find the closest distances
    distanceAndClassification *infoK = findK(allInfo, k, data.data.size());
    // Find which string repeat the most, and print it
    return findTheCommonType(infoK, k);
}