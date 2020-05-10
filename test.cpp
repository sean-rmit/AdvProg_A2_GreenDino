#include <iostream>

#include "Tiles.h"
#include "BoxLid.h"
#include "Line.h"

int main(int argc, char** argv) {
    tilePtr tile1 = new char(YELLOW);
    tilePtr tile2 = new char(RED);
    tilePtr tile3 = new char(DARKBLUE);
    tilePtr tile4 = new char(LIGHTBLUE);
    tilePtr tile5 = new char(BLACK);
    Line *line1 = new Line(5);
    Line *line2 = new Line(5);
    line1->addTileToBack(tile1);
    line1->addTileToBack(tile2);
    line1->addTileToBack(tile3);
    line1->addTileToBack(tile4);
    line1->addTileToBack(tile5);
    std::cout << "line1: " <<line1->getTilesAsString() << std::endl;
    std::cout << "line2: " <<line2->getTilesAsString() << std::endl;

    for (int i = 0; i < line1->size(); i++) {
        if (line1->hasTile(i)) {
            line2->addTileToBack(line1->removeTile(i));
        }
    }
    std::cout << "line1: " <<line1->getTilesAsString() << std::endl;
    std::cout << "line2: " <<line2->getTilesAsString() << std::endl;
}