
#include "DNA.h"


using namespace std;

DNA::DNA(const std::string& fName)
{
    content = "";
    line = "";
    ifstream inFile (fName);
    if(inFile.is_open())
    {
        getline(inFile, line);
        content += line;
        content +="|";
    }
}

