#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    blocks = GetAllBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    GameOver = false;
    score = 0;
    dashPressed = false;
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
    CurrentBlock.Draw(21,21);
    switch (NextBlock.id)
    {
    case 3:// I block
        NextBlock.Draw(409, 415);
        break;
    case 4:// O block
        NextBlock.Draw(410, 380);
        break;
    default:// Other blocks
        NextBlock.Draw(435, 380);
        break;
    }
}

void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    if (GameOver && keyPressed != 0){
        Reset();
    }
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
        UpdateScore(0, 1);
        break;
    case KEY_S:
        MoveCurrentBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateCurrentBlock();
        break;
    case KEY_W:
        RotateCurrentBlock();
        break;
    case KEY_SPACE:
        dashPressed = true;
        while (NoCollission() && !IsCurrentBlockOutOfBounds() && dashPressed)
        {
            MoveCurrentBlockDown();
            UpdateScore(0, 2);
        }
    }
}

void Game::MoveCurrentBlockDown() {
    if(!GameOver){
    CurrentBlock.Move(1,0);
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.Move(-1,0);
        LockBlock();
    }
    }
}
void Game::MoveCurrentBlockLeft() {
    if(!GameOver){
    CurrentBlock.Move(0,-1);
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.Move(0,1);
    }
    }
}
void Game::MoveCurrentBlockRight() {
    if(!GameOver){
    CurrentBlock.Move(0,1);
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.Move(0,-1);
    }
    }
}

bool Game::IsCurrentBlockOutOfBounds() {
    std::vector<Position> currentCells = CurrentBlock.GetCells();
    for(Position item: currentCells){
        if(grid.IsCellOutOfBounds(item.row, item.col)){
            dashPressed = false;
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
            dashPressed = false;
            return false;
        }
    }
    return true;
}

void Game::RotateCurrentBlock() {
    if(!GameOver){    
    CurrentBlock.Rotate();
    if(IsCurrentBlockOutOfBounds() || !NoCollission()){
        CurrentBlock.ReverseRotate();
    }
    }
}

void Game::LockBlock() {
    std::vector<Position> currentCells = CurrentBlock.GetCells();
    for(Position item: currentCells){
        grid.gridValues[item.row][item.col] = CurrentBlock.id;
    }
    CurrentBlock = NextBlock;
    if(!NoCollission()){
        GameOver = true;
    }
    int rowsCleared = grid.ClearFullRows();
    NextBlock = GetRandomBlock();
    UpdateScore(rowsCleared, 0);   
}
        
void Game::Reset() {
    grid.initializeGrid();
    blocks = GetAllBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    GameOver = false;
    score = 0;
}

void Game::UpdateScore(int rowsCleared, int moveDown)
{   
    switch (rowsCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDown;

}

bool Game::IsGameOver() {
    return GameOver;
}