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

    std::cout << "New Game < enter 'N'" << std::endl;
    std::cout << "Load Game < enter 'L'" << std::endl;
    std::cout << "Quit Game < enter 'Q'" << std::endl;
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
        std::cout << "> ";
        char input;
        std::cin >> input;
        if (input == 'C' || input == 'c')
        {
            creditsPage();
        }
        else if (std::cin.eof() || input == 'Q' || input == 'q')
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
    std::cout << "> ";
    std::string playerName1;
    std::cin >> playerName1;
    std::cout << "Enter a name for player 2:" << std::endl;
    std::cout << "> ";
    std::string playerName2;
    std::cin >> playerName2;
    std::cout << std::endl;

    // game initialised
    Game *game = new Game(playerName1, playerName2, seed);
    bool gameOngoing = true;
    std::cout << "Let’s Play!" << std::endl;
    std::cout << "== INSTRUCTIONS ==" << std::endl;
    std::cout << "Make a move: turn <factory index> <tile colour> <mosaic line index>" << std::endl;
    std::cout << "Save the game: save" << std::endl;
    std::cout << "Quit the game: quit" << std::endl;
    std::cout << std::endl;
    int roundCounter = 1; // odd = player 1 turn, even = player 2 turn
    while (gameOngoing)
    {
        bool roundOngoing = true;
        // initialise the round (aka load factories with tiles)
        std::cout << "=== Start Round ===" << std::endl;
        printPlayerPoints(game->getPlayer1(), game->getPlayer2());
        game->prepareNewRound();
        while (roundOngoing)
        {
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
                if (roundCounter % 2 == 1)
                {
                    std::cout << playerName1;
                }
                else
                {
                    std::cout << playerName2;
                }
                std::cout << "'s turn to make a move:" << std::endl;
                std::cout << "> ";
                std::string playerMove;
                std::cin >> playerMove;

                //if Ctrl+D is entered terminate the while loops
                if (std::cin.eof())
                {
                    validMove = true;
                    roundOngoing = false;
                    gameOngoing = false;
                    game->finaliseGame();
                }

                // TODO: save game function
                if (playerMove == "save")
                {
                    // validMove = true;
                    // gameOngoing = false;
                    // std::cout << "Enter the filename (.txt) you wish to save to:\n";
                    // std::string filename;
                    // std::cin >> filename;
                    // LoadSave *save = new LoadSave();
                    // save->saveFile(filename, playerName1, playerName2);
                    roundOngoing = false;
                    gameOngoing = false;
                }
                else if (playerMove == "quit")
                {
                    validMove = true;
                    roundOngoing = false;
                    gameOngoing = false;
                    game->finaliseGame();
                }
                else if (playerMove == "turn")
                {
                    if (roundCounter % 2 == 1)
                    {
                        validMove = game->playerMakesMove(1);
                    }
                    else
                    {
                        validMove = game->playerMakesMove(2);
                    }
                    if (validMove)
                    {
                        std::cout << "Turn Successful." << std::endl;
                    }
                }
                if (!validMove)
                {
                    std::cout << "Invalid Move." << std::endl;
                    std::cout << "To make a move:" << std::endl;
                    std::cout << "turn <factory index> <tile colour> <patternline index>" << std::endl;
                }
            }
            roundCounter++;
            // check if the round has ended (aka factories and centre are all empty)
            if (game->hasRoundEnded())
            {
                game->finaliseRound();
                roundOngoing = false;
            }
        }
    }

    if (game->hasGameEnded())
    {
        game->finaliseGame();
        gameOngoing = false;
    }

    std::cout << "=== GAME OVER ===" << std::endl;
}

void loadGamePage()
{
    // //line 1
    // printString("=", PAGEWIDTH);
    // std::cout << std::endl;

    // //line 2
    // printString(" ", PAGEWIDTH / 2 - 4);
    // std::cout << "LOAD GAME";
    // std::cout << std::endl;

    // //line 3
    // printString("=", PAGEWIDTH);
    // std::cout << std::endl;
    // std::cout << std::endl;

    // // User input for filename
    // std::cout << "Enter the filename you wish to load the game from:" << std::endl;
    // std::string filename;
    // std::cin >> filename;

    // LoadSave *load = new LoadSave();
    // load->loadFile(filename);
}