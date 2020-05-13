#ifndef Nodes
#define Nodes
#include "Tiles.h"

class Node {
public:
   tilePtr tile;
   Node* next;
};

#endif // Node