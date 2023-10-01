// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef A_OUT_COMMAND4_H
#define A_OUT_COMMAND4_H

#include "Command.h"

/**
 * Class for the 4th command in the menu.
 */
class Command4 : public Command {
private:
    fileDatabase &_results;
    fileDatabase &_classified;
    fileDatabase &_unclassified;
    bool &_isClassified;
public:
    /**
     * Command4 constructor.
     * @param dio
     * @param classified
     * @param unclassified
     * @param results
     */
    Command4(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, fileDatabase &results, bool &isClassified);

    /**
     * Prints the classifications of the vectors in the test file.
     */
    void execute() override;
};


#endif //A_OUT_COMMAND4_H
