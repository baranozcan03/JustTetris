#include "colors.h"


const Color green = { 0, 255, 0, 255 };
const Color red = { 255, 0, 0, 255 };
const Color orange = { 255, 165, 0, 255 };
const Color yellow = { 255, 255, 0, 255 };
const Color purple = { 128, 0, 128, 255 };
const Color cyan = { 0, 255, 255, 255 };
const Color blue = { 0, 0, 255, 255 };
const Color darkBlue = { 0, 0, 255, 255 };


const Color darkBrown = { 47, 1, 1, 255 };
const Color beuge = {242, 190, 160, 255 };

std::vector<Color> getColors()
{
    return { beuge, green, red, orange, yellow, purple, cyan, blue };
}
