#ifndef GameFactory
#define GameFactory

#include <string>
#include <vector>

#include "Centre.h"
#include "Tiles.h"
#include "TileBag.h"

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

    // removes tiles from a factory
    void removeTiles(int index);

    // removes all tiles from factories
    void clear();

    // load factories with randomised tile selection
    void loadFactory();

    private:

    std::vector<tilePtr> tile;

};



#endif // GameFactory