#ifndef GameFactory
#define GameFactory

#include <string>
#include <vector>

#include "Centre.h"
#include "Tiles.h"
#include "TileBag.h"
#include "Player.h"

#define FACTORY_SIZE 4

class Factory {
    public:

    Factory();
    ~Factory();

    // copy constructor
    Factory(Factory& other);

    // returns current size of factory
    int size();

    // adds tiles to factory
    void addTile(tilePtr tileP);

    tilePtr getTile(int index);

    // removes tiles from a factory to player board and centre
    void playerTakesTiles(char c, Player *player, Centre *centre, int patternLineIndex);

    // removes all tiles from factories
    void clear();

    // load factories with randomised tile selection
    void loadFactory(Bag *bag);

    private:

    Line *factoryTiles;

};



#endif // GameFactory