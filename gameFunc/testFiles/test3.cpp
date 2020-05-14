#include <iostream>

// #include "BoxLid.h"
// #include "TileBag.h"
#include "Factory.h"
#include "Player.h"
#include "Centre.h"
// #include "Tiles.h"
// #include "BrokenTiles.h"
// #include "Line.h"


int main(int argc, char **argv)
{

    //testing tiles
    tilePtr tile1 = new char(YELLOW);
    tilePtr tile2 = new char(YELLOW);
    tilePtr tile3 = new char(DARKBLUE);
    tilePtr tile4 = new char(LIGHTBLUE);
    tilePtr tile5 = new char(BLACK);

    // Lid *lid = new Lid();
    Bag *bag = new Bag();
    // Player *player1 = new Player();
    // Factory *factory1 = new Factory();
    Centre *centre = new Centre();

    centre->addTile(tile1);
    centre->addTile(tile2);
    centre->addTile(tile3);
    centre->addTile(tile4);
    centre->addTile(tile5);
    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "centre size: " << centre->size() << std::endl;

    std::cout << "DEBUG: " << "Adding 5 tiles into bag" << std::endl;
    bag->addTileToBack(centre->removeTile(0));
    bag->addTileToBack(centre->removeTile(0));
    bag->addTileToBack(centre->removeTile(0));
    bag->addTileToBack(centre->removeTile(0));
    bag->addTileToBack(centre->removeTile(0));
    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "centre size: " << centre->size() << std::endl;
    

}
