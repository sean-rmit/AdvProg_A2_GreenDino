#ifndef GamePlayer
#define GamePlayer

#include "Mosaic.h"
#include "Factory.h"
#include "Centre.h"
#include "Line.h"

class Player {
public:
    Player();
    Player(std::string name);
    ~Player();

    std::string getPlayerName();
    mosaicPtr getPlayerMosaic();
    // add the score to player's total score, negative parameter means minus score
    void addToPlayerScore(int score);
    bool takeTilesFromFactory(Factory *factory, char colour, Centre *centre, int patternLineIndex, Lid *lid);
    bool takeTilesFromCentre(char colour, Centre *centre, int patternLineIndex, Lid *lid);
    void moveTilesFromPatternLineToWall(Lid *lid);
    void moveTilesFromBrokenTilesToLid(Lid *lid, Centre *centre);

private:
    std::string playerName;
    int playerScore;
    Mosaic *playerMosaic;
};

typedef Player* playerPtr;

#endif // GamePlayer