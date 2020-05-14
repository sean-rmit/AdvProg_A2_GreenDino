#include <iostream>

#include "pages.h"

#define EXIT_SUCCESS    0

int main(int argc, char** argv) {

    bool programRunning = true;
    bool mainMenu = false;
    bool credits = false;
    bool inputExecuted = false; //prevent 1 input from executing 2 parts of the program

    // Game controller
    while(programRunning) {
        // go back to main menu if no pages are active, safety fallback
        if(!mainMenu && !credits) {
            //debug
            std::cout << "DEBUG: Safety fallback called" << std::endl;
            mainMenuPage();
            mainMenu = true;
        }
        inputExecuted = false;
        char input;
        std::cin >> input;

        /*** main menu page available inputs ***/
        if (mainMenu && !inputExecuted) {
            //main menu -> credits page
            if (input == 'C' || input == 'c') {
            creditsPage();
            credits = true;
            mainMenu = false;
            inputExecuted = true;
            }
            else if (input == 'Q' || input == 'q') {
                programRunning = false;
                inputExecuted = true;
            }
            else if (input == 'N' || input == 'n') {
                newGamePage();
                // these will be executed when newGamePage function has finished executing
                inputExecuted = true;
            }
            else if (input == 'L' || input == 'l') {
                loadGamePage();
                // these will be executed when loadGamePage function has finished executing
                inputExecuted = true;
            }
            else {
                std::cout << "No such available input!" << std::endl;
                inputExecuted = true;
            }
        }
        
        /*** credits page available inputs ***/
        if (credits && !inputExecuted) {
            //credits page -> main menu
            if (input == 'B' || input == 'b') {
                mainMenuPage();
                mainMenu = true;
                credits = false;
                inputExecuted = true;
            }
            else {
                std::cout << "No such available input!" << std::endl;
                inputExecuted = true;
            }
        }
    }
    std::cout << "Goodbye!" << std::endl;
    return EXIT_SUCCESS;
}





