#ifndef PlayerPatternLines
#define PlayerPatternLines

#include "Line.h"
#include "Tiles.h"

class PatternLines {
    public:

    PatternLines();
    ~PatternLines();

    // copy constructor
    PatternLines(PatternLines& other);

    // return current size of patternline
    int size();

    // get line element at given index
    LinePtr getLine(int index);

    // get colour of tile
    tilePtr getColour();

    // add tile to line
    void addTile(tilePtr lineTile);

    // removes all tiles from a line
    void clear();

    // iterate through array of pattern line
    void patternLineArray();

    private:

    int length;
    char colour;
    LinePtr* line;
    tilePtr* tile;
    
};


#endif // PlayerPatternLines