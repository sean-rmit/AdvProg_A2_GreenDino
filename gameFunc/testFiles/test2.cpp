#include <iostream>

// #include "BoxLid.h"
// #include "TileBag.h"
#include "Factory.h"
#include "Player.h"
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
    tilePtr tile6 = new char(BLACK);
    tilePtr tile7 = new char(BLACK);
    tilePtr tile8 = new char(BLACK);
    tilePtr tile9 = new char(BLACK);
    tilePtr tile10 = new char(BLACK);
    tilePtr tile11 = new char(BLACK);
    tilePtr tile12 = new char(BLACK);

    Lid *lid = new Lid();
    Bag *bag = new Bag();
    Player *player1 = new Player();
    Factory *factory1 = new Factory();
    Centre *centre = new Centre();

    std::cout << "DEBUG: " << "Adding 5 tiles into bag" << std::endl;
    bag->addTileToBack(tile1);
    bag->addTileToBack(tile2);
    bag->addTileToBack(tile3);
    bag->addTileToBack(tile4);
    bag->addTileToBack(tile5);

    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "lid: " << lid->getTilesAsString() << std::endl;
    std::cout << "factory1: " << factory1->getLine()->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(0)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(1)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(2)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(3)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(4)->getTilesAsString() << std::endl;
    std::cout << "player1 brokenTiles: " << player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString() << std::endl;
    std::cout << std::endl;

    std::cout << "DEBUG: " << "Loading factory with tiles from bag" << std::endl;
    factory1->loadFactory(bag);

    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "lid: " << lid->getTilesAsString() << std::endl;
    std::cout << "factory1: " << factory1->getLine()->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(0)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(1)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(2)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(3)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(4)->getTilesAsString() << std::endl;
    std::cout << "player1 brokenTiles: " << player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString() << std::endl;
    std::cout << std::endl;

    std::cout << "DEBUG: " << "player1 chooses tile color Y from factory 1 to their patternline1" << std::endl;
    player1->takeTilesFromFactory(factory1, 'Y', centre, 0, lid);

    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "lid: " << lid->getTilesAsString() << std::endl;
    std::cout << "factory1: " << factory1->getLine()->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(0)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(1)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(2)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(3)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(4)->getTilesAsString() << std::endl;
    std::cout << "player1 brokenTiles: " << player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString() << std::endl;
    std::cout << std::endl;

    centre->addTile(tile6);
    centre->addTile(tile7);
    centre->addTile(tile8);
    centre->addTile(tile9);
    centre->addTile(tile10);
    centre->addTile(tile11);
    centre->addTile(tile12);

    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "lid: " << lid->getTilesAsString() << std::endl;
    std::cout << "factory1: " << factory1->getLine()->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(0)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(1)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(2)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(3)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(4)->getTilesAsString() << std::endl;
    std::cout << "player1 brokenTiles: " << player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString() << std::endl;
    std::cout << std::endl;

    player1->takeTilesFromCentre(BLACK, centre, 4, lid);

    std::cout << "bag: " << bag->getTilesAsString() << std::endl;
    std::cout << "lid: " << lid->getTilesAsString() << std::endl;
    std::cout << "factory1: " << factory1->getLine()->getTilesAsString() << std::endl;
    std::cout << "centre: " << centre->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(0)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(1)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(2)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(3)->getTilesAsString() << std::endl;
    std::cout << "player1 patternline: " << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(4)->getTilesAsString() << std::endl;
    std::cout << "player1 brokenTiles: " << player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString() << std::endl;
    std::cout << std::endl;
}
