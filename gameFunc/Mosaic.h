#ifndef PlayerMosaic
#define PlayerMosaic

#include "Wall.h"
#include "PatternLines.h"
#include "Line.h"


class Mosaic {
    public:

    Mosaic();
    ~Mosaic();

    Wall getPlayerWall();
    PatternLines getPlayerPatternLines();
    void putTileToPatternLine(tilePtr tile, int patternLineIndex);

    private:
        Wall *playerWall;
        PatternLines *playerPatternLines;
};


#endif // PlayerMosaic