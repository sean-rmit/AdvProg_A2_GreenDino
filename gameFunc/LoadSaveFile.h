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

    void saveFile(std::string saveFile, Player *player1, Player *player2, Centre *centre, Factories *factories, Bag *bag, Lid *lid, int currentPlayer);

    void loadFile(std::string loadFile, Player *player1, Player *player2, Centre *centre, Factories *factories, Bag *bag, Lid *lid, int currentPlayer);

    void getData(std::string line, std::string &data);
};

#endif 