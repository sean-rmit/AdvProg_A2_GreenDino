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
  // tile.resize(5); owo whats this?
  return tile.size();
}

void Factory::addTile(tilePtr tileP)
{
  tile.push_back(tileP);
}

tilePtr Factory::getTile(int index) {

}

tilePtr Factory::removeTiles(char c)
{
  for (int i = 0; i < tile.size(); i++) {
    if (*tile.getTile() == c) {
      
    }
  }
}

void Factory::moveAllTilesToCentre(Centre *centre) {

}

void Factory::clear()
{
  tile.clear();
}

void Factory::loadFactory(Bag *bag) {
  clear();
  for (int i = 0; i < FACTORY_SIZE; i++) {
    addTile(bag->removeTileFront());
  }
}