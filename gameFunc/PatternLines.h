#ifndef PlayerPatternLines
#define PlayerPatternLines

#include "Line.h"
#include "Tiles.h"
#include "Wall.h"
#include "BoxLid.h"

#define PATTERN_LINES_NUM 5

class PatternLines {
    public:

    PatternLines();
    ~PatternLines();

    // copy constructor
    PatternLines(PatternLines& other);

    // get line object at given index
    linePtr getLine(int index);

    //void moveAllTilesToWall(Wall *wall, Lid *lid);

    private:
    linePtr *patternLines;
};


#endif // PlayerPatternLines