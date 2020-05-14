#ifndef FactoryCentre
#define FactoryCentre

#include <vector>
#include <string>

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

    char getTileColour(int index);

    // removes tiles from a factory
    tilePtr removeTile(int index);

    // removes all tiles from factories
    void clear();

    std::string getTilesAsString();

private:

    std::vector<tilePtr> centreTiles;

};

typedef Centre* centrePtr;

#endif // FactoryCentre