#ifndef TilesBag
#define TilesBag

#include "Tiles.h"
#include <string>
#include "LinkedList.h"

class Bag {
public:

    Bag();
    ~Bag();

    // copy constructor
    Bag(Bag& other);

    // return number of tiles in bag
    unsigned int size();

    // add tile to back of the linked list of bag
    void addTileToBack(tilePtr tile);

    // remove the tile at the front of the linked list of bag
    tilePtr removeTileFront();

    // removes all tiles from the linked list of bag
    void clearBag();

    // print tiles contained in linked list of bag
    std::string getTilesAsString();

private:
    LinkedList* bag;
};


#endif // TilesBag