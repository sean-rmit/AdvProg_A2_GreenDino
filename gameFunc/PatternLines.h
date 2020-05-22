#ifndef PlayerPatternLines
#define PlayerPatternLines

#include "Line.h"
#include "Tiles.h"
#include "Wall.h"
#include "BoxLid.h"

#define PATTERN_LINES_NUM 5

class PatternLines {
public:

    // Constructor
    PatternLines();
    // Deconstructor
    ~PatternLines();

    // Copy constructor
    PatternLines(PatternLines& other);

    // Get line object at given index
    linePtr getLine(int index);

private:
    linePtr *patternLines;
};

typedef PatternLines* patternLinesPtr;

#endif // PlayerPatternLines