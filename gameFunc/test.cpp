#include <iostream>

#include "Tiles.h"
#include "BoxLid.h"

int main(int argc, char** argv) {
    tilePtr tile = new char(YELLOW);
    Lid *lid = new Lid();
    lid->addTileToBack(tile);
    std::cout << lid->getTilesAsString() << std::endl;
}