// Avigail Danesh 213372063
// Noy Dvori 211908256

#ifndef SIMPLE_EXAMPLE_FILEHANDLER_HPP
#define SIMPLE_EXAMPLE_FILEHANDLER_HPP

#include <string>
#include <vector>

namespace files {
    class fileHandler {
    public:
        /**
        * from string to lines.
        * @param data string.
        * @param separator char.
        * @return vector string.
        */
        static std::vector<std::string> stringToLines(const std::string &data, char separator = '\n');

        /**
         * check if valid file.
         * @param path string.
         * @return true or false.
         */
        static bool validPath(const std::string &path);
    };
}

#endif //SIMPLE_EXAMPLE_FILEHANDLER_HPP