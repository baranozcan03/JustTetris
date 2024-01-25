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

    Color backgroundColour = { 0x00, 0x00, 0x8B, 0xFF }; //dark blue color, first number is red, second is green, third is blue, fourth is alpha(opacity,transparency)
    InitWindow(800, 1040, "Hello World"); //initilaize  a window with a width of 800, height of 600, and a title of "Hello World"
    SetTargetFPS(60);//set the target framerate to 60 frames per second

    Font font = LoadFontEx("font/Tetris.ttf", 64, 0, 0);

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
        DrawTextEx(font, "Tetris", {550,30}, 62, 3, RED);
        DrawTextEx(font,"Score: ", {560,125}, 32, 2, WHITE);
        DrawRectangleRounded((Rectangle){ 550, 175, 220, 70 }, 0.3, 0, LIGHTGRAY );
        char score[10];
        sprintf(score, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, score, 42, 2);
        DrawTextEx(font, score, { 550 + (220 - textSize.x)/2, 175 + (70 - textSize.y)/2 }, 42, 2, darkBlue);

        DrawTextEx(font, "Next: ", {560,280}, 32, 2, WHITE);
        DrawRectangleRounded((Rectangle){ 550, 330, 220, 220 }, 0.3, 0,LIGHTGRAY );
        if(game.IsGameOver()){
            DrawTextEx(font, "GAME OVER", {550,600}, 32, 2, WHITE);
        }   
        game.Draw();
        EndDrawing();//stop drawing
    }

    CloseWindow();//close the window and clean up resources
}