#include "PatternLines.h"

PatternLines::PatternLines()
{
  length = 0;
  line = new LinePtr[MAX_PATTERN_LINE];
}

PatternLines::PatternLines(PatternLines &other) : PatternLines()
{
  length = other.length;
  for (int i = 0; i != length; ++i)
  {
    line[i] = new Line(*other.line[i]);
  }
}

PatternLines::~PatternLines()
{
  clear();
}

void PatternLines::patternLineArray()
{

  // iterating through array
  for (int i = 0; i < MAX_PATTERN_LINE; i++)
  {
    // TODO
  }

  // nullptr check
  for (int i = 0; i != MAX_PATTERN_LINE; ++i)
  {
    line[i] = nullptr;
  }
}

int PatternLines::size()
{
  return length;
}

void PatternLines::addTile(tilePtr lineTile)
{
  if (length != MAX_PATTERN_LINE)
  {
    tile[length] = lineTile;
    ++length;
  }
}

void PatternLines::clear()
{
  for (int i = 0; i != length; ++i)
  {
    delete tile[i];
    tile[i] = nullptr;
  }
}

LinePtr PatternLines::getLine(int index)
{
  LinePtr patternLine = nullptr;
  if (index >= 0 && index < length)
  {
    patternLine = line[index];
  }
  return patternLine;
}

// TODO
tilePtr PatternLines::getColour()
{
  tilePtr tile = nullptr;
  int index = 0;
  if (index >= 0 && index < length)
  {
    tile = &colour;
  }
  return tile;
}