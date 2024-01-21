#include "fileHandler.hpp"

#include <iostream>

FileHandler::FileHandler(std::string fileName) {
  this->fileInfo.fileName = fileName;

  // Add check here for fileName perhaps?

  this->openFile(this->fileInfo.fileName) ? std::cout << this->fileInfo.fileName << " opened\n"
                                          : std::cout << this->fileInfo.fileName << " not opened\n";
}

FileHandler::~FileHandler() {}

int FileHandler::openFile(std::string fileName) {
  this->fileInfo.openFile = std::ifstream(fileName);

  if (this->fileInfo.openFile.is_open()) {
    return 1;
  } else {
    return 0;
  }
}