#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double CheckPoint = 0;

bool EventTrigger(double interval){
    double currentTime = GetTime();
    if(currentTime - CheckPoint >= interval)
    {
        CheckPoint = currentTime;
        return true;
    }
    return false;
}


int main()
{

    Color backgroundColour = darkBrown; //dark blue color, first number is red, second is green, third is blue, fourth is alpha(opacity,transparency)
    InitWindow(800, 1040, "Hello World"); //initilaize  a window with a width of 800, height of 600, and a title of "Hello World"
    SetTargetFPS(60);//set the target framerate to 60 frames per second

    Font fontT = LoadFontEx("font/Tetris.ttf", 64, 0, 0);
    Font fontA = LoadFontEx("font/ARIAL.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false) //loop until the user clicks the close button, or presses escape
    {
        game.HandleInput();
        if(EventTrigger(0.4)){
            game.MoveCurrentBlockDown();
        }
        BeginDrawing();//prepare to begin drawing
        ClearBackground(backgroundColour);//clear the background to pale green, /typically done once per frame, at the beginning of the loop
        //the previous frame is now gone, so we can work without worrying about what was there before
        DrawTextEx(fontT, "Tetris", {550,30}, 62, 3, beuge);
        DrawTextEx(fontT,"Score: ", {560,125}, 32, 2, WHITE);
        DrawRectangleRounded((Rectangle){ 550, 175, 220, 70 }, 0.3, 0, LIGHTGRAY );
        char score[10];
        sprintf(score, "%d", game.score);
        Vector2 textSize = MeasureTextEx(fontA, score, 42, 2);
        DrawTextEx(fontT, score, { 550 + (220 - textSize.x)/2, 175 + (70 - textSize.y)/2 }, 42, 2, darkBrown);

        DrawTextEx(fontT, "Next: ", {560,280}, 32, 2, WHITE);
        DrawRectangleRounded((Rectangle){ 550, 330, 220, 220 }, 0.3, 0,LIGHTGRAY );
        game.Draw();
        Vector2 gameOverTextSize1 = MeasureTextEx(fontT, "GAME OVER", 32, 2);
        Vector2 gameOverTextSize2 = MeasureTextEx(fontA, "-ress any key to restart-", 18, 2);
        if(game.IsGameOver()){
            DrawRectangleRounded((Rectangle){ 95, 435 , 350, 100 }, 0.3, 0, LIGHTGRAY );
            DrawTextEx(fontT, "GAME OVER", {270 - gameOverTextSize1.x/2, 470- gameOverTextSize1.y/2}, 32, 2, darkBrown);
            DrawTextEx(fontA, "-press any key to restart-", {270 - gameOverTextSize2.x/2, 505- gameOverTextSize2.y/2}, 18, 2, BLACK);
        }  
        EndDrawing();//stop drawing
    }

    CloseWindow();//close the window and clean up resources
}