#ifndef MosaicLine
#define MosaicLine

#include "Tiles.h"
#include <string>

class Line {
public:

    // Constructor
    Line();

    // Gets the length of the array
    Line(int length);

    // Deconstructor
    ~Line();

    // Returns the size of the array
    int size();

    // Returns the number of tiles in the array
    int getTilesNumber();


    // Although these two functions exists in the same class, they cannot be called simultaneously
    void addTileToBack(char tile);

    // Add the tile to the location of the index
    void addTileToIndex(char tile, int index);

    // Gets the colour of tiles at the index
    char getTileColour(int index);

    // Checks if the index contains a tile
    bool hasTile(int index);

    // Checks if the line is full
    bool isFull();

    // Removed a tile at the index
    char removeTile(int index);
    std::string getTilesAsString(bool hasNoTile);
    
private:
    char* line;
    int array_length; //size of the array of line
    int numTiles; // number of tiles in array of line
    
};

typedef Line* linePtr;


#endif // MosaicLine