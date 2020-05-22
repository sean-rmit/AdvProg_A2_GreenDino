#ifndef PlayerMosaic
#define PlayerMosaic

#include "Wall.h"
#include "PatternLines.h"
#include "BrokenTiles.h"


class Mosaic {
    public:

    // Constructor
    Mosaic();
    // Deconstructor
    ~Mosaic();

    wallPtr getPlayerWall();
    patternLinesPtr getPlayerPatternLines();
    brokenTilesPtr getPlayerBrokenTiles();
    // Gets the tile and puts it on the pattern line
    void putTileToPatternLine(char tile, int patternLineIndex);
    // Gets the tiles and puts it to the floor/broken line
    void putTileToBrokenTiles(char tile);

    private:
        Wall *playerWall;
        PatternLines *playerPatternLines;
        BrokenTiles *playerBrokenTiles;
};

typedef Mosaic* mosaicPtr;

#endif // PlayerMosaic