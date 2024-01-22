#include "block.h"
#include <iostream>

Block::Block(){
    cellSize = 50;
    rotationSatate = 0;
    colors = getColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(){
    
    std::vector<Position> currentCells = GetCells();
    for(Position item: currentCells){
        DrawRectangle(item.col*cellSize+1, item.row*cellSize+1, cellSize-1, cellSize-1, colors[id]);
    }
}

void Block::Move(int row, int col) {
    rowOffset += row;
    colOffset += col;
}

std::vector <Position> Block::GetCells() {
    std::vector<Position> currentCells = cells[rotationSatate];
    std::vector<Position> newCells;
    for(Position item: currentCells){
        newCells.push_back(Position(item.row + rowOffset, item.col + colOffset));
    }
    return newCells;
}