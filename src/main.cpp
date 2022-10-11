#include <iostream>

using std::cout;
using std::endl;

#include "RouteArr.h"

int main(){

    RouteArr routeArr;

    while(true){

        bool exitWhile = false;

        clearTerminal();
        cout << "1 - work with routes\n2 - work with string and file threads\ne - exit\n";

        char c = enterSymbol();

        switch (c)
        {
        case '1':
            routeArr.menu();
            break;

        case '2':
            break;

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