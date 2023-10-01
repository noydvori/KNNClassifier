// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef A_OUT_COMMAND1_H
#define A_OUT_COMMAND1_H

#include "Command.h"
#include "../CSV/fileDatabase.h"

/**
 *  Class for the 2th command in the menu.
 */
class Command1 : public Command {
private:
    fileDatabase &_classified;
    fileDatabase &_unclassified;
    bool &_isClassified;
public:
    /**
     * Command2 constructor
     * @param dio
     * @param classified
     * @param unclassified
     */
    Command1(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, bool &_isClassified);

    /**
     * Lets the user enter 2 files.
     */
    void execute() override;
};

#endif //A_OUT_COMMAND1_H
