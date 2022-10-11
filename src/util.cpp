#include "util.h"

int enterInt(){

    int num;

    cout << "Enter int number" << endl;
    cin >> num;

    while (!(cin.good())){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong number! Try once again!" << endl; 
        cout << "Enter int number" << endl;
        cin >> num;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}

/*reads char if char provided*/
char enterSymbol(){

    std::string str;

    cout << "Enter symbol" << endl;
    cin >> str;

    while (!(cin.good()) || str.length() > 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong symbol! Try once again!" << endl; 
        cout << "Enter symbol" << endl;
        cin >> str;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return str[0];
}

string enterString(){

    std::string str;

    cout << "Enter string" << endl;
    cin >> str;

    while (!(cin.good())){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong string!" << endl; 
        cout << "Enter string" << endl;
        cin >> str;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return str;
}

void waitAnyKeyAndNewLine(){

    cout << "Enter any symbol to continue" << endl;
    std::string str;
    cin >> str;
}

void clearTerminal(){
    system("clear");
}