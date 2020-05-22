#ifndef LoadSaveF
#define LoadSaveF

#include "pages.h"
#include <string>

class LoadSave {
public:

    LoadSave();
    ~LoadSave();

    // copy constructor
    LoadSave(LoadSave& other);

    // function to manage saving files
    void saveFile(std::string saveFile, Player *player1, Player *player2, Centre *centre, Factories *factories, Bag *bag, Lid *lid, int currentPlayer);

    // function to manage loading files
    void loadFile(std::string loadFile, Player *player1, Player *player2, Centre *centre, Factories *factories, Bag *bag, Lid *lid, int &currentPlayer);

    // gets data from files during loading
    void getData(std::string line, std::string &data);

};

#endif 