#include <fstream>
#include <iostream>
#include "LoadSaveFile.h"

LoadSave::LoadSave()
{
}

LoadSave::~LoadSave()
{
}

LoadSave::LoadSave(LoadSave &other)
{
}

void LoadSave::saveFile(std::string saveFile, std::string player1, std::string player2) {
    std::ofstream saveToFile(saveFile);
    saveToFile << player1;
    saveToFile << player2;
}

/* Change here */
void LoadSave::loadFile(std::string loadFile)
//, Factories *factories, Player *player1
{   
    // Reading file
    std::ifstream savedFile(loadFile);

    bool found = false;
    
    // inside this if function this check if the file exist and nothing else
    if (!savedFile && (found == false))
    {
        std::cout << "File was not found, please enter another file: " << std::endl;
        std::string filename;
        std::cin >> filename;

        // this is very messy, don't call yourself inside yourself
        LoadSave *load = new LoadSave();
        load->loadFile(filename);
        
        if (savedFile) {
            found = true;
        }
    }
    

    // use these to make sure all elements are loaded up, return error if one of them doesn't load
    bool factoriesLoaded = false;
    bool playersLoaded = false;
    //add more

    //while loop to read everything
    std::string line;
    while (getline(savedFile, line)) {
        std::string data;
        int k, dl;

        //FACTORIES +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //Finding keyword line
        if (line.find("BAG") != std::string::npos) {
            //Getting all the information after the '=' sign
            getData(line, data);

            //Splitting data into individual characters
            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        if (line.find("LID") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        if (line.find("FACTORY_CENTRE") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        for (int i = 0; i <= 4; i++) {
            std::string factories = "FACTORY_";
            factories += std::to_string(i);
            if (line.find(factories) != std::string::npos) {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
        }

        //PLAYER_1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if (line.find("PLAYER_1_NAME") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        if (line.find("PLAYER_1_SCORE") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        for (int i = 1; i <= 5; i++) {
            std::string playerPattern = "PLAYER_1_PATTERN_LINE";
            playerPattern += std::to_string(i);
            if (line.find(playerPattern) != std::string::npos) {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
        }

        if (line.find("PLAYER_1_FLOOR_LINE") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        for (int i = 0; i <= 4; i++) {
            std::string playerMosaic = "PLAYER_1_MOSAIC_";
            playerMosaic += std::to_string(i);
            if (line.find(playerMosaic) != std::string::npos) {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
        }

        //PLAYER_2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if (line.find("PLAYER_2_NAME") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        if (line.find("PLAYER_2_SCORE") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        for (int i = 1; i <= 5; i++) {
            std::string playerPattern = "PLAYER_2_PATTERN_LINE";
            playerPattern += std::to_string(i);
            if (line.find(playerPattern) != std::string::npos) {
                getData(line, data);
                
                dl = data.length();
                for (k = 0; k < dl; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
        }

        if (line.find("PLAYER_2_FLOOR_LINE") != std::string::npos) {
            getData(line, data);
            
            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }

        for (int i = 0; i <= 4; i++) {
            std::string playerMosaic = "PLAYER_2_MOSAIC_";
            playerMosaic += std::to_string(i);
            if (line.find(playerMosaic) != std::string::npos) {
                getData(line, data);

                dl = data.length();
                for (k = 0; k < dl; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
        }

        //OTHER +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if (line.find("CURRENT_PLAYER") != std::string::npos) {
            getData(line, data);

            dl = data.length();
            for (k = 0; k < dl; k++) {
                std::cout << data[k] << std::endl;
            }
        }
    }
}

//Getting the data after the '='
void getData(std::string line, std::string& data) {
    int ll;
    char e = '='; 
    size_t found = line.find(e); 
    int el = 0;
    if (found != std::string::npos) {
        el = found + 1;
    }
    ll = line.length();

    data = line.substr(el, ll-el);
}
