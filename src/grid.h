#pragma once //ensure header only included once during compilation
#include <vector>
#include <raylib.h>

class Grid{

public:
    Grid();
    void initializeGrid(); //initialize the grid to all 0's
    int gridValues[20][10]; //the grid values, 0 is empty, (1-7) is a piece.
    void Draw(); //draw the grid to the screen
    void PrintGrid(); //draw the grid to the screen

private:
    //methods
    std::vector<Color> getCellColours();


    //variables
    int numberOfRows; //number of rows in the game grid
    int numberOfColumns; //number of columns in the game grid
    int cellSize; //length of one side of a gird cell in pixels
    std::vector<Color> colors; //colors for each piece

};