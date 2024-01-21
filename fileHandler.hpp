#include <string>
#include <fstream>


struct FileInformation {

    std::string fileName;
};

class FileHandler {

    public:
    FileHandler(std::string fileName);
    ~FileHandler();

    // Copy constructor
    // Move constructor 
    

    private:
    FileInformation fileInformation;

};