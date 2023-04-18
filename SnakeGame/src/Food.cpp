#include "Food.h"
#include <cstdlib>
#include <ctime>
#define WIDTH 50
#define HEIGHT 30

Food::Food()
{
   srand(time(NULL));
   genFood();
}

void Food::genFood()
{
    foodPos.X = rand() % WIDTH + 1;
    foodPos.Y = rand() % HEIGHT + 1;
}

COORD Food::getFoodPos()
{
    return foodPos;
}


