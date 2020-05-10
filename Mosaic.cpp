#include "Mosaic.h"

Mosaic::Mosaic() {
    playerWall = new Wall();
    playerPatternLines = new PatternLines();
}

Mosaic::~Mosaic() {
    delete playerWall;
    delete playerPatternLines;
}

Wall Mosaic::getPlayerWall() {
    return *playerWall;
}

PatternLines Mosaic::getPlayerPatternLines() {
    return *playerPatternLines;
}

void Mosaic::putTileToPatternLine(tilePtr tile, int patternLineIndex) {
    *playerPatternLines->getLine(patternLineIndex)->addTileToBack(tile);
}