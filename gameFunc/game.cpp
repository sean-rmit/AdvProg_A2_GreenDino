#include "game.h"

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <cstring>

Game::Game(std::string playerName1, std::string playerName2, int seed) {
    factories = new Factories();
    centre = new Centre;
    player1 = new Player(playerName1);
    player2 = new Player(playerName2);
    lid = new Lid();
    bag = new Bag();
    bag->fillBagWithTiles(seed);
}
Game::~Game() {
    delete factories;
    delete centre;
    delete player1;
    delete player2;
    delete lid;
    delete bag;
}

Game::Game(Game& other) {

}

void Game::finaliseRound() {
    player1->moveTilesFromPatternLineToWall(lid);
    player1->moveTilesFromBrokenTilesToLid(lid, centre);
    player2->moveTilesFromPatternLineToWall(lid);
    player2->moveTilesFromBrokenTilesToLid(lid, centre);
}

void Game::prepareNewRound() {
    // refill bag with tiles from lid if insufficient tiles
    if (bag->size() < 25) {
        int lidSize = lid->size();
        for (int i = 0; i < lidSize; i++) {
            bag->addTileToBack(lid->removeTileFront());
        }
    }
    for (int i = 0; i < FACTORIES_NUM; i++) {
        factories->getFactory(i)->loadFactory(bag);
    }
}

bool Game::playerMakesMove(int playerNum, std::string move) {
    int factoryNum;
    char tileColour;
    int patternlineIndex;

    std::string tokens[4];
    std::istringstream ssin(move);
    int i = 0;
    while (ssin.good() && i < 4){
        ssin >> tokens[i];
        ++i;
    }
    try {
        factoryNum = std::stoi(tokens[1]);
        std::string tileColourAsString = tokens[2];
        strcpy(&tileColour, &tileColourAsString[0]);
        patternlineIndex = std::stoi(tokens[3]);
    }
    catch (std::invalid_argument const &e) {
        std::cout << "Invalid input" << std::endl;
        return false;
    }
    catch (std::out_of_range const &e) {
        std::cout << "Integer overflow: std::out_of_range thrown" << std::endl;
        return false;
    }

    // validate first token "turn"
    if (tokens[0] != "turn") {
        std::cout << "Invalid input" << std::endl;
        std::cout << "DEBUG: Its not turn!" << std::endl;
        return false;
    }
    
    // validate factoryNum
    // FACTORIES_NUM+1 because centre is included
    if (factoryNum < 0 || factoryNum >= FACTORIES_NUM+1) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "DEBUG: factoryNum wrong!" << std::endl;
        return false;
    }

    //validate tileColour
    if (tileColour != RED && tileColour != YELLOW && tileColour != DARKBLUE && tileColour != LIGHTBLUE && tileColour != BLACK) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "DEBUG: tileColour wrong!" << std::endl;
        return false;
    }

    //validate patternlineIndex
    if (patternlineIndex < 0 || patternlineIndex >= PATTERN_LINES_NUM) {
        std::cout << "Invalid input" << std::endl;
        std::cout << "DEBUG: patternlineIndex wrong!" << std::endl;
        return false;
    }

    // player move
    if (factoryNum == 0) {
        if (playerNum == 1) {
            player1->takeTilesFromCentre(tileColour, centre, patternlineIndex, lid);
        }
        else if (playerNum == 2) {
            player2->takeTilesFromCentre(tileColour, centre, patternlineIndex, lid);
        }
        else {
            std::cout << "Invalid input" << std::endl;
            std::cout << "DEBUG: playerNum wrong!" << std::endl;
            return false;
        }
    }
    else {
        if (playerNum == 1) {
            player1->takeTilesFromFactory(factories->getFactory(factoryNum-1), tileColour, centre, patternlineIndex, lid);
            return true;
        }
        else if (playerNum == 2) {
            player2->takeTilesFromFactory(factories->getFactory(factoryNum-1), tileColour, centre, patternlineIndex, lid);
            return true;
        }
        else {
            std::cout << "Invalid input" << std::endl;
            std::cout << "DEBUG: playerNum wrong!" << std::endl;
            return false;
        }
    }
    return false;
}

bool Game::hasRoundEnded() {
    bool isEverythingEmpty = true;
    // check if centre is empty
    if (centre->size() != 0) {
        isEverythingEmpty = false;
    }
    // check if each factory is empty
    for (int i = 0; i < FACTORIES_NUM; i++) {
        if (factories->getFactory(i)->getLine()->getTilesNumber() != 0) {
            isEverythingEmpty = false;
        }
    }
    return isEverythingEmpty = true;
}

bool Game::hasGameEnded() {
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        if (player1->getPlayerMosaic()->getPlayerWall()->getLine(i)->isFull()){
            return true;
        }
        if (player2->getPlayerMosaic()->getPlayerWall()->getLine(i)->isFull()){
            return true;
        }
    }
    return false;
}

void Game::finaliseGame() {

}

// getters and setters
factoriesPtr Game::getFactories() {
    return this->factories;
}

centrePtr Game::getCentre() {
    return this->centre;
}

playerPtr Game::getPlayer1() {
    return this->player1;
}

playerPtr Game::getPlayer2() {
    return this->player2;
}

lidPtr Game::getLid() {
    return this->lid;
}

bagPtr Game::getBag() {
    return this->bag;
}