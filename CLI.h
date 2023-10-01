#ifndef SIMPLE_EXAMPLE_CLI_H
#define SIMPLE_EXAMPLE_CLI_H

#include <vector>
#include <memory>
#include "Commands/Command.h"
#include "Commands/Command1.h"
#include "Commands/Command2.h"
#include "Commands/Command3.h"
#include "Commands/Command4.h"
#include "Commands/Command5.h"


class CLI {
private:
    std::vector<std::unique_ptr<Command>> _commands;
    DefaultIO &_dio;

    static bool isInteger(const std::string &str);

public:
    fileDatabase *_results = new fileDatabase();
    fileDatabase *_classified = new fileDatabase();
    fileDatabase *_unclassified = new fileDatabase();
    int _k;
    string _distanceType;
    bool _isClassified;

    /**
     * Initializes a command line interface with default settings and set of commands.
     * @param dio IO for reading and writing.
     */
    CLI(DefaultIO &dio) : _dio(dio), _commands() {
        _k = 5;
        _distanceType = "AUC";
        _isClassified = false;
        auto *uploader = new Command1{dio, *_classified, *_unclassified, _isClassified};
        auto *setter = new Command2{dio,*_classified, *_unclassified, _k, _distanceType, _isClassified};
        auto *knn = new Command3{dio, *_classified, *_unclassified, *_results, _k, _distanceType, _isClassified};
        auto *display=new Command4{dio,*_classified,*_unclassified,*_results, _isClassified};
        auto *csvCreator=new Command5{dio,*_classified,*_unclassified,*_results, _isClassified};
        _commands.push_back(unique_ptr<Command1>(uploader));
        _commands.push_back(unique_ptr<Command2>(setter));
        _commands.push_back(unique_ptr<Command3>(knn));
        _commands.push_back(unique_ptr<Command4>(display));
        _commands.push_back(unique_ptr<Command5>(csvCreator));
    }

    /**
    * starts CLI.
    */
    void start();
};


#endif //SIMPLE_EXAMPLE_CLI_HPP
