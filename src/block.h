#pragma once
#include "position.h"
#include <vector>
#include <map>
#include "colors.h"

class Block{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int row, int col);
    std::vector<Position> GetCells();
    void Rotate();
    void ReverseRotate();
    int id;
    std::map<int, std::vector<Position>> cells;



private:
    int cellSize;
    int rotationSatate;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;

};