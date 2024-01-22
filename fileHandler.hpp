#pragma once

#include <fstream>
#include <sstream>
#include <string>

struct FileInformation {
  std::string fileName;

  std::fstream openFile;
};

class FileHandler {
 public:
  FileHandler(std::string fileName);
  ~FileHandler();

  // Copy constructor
  // Move constructor

 private:
  FileInformation fileInfo;
  void readFile(std::fstream &fileHandle);
  std::stringstream outputBuffer;

  std::streampos cursorPosition;

  void moveCursorForward();

  void moveCursorBackward();

  void displayCurrentLine();

  void runCLI();
  // int openFile(std::string fileName);
};