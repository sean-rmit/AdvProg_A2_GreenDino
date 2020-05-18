#ifndef BoxLid
#define BoxLid

#include "Tiles.h"
#include "LinkedList.h"
#include <string>

// class Node {
// public:
//    tilePtr tile;
//    Node* next;
// };

// class LinkedList {
// public:
//    Node* head;
// };

class Lid {
public:

    Lid();
    ~Lid();

    // copy constructor
    Lid(Lid& other);

    // return number of tiles in lid
    unsigned int size();

    // add tile to back of the linked list of lid
    void addTileToBack(char tile);

    // remove the tile at the front of the linked list of lid
    char removeTileFront();

    // removes all tiles from the linked list of lid
    void clearLid();

    // print tiles contained in linked list of lid
    std::string getTilesAsString();

private:
    LinkedList* lid;
};

typedef Lid* lidPtr;

#endif // BoxLid