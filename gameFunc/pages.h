#ifndef PAGES_H
#define PAGES_H

#include "utils.h"
#include "game.h"
#include "LoadSaveFile.h"

#define PAGEWIDTH       80

void mainMenuPage(int seed);
void creditsPage();
void newGamePage(int seed);
void loadGamePage();


#endif // PAGES_H