#include<fstream>

//Read from file
int readSavedFile() {
    //Reading file
    std::string filename = "SaveFile.txt";
    std::ifstream savedFile;

    savedFile.open(filename);

    if(!savedFile.is_open()) {
        return 1;
    }
    
    while(savedFile) {
        std::string line;

        getline(savedFile, line);
    }

    savedFile.close();
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


