#include <iostream>
#include <string>
#include <memory>

#include "fileHandler.hpp"

int main(int, char** argv){

    // Assuming correct argv for now (Single argument of string).
    // TODO: Checks for strings.
    if (!argv[1]) {
        std::cerr << "No file name specified" << std::endl;
        exit(0);
    }
    
    auto fileName = std::string(argv[1]);
    
    auto testHandler = std::make_unique<FileHandler>(fileName);
}