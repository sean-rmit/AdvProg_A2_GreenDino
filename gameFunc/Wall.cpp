#include "Wall.h"

Wall::Wall() {
    wallLines = new linePtr[WALL_LINES_NUM];
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        Line *line = new Line(5);
        wallLines[i] = line;
    }
    fixedColourPattern = new linePtr[WALL_LINES_NUM];
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        Line *line = new Line(5);
        fixedColourPattern[i] = line;
    }
}

Wall::~Wall() {
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        delete wallLines[i];
    }
    delete wallLines;
}

Wall::Wall(Wall& other) {

}

void Wall::initialiseFixedColourPattern() {
    // read in from an external file

}

linePtr Wall::getLine(int index) {
    return wallLines[index];
}

void Wall::receiveTileFromPatternLine(tilePtr tile, int lineIndex, Lid *lid) {
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        if (fixedColourPattern[lineIndex]->getTileColour(i) == *tile) {
            wallLines[lineIndex]->addTileToIndex(tile, i);
        }
        else {
            lid->addTileToBack(tile);
        }
    }
}