#ifndef broken_tiles
#define broken_tiles

#include "Line.h"
#include "BoxLid.h"
#include "Centre.h"

#define MAX_BROKEN_TILES    7
#define NO_PENALTY          0
#define ONE_TILE_PENALTY    -1
#define TWO_TILE_PENALTY    -2
#define THREE_TILE_PENALTY  -4
#define FOUR_TILE_PENALTY   -6
#define FIVE_TILE_PENALTY   -8
#define SIX_TILE_PENALTY    -11
#define SEVEN_TILE_PENALTY  -14

class BrokenTiles {
public:
    // Constructor
    BrokenTiles();
    // Deconstructor
    ~BrokenTiles();


    linePtr getLine();
    int getPenaltyPoints();
    void moveAllTilesToLid(Lid *lid, Centre *centre);

private:
   Line *brokenTiles;
};

typedef BrokenTiles* brokenTilesPtr;

#endif // Broken Tiles