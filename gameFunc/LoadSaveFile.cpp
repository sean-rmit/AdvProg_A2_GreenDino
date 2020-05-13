#include<fstream>
#include<iostream>

void findData(std::string line);

//Read from file
int main() {
    //Reading file

    // if (!savedFile.eof()) {
    //     std::string line;
    //     getline(savedFile, line);
    //     if (line contains "factory1") {
    //         String[] tokens = line.split(" ")
    //         for each (tokens[2]) {
    //             char array = token[2];
    //             factory1->addTile(array[i]);
    //         }
    //     }
    // }

    std::ifstream savedFile("saveFile.txt");
    std::string file;
    std::string text;
    // int l = 0;
    // int fl = 0;

    while(!savedFile.eof()) {
        std::string line;
        for (int i = 0; getline(savedFile, line) && i < 35; i++) {
            int j;
            // int k;

            //BAG
            if (i == 0) {
                findData(line);

                // int tll = data.length();
                // for (k = 0; k < tll; k++) {
                //     std::cout << data[k] << std::endl;
                // }
            }

            //LID
            if (i == 1) {
                findData(line);

                // int tll = data.length();
                // for (k = 0; k < tll; k++) {
                //     std::cout << data[k] << std::endl;
                // }
            }

            //FACTORIES ----------------------------
            //factory centre
            if (i == 2) {
                findData(line);

                // int tll = data.length();
                // for (k = 0; k < tll; k++) {
                //     std::cout << data[k] << std::endl;
                // }
            }
            
            //factory 1-5
            for (j = 3; j <= 7; j++) {
                if (i == j) {
                    findData(line);

                    // int tll = data.length();
                    // for (k = 0; k < tll; j++) {
                    //     std::cout << data[j] << std::endl;
                    // }
                }
            }

            //PLAYER_1 -------------------------------
            //name
            if (i == 8) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }

            //score
            if (i == 9) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }

            //patternLine1-5
            for (j = 10; j <= 14; j++) {
                if (i == j) {
                    findData(line);

                    // int tll = data.length();
                    // for (j = 0; j < tll; j++) {
                    //     std::cout << data[j] << std::endl;
                    // }
                }
            }
            
            //floorLine
            if (i == 15) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }

            //Mosaic1-5
            for (j = 16; j <= 20; j++) {
                if (i == j) {
                    findData(line);

                    // int tll = data.length();
                    // for (j = 0; j < tll; j++) {
                    //     std::cout << data[j] << std::endl;
                    // }
                }
            }
            
            //PLAYER_2 --------------------------------
            //P2name
            if (i == 21) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }

            //P2score
            if (i == 22) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }

            //P2patternLine1-5
            for (j = 23; j <= 27; j++) {
                if (i == j) {
                    findData(line);

                    // int tll = data.length();
                    // for (j = 0; j < tll; j++) {
                    //     std::cout << data[j] << std::endl;
                    // }
                }
            }

            //P2floorLine
            if (i == 28) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }
            
            //P2Mosaic_0
            for (j = 29; j <= 33; j++) {
                if (i == j) {
                    findData(line);

                    // int tll = data.length();
                    // for (j = 0; j < tll; j++) {
                    //     std::cout << data[j] << std::endl;
                    // }
                }
            }

            //NUMBER OF PLAYERS------------------------
            //currentPlayers
            if (i == 34) {
                findData(line);

                // int tll = data.length();
                // for (j = 0; j < tll; j++) {
                //     std::cout << data[j] << std::endl;
                // }
            }
        }
    
    }

}

void findData(std::string line) {
    int ll;
    std::string data;
    char e = '='; 
    size_t found = line.find(e); 
    int el = 0;
    if (found != std::string::npos) {
        el = found + 1;
    }
    ll = line.length();

    data = line.substr(el, ll-el);
    std::cout << data << std::endl;
}