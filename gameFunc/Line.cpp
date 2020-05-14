#include "Line.h"

#include <exception>
#include <iostream>

Line::Line() {
    this->array_length = 0;
    numTiles = 0;
}

Line::Line(int length) {
    this->numTiles = 0;
    this->array_length = length;
    line = new tilePtr[array_length];
    for (int i = 0; i < length; i++) {
        line[i] = nullptr;
    }
}

Line::~Line() {
    delete line;
}

int Line::size() {
    return array_length;
}

int Line::getTilesNumber() {
    return numTiles;
}

void Line::addTileToBack(tilePtr tile) {
    if (numTiles < array_length) {
        line[numTiles] = tile;
        numTiles++;
    }
    else {
        std::cout << "ERROR: exceeded line size" << std::endl;
    }
}

void Line::addTileToIndex(tilePtr tile, int index) {
    if (index >= 0 && index < array_length) {
        line[index] = tile;
        numTiles++;
    }
    else {
        std::cout << "ERROR: index out of bounds of line range" << std::endl;
    }
}

char Line::getTileColour(int index) {
    if (index >= 0 && index < array_length) {
        return *line[index];
    }
    else {
        throw std::logic_error("ERROR: index out of bounds of line range");
    }
}

bool Line::hasTile(int index) {
    if (index >= 0 && index < array_length) {
        if (line[index] != nullptr) {
            return true;
        } else {
            return false;
        }
    }
    else {
        throw std::logic_error("ERROR: index out of bounds of line range");
    }
}

bool Line::isFull() {
    if (numTiles == array_length) {
        return true;
    }
    else {
        return false;
    }
}

tilePtr Line::removeTile(int index) {
    if (index >= 0 && index < array_length) {
        if (line[index] != nullptr) {
            tilePtr tile = line[index];
            line[index] = nullptr;
            numTiles--;
            return tile;
        } else {
            throw std::logic_error("ERROR: index out of bounds of line range");
        }
    }
    else {
        throw std::logic_error("Line: Deleting on index with empty tile");
    }
}

std::string Line::getTilesAsString(bool hasNoTile) {
    std::string allTilesAsString;
    for (int i = 0; i < array_length; i++) {
        if (line[i] != nullptr) {
            allTilesAsString += line[i];
        }
        else {
            if (hasNoTile) {
                allTilesAsString += NOTILE;
            }
        }
    }
    return allTilesAsString;
}