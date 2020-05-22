#ifndef FactoryCentre
#define FactoryCentre

#include <vector>
#include <string>

#include "Tiles.h"

class Centre {
public:

    // Constructor
    Centre();
    //Deconstructors
    ~Centre();

    // Copy constructor
    Centre(Centre& other);

    // Returns current size of factory
    int size();

    // Adds tiles to factory
    void addTile(char tileP);

    char getTileColour(int index);

    // Removes tiles from a factory
    char removeTile(int index);

    // Removes all tiles from factories
    void clear();

    std::string getTilesAsString();

private:

    std::vector<char> centreTiles;

};

typedef Centre* centrePtr;

#endif // Factory Centre