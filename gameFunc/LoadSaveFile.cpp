#include<fstream>
#include<iostream>

void getData(std::string line, std::string& data);
// void splitData(std::string data);

//Read from file
int main() {
    //Reading file
    std::ifstream savedFile("saveFile.txt");
    while(!savedFile.eof()) {
        std::string line;
        for (int i = 0; getline(savedFile, line) && i < 35; i++) {
            int j, k, tll;

            std::string data;          


            //BAG
            if (i == 0) {
                getData(line, data);
                
                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }

            //LID
            if (i == 1) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }

            //FACTORIES ----------------------------
            //factory centre
            if (i == 2) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
            
            //factory 1-5
            for (j = 3; j <= 7; j++) {
                if (i == j) {
                    getData(line, data);

                    //split data
                    tll = data.length();
                    for (k = 0; k < tll; k++) {
                        std::cout << data[k] << std::endl;
                    }
                }
            }

            //PLAYER_1 -------------------------------
            //name
            if (i == 8) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }

            //score
            if (i == 9) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }         
            }

            //patternLine1-5
            for (j = 10; j <= 14; j++) {
                if (i == j) {
                    getData(line, data);

                    //split data
                    tll = data.length();
                    for (k = 0; k < tll; k++) {
                        std::cout << data[k] << std::endl;
                    }
                }
            }
            
            //floorLine
            if (i == 15) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }

            //Mosaic1-5
            for (j = 16; j <= 20; j++) {
                if (i == j) {
                    getData(line, data);

                    //split data
                    tll = data.length();
                    for (k = 0; k < tll; k++) {
                        std::cout << data[k] << std::endl;
                    }
                }
            }
            
            //PLAYER_2 --------------------------------
            //P2name
            if (i == 21) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }

            //P2score
            if (i == 22) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }

            //P2patternLine1-5
            for (j = 23; j <= 27; j++) {
                if (i == j) {
                    getData(line, data);

                    //split data
                    tll = data.length();
                    for (k = 0; k < tll; k++) {
                        std::cout << data[k] << std::endl;
                    }
                }
            }

            //P2floorLine
            if (i == 28) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
            
            //P2Mosaic_0
            for (j = 29; j <= 33; j++) {
                if (i == j) {
                    getData(line, data);

                    //split data
                    tll = data.length();
                    for (k = 0; k < tll; k++) {
                        std::cout << data[k] << std::endl;
                    }
                }
            }

            //NUMBER OF PLAYERS------------------------
            //currentPlayers
            if (i == 34) {
                getData(line, data);

                //split data
                tll = data.length();
                for (k = 0; k < tll; k++) {
                    std::cout << data[k] << std::endl;
                }
            }
        }
    }
}

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
    //std::cout << data << std::endl;

    //splitData(data);
}

// void splitData(std::string data) {
//     // int k;
//     // int tll = data.length();
//     // for (k = 0; k < tll; k++) {
//     //     std::cout << data[k] << std::endl;;
//     // }
// }
