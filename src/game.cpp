#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    blocks = GetAllBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {
    if(blocks.size() == 0){
        blocks =  GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block=  blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
};

std::vector<Block> Game::GetAllBlocks() {
    return {I_Tetromino(),  J_Tetromino(), L_Tetromino(), O_Tetromino(), S_Tetromino(), T_Tetromino(), Z_Tetromino()};
}

void Game::Draw() {
    grid.Draw();
    CurrentBlock.Draw();
}

void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveCurrentBlockLeft();
        break;
    case KEY_A:
        MoveCurrentBlockLeft();
        break;
    case KEY_RIGHT:
        MoveCurrentBlockRight();
        break;
    case KEY_D:
        MoveCurrentBlockRight();
        break;
    case KEY_DOWN:
        MoveCurrentBlockDown();
        break;
    case KEY_S:
        MoveCurrentBlockDown();
        break;
    case KEY_UP:
        RotateCurrentBlock();
        break;
    case KEY_W:
        RotateCurrentBlock();
        break;
    }
}

void Game::MoveCurrentBlockDown() {
    CurrentBlock.Move(1,0);
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.Move(-1,0);
        LockBlock();
    }
}
void Game::MoveCurrentBlockLeft() {
    CurrentBlock.Move(0,-1);
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.Move(0,1);
    }
}
void Game::MoveCurrentBlockRight() {
    CurrentBlock.Move(0,1);
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.Move(0,-1);
    }
}

bool Game::IsCurrentBlockOutOfBounds() {
    std::vector<Position> currentCells = CurrentBlock.GetCells();
    for(Position item: currentCells){
        if(grid.IsCellOutOfBounds(item.row, item.col)){
            return true;
        }
    }
    return false;
}

bool Game::NoCollission()
{
    std::vector<Position> currentCells = CurrentBlock.GetCells();
    for(Position item: currentCells){
        if(!grid.IsCellEmpty(item.row, item.col)){
            return false;
        }
    }
    return true;
}

void Game::RotateCurrentBlock() {
    CurrentBlock.Rotate();
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.ReverseRotate();
    }
}

void Game::LockBlock() {
    std::vector<Position> currentCells = CurrentBlock.GetCells();
    for(Position item: currentCells){
        grid.gridValues[item.row][item.col] = CurrentBlock.id;
    }
    CurrentBlock = NextBlock;
    grid.ClearFullRows();
    NextBlock = GetRandomBlock();
}
        