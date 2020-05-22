#ifndef GameFactory
#define GameFactory

#include "Line.h"
#include "TileBag.h"
#include <string>
#include <vector>

#define FACTORY_SIZE 4

class Factory {
public:

    // Constructor
    Factory();
    // Deconstructor
    ~Factory();

    // Copy constructor
    Factory(Factory& other);

    // Returns current size of factory
    int size();

    // Returns the factory tiles array pointer
    linePtr getLine();

    // Load factories with randomised tile selection
    void loadFactory(Bag *bag);

private:

    Line *factoryTiles;

};

typedef Factory* factoryPtr;


#endif // Game Factory