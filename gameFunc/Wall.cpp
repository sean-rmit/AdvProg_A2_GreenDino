#include "Wall.h"

Wall::Wall() {
    wallLines = new linePtr[WALL_LINES_NUM];
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        Line *line = new Line(5);
        wallLines[i] = line;
    }
    initialiseFixedColourPattern();
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
    // read in from an fixedWallPatternTiles.txt file
    std::string filename = "fixedWallPatternTiles.txt";
    std::ifstream inputFile(filename);
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        for (int j = 0; j < WALL_LINES_NUM; j++) {
            inputFile >> fixedColourPattern[i][j];
        }
    }
}

linePtr Wall::getLine(int index) {
    return wallLines[index];
}

void Wall::addTile(char tile, int lineIndex, Lid *lid) {
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        if (fixedColourPattern[lineIndex][i] == tile) {
            if (!wallLines[lineIndex]->hasTile(i)) {
                wallLines[lineIndex]->addTileToIndex(tile, i);
            }
            else {
                lid->addTileToBack(tile);
            }
        }
    }
}