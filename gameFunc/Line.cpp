#include "Line.h"

#include <exception>
#include <iostream>

Line::Line()
{
    this->array_length = 0;
    numTiles = 0;
}

Line::Line(int length)
{
    this->numTiles = 0;
    this->array_length = length;
    line = new char[array_length];
    for (int i = 0; i < length; i++)
    {
        line[i] = NOTILE;
    }
}

Line::~Line()
{
    delete line;
}

int Line::size()
{
    return array_length;
}

int Line::getTilesNumber()
{
    return numTiles;
}

void Line::addTileToBack(char tile)
{
    if (numTiles < array_length)
    {
        line[numTiles] = tile;
        numTiles++;
    }
    else
    {
        std::cout << "ERROR: exceeded line size" << std::endl;
    }
}

void Line::addTileToIndex(char tile, int index)
{
    if (index >= 0 && index < array_length)
    {
        line[index] = tile;
        numTiles++;
    }
    else
    {
        std::cout << "ERROR: index out of bounds of line range 1" << std::endl;
    }
}

char Line::getTileColour(int index)
{
    if (index >= 0 && index < array_length)
    {
        return line[index];
    }
    else
    {
        throw std::logic_error("ERROR: index out of bounds of line range 2");
    }
}

bool Line::hasTile(int index)
{
    try
    {
        if (index >= 0 && index < array_length)
        {
            if (line[index] != NOTILE)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            throw std::logic_error("ERROR: index out of bounds of line range 3");
        }
    }
    catch (std::logic_error)
    {
        
    }

    return false;
}

bool Line::isFull()
{
    int counter = 0;
    for (int i = 0; i < array_length; i++) {
        if (line[i] != NOTILE) {
            counter++;
        }
    }
    if (counter == array_length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char Line::removeTile(int index)
{
    char tile = line[index];
    if (index >= 0 && index < array_length)
    {
        try
        {
            if (line[index] != NOTILE)
            {
                line[index] = NOTILE;
                numTiles--;
                return tile;
            }
            else
            {
                throw std::logic_error("ERROR: index out of bounds of line range 4");
            }
        }
        catch (std::logic_error)
        {
            
        }
    }
    else
    {
        throw std::logic_error("Line: Deleting on index with empty tile");
    }
    return tile;
}

std::string Line::getTilesAsString(bool hasNoTile)
{
    std::string allTilesAsString;
    for (int i = 0; i < array_length; i++)
    {
        if (line[i] != NOTILE)
        {
            allTilesAsString += line[i];
        }
        else
        {
            if (hasNoTile)
            {
                allTilesAsString += NOTILE;
            }
        }
    }
    return allTilesAsString;
}