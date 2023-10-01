// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef SIMPLE_EXAMPLE_DEFAULTIO_H
#define SIMPLE_EXAMPLE_DEFAULTIO_H

#include <string>

/**
 * DefaultIO class.
 */
class DefaultIO {
public:
    virtual std::string read()=0;
    virtual void write(const std::string& message)=0;
};


#endif //SIMPLE_EXAMPLE_DEFAULTIO_H
