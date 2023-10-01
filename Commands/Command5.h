// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef A_OUT_COMMAND5_H
#define A_OUT_COMMAND5_H

#include "Command.h"

/**
 * Class for the 5th command in the menu.
 */
class Command5 : public Command {
private:
    fileDatabase &_results;
    fileDatabase &_classified;
    fileDatabase &_unclassified;
    bool &_isClassified;
public:
    /**
    * Command5 constructor
    * @param dio
    * @param classified
    * @param unclassified
    * @param results
    */
    Command5(DefaultIO &dio, fileDatabase &classified, fileDatabase &unclassified, fileDatabase &results, bool &isClassified);
    /**
     * creates file on the given path.
     * @param path
     */
    void toFile(string path);

    /**
     * Creates new file contains the classifications of the vectors in the test file.
     */
    void execute() override;
};


#endif //A_OUT_COMMAND5_H
