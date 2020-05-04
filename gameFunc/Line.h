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
    void addTileToBack(tilePtr tile);
    void addTileToIndex(tilePtr tile, int index);

    bool hasTile(int index);
    tilePtr removeTile(int index);
    std::string getTilesAsString();
    
private:
    tilePtr* line;
    int array_length; //size of the array of line
    int length; // number of tiles in array of line
};

// typedef Line* LinePtr;


#endif // MosaicLine