// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef A_OUT_COMMAND3_H
#define A_OUT_COMMAND3_H

#include "Command.h"

/**
 * Class for the 3th command in the menu.
 */
class Command3 : public Command {
private:
    fileDatabase &_classified;
    fileDatabase &_unclassified;
    fileDatabase &_results;
    int &_k;
    string &_distanceType;
    bool &_isClassified;
public:
    /**
     * Command4 constructor.
     * @param dio
     * @param classified
     * @param unclassified
     * @param results
     * @param k
     * @param distanceType
     */
    Command3(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, fileDatabase &results, int &k,
             string &distanceType, bool &isClassified);

    /**
     * classify the test file.
     */
    void execute() override;
};


#endif //A_OUT_COMMAND3_H
