#include "Mosaic.h"

Mosaic::Mosaic() {
    playerWall = new Wall();
    playerPatternLines = new PatternLines();
    playerBrokenTiles = new BrokenTiles();
}

Mosaic::~Mosaic() {
    delete playerWall;
    delete playerPatternLines;
}

wallPtr Mosaic::getPlayerWall() {
    return playerWall;
}

patternLinesPtr Mosaic::getPlayerPatternLines() {
    return playerPatternLines;
}

brokenTilesPtr Mosaic::getPlayerBrokenTiles() {
    return playerBrokenTiles;
}

void Mosaic::putTileToPatternLine(char tile, int patternLineIndex) {
    playerPatternLines->getLine(patternLineIndex)->addTileToBack(tile);
}

void Mosaic::putTileToBrokenTiles(char tile) {
    playerBrokenTiles->getLine()->addTileToBack(tile);
}