#include <iostream>

#define EXIT_SUCCESS    0
#define PAGEWIDTH       80

void mainMenuPage();
void creditsPage();
void printString(std::string s, int num);

int main(int argc, char** argv) {

    bool game = true;
    bool mainMenu = false;
    bool credits = false;
    bool inputExecuted = false; //prevent 1 input from executing 2 parts of the program

    // Game controller
    while(game) {
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
                game = false;
                inputExecuted = true;
            }
            else {
                std::cout << "No such available input! A" << std::endl;
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
                std::cout << "No such available input! B" << std::endl;
                inputExecuted = true;
            }
        }
    }
    
    return EXIT_SUCCESS;
}

void mainMenuPage() {
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH/2 - 2); //3 = half of letters in AZUL
    std::cout << "AZUL";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    //line 4
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "New Game < enter 'N'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "Load Game < enter 'L'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "Credits < enter 'C'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "Quit Game < enter 'Q'";
    std::cout << std::endl;
    std::cout << std::endl;


}

void creditsPage() {

    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH/2 - 3); //3 = half of letters in CREDITS
    std::cout << "CREDITS";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    //line 4
    printString(" ", PAGEWIDTH/2 - 4);
    std::cout << "Design by";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH/2 - 4);
    std::cout << "Sean Tan";
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH/2 - 5);
    std::cout << "Aaron Soa";
    std::cout << std::endl;

    //line 7
    printString(" ", PAGEWIDTH/2 - 5);
    std::cout << "Amy Nguyen";
    std::cout << std::endl;
    std::cout << std::endl;

    //toolbar
    std::cout << "< enter B to go back to Main menu" << std::endl;
}

void printString(std::string s, int num) {
    for (int i = 0; i < num; i++) {
        std::cout << s;
    }
}