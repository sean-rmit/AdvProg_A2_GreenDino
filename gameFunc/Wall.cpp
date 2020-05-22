#include "Wall.h"

Wall::Wall()
{
    wallLines = new linePtr[WALL_LINES_NUM];
    for (int i = 0; i < WALL_LINES_NUM; i++)
    {
        Line *line = new Line(5);
        wallLines[i] = line;
    }
    initialiseFixedColourPattern();
}

Wall::~Wall()
{
    for (int i = 0; i < WALL_LINES_NUM; i++)
    {
        delete wallLines[i];
    }
    delete wallLines;
}

Wall::Wall(Wall &other)
{
}

void Wall::initialiseFixedColourPattern()
{
    // read in from an fixedWallPatternTiles.txt file
    std::string filename = "fixedWallPatternTiles.txt";
    std::ifstream inputFile(filename);
    for (int i = 0; i < WALL_LINES_NUM; i++)
    {
        for (int j = 0; j < WALL_LINES_NUM; j++)
        {
            inputFile >> fixedColourPattern[i][j];
        }
    }
}

linePtr Wall::getLine(int index)
{
    return wallLines[index];
}

int Wall::addTile(char tile, int lineIndex, Lid *lid)
{
    int points = 0;
    for (int i = 0; i < WALL_LINES_NUM; i++)
    {
        if (fixedColourPattern[lineIndex][i] == tile)
        {
            if (!wallLines[lineIndex]->hasTile(i))
            {
                wallLines[lineIndex]->addTileToIndex(tile, i);

                // scoring implementation
                int adjacentTilesOnRow = 0;
                int adjacentTilesOnCol = 0;
                int row = lineIndex;
                int col = i;

                // check row
                while (col + 1 < WALL_LINES_NUM && wallLines[row]->hasTile(col + 1))
                {
                    adjacentTilesOnRow++;
                    col++;
                }
                col = i;
                while (col - 1 >= 0 && wallLines[row]->hasTile(col - 1))
                {
                    adjacentTilesOnRow++;
                    col--;
                }
                col = i;
                // check column
                while (row + 1 < WALL_LINES_NUM && wallLines[row + 1]->hasTile(col))
                {
                    adjacentTilesOnCol++;
                    row++;
                }
                row = lineIndex;
                while (row-1 >= 0 && wallLines[row - 1]->hasTile(col))
                {
                    adjacentTilesOnCol++;
                    row--;
                }
                if (adjacentTilesOnRow != 0)
                {
                    points += adjacentTilesOnRow + 1;
                }
                if (adjacentTilesOnCol != 0)
                {
                    points += adjacentTilesOnCol + 1;
                }
                if (adjacentTilesOnCol == 0 && adjacentTilesOnRow == 0)
                {
                    points = 1;
                }
                // end of scoring implementation
            }
            else
            {
                lid->addTileToBack(tile);
            }
        }
    }
    return points;
}

int Wall::addEndGameBonusPoints()
{
    int points = 0;
    int completedRows = 0;
    int completedCols = 0;
    int completedColours = 0;

    // count completed rows
    for (int rowIndex = 0; rowIndex < WALL_LINES_NUM; rowIndex++)
    {
        if (wallLines[rowIndex]->isFull())
        {
            completedRows++;
        }
    }

    // count completed columns
    for (int colIndex = 0; colIndex < WALL_LINES_NUM; colIndex++)
    {
        int counter = 0;
        for (int rowIndex = 0; rowIndex < WALL_LINES_NUM; rowIndex++)
        {
            if (wallLines[rowIndex]->hasTile(colIndex))
            {
                counter++;
            }
        }
        if (counter == 5)
        {
            completedCols++;
        }
        counter = 0;
    }

    // count complete colours
    char tile;
    int red = 0, yellow = 0, lightBlue = 0, darkBlue = 0, black = 0;
    for (int rowIndex = 0; rowIndex < WALL_LINES_NUM; rowIndex++)
    {
        for (int colIndex = 0; colIndex < WALL_LINES_NUM; colIndex++)
        {
            tile = wallLines[rowIndex]->getTileColour(colIndex);
            if (tile == RED)
            {
                red++;
            }
            else if (tile == YELLOW)
            {
                yellow++;
            }
            else if (tile == LIGHTBLUE)
            {
                lightBlue++;
            }
            else if (tile == DARKBLUE)
            {
                darkBlue++;
            }
            else if (tile == BLACK)
            {
                black++;
            }
        }
    }
    if (red == 5)
    {
        completedColours++;
    }
    if (yellow == 5)
    {
        completedColours++;
    }
    if (black == 5)
    {
        completedColours++;
    }
    if (darkBlue == 5)
    {
        completedColours++;
    }
    if (lightBlue == 5)
    {
        completedColours++;
    }

    // calculate bonus points
    points += (completedRows * 2) + (completedCols * 7) + (completedColours * 10);
    return points;
}