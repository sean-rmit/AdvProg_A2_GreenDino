#include "Centre.h"

Centre::Centre() : centreTiles()
{
}

Centre::Centre(Centre &other)
{
}

Centre::~Centre()
{
    clear();
}

int Centre::size()
{
    return centreTiles.size();
}

void Centre::addTile(tilePtr tileP)
{
    centreTiles.push_back(tileP);
}

char Centre::getTileColour(int index) {
    return *centreTiles.at(index);
}

tilePtr Centre::removeTile(int index) {
    tilePtr tile = centreTiles.at(index);
    centreTiles.erase(centreTiles.begin() + index);
    return tile;
}

void Centre::clear()
{
    centreTiles.clear();
}

std::string Centre::getTilesAsString() {
    std::string allTilesAsString;
    for (unsigned int i = 0; i < centreTiles.size(); i++) {
        allTilesAsString += centreTiles.at(i);
    }
    return allTilesAsString;
}