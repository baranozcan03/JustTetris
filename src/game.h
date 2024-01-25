#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {

public:
    Game();
    void Draw();
    void HandleInput();
    void MoveCurrentBlockDown();
    bool IsGameOver();
    int score;

private:
    Grid grid;
    std::vector<Block> blocks;
    std::vector<Block> GetAllBlocks();
    Block CurrentBlock;
    Block NextBlock;
    Block GetRandomBlock();
    void RotateCurrentBlock();
    void MoveCurrentBlockLeft();
    void MoveCurrentBlockRight();
    void LockBlock();
    bool IsCurrentBlockOutOfBounds();
    bool NoCollission();
    void Reset();
    void UpdateScore(int rowsCleared, int moveDown);
    bool GameOver;
    bool dashPressed;
};