#include "block.h"
#include <iostream>

Block::Block(){
    cellSize = 50;
    rotationSatate = 0;
    colors = getColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(int offsetX, int offsetY){
    
    std::vector<Position> currentCells = GetCells();
    for(Position item: currentCells){
        DrawRectangle(item.col*cellSize+offsetX, item.row*cellSize+offsetY, cellSize-1, cellSize-1, colors[id]);
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

void Block::Rotate() {
    rotationSatate = (rotationSatate + 1);
    if(rotationSatate == int(cells.size())){
        rotationSatate = 0;
    }
}

void Block::ReverseRotate() {
    rotationSatate = (rotationSatate - 1);
    if(rotationSatate == -1){
        rotationSatate = int(cells.size()) - 1;
    }
}