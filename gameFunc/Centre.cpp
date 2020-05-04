#include "Centre.h"

Centre::Centre() : tile()
{
}

Centre::Centre(Centre &other)
{
  clear();
}

Centre::~Centre()
{
}

int Centre::size()
{
  tile.resize(1);
  return tile.size();
}

void Centre::addTile(tilePtr tileP) {
  tile.push_back(tileP);
}

void Centre::removeTiles(int index)
{
  if (tile.size() > 0 && index >= 0 && index < tile.size())
  {
    for (int i = index; i < tile.size() - 1; ++i)
    {
      tile[i] = tile[i + 1];
    }

    tile.pop_back();
  }
}

void Centre::clear()
{
  tile.clear();
}