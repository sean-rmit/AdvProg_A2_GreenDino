#ifndef GameFactory
#define GameFactory

#include "Line.h"
#include "TileBag.h"
#include <string>
#include <vector>
#define FACTORY_SIZE 4

class Factory {
public:

    Factory();
    ~Factory();

    // copy constructor
    Factory(Factory& other);

    // returns current size of factory
    int size();

    // returns the factory tiles array pointer
    linePtr getLine();

    // load factories with randomised tile selection
    void loadFactory(Bag *bag);

private:

    Line *factoryTiles;

};

typedef Factory* factoryPtr;


#endif // GameFactory