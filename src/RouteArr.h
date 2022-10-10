#include <fstream>

#include "WrongFileContentErr.h"
#include "NoFileExistsErr.h"
#include "Route.h"
#include "util.h"

using std::cin;
using std::cout;
using std::endl;

class RouteArr{
    public:
    RouteArr();
    ~RouteArr();

    void enterArr();
    void readArrFromFile(std::string& filePath);

    void printRoutesWithSourceName(std::string& sourceName);
    void printRoutesWithDestinationName(std::string& destinationName);

    //TODO sortRoutes

    private:
    Route** routesArr = nullptr;
};