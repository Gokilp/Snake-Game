#ifndef FOOD_H
#define FOOD_H
#define WIDTH 50
#define HEIGHT 30

#include <windows.h>

class Food
{
private:
    COORD foodPos;
public:
    Food();
    void genFood();
    COORD getFoodPos();
};

#endif // FOOD_H

