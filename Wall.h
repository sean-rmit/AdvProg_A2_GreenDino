#ifndef MosaicWall
#define MosaicWall

#include "Line.h"
#include "BoxLid.h"

#define WALL_LINES_NUM 5

class Wall {
public:

    Wall();
    ~Wall();

    // copy constructor
    Wall(Wall& other);
    
    void initialiseFixedColourPattern();

    // get line object at given index
    linePtr getLine(int index);

    void receiveTileFromPatternLine(tilePtr tile, int lineIndex, Lid *lid);

private:
    linePtr *wallLines;
    linePtr *fixedColourPattern;
};


#endif // MosaicWall