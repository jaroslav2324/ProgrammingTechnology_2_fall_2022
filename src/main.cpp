#include <iostream>

using std::cout;
using std::endl;

#include "RouteArr.h"
#include "DoubleDigitFinder.h"

int main(){

    RouteArr routeArr;
    DoubleDigitFinder finder;

    while(true){

        bool exitWhile = false;

        clearTerminal();
        cout << "1 - work with routes\n2 - find all strings without double digits\ne - exit\n";

        char c = enterSymbol();

        switch (c)
        {
        case '1':
            routeArr.menu();
            break;

        case '2':
        {
            std::string filePath = "input2.txt";
            finder.printNoDoubleDigitsString(filePath);
            break;
        }

        case 'e':
            exitWhile = true;
            break;
            
        default:
            cout << "Wrong key! Try once again." << endl;
            waitAnyKeyAndNewLine();
            break;
        }

        if (exitWhile)
            break;
    }
}