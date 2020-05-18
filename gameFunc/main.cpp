#include <iostream>

#include "pages.h"

#define EXIT_SUCCESS 0

class Args
{
public:
    int input;
};

void processArgs(int argc, char **argv, Args *args);

int main(int argc, char **argv)
{
    Args args;
    processArgs(argc, argv, &args);

    // End of File Reached
    std::cout << "Goodbye!" << std::endl;
    return EXIT_SUCCESS;
}

void processArgs(int argc, char **argv, Args *args)
{
    if (argc == 1)
    {
        int seed = 0;
        mainMenuPage(seed);
    }

    if (argc >= 2)
    {
        char *a = argv[2];
        int seedInput = atoi(a);
        args->input = seedInput;

        if (std::string(argv[1]) == "-s")
        {
            mainMenuPage(seedInput);
        }
    }
}
