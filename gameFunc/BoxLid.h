#ifndef BoxLid
#define BoxLid

#include "Tiles.h"
#include "LinkedList.h"
#include <string>

class Lid {
public:

    // Constructor
    Lid();
    // Deconstructor
    ~Lid();
    // Copy Constructor
    Lid(Lid& other);

    // Return number of tiles in lid
    unsigned int size();
    // Add tile to back of the linked list of lid
    void addTileToBack(char tile);
    // Remove the tile at the front of the linked list of lid
    char removeTileFront();
    // Removes all tiles from the linked list of lid
    void clearLid();

    // Print tiles contained in linked list of lid
    std::string getTilesAsString();

private:
    LinkedList* lid;
};

typedef Lid* lidPtr;

#endif // BoxLid