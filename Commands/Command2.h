// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef A_OUT_COMMAND2_H
#define A_OUT_COMMAND2_H

#include "Command.h"
#include <string>

/**
 * Class for the 2th command in the menu.
 */
class Command2 : public Command {
public:
    fileDatabase &_classified;
    fileDatabase &_unclassified;
    int &_k;
    std::string &_distanceType;
    bool &_isClassified;

    /**
     * Command2 constructor
     * @param dio
     * @param _classified
     * @param _unclassified
     * @param k
     * @param distanceType
     */
    Command2(DefaultIO &dio, fileDatabase &_classified, fileDatabase &_unclassified, int &k, std::string &distanceType, bool &isClassified);

    /**
     * Lets the user change k and distance type.
     */
    void execute() override;
};


#endif //A_OUT_COMMAND2_H
