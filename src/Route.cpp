#include "Route.h"

void Route::setSourceName(std::string& sourceName){
    this->sourceName = sourceName;
}

void Route::setDestinationName(std::string& destinationName){
    this->destinationName = destinationName;
}

void Route::setNumRoute(int numRoute){
    this->numRoute = numRoute;
}

std::string Route::getSourceName(){
    return sourceName;
}

std::string Route::getDestinationName(){
    return destinationName;
}

int Route::getNumRoute(){
    return numRoute;
}
