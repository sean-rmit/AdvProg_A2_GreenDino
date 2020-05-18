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

    void saveFile(std::string saveFile, Player *player1, Player *player2, Centre *centre, Factories *factories);

    void loadFile(std::string loadFile);
    // , Factories *factories, Player *player1

    void getData(std::string line, std::string &data);
};

#endif 