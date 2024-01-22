#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {

public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveCurrentBlockLeft();
    void MoveCurrentBlockRight();
    void MoveCurrentBlockDown();
    

    Grid grid;

private:
    std::vector<Block> blocks;
    Block CurrentBlock;
    Block NextBlock;
    void RotateCurrentBlock();
    void LockBlock();
    bool IsCurrentBlockOutOfBounds();
    bool NoCollission();
};