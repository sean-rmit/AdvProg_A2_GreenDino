#include "Wall.h"

Wall::Wall()
{
  length = 0;
  wall = new LinePtr[MAX_PATTERN_LINE];
}

Wall::Wall(Wall &other) : Wall()
{
  length = other.length;
  for (int i = 0; i != length; ++i)
  {
    wall[i] = new Line(*other.wall[i]);
  }
}

Wall::~Wall()
{
  clear();
}

void Wall::wallArray()
{
  int x = 0;
  int y = 0;

  // fixed wall size
  for (int i = 0; i < MAX_PATTERN_LINE; i++)
  {
    for (int j = 0; j < MAX_PATTERN_LINE; j++)
    {
      x = j;
      y = i;
    }
  }

  // nullptr check
  for (int i = 0; i != MAX_PATTERN_LINE; ++i)
  {
    wall[i] = nullptr;
  }
}

void Wall::addTile(tilePtr lineTile)
{
  if (length != MAX_PATTERN_LINE)
  {
    tile[length] = lineTile;
    ++length;
  }
}

tilePtr *Wall::getPtr(int i) {
  return &tile[i];
}

int Wall::size()
{
  return length;
}

int Wall::getX() {
  return x;
}

int Wall::getY() {
  return y;
}

void Wall::clear()
{
  for (int i = 0; i != length; ++i)
  {
    delete tile[i];
    tile[i] = nullptr;
  }
}