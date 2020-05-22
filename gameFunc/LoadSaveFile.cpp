#include <fstream>
#include <iostream>
#include "LoadSaveFile.h"

LoadSave::LoadSave()
{
}

LoadSave::~LoadSave()
{
}

LoadSave::LoadSave(LoadSave &other)
{
}

void LoadSave::saveFile(std::string saveFile, Player *player1, Player *player2, Centre *centre, Factories *factories, Bag *bag, Lid *lid, int currentPlayer)
{
    std::ofstream saveToFile(saveFile);

    // Bag
    saveToFile << "BAG=" << bag->getTilesAsString() << std::endl;

    // Lid
    saveToFile << "LID=" << lid->getTilesAsString() << std::endl;

    // Factory Details
    saveToFile << "FACTORY_CENTRE=" << centre->getTilesAsString() << std::endl;
    for (int i = 0; i < 5; i++)
    {
        saveToFile << "FACTORY_" << i << "=" << factories->getFactory(i)->getLine()->getTilesAsString(false) << std::endl;
    }

    // Player 1 Details
    saveToFile << "PLAYER_1_NAME=" << player1->getPlayerName() << std::endl;
    saveToFile << "PLAYER_1_SCORE=" << player1->getPlayerScore() << std::endl;
    for (int i = 0; i < 5; i++)
    {
        saveToFile << "PLAYER_1_PATTERN_LINE" << i << "=" << player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->getTilesAsString(true) << std::endl;
    }
    saveToFile << "PLAYER_1_FLOOR_LINE=" << player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString(true) << std::endl;
    for (int i = 0; i < 5; i++)
    {
        saveToFile << "PLAYER_1_MOSAIC_" << i << "=" << player1->getPlayerMosaic()->getPlayerWall()->getLine(i)->getTilesAsString(true) << std::endl;
    }

    // Player 2 Details
    saveToFile << "PLAYER_2_NAME=" << player2->getPlayerName() << std::endl;
    saveToFile << "PLAYER_2_SCORE=" << player2->getPlayerScore() << std::endl;
    for (int i = 0; i < 5; i++)
    {
        saveToFile << "PLAYER_2_PATTERN_LINE" << i << "=" << player2->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->getTilesAsString(true) << std::endl;
    }
    saveToFile << "PLAYER_2_FLOOR_LINE=" << player2->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->getTilesAsString(true) << std::endl;
    for (int i = 0; i < 5; i++)
    {
        saveToFile << "PLAYER_2_MOSAIC_" << i << "=" << player2->getPlayerMosaic()->getPlayerWall()->getLine(i)->getTilesAsString(true) << std::endl;
    }

    // Current Player
    // odd = player 1 turn, even = player 2 turn
    saveToFile << "CURRENT_PLAYER=" << currentPlayer << std::endl;
}

void LoadSave::loadFile(std::string loadFile, Player *player1, Player *player2, Centre *centre, Factories *factories, Bag *bag, Lid *lid, int &currentPlayer)
{
    bool found = false;
    while (found == false)
    {
        std::ifstream checkFile(loadFile);
        // Check if file exists
        if (!checkFile && (found == false))
        {
            std::cout << "File was not found, please enter another file: " << std::endl;
            std::string filename;
            std::cin >> filename;

            loadFile = filename;
        }
        else
        {
            found = true;
        }
    }

    // Reading file in
    std::ifstream savedFile(loadFile);

    // while loop to read everything
    std::string line;
    while (getline(savedFile, line))
    {
        std::string data;
        int k, dl;

        /* FACTORIES */
        // Finding keyword line
        if (line.find("BAG") != std::string::npos)
        {
            getData(line, data);

            // Splitting data into individual characters
            dl = data.length();
            for (k = 0; k < dl; k++)
            {
                bag->addTileToBack(data[k]);
            }
        }

        if (line.find("LID") != std::string::npos)
        {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++)
            {
                lid->addTileToBack(data[k]);
            }
        }

        if (line.find("FACTORY_CENTRE") != std::string::npos)
        {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++)
            {
                if (data[k] != 'F')
                {
                    char d = data[k];
                    centre->addTile(d);
                }
                else if (data[k] == 'F')
                {
                    centre->addTile(FIRSTPLAYER);
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            std::string factory = "FACTORY_";
            factory += std::to_string(i);
            if (line.find(factory) != std::string::npos)
            {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++)
                {
                    factories->getFactory(i)->getLine()->addTileToBack(data[k]);
                }
            }
        }

        /* PLAYER_1 */
        if (line.find("PLAYER_1_NAME") != std::string::npos)
        {
            getData(line, data);
            player1->setPlayerName(data);
        }

        if (line.find("PLAYER_1_SCORE") != std::string::npos)
        {
            getData(line, data);
            player1->setPlayerScore(stoi(data));
        }

        for (int i = 0; i < 5; i++)
        {
            std::string playerPattern = "PLAYER_1_PATTERN_LINE";
            playerPattern += std::to_string(i);
            if (line.find(playerPattern) != std::string::npos)
            {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++)
                {
                    if (data[k] == NOTILE)
                    {
                        player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->removeTile(i);
                    }
                    else
                    {
                        player1->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->addTileToBack(data[k]);
                    }
                }
            }
        }

        if (line.find("PLAYER_1_FLOOR_LINE") != std::string::npos)
        {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++)
            {
                if (data[k] != NOTILE)
                {
                    player1->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->addTileToBack(data[k]);
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            std::string playerMosaic = "PLAYER_1_MOSAIC_";
            playerMosaic += std::to_string(i);
            if (line.find(playerMosaic) != std::string::npos)
            {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++)
                {
                    player1->getPlayerMosaic()->getPlayerWall()->getLine(i)->addTileToIndex(data[k], k);
                    if (data[k] == NOTILE || data[k] == '.')
                    {
                        player1->getPlayerMosaic()->getPlayerWall()->getLine(i)->removeTile(k);
                    }
                }
            }
        }

        /* PLAYER_2 */
        if (line.find("PLAYER_2_NAME") != std::string::npos)
        {
            getData(line, data);
            player2->setPlayerName(data);
        }

        if (line.find("PLAYER_2_SCORE") != std::string::npos)
        {
            getData(line, data);
            player2->setPlayerScore(stoi(data));
        }

        for (int i = 0; i < 5; i++)
        {
            std::string playerPattern = "PLAYER_2_PATTERN_LINE";
            playerPattern += std::to_string(i);
            if (line.find(playerPattern) != std::string::npos)
            {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++)
                {
                    if (data[k] == NOTILE)
                    {
                        player2->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->removeTile(i);
                    }
                    else
                    {
                        player2->getPlayerMosaic()->getPlayerPatternLines()->getLine(i)->addTileToBack(data[k]);
                    }
                }
            }
        }

        if (line.find("PLAYER_2_FLOOR_LINE") != std::string::npos)
        {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++)
            {
                if (data[k] != NOTILE)
                {
                    player2->getPlayerMosaic()->getPlayerBrokenTiles()->getLine()->addTileToBack(data[k]);
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            std::string playerMosaic = "PLAYER_2_MOSAIC_";
            playerMosaic += std::to_string(i);
            if (line.find(playerMosaic) != std::string::npos)
            {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++)
                {
                    player2->getPlayerMosaic()->getPlayerWall()->getLine(i)->addTileToIndex(data[k], k);
                    if (data[k] == NOTILE || data[k] == '.')
                    {
                        player2->getPlayerMosaic()->getPlayerWall()->getLine(i)->removeTile(k);
                    }
                }
            }
        }

        /* CURRENT PLAYER */
        if (line.find("CURRENT_PLAYER") != std::string::npos)
        {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++)
            {
                std::string s = "";
                s.push_back(data[k]);
                currentPlayer = std::stoi(s);
            }
        }
    }
}

// Getting the data after the '='
void LoadSave::getData(std::string line, std::string &data)
{
    int ll;
    char e = '=';
    size_t found = line.find(e);
    int el = 0;
    if (found != std::string::npos)
    {
        el = found + 1;
    }
    // Getting the line length
    ll = line.length();

    data = line.substr(el, ll - el);
}
