#ifndef PAGES_H
#define PAGES_H

#include "utils.h"
#include "game.h"
#include "LoadSaveFile.h"

#define PAGEWIDTH       80

// Loads in the main menu screen
void mainMenuPage(int seed);

// Displays the credits screen
void creditsPage();

// Displays empty board for a new name
void newGamePage(int seed);

// Asks file to be loaded then displays the loaded board
void loadGamePage(int seed);


#endif // PAGES_H