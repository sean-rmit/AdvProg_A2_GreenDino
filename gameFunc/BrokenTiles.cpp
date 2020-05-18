#include "BrokenTiles.h"


BrokenTiles::BrokenTiles() {
    brokenTiles = new Line(MAX_BROKEN_TILES);
}

BrokenTiles::~BrokenTiles() {
    delete brokenTiles;
}

linePtr BrokenTiles::getLine() {
    return brokenTiles;
}

int BrokenTiles::getPenaltyPoints() {
    if (brokenTiles->getTilesNumber() == 0) {
        return NO_PENALTY;
    }
    else if (brokenTiles->getTilesNumber() == 1) {
        return ONE_TILE_PENALTY;
    }
    else if (brokenTiles->getTilesNumber() == 2) {
        return TWO_TILE_PENALTY;
    }
    else if (brokenTiles->getTilesNumber() == 3) {
        return THREE_TILE_PENALTY;
    }
    else if (brokenTiles->getTilesNumber() == 4) {
        return FOUR_TILE_PENALTY;
    }
    else if (brokenTiles->getTilesNumber() == 5) {
        return FIVE_TILE_PENALTY;
    }
    else if (brokenTiles->getTilesNumber() == 6) {
        return SIX_TILE_PENALTY;
    }
    else {
        return SEVEN_TILE_PENALTY;
    }
}

void BrokenTiles::moveAllTilesToLid(Lid *lid, Centre *centre) {
    for (int i = 0; i < brokenTiles->size(); i++) {
        if (brokenTiles->hasTile(i)) {
            if (brokenTiles->getTileColour(i) == FIRSTPLAYER) {
                centre->addTile(brokenTiles->removeTile(i));
            }
            else {
                lid->addTileToBack(brokenTiles->removeTile(i));
            }
        }
    }
}