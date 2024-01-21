#include <string>
#include <fstream>


struct FileInformation {

    std::string fileName;
    
    std::ifstream openFile;
};

class FileHandler {

    public:
    FileHandler(std::string fileName);
    ~FileHandler();

    // Copy constructor
    // Move constructor 


    private:
    FileInformation fileInfo;

    int openFile(std::string fileName);

};