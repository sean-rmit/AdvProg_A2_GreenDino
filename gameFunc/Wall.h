#ifndef MosaicWall
#define MosaicWall

#include "Line.h"
#include "PatternLines.h"
#include "BoxLid.h"

#include <iostream>
#include <fstream>

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
    void addTile(char tile, int lineIndex, Lid *lid);

private:
    linePtr *wallLines;
    char fixedColourPattern[WALL_LINES_NUM][WALL_LINES_NUM];
};

typedef Wall* wallPtr;

#endif // MosaicWall