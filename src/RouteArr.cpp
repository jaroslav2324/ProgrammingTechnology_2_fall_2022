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
        routesArr[i]->setSourceName(sourceName);
    }
}

void RouteArr::readArrFromFile(std::string& filePath){

    try{

        std::fstream file;
        file.open(filePath, std::ios::in);
        if (! file.is_open())
            throw NoFileExistsError();
            
        std::string sourceName;
        std::string destinationName;
        int numRoute;

        for (int i = 0; i < 8; i ++){
            cin >> sourceName;
            cin >> destinationName;
            cin >> numRoute;

            if ( ! file.good())
            throw WrongFileContentError();

            routesArr[i]->setSourceName(sourceName);
            routesArr[i]->setDestinationName(destinationName);
            routesArr[i]->setNumRoute(numRoute);
        }

    }
    catch(NoFileExistsError& err){
        cout << "File " << filePath << "does not exist" << endl;
    }
    catch(WrongFileContentError& err){
        cout << "File " << filePath << " is corrupted" << endl;
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
