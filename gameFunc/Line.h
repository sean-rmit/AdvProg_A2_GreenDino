#ifndef MosaicLine
#define MosaicLine

#include "Tiles.h"
#include <string>

class Line {
public:

    Line();
    Line(int length);
    ~Line();
    int size();
    int getTilesNumber();

    // although these two functions exists in the same class, they cannot be called simultaneously
    void addTileToBack(char tile);
    void addTileToIndex(char tile, int index);

    char getTileColour(int index);
    bool hasTile(int index);
    bool isFull();
    char removeTile(int index);
    std::string getTilesAsString(bool hasNoTile);
    
private:
    char* line;
    int array_length; //size of the array of line
    int numTiles; // number of tiles in array of line
    
};

typedef Line* linePtr;


#endif // MosaicLine