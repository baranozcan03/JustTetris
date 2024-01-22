#include <raylib.h>
#include "game.h"

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
    InitWindow(500, 1000, "Hello World"); //initilaize  a window with a width of 800, height of 600, and a title of "Hello World"
    SetTargetFPS(60);//set the target framerate to 60 frames per second

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
        game.Draw();
        EndDrawing();//stop drawing
    }

    CloseWindow();//close the window and clean up resources
}