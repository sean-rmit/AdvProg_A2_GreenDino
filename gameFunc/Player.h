#ifndef GamePlayer
#define GamePlayer

#include "Mosaic.h"
#include "Factory.h"
#include "Centre.h"
#include "Line.h"

class Player {
public:

    Player();
    ~Player();

    mosaicPtr getPlayerMosaic();
    void takeTilesFromFactory(Factory *factory, char colour, Centre *centre, int patternLineIndex, Lid *lid);
    void takeTilesFromCentre(char colour, Centre *centre, int patternLineIndex, Lid *lid);
    void moveTilesFromPatternLineToWall(Lid *lid);
    void moveTilesFromBrokenTilesToLid(Lid *lid);

private:
    Mosaic *playerMosaic;
};


#endif // GamePlayer