#include <iostream>
#include <string>
#include <memory>

#include <gtest/gtest.h>

#include "fileHandler.hpp"

// int main(int, char** argv){

//     // Assuming correct argv for now (Single argument of string).
//     // TODO: Checks for strings.
//     if (!argv[1]) {
//         std::cerr << "No file name specified" << std::endl;
//         exit(0);
//     }
    
//     auto fileName = std::string(argv[1]);
    
//     auto testHandler = std::make_unique<FileHandler>(fileName);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}