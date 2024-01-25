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
            DrawRectangle(col * cellSize + 21, row * cellSize + 21, cellSize-1, cellSize-1, cellColor);
        }
    }
}

bool Grid::IsCellOutOfBounds(int row, int col)
{
    return (((row < 0) || (row >= numberOfRows)) || ((col < 0) || (col >= numberOfColumns)));
}

bool Grid::IsCellEmpty(int row, int col)
{
    return gridValues[row][col] == 0;
}

bool Grid::IsRowFull(int row)
{
    for(int col = 0; col < numberOfColumns; col++) //for all columns
    {
        if(gridValues[row][col] == 0) //if the cell is empty
        {
            return false; //the row is not full
        }
    }
    return true; //the row is full
}

void Grid::DeleteRow(int row)
{
    for(int col = 0; col < numberOfColumns; col++) //for all columns
    {
        gridValues[row][col] = 0; //set the cell to 0
    }
} 

void Grid::MoveRowDown(int row, int numberOfTimes)
{
    for(int col = 0; col < numberOfColumns; col++) //for all columns
    {
        gridValues[row+numberOfTimes][col] = gridValues[row][col]; //move the cell down one row
        gridValues[row][col] = 0; //set the cell to 0
    }
}

int Grid::ClearFullRows()
{
    int numberOfRowsCleared = 0; //the number of rows cleared
    for(int row = numberOfRows-1; row >=0; row--) //for all rows
    {
        if(IsRowFull(row)) //if the row is full
        {
            DeleteRow(row); //delete the row
            numberOfRowsCleared++; //increment the number of rows cleared
        }
        else if(numberOfRowsCleared > 0) //if the row is not full, but we have already cleared at least one row
        {
            MoveRowDown(row, numberOfRowsCleared); //move the row down
        }
    }
    return numberOfRowsCleared; //return the number of rows cleared
}