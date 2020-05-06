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
    centreTiles.resize(1);
    return centreTiles.size();
}

void Centre::addTile(tilePtr tileP)
{
    centreTiles.push_back(tileP);
}

void Centre::removeTiles(int index)
{
    if (centreTiles.size() > 0 && index >= 0 && index < centreTiles.size())
    {
        for (int i = index; i < centreTiles.size() - 1; ++i)
        {
          centreTiles[i] = centreTiles[i + 1];
        }

        centreTiles.pop_back();
    }
}

void Centre::clear()
{
    centreTiles.clear();
}