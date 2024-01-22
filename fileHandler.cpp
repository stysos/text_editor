#include "fileHandler.hpp"

#include <termios.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

FileHandler::FileHandler(std::string fileName)
    : fileInfo{fileName, std::fstream(fileName)} {
  std::cout << fileInfo.fileName
            << (fileInfo.openFile.is_open() ? " opened\n" : " not opened\n");

  readFile(fileInfo.openFile);

  cursorPosition = 0;

  runCLI();
}

FileHandler::~FileHandler() {}

/*
May be used in the future
int FileHandler::openFile(std::string fileName) {
  fileInfo.openFile = std::ifstream(fileName);

  return fileInfo.openFile.is_open();
}
*/

void FileHandler::readFile(std::fstream &fileHandle) {
  outputBuffer << fileInfo.openFile.rdbuf();
  std::cout << outputBuffer.str() << "\n";
}

void FileHandler::moveCursorForward() {
  // Assuming each character is one byte
  cursorPosition += sizeof(char);
}

void FileHandler::moveCursorBackward() {
  // Assuming each character is one byte
  if (cursorPosition >= sizeof(char)) {
    cursorPosition -= sizeof(char);
  }
}
void FileHandler::displayCurrentLine() {
  fileInfo.openFile.seekg(cursorPosition, std::ios::beg);

  std::string currentLine;
  std::getline(fileInfo.openFile, currentLine);
  std::cout << "Cursor at position " << cursorPosition << ": " << currentLine
            << "\n";
}

void FileHandler::runCLI() {
  struct termios oldt, newt;
  char ch;

  // Save the current terminal settings
  tcgetattr(STDIN_FILENO, &oldt);

  // Disable canonical mode and echo
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  // Display the initial cursor position
  displayCurrentLine();

  // Listen for user input
  while (1) {
    std::cin.get(ch);

    // Handle Vim-like motions
    switch (ch) {
      case 'h':
        moveCursorBackward();
        displayCurrentLine();
        break;
      case 'l':
        moveCursorForward();
        displayCurrentLine();
        break;
      case 'q':
        // Quit the loop
        goto endLoop;
      default:
        // Ignore other characters
        break;
    }
  }

endLoop:
  // Restore the original terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}