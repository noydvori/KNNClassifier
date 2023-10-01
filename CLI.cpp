// Avigail Danesh 213372063
// Noy Dvori 211908256

#include "CLI.h"
#include <string>
#include "DefaultIO.h"

using namespace std;

void CLI::start() {
    bool stop = false;
    // prints the welcome message on the first try.
    bool firstTime = true;
    while (!stop) {
        if (firstTime) {
            _dio.write("printWelcome to the KNN Classifier Server. Please choose an option:\n");
            firstTime = false;
        } else {
            // normal message.
            _dio.write("printPlease choose an option:\n");
        }
        // prints description of every command.
        for (int i = 0; i < _commands.size(); i++) {
            _dio.write("print" + to_string(i + 1) + ". " + _commands[i]->description() + "\n");
        }
        // exit option.
        _dio.write("write8. exit\n");
        // client's choice.
        string input = _dio.read();
        // must be an integer between 1 and the number of commands.
        if (!isInteger(input) || stoi(input) < 1 || (stoi(input) > _commands.size() + 1 && stoi(input) != 8)) {
            // asks for input until a valid choice is entered.
            do {
                _dio.write("writeInvalid choice! Please try again.\n");
                input = _dio.read();
            } while (!isInteger(input) || stoi(input) < 1 || stoi(input) > _commands.size() + 1);
        }
        // executes chosen command.
        int choice = stoi(input);
        if (choice == 8) {
            stop = true;
            _dio.write("end");
        } else {
            _commands[choice - 1]->execute();
        }
    }
}

bool CLI::isInteger(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    for (const char &c: str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}