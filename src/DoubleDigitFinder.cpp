#include "DoubleDigitFinder.h"

void DoubleDigitFinder::printNoDoubleDigitsString(std::string& filePath){

    std::fstream file;
    try{
        file.open(filePath, std::ios::in);
        if (! file.is_open())
            throw NoFileExistsError();
    }
    catch(NoFileExistsError& err){
        cout << "File " << filePath << " does not exist" << endl;
        waitAnyKeyAndNewLine();
    }

    clearTerminal();

    std::string line;
    while (std::getline(file, line))
    {
        int lenDigit = 0;
        bool doubleDigit = false;
        std::istringstream iss(line);
        std::noskipws(iss);
        char c;
        while(iss >> c){

            if ('0' <= c && c <= '9'){
                lenDigit++;
                continue;
            }
            
            if (lenDigit == 2){
                doubleDigit = true;
                break;
            }

            lenDigit = 0;
        }
        
        if (doubleDigit)
            continue;
        cout << line << endl;        
    }
    waitAnyKeyAndNewLine();
    
}