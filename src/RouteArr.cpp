#include "RouteArr.h"

RouteArr::RouteArr(){

    routesArr = new Route*[8];

    for (int i = 0; i < 8; i++)
        routesArr[i] = new Route;
}

RouteArr::~RouteArr(){

    for (int i = 0; i < 8; i++)
        delete routesArr[i];

    delete[] routesArr;
}

void RouteArr::enterArr(){

    std::string sourceName;
    std::string destinationName;
    int numRoute;

    for (int i = 0; i < 8; i++){

        cout << "Enter " << i + 1 << " source name" << endl;
        cin >> sourceName;
        routesArr[i]->setSourceName(sourceName);
        cout << "Enter " << i + 1 << " destination name" << endl;
        cin >> destinationName;
        routesArr[i]->setDestinationName(destinationName);
        cout << "Enter " << i + 1 << " number of route";
        numRoute = enterInt();
        routesArr[i]->setNumRoute(numRoute);
    }
}

void RouteArr::readArrFromFile(std::string& filePath){

    std::fstream file;

    try{

        file.open(filePath, std::ios::in);
        if (! file.is_open())
            throw NoFileExistsError();
            
        std::string sourceName;
        std::string destinationName;
        int numRoute;

        for (int i = 0; i < 8; i ++){
            file >> sourceName;
            file >> destinationName;
            file >> numRoute;

            if ( ! file.good())
            throw WrongFileContentError();

            routesArr[i]->setSourceName(sourceName);
            routesArr[i]->setDestinationName(destinationName);
            routesArr[i]->setNumRoute(numRoute);
        }
        file.close();

    }
    catch(NoFileExistsError& err){
        cout << "File " << filePath << " does not exist" << endl;
        waitAnyKeyAndNewLine();
    }
    catch(WrongFileContentError& err){
        cout << "File " << filePath << " is corrupted" << endl;
        file.close();
        waitAnyKeyAndNewLine();
    }
}

void RouteArr::printRoutesWithSourceName(std::string& sourceName){

    bool nameExist = false;

    for (int i = 0; i < 8; i++){
        std::string name = routesArr[i]->getSourceName();
        if (name == sourceName){
            cout << routesArr[i]->getNumRoute() << " " << sourceName << "->" << routesArr[i]->getDestinationName() << endl;
            nameExist = true;
        }
    }

    if ( ! nameExist)
        cout << "No route with such source name" << endl;
}

void RouteArr::printRoutesWithDestinationName(std::string& destinationName){

    bool nameExist = false;

    for (int i = 0; i < 8; i++){
        std::string name = routesArr[i]->getDestinationName();
        if (name == destinationName){
            cout << routesArr[i]->getNumRoute() << " " << routesArr[i]->getSourceName() << "->" << destinationName << endl;
            nameExist = true;
        }
    }

    if ( ! nameExist)
        cout << "No route with such destination name" << endl;
}

void RouteArr::sortRoutesByNumber(){

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if (routesArr[j]->getNumRoute() > routesArr[j + 1]->getNumRoute()){
                Route* tempPtr = routesArr[j];
                routesArr[j] = routesArr[j + 1];
                routesArr[j + 1] = tempPtr;
            }

}

void RouteArr::printRoutes(){

    for (int i = 0; i < 8; i++)
        cout << routesArr[i]->getNumRoute() << " " << routesArr[i]->getSourceName() << "->" << routesArr[i]->getDestinationName() << endl;
}

void RouteArr::menu(){

while (true){

    bool exitWhile = false;

    clearTerminal();
    cout << "1 - Enter routes from keyboard\n2 - Enter routes from file\n";

        char c = enterSymbol();

        switch (c)
        {
        case '1':
            clearTerminal();
            enterArr();
            sortRoutesByNumber();
            exitWhile = true;
            break;
        case '2':
        {
            clearTerminal();
            std::string filePath = "input.txt";
            readArrFromFile(filePath);
            sortRoutesByNumber();
            exitWhile = true;
            break;
        }
        default:
            clearTerminal();
            cout << "Wrong option! Try once again." << endl;
            waitAnyKeyAndNewLine();
            break;
        }
        
    if (exitWhile)
        break; 

}

while (true){

    bool exitWhile = false;

    clearTerminal();
    cout << "1 - enter routes\n2 - print routes\n3 - print routes with source name\n4 - print routes with destination name\n5 - print chosen route\n\
6 - choose route\n7 - change source name of chosen route\n8 - change destination name of chosen route\n9 - change number of route\nb - go back\n";

    char c = enterSymbol();

    switch(c){
    
    case '1':
        clearTerminal();
        enterArr();
        sortRoutesByNumber();
        break;
    case '2':
        clearTerminal();
        printRoutes();
        waitAnyKeyAndNewLine();
        break;
    case '3':
    {
        std::string sourceName;

        clearTerminal();
        cout << "Enter source name" << endl;
        sourceName = enterString();

        clearTerminal();
        printRoutesWithSourceName(sourceName);
        waitAnyKeyAndNewLine();
        break;
    }
    case '4':
        {
        std::string destinationName;

        clearTerminal();
        cout << "Enter destination name" << endl;
        destinationName = enterString();

        clearTerminal();
        printRoutesWithDestinationName(destinationName);
        waitAnyKeyAndNewLine();
        break;
    }
    case '5':
        {
        clearTerminal();

        cout << routesArr[indexChosenRoute]->getNumRoute() << " " << routesArr[indexChosenRoute]->getSourceName() <<
         "->" << routesArr[indexChosenRoute]->getDestinationName() << "\n";

        waitAnyKeyAndNewLine();
        break;
    }
    case '6':
    {
        clearTerminal();
        cout << "Chosen route is " << indexChosenRoute << endl;
        cout << "Enter index(0-7) of new route:" << endl;
        int index = enterInt();
        if (index < 0 || 7 < index){
            cout << "Wrong index!" << endl;
            waitAnyKeyAndNewLine();
            break;
        }
        indexChosenRoute = index;
        break;
    }
    case '7':
    {
        std::string sourceName;

        clearTerminal();
        cout << "Enter source name" << endl;
        sourceName = enterString();

        routesArr[indexChosenRoute]->setSourceName(sourceName);
        break;
    }
    case '8':
    {
        std::string destinationName;

        clearTerminal();
        cout << "Enter destination name" << endl;
        destinationName = enterString();

        routesArr[indexChosenRoute]->setDestinationName(destinationName);
        break;
    }
    case '9':
    {
        int number;

        clearTerminal();
        cout << "Enter number of route" << endl;
        number = enterInt();

        routesArr[indexChosenRoute]->setNumRoute(number);
        sortRoutesByNumber();
        
        break;
    }
    case 'b':
        exitWhile = true;
        break;

    default:
        cout << "Wrong key!" << endl;
        waitAnyKeyAndNewLine();
        break;
    }

if (exitWhile)
    break;
}
  
}
