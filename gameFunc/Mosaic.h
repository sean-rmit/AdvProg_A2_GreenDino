#ifndef PlayerMosaic
#define PlayerMosaic

#include "Wall.h"
#include "PatternLines.h"
#include "BrokenTiles.h"


class Mosaic {
    public:

    Mosaic();
    ~Mosaic();

    wallPtr getPlayerWall();
    patternLinesPtr getPlayerPatternLines();
    brokenTilesPtr getPlayerBrokenTiles();
    void putTileToPatternLine(char tile, int patternLineIndex);
    void putTileToBrokenTiles(char tile);

    private:
        Wall *playerWall;
        PatternLines *playerPatternLines;
        BrokenTiles *playerBrokenTiles;
};

typedef Mosaic* mosaicPtr;

#endif // PlayerMosaic