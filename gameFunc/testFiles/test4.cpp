#include <iostream>

// #include "BoxLid.h"
#include "TileBag.h"
// #include "Factory.h"
// #include "Player.h"
// #include "Centre.h"
// #include "Tiles.h"
// #include "BrokenTiles.h"
// #include "Line.h"


int main(int argc, char **argv)
{

    
    Bag *bag = new Bag();
    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    bag->fillBagWithTiles(0);
    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    

}
