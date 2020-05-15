#include "Player.h"

#include <iostream>

Player::Player(std::string name) {
    this->playerName = name;
    this->playerScore = 0;
    playerMosaic = new Mosaic();
}

Player::~Player() {
    delete playerMosaic;
}

std::string Player::getPlayerName() {
    return playerName;
}

mosaicPtr Player::getPlayerMosaic() {
    return playerMosaic;
}

void Player::addToPlayerScore(int score) {
    playerScore += score;
}

void Player::takeTilesFromFactory(Factory *factory, char colour, Centre *centre, int patternLineIndex, Lid *lid) {
    for (int i = 0; i < factory->size(); i++) {
        // check if the factory has a tile in the current position i
        if (factory->getLine()->hasTile(i)) {
            //check if the tile is the colour chosen by the player
            if (factory->getLine()->getTileColour(i) == colour) {
                //check if the player's pattern line still has space to put tiles
                if (!playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull()) {
                    playerMosaic->putTileToPatternLine(factory->getLine()->removeTile(i), patternLineIndex);
                }
                //else if the pattern line is full, add it to player's broken tiles
                else {
                    // check if the player's broken tiles is full
                    if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull()) {
                        playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(factory->getLine()->removeTile(i));
                    }
                    // else if broken tiles if full, add tile to lid
                    else {
                        lid->addTileToBack(factory->getLine()->removeTile(i));
                    }
                }
            }
            //else if tile is not the colour chosen by player, move it to the centre
            else {
                centre->addTile(factory->getLine()->removeTile(i));
            }
        }
        else {
            throw std::logic_error("Factory: Deleting on index with empty tile");
        }
    }
}

void Player::takeTilesFromCentre(char colour, Centre *centre, int patternLineIndex, Lid *lid) {
    // int centreSize = centre->size();
    for (int i = 0; i < centre->size(); i++) {
        // find the tiles from the centre according to the colour the player wants including the firstplayer token
        if (centre->getTileColour(i) == colour || centre->getTileColour(i) == FIRSTPLAYER) {
            //check if the player's pattern line still has space to put tiles and make sure not to add
            //firstplayer token into patternline
            if (!playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull() && centre->getTileColour(i) != FIRSTPLAYER) {
                playerMosaic->putTileToPatternLine(centre->removeTile(i), patternLineIndex);
                i--;
            }
            //else if the pattern line is full or the tile is the firstplayer token, 
            //add it to player's broken tiles
            else {
                // check if the player's broken tiles is full
                if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull()) {
                    playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(centre->removeTile(i));
                    i--;
                }
                // else if broken tiles if full, add tile to lid
                else {
                    lid->addTileToBack(centre->removeTile(i));
                    i--;
                }
            }
        }
    }
}

void Player::moveTilesFromPatternLineToWall(Lid *lid) {
    for (int lineIndex = 0; lineIndex < PATTERN_LINES_NUM; lineIndex++) {
        if (playerMosaic->getPlayerPatternLines()->getLine(lineIndex)->isFull()) {
            for (int i = 0; i < playerMosaic->getPlayerPatternLines()->getLine(lineIndex)->size(); i++) {
                playerMosaic->getPlayerWall()->addTile(playerMosaic->getPlayerPatternLines()->getLine(lineIndex)->removeTile(i), lineIndex, lid);
            }
        }
    }
}

void Player::moveTilesFromBrokenTilesToLid(Lid *lid, Centre *centre) {
    playerMosaic->getPlayerBrokenTiles()->moveAllTilesToLid(lid, centre);
}

