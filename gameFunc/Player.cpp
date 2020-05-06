#include "Player.h"

Player::Player() {
    playerMosaic = new Mosaic();
}

Player::~Player() {
    delete playerMosaic;
}

Mosaic Player::getPlayerMosaic() {
    return *playerMosaic;
}

void Player::takeTilesFromFactory(Factory *factory, char colour, Centre *centre, int patternLineIndex) {
    factory->playerTakesTiles(colour, this, centre, patternLineIndex);
}

void Player::putTileToPatternLine(tilePtr tile, int patternLineIndex) {
    playerMosaic->putTileToPatternLine(tile, patternLineIndex);
}

