#include <iostream>
#include <string>

#include "Factory.h"

Factory::Factory() : tile()
{
}

Factory::Factory(Factory &other)
{
}

Factory::~Factory()
{
  clear();
}

int Factory::size()
{
  tile.resize(5);
  return tile.size();
}

void Factory::addTile(tilePtr tileP) {
  tile.push_back(tileP);
}

void Factory::removeTiles(int index)
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

void Factory::clear()
{
  tile.clear();
}

void Factory::loadFactory()
{
  clear();

  std::cout << "Factories:\n";
  tilePtr tile = new char(RED);
  
  //TODO

}