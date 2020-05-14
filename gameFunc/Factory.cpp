#include <iostream>
#include <string>

#include "Factory.h"

Factory::Factory() {
    factoryTiles = new Line(FACTORY_SIZE);
}

Factory::Factory(Factory &other) {

}

int Factory::size() {
    return FACTORY_SIZE;
}

Factory::~Factory() {
    delete factoryTiles;
}

linePtr Factory::getLine() {
    return factoryTiles;
}

void Factory::loadFactory(Bag *bag) {
    if (factoryTiles->getTilesNumber() == 0) {
        for (int i = 0; i < FACTORY_SIZE; i++) {
            factoryTiles->addTileToIndex(bag->removeTileFront(), i);
        }
    }
    else {
        throw std::logic_error("Factory: Tiles present when trying to load factory");
    }
}