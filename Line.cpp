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
    line[numTiles] = tile;
    numTiles++;
}

void Line::addTileToIndex(tilePtr tile, int index) {
    line[index] = tile;
    numTiles++;
}

char Line::getTileColour(int index) {
    return *line[index];
}

bool Line::hasTile(int index) {
    if (line[index] != nullptr) {
        return true;
    } else {
        return false;
    }
}

tilePtr Line::removeTile(int index) {
    if (line[index] != nullptr) {
        tilePtr tile = line[index];
        line[index] = nullptr;
        numTiles--;
        return tile;
    } else {
        throw std::logic_error("Line: Deleting on index with empty tile");
    }
}

std::string Line::getTilesAsString() {
    std::string allTilesAsString;
    for (int i = 0; i < array_length; i++) {
        if (line[i] != nullptr) {
            allTilesAsString += line[i];
        }
        else {
            allTilesAsString += NOTILE;
        }
    }
    return allTilesAsString;
}