#ifndef MosaicWall
#define MosaicWall

#include "Line.h"

class Wall {
    public:

    Wall();
    ~Wall();

    // copy constructor
    Wall(Wall& other);

    // current size of wall
    int size();

    // get x-coordinate of tile location
    int getX();

    // get y-coordinate of tile location
    int getY();

    // iterate through wall array
    void wallArray();

    // add tile to wall
    void addTile(tilePtr lineTile);

    tilePtr* getPtr(int i);

    // removes all tiles from the wall
    void clear();

    private:

    LinePtr* wall;
    tilePtr* tile;
    int length;
    int x;
    int y;

};


#endif // MosaicWall