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
    void putTileToPatternLine(tilePtr tile, int patternLineIndex);
    void putTileToBrokenTiles(tilePtr tile);

    private:
        Wall *playerWall;
        PatternLines *playerPatternLines;
        BrokenTiles *playerBrokenTiles;
};

typedef Mosaic* mosaicPtr;

#endif // PlayerMosaic