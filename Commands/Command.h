// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef SIMPLE_EXAMPLE_COMMAND_HPP
#define SIMPLE_EXAMPLE_COMMAND_HPP

#include "../DefaultIO.h"
#include "../CSV/fileDatabase.h"
#include "../KNN/distanceAndClassification.h"
#include "../KNN/distances.h"

/**
 * Command class.
 */
class Command {
protected:
    DefaultIO &_dio;
    string _description;
public:
    /**
     * command message is "Default Command".
     * @param dio IO for reading and writing.
     */
    explicit Command(DefaultIO &dio);

    /**
     * @return the description of the command.
     */
    string description();

    /**
     * Command execution.
     */
    virtual void execute() = 0;

    /**
     * Virtual destructor to be able to manage "new" instances of inheritor classes.
     */
    virtual ~Command() = default;
};


#endif //SIMPLE_EXAMPLE_COMMAND_HPP
