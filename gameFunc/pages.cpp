#include <iostream>
#include <string>

#include "pages.h"

void creditsPage()
{
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH / 2 - 3); //3 = half of letters in CREDITS
    std::cout << "CREDITS";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    //line 4
    printString(" ", PAGEWIDTH / 2 - 4);
    std::cout << "Design by";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH / 2 - 4);
    std::cout << "Sean Tan";
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH / 2 - 5);
    std::cout << "Aaron Soa";
    std::cout << std::endl;

    //line 7
    printString(" ", PAGEWIDTH / 2 - 5);
    std::cout << "Amy Nguyen";
    std::cout << std::endl;
    std::cout << std::endl;

    //toolbar
    std::cout << "< enter B to go back to Main menu" << std::endl;

    bool creditsPageRunning = true;
    while (creditsPageRunning)
    {
        char input;
        std::cin >> input;
        if (input == 'B' || input == 'b')
        {
            creditsPageRunning = false;
        }
        else
        {
            std::cout << "No such available input! Please try again." << std::endl;
        }
    }
}

void mainMenuPage(int seed)
{
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH / 2 - 2); //3 = half of letters in AZUL
    std::cout << "AZUL";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    //line 4
    printString(" ", PAGEWIDTH / 2 - 10);
    std::cout << "New Game < enter 'N'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH / 2 - 10);
    std::cout << "Load Game < enter 'L'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH / 2 - 10);
    std::cout << "Credits < enter 'C'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH / 2 - 10);
    std::cout << "Quit Game < enter 'Q'";
    std::cout << std::endl;
    std::cout << std::endl;

    bool mainMenuRunning = true;
    while (mainMenuRunning)
    {
        char input;
        std::cin >> input;
        if (input == 'C' || input == 'c')
        {
            creditsPage();
        }
        else if (input == 'Q' || input == 'q')
        {
            mainMenuRunning = false;
        }
        else if (input == 'N' || input == 'n')
        {
            newGamePage(seed);
            mainMenuRunning = false;
        }
        else if (input == 'L' || input == 'l')
        {
            loadGamePage();
        }
        else
        {
            std::cout << "No such available input! Please try again." << std::endl;
        }
    }
}

void newGamePage(int seed)
{
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH / 2 - 4); //4 = half of letters in NEW GAME
    std::cout << "NEW GAME";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    // take in player names
    std::cout << "Enter a name for player 1:" << std::endl;
    std::string playerName1;
    std::cin >> playerName1;
    std::cout << "Enter a name for player 2:" << std::endl;
    std::string playerName2;
    std::cin >> playerName2;
    std::cout << std::endl;

    // game initialised
    Game *game = new Game(playerName1, playerName2, seed);
    bool gameOngoing = true;
    std::cout << "Let’s Play!" << std::endl;
    std::cout << std::endl;
    int roundCounter = 1; // odd = player 1 turn, even = player 2 turn
    while (gameOngoing)
    {
        // initialise the round (aka load factories with tiles)
        std::cout << "=== Start Round ===" << std::endl;
        game->prepareNewRound();

        std::cout << "TURN FOR PLAYER: ";
        if (roundCounter % 2 == 1)
        {
            std::cout << playerName1 << std::endl;
        }
        else
        {
            std::cout << playerName2 << std::endl;
        }
        printFactories(game->getCentre(), game->getFactories());
        std::cout << std::endl;
        if (roundCounter % 2 == 1)
        {
            printPlayerMosaic(game->getPlayer1());
        }
        else
        {
            printPlayerMosaic(game->getPlayer2());
        }
        bool validMove = false;
        // loop until valid move is made
        while (!validMove)
        {
            std::string playerMove;
            std::cin >> playerMove;

            // TODO: save game function
            if (playerMove == "save")
            {
                validMove = true;
                gameOngoing = false;
                std::cout << "Enter the filename (.txt) you wish to save to:\n";
                std::string filename;
                std::cin >> filename;
                LoadSave *save = new LoadSave();
                save->saveFile(filename, playerName1, playerName2);
                
            }
            else if (playerMove == "quit")
            {
                validMove = true;
                gameOngoing = false;
            }
            else
            {
                if (roundCounter % 2 == 1)
                {
                    validMove = game->playerMakesMove(1, playerMove);
                }
                else
                {
                    validMove = game->playerMakesMove(2, playerMove);
                }
                std::cout << "Turn Successful." << std::endl;
            }
        }

        roundCounter++;
        // check if the round has ended (aka factories and centre are all empty)
        if (game->hasRoundEnded())
        {
            game->finaliseRound();
        }
        if (game->hasGameEnded())
        {
            gameOngoing = false;
        }
    }
    std::cout << "=== GAME OVER ===" << std::endl;
}

void loadGamePage()
{
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH / 2 - 4);
    std::cout << "LOAD GAME";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    // User input for filename
    std::cout << "Enter the filename you wish to load the game from:" << std::endl;
    std::string filename;
    std::cin >> filename;

    LoadSave *load = new LoadSave();
    load->loadFile(filename);
}