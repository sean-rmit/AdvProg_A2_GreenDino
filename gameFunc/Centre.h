#ifndef FactoryCentre
#define FactoryCentre

#include <vector>

#include "Tiles.h"

class Centre {
    public:

    Centre();
    ~Centre();

    // copy constructor
    Centre(Centre& other);

    // returns current size of factory
    int size();

    // adds tiles to factory
    void addTile(tilePtr tileP);

    // removes tiles from a factory
    void removeTiles(int index);

    // removes all tiles from factories
    void clear();

    private:

    std::vector<tilePtr> centreTiles;

};


#endif // FactoryCentre