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
    printString(" ", PAGEWIDTH / 2 - 8);
    std::cout << "Sean Tan < s3806690 >";
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH / 2 - 9);
    std::cout << "Aaron Soa < s3786067 >";
    std::cout << std::endl;

    //line 7
    printString(" ", PAGEWIDTH / 2 - 10);
    std::cout << "Amy Nguyen < s3783694 >";
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
            loadGamePage(seed);
            mainMenuRunning = false;
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
    Player *player1 = game->getPlayer1();
    Player *player2 = game->getPlayer2();
    game->getBag()->fillBagWithTiles(seed);
    game->getCentre()->addTile(FIRSTPLAYER);
    bool gameOngoing = true;
    std::cout << "Let’s Play!\n" << std::endl;
    std::cout << "== INSTRUCTIONS ==" << std::endl;
    std::cout << "Make a move: turn <factory index> <tile colour> <patternline index>" << std::endl;
    std::cout << "Save the game: save" << std::endl;
    std::cout << "Quit the game: quit" << std::endl;
    std::cout << std::endl;
    int roundCounter = 1; // odd = player 1 turn, even = player 2 turn
    while (gameOngoing)
    {
        bool roundOngoing = true;
        // initialise the round (i.e. load factories with tiles)
        std::cout << "=== Start Round ===" << std::endl;
        printPlayerPoints(player1, player2);
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
                printPlayerMosaic(player1);
            }
            else
            {
                printPlayerMosaic(player2);
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

                // if Ctrl+D is entered terminate the while loops
                if (std::cin.eof())
                {
                    validMove = true;
                    roundOngoing = false;
                    gameOngoing = false;
                    game->finaliseGame();
                }

                if (playerMove == "save")
                {
                    validMove = true;
                    roundOngoing = false;
                    gameOngoing = false;
                    std::cout << "Enter the filename (.txt) you wish to save to:" << std::endl;
                    std::cout << "> ";
                    std::string filename;
                    std::cin >> filename;
                    LoadSave *save = new LoadSave();
                    save->saveFile(filename, player1, player2, game->getCentre(), game->getFactories(), game->getBag(), game->getLid(), roundCounter);
                    delete save;
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
            if (game->hasGameEnded())
            {
                game->finaliseGame();
                roundOngoing = false;
                gameOngoing = false;
            }
        }
    }
    std::cout << "=== GAME OVER ===" << std::endl;
    delete game;
}

void loadGamePage(int seed)
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
    std::cout << "> ";
    std::string filename;
    std::cin >> filename;

    Player *player1 = new Player();
    Player *player2 = new Player();

    // game initialised
    Game *game = new Game(player1->getPlayerName(), player2->getPlayerName(), seed);

    player1 = game->getPlayer1();
    player2 = game->getPlayer2();

    bool gameOngoing = true;
    int roundCounter = 0; // odd = player 1 turn, even = player 2 turn

    Factories *factories = game->getFactories();


    LoadSave *load = new LoadSave();
    load->loadFile(filename, player1, player2, game->getCentre(), factories, game->getBag(), game->getLid(), roundCounter);
    delete load;
    if (game->getCentre()->getTileColour(0) == FIRSTPLAYER) {
        std::cout << "It's firstplayer token\n" << std::endl;
    }
    std::cout << "=== Azul Game Successfully Loaded ===" << std::endl;
    std::cout << "Let’s Play!\n" << std::endl;
    std::cout << "== INSTRUCTIONS ==" << std::endl;
    std::cout << "Make a move: turn <factory index> <tile colour> <patternline index>" << std::endl;
    std::cout << "Save the game: save" << std::endl;
    std::cout << "Quit the game: quit\n" << std::endl;
    std::cout << "== Current Player Progress ==" << std::endl;
    printPlayerMosaic(player1);
    printPlayerMosaic(player2);
    std::cout << std::endl;
    bool firstRoundSinceLoad = true;

    while (gameOngoing)
    {
        bool roundOngoing = true;
        // initialise the round (i.e. load factories with tiles)
        if (!firstRoundSinceLoad) {
            std::cout << "=== Start Round ===" << std::endl;
            printPlayerPoints(player1, player2);
            game->prepareNewRound();
            printPlayerPoints(player1, player2);
        }
        else {
            // check if the round has ended (aka factories and centre are all empty)
            if (game->hasRoundEnded())
            {
                game->finaliseRound();
                roundOngoing = false;
            }
            if (game->hasGameEnded())
            {
                game->finaliseGame();
                roundOngoing = false;
                gameOngoing = false;
            }
            firstRoundSinceLoad = false;
        }
        
        while (roundOngoing)
        {
            std::cout << "TURN FOR PLAYER: ";
            if (roundCounter % 2 == 1)
            {
                std::cout << player1->getPlayerName() << std::endl;
            }
            else
            {
                std::cout << player2->getPlayerName() << std::endl;
            }

            printFactories(game->getCentre(), factories);
            std::cout << std::endl;
            if (roundCounter % 2 == 1)
            {
                printPlayerMosaic(player1);
            }
            else
            {
                printPlayerMosaic(player2);
            }
            bool validMove = false;
            // loop until valid move is made
            while (!validMove)
            {
                if (roundCounter % 2 == 1)
                {
                    std::cout << player1->getPlayerName();
                }
                else
                {
                    std::cout << player2->getPlayerName();
                }
                std::cout << "'s turn to make a move:" << std::endl;
                std::cout << "> ";
                std::string playerMove;
                std::cin >> playerMove;

                // if Ctrl+D is entered terminate the while loops
                if (std::cin.eof())
                {
                    validMove = true;
                    roundOngoing = false;
                    gameOngoing = false;
                    game->finaliseGame();
                }

                if (playerMove == "save")
                {
                    validMove = true;
                    roundOngoing = false;
                    gameOngoing = false;
                    std::cout << "Enter the filename (.txt) you wish to save to:" << std::endl;
                    std::cout << "> ";
                    std::string filename;
                    std::cin >> filename;
                    LoadSave *save = new LoadSave();
                    save->saveFile(filename, player1, player2, game->getCentre(), factories, game->getBag(), game->getLid(), roundCounter);
                    delete save;
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
            if (game->hasGameEnded())
            {
                game->finaliseGame();
                roundOngoing = false;
                gameOngoing = false;
            }
        }
    }

    std::cout << "=== GAME OVER ===" << std::endl;
    delete game;
}