#include "game.h"

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <cstring>

Game::Game(std::string playerName1, std::string playerName2, int seed)
{
    factories = new Factories();
    centre = new Centre;
    player1 = new Player(playerName1);
    player2 = new Player(playerName2);
    lid = new Lid();
    bag = new Bag();
}
Game::~Game()
{
    delete factories;
    delete centre;
    delete player1;
    delete player2;
    delete lid;
    delete bag;
}

Game::Game(Game &other)
{
}

void Game::finaliseRound()
{
    player1->addPenaltyPoints();
    player2->addPenaltyPoints();
    player1->moveTilesFromPatternLineToWall(lid);
    player1->moveTilesFromBrokenTilesToLid(lid, centre);
    player2->moveTilesFromPatternLineToWall(lid);
    player2->moveTilesFromBrokenTilesToLid(lid, centre);
    if (centre->size() == 0) {
        centre->addTile(FIRSTPLAYER);
    }
}

void Game::prepareNewRound()
{
    // refill bag with tiles from lid if insufficient tiles
    if (bag->size() < 25)
    {
        int lidSize = lid->size();
        for (int i = 0; i < lidSize; i++)
        {
            bag->addTileToBack(lid->removeTileFront());
        }
    }
    for (int i = 0; i < FACTORIES_NUM; i++)
    {
        factories->getFactory(i)->loadFactory(bag);
    }
}

bool Game::playerMakesMove(int playerNum)
{
    int factoryNum;
    char tileColour;
    int patternlineIndex;
    std::string factoryNumAsString;
    std::cin >> factoryNumAsString;
    std::cin >> tileColour;
    std::string patternlineIndexAsString;
    std::cin >> patternlineIndexAsString;

    try
    {
        factoryNum = std::stoi(factoryNumAsString);
        patternlineIndex = std::stoi(patternlineIndexAsString);
    }
    catch (std::invalid_argument const &e)
    {
        std::cout << "Invalid input" << std::endl;
        return false;
    }
    catch (std::out_of_range const &e)
    {
        std::cout << "Integer overflow: std::out_of_range thrown" << std::endl;
        return false;
    }

    // validate factoryNum
    // FACTORIES_NUM + 1 because centre is included
    if (factoryNum < 0 || factoryNum >= FACTORIES_NUM + 1)
    {
        std::cout << "Invalid factoryNum!" << std::endl;
        return false;
    }

    //validate tileColour
    if (tileColour != RED && tileColour != YELLOW && tileColour != DARKBLUE && tileColour != LIGHTBLUE && tileColour != BLACK)
    {
        std::cout << "Invalid tileColour!" << std::endl;
        return false;
    }

    // validate patternlineIndex
    // PATTERN_LINES_NUM + 1 because broken line is included
    if (patternlineIndex < 1 || patternlineIndex > PATTERN_LINES_NUM + 1)
    {
        std::cout << "Invalid patternlineIndex!" << std::endl;
        return false;
    }
    bool validMove = false;
    // player move
    if (factoryNum == 0)
    {
        // patternlineIndex = 6 is broken line
        if (patternlineIndex == 6)
        {
            if (playerNum == 1)
            {
                validMove = player1->takeTilesFromCentreToBrokenLine(centre, tileColour, lid);
            }
            else if (playerNum == 2)
            {
                validMove = player2->takeTilesFromCentreToBrokenLine(centre, tileColour, lid);
            }
        }
        else
        {
            if (playerNum == 1)
            {
                validMove = player1->takeTilesFromCentre(tileColour, centre, patternlineIndex - 1, lid);
            }
            else if (playerNum == 2)
            {
                validMove = player2->takeTilesFromCentre(tileColour, centre, patternlineIndex - 1, lid);
            }
        }
        return validMove;
    }
    else
    {
        // patternlineIndex = 6 is broken line
        if (patternlineIndex == 6)
        {
            if (playerNum == 1)
            {
                validMove = player1->takeTilesFromFactoryToBrokenLine(factories->getFactory(factoryNum - 1), tileColour, centre, lid);
            }
            else if (playerNum == 2)
            {
                validMove = player2->takeTilesFromFactoryToBrokenLine(factories->getFactory(factoryNum - 1), tileColour, centre, lid);
            }
        }
        else
        {
            if (playerNum == 1)
            {
                validMove = player1->takeTilesFromFactory(factories->getFactory(factoryNum - 1), tileColour, centre, patternlineIndex - 1, lid);
            }
            else if (playerNum == 2)
            {
                validMove = player2->takeTilesFromFactory(factories->getFactory(factoryNum - 1), tileColour, centre, patternlineIndex - 1, lid);
            }
        }
        return validMove;
    }
    std::cout << "DEBUG: end of playerMakesMove() function reached, this shouldn't happen" << std::endl;
    return false;
}

bool Game::hasRoundEnded()
{
    bool isEverythingEmpty = true;
    // check if centre is empty
    if (centre->size() != 0)
    {
        isEverythingEmpty = false;
    }
    // check if each factory is empty
    for (int i = 0; i < FACTORIES_NUM; i++)
    {
        if (factories->getFactory(i)->getLine()->getTilesNumber() != 0)
        {
            isEverythingEmpty = false;
        }
    }
    return isEverythingEmpty;
}

bool Game::hasGameEnded()
{
    for (int i = 0; i < WALL_LINES_NUM; i++)
    {
        if (player1->getPlayerMosaic()->getPlayerWall()->getLine(i)->isFull())
        {
            return true;
        }
        if (player2->getPlayerMosaic()->getPlayerWall()->getLine(i)->isFull())
        {
            return true;
        }
    }
    return false;
}

void Game::finaliseGame()
{
    player1->addEndGameBonusPoints();
    player2->addEndGameBonusPoints();
    std::cout << "Game has ended: " << std::endl;
    std::cout << player1->getPlayerName() << "'s score: " << player1->getPlayerScore() << std::endl;
    std::cout << player2->getPlayerName() << "'s score: " << player2->getPlayerScore() << std::endl;

    if (player1->getPlayerScore() > player2->getPlayerScore())
    {
        std::cout << player1->getPlayerName() << " wins the game!" << std::endl;
    }
    else if (player1->getPlayerScore() < player2->getPlayerScore())
    {
        std::cout << player2->getPlayerName() << " wins the game!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }
}

void Game::finaliseLoadedGame()
{
    std::cout << "Game has ended: " << std::endl;
    std::cout << player1->getPlayerName() << "'s score: " << player1->getPlayerScore() << std::endl;
    std::cout << player2->getPlayerName() << "'s score: " << player2->getPlayerScore() << std::endl;

    if (player1->getPlayerScore() > player2->getPlayerScore())
    {
        std::cout << player1->getPlayerName() << " wins the game!" << std::endl;
    }
    else if (player1->getPlayerScore() < player2->getPlayerScore())
    {
        std::cout << player2->getPlayerName() << " wins the game!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }
}

// getters and setters
factoriesPtr Game::getFactories()
{
    return this->factories;
}

centrePtr Game::getCentre()
{
    return this->centre;
}

playerPtr Game::getPlayer1()
{
    return this->player1;
}

playerPtr Game::getPlayer2()
{
    return this->player2;
}

lidPtr Game::getLid()
{
    return this->lid;
}

bagPtr Game::getBag()
{
    return this->bag;
}