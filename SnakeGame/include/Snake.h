#ifndef SNAKE_H
#define SNAKE_H
#endif // SNAKE_H
#include<windows.h>
#include<food.h>
#include <vector>

using namespace std;




class Snake
{
    COORD pos;
    int len;
    int dir;
vector <COORD> snakeBody;


public:
Snake(COORD pos);
COORD getpos();
void setDir(int d);
void movesnake();
bool collided();
bool eaten(Food &food);
void grow();
 std::vector<COORD> getsnakeBody();
};




