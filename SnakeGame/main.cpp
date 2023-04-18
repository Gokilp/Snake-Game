#include <iostream>
#include <windows.h>
#include <Snake.h>
#include <Food.h>
#include <conio.h>
#include<vector>

using namespace std;

#define WIDTH 50
#define HEIGHT 30
#define UP_KEY 72
#define DOWN_KEY 80
#define RIGHT_KEY 77
#define LEFT_KEY 75

Snake snake({WIDTH/2, HEIGHT/2});
Food food;

void broder()
{
    vector<COORD> snakeBody =snake.getsnakeBody();
    for(int i=0; i<=HEIGHT+1; i++)
    {
        cout << "\t\t";
        COORD SnakePos = snake.getpos();
        for(int j=0; j<=WIDTH+1; j++)
        {
            if(i==0 || i==HEIGHT+1 || j==0 || j==WIDTH+1)
                cout << "#";
            else if (i == food.getFoodPos().Y && j == food.getFoodPos().X)
                cout << "*";

            else
            {
                bool SnakePos =false;
                for(int k=0;k< snakeBody.size();k++)
                {
                    if(i==snakeBody[k].Y&&
                       j==snakeBody[k].X)
                    {
                        cout<<"o";
                        SnakePos=true;
                        break;
                    }
                }
                if(!SnakePos)
                    cout<<' ';
            }

        }
        cout << endl;
    }
}

int main()
{
    while(true)
    {
        Sleep(100);
        broder();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});

        // console cursor point on origin point

        if(kbhit())
        {
            int ch = getch();
            if (ch == UP_KEY)
                snake.setDir('u');
            else if (ch == DOWN_KEY)
                snake.setDir('d');
            else if (ch == RIGHT_KEY)
                snake.setDir('r');
            else if (ch == LEFT_KEY)
                snake.setDir('l');
        }

        if (snake.collided())
        {
            cout << "Game Over";
            break;
        }
        if (snake.eaten(food))
        {
            snake.grow();
            food.genFood();
        }

        snake.movesnake();
    }

    return 0;
}



