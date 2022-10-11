#include <iostream>
#include <string>

class Route{
    public:

    void setSourceName(std::string& sourceName);
    void setDestinationName(std::string& destinationName);
    void setNumRoute(int num);

    std::string getSourceName();
    std::string getDestinationName();
    int getNumRoute();

    protected:
    std::string sourceName = "Undefined";
    std::string destinationName = "Undefined";
    int numRoute = -1;
};