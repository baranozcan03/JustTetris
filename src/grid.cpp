#include "grid.h"
#include "colors.h"
#include "iostream"


Grid::Grid()
{
    numberOfRows = 20;
    numberOfColumns = 10;
    cellSize = 50; //length of one side of a gird cell in pixels
    initializeGrid();//initialize the grid to all 0's
    colors = getColors();
}

void Grid::initializeGrid()
{
    for (int i = 0; i < numberOfRows; i++)//for all rows
    {
        for (int j = 0; j < numberOfColumns; j++)//for all columns
        {
            gridValues[i][j] = 0; //set the value to 0
        }
    }
}

void Grid::PrintGrid()
{
    for (int row =0 ; row < numberOfRows; row++) {
        for(int col = 0 ; col < numberOfColumns; col++) {
            std::cout << gridValues[row][col] << " ";
        }
        std::cout << std::endl;
    }
}


void Grid::Draw()
{
    for(int row =0; row < numberOfRows; row++) //for all rows
    {
        for(int col = 0; col < numberOfColumns; col++) //for all columns
        {
            int cellValue = gridValues[row][col]; //get the value of the cell
            Color cellColor = colors[cellValue]; //get the color of the cell

            //we will use raylib's DrawRectangle function to draw the cell
            //the first two parameters are the x and y coordinates of the top left corner of the rectangle
            //the second two parameters are the width and height of the rectangle
            //the last parameter is the color of the rectangle
            DrawRectangle(col * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, cellColor);
        }
    }
}
    