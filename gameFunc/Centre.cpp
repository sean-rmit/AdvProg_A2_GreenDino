#include "Centre.h"

Centre::Centre() : centreTiles()
{
    addTile(FIRSTPLAYER);
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

void Centre::addTile(char tileP)
{
    centreTiles.push_back(tileP);
}

char Centre::getTileColour(int index) {
    return centreTiles.at(index);
}

char Centre::removeTile(int index) {
    char tile = centreTiles.at(index);
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