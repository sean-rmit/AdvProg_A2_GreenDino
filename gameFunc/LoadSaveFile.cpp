#include<fstream>
#include<iostream>
#include<cstring>

//Read from file
int main() {
    //Reading file
    std::ifstream savedFile("saveFile.txt");
    std::string line;

    if (!savedFile.eof()) {
        if (line.find("factory1")) {
            getline(savedFile, line);
            std::cout << line << std::endl;
        }
        if (line.find("factory2")) {
            getline(savedFile, line);
            std::cout << line << std::endl;
        }
        if (line.find("factory3")) {
            getline(savedFile, line);
            std::cout << line << std::endl;
        }
        if (line.find("factory4")) {
            getline(savedFile, line);
            std::cout << line << std::endl;
        }
        if (line.find("factory5")) {
            getline(savedFile, line);
            std::cout << line << std::endl;
        }
    }
   
    
    std::cout << std::endl;
    std::cout << "all file info: " << std::endl;
    while (!savedFile.eof()) {
        std::string out;

        getline(savedFile, out);
        std::cout << out << std:: endl;

    }

    return EXIT_SUCCESS;
}



// readSaveFile(savefile, player, *factory1-5, *centre, lid, bag) {
//     //read file line by line
//     for (filename.hasnext) {
//         String line = filename.getline()
//         if (line contains "factory1") {
//             String[] tokens = line.split(" ")
//             for each (tokens[2]) {
//                 char array = token[2];
//                 factory1->addTile(array[i]);

//             }

//         }
//     }
//     centre lid bag
// }
