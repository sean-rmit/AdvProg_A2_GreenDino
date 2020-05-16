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

    void loadFile(std::string loadFile);

    void getData(std::string line, std::string &data);
};

#endif 