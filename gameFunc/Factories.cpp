#include "Factories.h"
#include <iostream>
#include <string>
#include <exception>

Factories::Factories() {
    factories = new factoryPtr[FACTORIES_NUM];
    for (int i = 0; i < FACTORIES_NUM; i++)
    {
        Factory *factory = new Factory();
        factories[i] = factory;
    }
}
Factories::~Factories() {
    for (int i = 0; i < FACTORIES_NUM; i++)
    {
        delete factories[i];
    }
    delete factories;
}

Factories::Factories(Factories& other) {

}

factoryPtr Factories::getFactory(int index) {
    try
    {
        if (index < 0 || index > FACTORIES_NUM-1)
        {
            throw "Out of Bounds Exception!";
        }
    }
    catch (char const *e)
    {
        std::cout << "Error! Factory has exceeded 4 factories! ";
        std::cout << e << std::endl;
    }
    return factories[index];
}