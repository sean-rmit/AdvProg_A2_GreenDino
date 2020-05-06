#ifndef GamePlayer
#define GamePlayer

#include "Mosaic.h"
#include "Factory.h"
#include "Centre.h"

class Player {
    public:

    Player();
    ~Player();

    Mosaic getPlayerMosaic();
    void takeTilesFromFactory(Factory *factory, char colour, Centre *centre, int patternLineIndex);
    void putTileToPatternLine(tilePtr tile, int patternLineIndex);

    private:
        Mosaic *playerMosaic;
};


#endif // GamePlayer