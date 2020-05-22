#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::Player(std::string name)
{
    this->playerName = name;
    this->playerScore = 0;
    playerMosaic = new Mosaic();
}

Player::~Player()
{
    delete playerMosaic;
}

std::string Player::getPlayerName()
{
    return playerName;
}

void Player::setPlayerName(std::string name)
{
    playerName = name;
}

mosaicPtr Player::getPlayerMosaic()
{
    return playerMosaic;
}

void Player::setPlayerMosaic(Mosaic *mosaic) {
    playerMosaic = mosaic;
}

int Player::getPlayerScore()
{
    return playerScore;
}

void Player::setPlayerScore(int score)
{
    playerScore = score;
}

void Player::addToPlayerScore(int score)
{
    playerScore += score;
}

bool Player::takeTilesFromFactory(Factory *factory, char colour, Centre *centre, int patternLineIndex, Lid *lid)
{
    bool tilesTaken = false;
    // if patternLine at patternLineIndex is already full, invalid move
    if (playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull())
    {
        std::cout << "Pattern line chosen is full!" << std::endl;
        return false;
    }
    // if factory is empty, invalid move
    else if (factory->getLine()->getTilesNumber() == 0)
    {
        std::cout << "Factory chosen is empty!" << std::endl;
        return false;
    }
    // if patternline chosen has a different colour, invalid move
    else if (playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->getTileColour(0) != NOTILE && playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->getTileColour(0) != colour)
    {
        std::cout << "Pattern line has tiles of colour " << playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->getTileColour(0) << " but you chose the color " << colour << ". Invalid move!" << std::endl;
    }
    // check if wall already has that colour
    for (int i = 0; i < WALL_LINES_NUM; i++) {
        if (playerMosaic->getPlayerWall()->getLine(patternLineIndex)->hasTile(i)) {
            if (playerMosaic->getPlayerWall()->getLine(patternLineIndex)->getTileColour(i) == colour) {
                std::cout << "Wall already has that color on this line!" << std::endl;
                return false;
            }
        }
    }
    // check if factory contains the color specified first, if none then invalid move
    bool hasColour = false;
    for (int i = 0; i < factory->size(); i++)
    {
        // check if the factory has a tile in the current position i
        if (factory->getLine()->hasTile(i))
        {
            //check if the tile is the colour chosen by the player
            if (factory->getLine()->getTileColour(i) == colour)
            {
                hasColour = true;
            }
        }
    }
    if (!hasColour)
    {
        std::cout << "factory chosen does not have the colour " << colour << "!" << std::endl;
        return false;
    }

    for (int i = 0; i < factory->size(); i++)
    {
        // check if the factory has a tile in the current position i
        if (factory->getLine()->hasTile(i))
        {
            //check if the tile is the colour chosen by the player
            if (factory->getLine()->getTileColour(i) == colour)
            {
                //check if the player's pattern line still has space to put tiles
                if (!playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull())
                {
                    playerMosaic->putTileToPatternLine(factory->getLine()->removeTile(i), patternLineIndex);
                }
                //else if the pattern line is full, add it to player's broken tiles
                else
                {
                    // check if the player's broken tiles is full
                    if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull())
                    {
                        playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(factory->getLine()->removeTile(i));
                    }
                    // else if broken tiles if full, add tile to lid
                    else
                    {
                        lid->addTileToBack(factory->getLine()->removeTile(i));
                    }
                }
                tilesTaken = true;
            }
            //else if tile is not the colour chosen by player, move it to the centre
            else
            {
                centre->addTile(factory->getLine()->removeTile(i));
            }
        }
        else
        {
            throw std::logic_error("Factory: Deleting on index with empty tile");
        }
    }
    return tilesTaken;
}

bool Player::takeTilesFromCentre(char colour, Centre *centre, int patternLineIndex, Lid *lid)
{
    bool tilesTaken = false;
    // if patternLine at patternLineIndex is already full, invalid move
    if (playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull())
    {
        std::cout << "Pattern line chosen is full!" << std::endl;
        return false;
    }
    // if patternline chosen has a different colour, invalid move
    else if (playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->getTileColour(0) != NOTILE && playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->getTileColour(0) != colour)
    {
        std::cout << "Pattern line has tiles of colour " << playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->getTileColour(0) << " but you chose the colour " << colour << ". Invalid move!" << std::endl;
        return false;
    }
    // if patternLine at patternLineIndex is already full, invalid move
    if (playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull())
    {
        return false;
    }
    // check if centre contains the color specified first, if none then invalid move
    bool hasColour = false;
    for (int i = 0; i < centre->size(); i++)
    {
        //check if the tile is the colour chosen by the player
        if (centre->getTileColour(i) == colour)
        {
            hasColour = true;
        }
    }
    if (!hasColour)
    {
        std::cout << "centre does not have the colour " << colour << "!" << std::endl;
        return false;
    }

    int centreSize = centre->size();
    for (int i = 0; i < centreSize; i++)
    {
        // find the tiles from the centre according to the colour the player wants
        if (centre->getTileColour(i) == colour)
        {
            //check if the player's pattern line still has space to put tiles
            if (!playerMosaic->getPlayerPatternLines()->getLine(patternLineIndex)->isFull())
            {
                playerMosaic->putTileToPatternLine(centre->removeTile(i), patternLineIndex);
                i--;
                centreSize--;
            }

            //else if the pattern line is full, add it to player's broken tiles
            else
            {
                // check if the player's broken tiles is full
                if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull())
                {
                    playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(centre->removeTile(i));
                    i--;
                    centreSize--;
                }
                // else if broken tiles if full, add tile to lid
                else
                {
                    lid->addTileToBack(centre->removeTile(i));
                    i--;
                    centreSize--;
                }
            }
            tilesTaken = true;
        }
    }
    // only take the Firstplayer token if at least one coloured tile was taken from the centre,
    // else it was a invalid move and player should repeat his turn again
    if (tilesTaken && centre->size() > 0 && centre->getTileColour(0) == FIRSTPLAYER)
    {
        // check if the player's broken tiles is full
        if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull())
        {
            playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(centre->removeTile(0));
        }
        else {
            centre->removeTile(0);
        }
    }
    return tilesTaken;
}

bool Player::takeTilesFromFactoryToBrokenLine(Factory *factory, char colour, Centre *centre, Lid *lid)
{
    bool tilesTaken = false;
    // if factory is empty, invalid move
    if (factory->getLine()->getTilesNumber() == 0)
    {
        std::cout << "Factory chosen is empty!" << std::endl;
        return false;
    }
    // check if factory contains the color specified first, if none then invalid move
    bool hasColour = false;
    for (int i = 0; i < factory->size(); i++)
    {
        // check if the factory has a tile in the current position i
        if (factory->getLine()->hasTile(i))
        {
            //check if the tile is the colour chosen by the player
            if (factory->getLine()->getTileColour(i) == colour)
            {
                hasColour = true;
            }
        }
    }
    if (!hasColour)
    {
        std::cout << "factory chosen does not have the colour " << colour << "!" << std::endl;
        return false;
    }
    for (int i = 0; i < factory->size(); i++)
    {
        // check if the factory has a tile in the current position i
        if (factory->getLine()->hasTile(i))
        {
            //check if the tile is the colour chosen by the player
            if (factory->getLine()->getTileColour(i) == colour)
            {
                // check if the player's broken tiles is full
                if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull())
                {
                    playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(factory->getLine()->removeTile(i));
                }
                // else if broken tiles if full, add tile to lid
                else
                {
                    lid->addTileToBack(factory->getLine()->removeTile(i));
                }
                tilesTaken = true;
            }
            //else if tile is not the colour chosen by player, move it to the centre
            else
            {
                centre->addTile(factory->getLine()->removeTile(i));
            }
        }
        else
        {
            throw std::logic_error("Factory: Deleting on index with empty tile");
        }
    }
    return tilesTaken;
}

bool Player::takeTilesFromCentreToBrokenLine(Centre *centre, char colour, Lid *lid)
{
    bool tilesTaken = false;
    // check if centre contains the color specified first, if none then invalid move
    bool hasColour = false;
    for (int i = 0; i < centre->size(); i++)
    {
        //check if the tile is the colour chosen by the player
        if (centre->getTileColour(i) == colour)
        {
            hasColour = true;
        }
    }
    if (!hasColour)
    {
        std::cout << "centre does not have the colour " << colour << "!" << std::endl;
        return false;
    }

    int centreSize = centre->size();
    for (int i = 0; i < centreSize; i++)
    {
        // find the tiles from the centre according to the colour the player wants
        if (centre->getTileColour(i) == colour)
        {
            // check if the player's broken tiles is full
            if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull())
            {
                playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(centre->removeTile(i));
                i--;
                centreSize--;
            }
            // else if broken tiles if full, add tile to lid
            else
            {
                lid->addTileToBack(centre->removeTile(i));
                i--;
                centreSize--;
            }
            tilesTaken = true;
        }
    }
    // only take the Firstplayer token if at least one coloured tile was taken from the centre,
    // else it was a invalid move and player should repeat his turn again
    if (tilesTaken && centre->size() > 0 && centre->getTileColour(0) == FIRSTPLAYER)
    {
        // check if the player's broken tiles is full
        if (!playerMosaic->getPlayerBrokenTiles()->getLine()->isFull())
        {
            playerMosaic->getPlayerBrokenTiles()->getLine()->addTileToBack(centre->removeTile(0));
        }
    }
    return tilesTaken;
}

void Player::moveTilesFromPatternLineToWall(Lid *lid)
{
    for (int lineIndex = 0; lineIndex < PATTERN_LINES_NUM; lineIndex++)
    {
        if (playerMosaic->getPlayerPatternLines()->getLine(lineIndex)->isFull())
        {
            for (int i = 0; i < playerMosaic->getPlayerPatternLines()->getLine(lineIndex)->size(); i++)
            {
                int points = playerMosaic->getPlayerWall()->addTile(playerMosaic->getPlayerPatternLines()->getLine(lineIndex)->removeTile(i), lineIndex, lid);
                addToPlayerScore(points);
            }
        }
    }
}

void Player::moveTilesFromBrokenTilesToLid(Lid *lid, Centre *centre)
{
    playerMosaic->getPlayerBrokenTiles()->moveAllTilesToLid(lid, centre);
}

void Player::addPenaltyPoints()
{
    addToPlayerScore(playerMosaic->getPlayerBrokenTiles()->getPenaltyPoints());
}

void Player::addEndGameBonusPoints()
{
    addToPlayerScore(playerMosaic->getPlayerWall()->addEndGameBonusPoints());
}
