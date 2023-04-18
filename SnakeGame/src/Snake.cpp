#include "Snake.h"
#define WIDTH 50
#define HEIGHT 30
using namespace std;

Snake::Snake(COORD pos)
{
    this->pos = pos;
    len = 1;
    snakeBody.push_back(pos);
}

COORD Snake::getpos()
{
    return pos;
}
void Snake::setDir(int d)
{

    dir=d;
}
void Snake::movesnake()
{
    switch(dir)
    {
        case 'u':
        pos.Y--;
        break;
    case 'd':
        pos.Y++;
        break;
    case 'l':
        pos.X--;
        break;
    case 'r':
        pos.X++;
        break;
    }

    snakeBody.push_back(pos);
    if(snakeBody.size()>len)
    {
        snakeBody.erase(snakeBody.begin());
    }
}
bool Snake ::collided()
{
    if (pos.X == 0 || pos.X == WIDTH + 1 ||
        pos.Y == 0 || pos.Y == HEIGHT + 1)
        return true;
    else
        return false;

}
bool Snake::eaten(Food &food)
{
    if(pos.X==food.getFoodPos().X&&
   pos.Y==food.getFoodPos().Y)
    return true;
else
    return false;
}


void Snake:: grow()
{
    len++;
}
 vector<COORD>Snake::getsnakeBody()
{

return snakeBody;
}
