#include "PatternLines.h"

PatternLines::PatternLines() {
    patternLines = new linePtr[PATTERN_LINES_NUM];
    for (int i = 0; i < PATTERN_LINES_NUM; i++) {
        Line *line = new Line(i+1);
        patternLines[i] = line;
    }
}

PatternLines::~PatternLines() {
    for (int i = 0; i < PATTERN_LINES_NUM; i++) {
        delete patternLines[i];
    }
    delete patternLines;
}

PatternLines::PatternLines(PatternLines &other) : PatternLines() {

}

linePtr PatternLines::getLine(int index)
{
    return patternLines[index];
}

// void PatternLines::moveAllTilesToWall(Wall *wall, Lid *lid) {
//     for (int i = 0; i < PATTERN_LINES_NUM; i++) {
//         for (int i = 0; i < patternLines[i]->size(); i++) {
//             if (patternLines[i]->hasTile(i)) {
//                 wall->receiveTileFromPatternLine(patternLines[i]->removeTile(i), i, lid);
//             }
//         }
//     }
// }
