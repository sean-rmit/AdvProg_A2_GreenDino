#include <iostream>
#include <sstream>
#include <cstring>

#include "utils.h"

void printString(std::string s, int num) {
    for (int i = 0; i < num; i++) {
        std::cout << s;
    }
}

void printFactories(Centre *centre, Factories *factories) {
    std::cout << "Factories:" << std::endl;
    std::cout << "0: " << centre->getTilesAsString()<< std::endl;
    for (int i = 0; i < FACTORIES_NUM; i++) {
        std::cout << i+1 <<": " << factories->getFactory(i)->getLine()->getTilesAsString(false) << std::endl;
    }
}

void printPlayerMosaic(Player *player) {
    std::cout << "Mosaic for " << player->getPlayerName() << " :" << std::endl;
    for (int i = 0; i < PATTERN_LINES_NUM; i++) {
        std::cout << i+1 <<": " << player->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->getTilesAsString(true);
        std::cout << " || ";
        std::cout << player->getPlayerMosaic()->getPlayerWall()->getLine(i)->getTilesAsString(true) << std::endl;;
    }
    std::cout <<"broken: " << player->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString(true) << std::endl;
}





