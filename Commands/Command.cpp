// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "Command.h"

string Command::description() {
    return _description;
}

Command::Command(DefaultIO &dio) : _dio(dio),_description("Default Command") {
}
