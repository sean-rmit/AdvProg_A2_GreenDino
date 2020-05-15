#include <iostream>

#include "pages.h"

#define EXIT_SUCCESS    0

int main(int argc, char** argv) {
    // need to get argument to pass in seed value
    int seed = 0;
    mainMenuPage(seed);

    //end of file reached
    std::cout << "Goodbye!" << std::endl;
    return EXIT_SUCCESS;
}





