#ifndef GameFactories
#define GameFactories

#include "Factory.h"

#define FACTORIES_NUM 5

class Factories {
public:

    // Constructor
    Factories();
    // Deconstructor
    ~Factories();

    // copy constructor
    Factories(Factories& other);
    // get factory object at given index
    factoryPtr getFactory(int index);

private:
    factoryPtr *factories;
};

typedef Factories* factoriesPtr;

#endif // Game Factories