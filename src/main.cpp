#include <raylib.h>
#include "grid.h"
   

int main()
{

    InitWindow(800, 1000, "Hello World"); //initilaize  a window with a width of 800, height of 600, and a title of "Hello World"
    SetTargetFPS(60);//set the target framerate to 60 frames per second

    const Color backgroundColour = { 0xD1, 0xFF, 0xE1, 0xFF }; //pale green color,
    //first number is red, second is green, third is blue, fourth is alpha(opacity,transparency)



    Grid grid;
    grid.PrintGrid();


    while (WindowShouldClose() == false) //loop until the user clicks the close button, or presses escape
    {
        BeginDrawing();//prepare to begin drawing
        ClearBackground(backgroundColour);//clear the background to pale green, /typically done once per frame, at the beginning of the loop
        //the previous frame is now gone, so we can work without worrying about what was there before
        
        grid.Draw(); //draw the grid to the screen




        EndDrawing();//stop drawing
    }

    CloseWindow();//close the window and clean up resources


}