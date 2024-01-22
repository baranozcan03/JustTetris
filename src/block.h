#pragma once
#include "position.h"
#include <vector>
#include <map>
#include "colors.h"

class Block{
public:
    Block();
    void Draw();
    void Move(int row, int col);
    std::vector<Position> GetCells();
    int id;
    std::map<int, std::vector<Position>> cells;


private:
    int cellSize;
    int rotationSatate;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;

};