#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define snake_num 300
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct snake
{
	int size;
	int speed;
	int dir;
	int coler;
	POINT cool[snake_num];
}snake;

struct food
{
	int x;
	int y;
	bool is;
	int size;
	int coler;
	int change;
}food;

void snake_init()
{
	mciSendString("open ./BGM.mp3", 0, 0, 0);
	mciSendString("play ./BGM.mp3 repeat", 0, 0, 0);
	initgraph(640, 480);
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	snake.coler = GREEN;
	for (int i = 0; i < snake.size; i++)
	{
		snake.cool[i].x = 40 - i * 10;
		snake.cool[i].y = 10;
	}
	int x = rand()*7 % 630;
	int y = rand()*7 % 470;
	food.x= x - x%10 ;
	food.y = y- y%10 ;
	food.size = rand() % 2 + 5;
	food.coler = RGB(rand()%256, rand() % 256, rand() % 256);
	food.is = true;
}

void game_draw()
{
	BeginBatchDraw();
	setbkcolor(RGB(44,211,194));
	cleardevice();
	for (int i = 0; i < snake.size; i++)
	{
		if (i == 0)
		{
			setfillcolor(snake.coler);
			solidcircle(snake.cool[0].x, snake.cool[0].y, 6);
		}
		else
		{
			setfillcolor(snake.coler);
			solidcircle(snake.cool[i].x, snake.cool[i].y, 5);
		}
	}
	if (food.is)
	{
		setfillcolor(food.coler);
		solidcircle(food.x, food.y, food.size);
		setfillcolor(RED);
		solidcircle(food.x, food.y, 2);
	}
	EndBatchDraw();
}

void snake_move()
{
	for (int i=snake.size-1;i>0;i--)
	{
		snake.cool[i] = snake.cool[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.cool[0].y -= snake.speed;
		if (snake.cool[0].y <= -10)
		{
			snake.cool[0].y = 480;
		}
		break;
	case DOWN:
		snake.cool[0].y += snake.speed;
		if (snake.cool[0].y >= 490)
		{
			snake.cool[0].y = 0;
		}
		break;
	case LEFT:
		snake.cool[0].x -= snake.speed;
		if (snake.cool[0].x <= -10)
		{
			snake.cool[0].x = 640;
		}
		break; 
	case RIGHT:
		snake.cool[0].x += snake.speed;
		if (snake.cool[0].x >= 650)
		{
			snake.cool[0].x = 0;
		}
		break;
	}
}

void snake_dir()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		case 'W':
			if(snake.dir!=DOWN)
			snake.dir = UP;
			break;
		case 's':
		case 'S':
			if(snake.dir!=UP)
			snake.dir = DOWN;
			break;
		case 'a':
		case 'A':
			if(snake.dir!=RIGHT)
			snake.dir = LEFT;
			break;
		case 'd':
		case 'D':
			if(snake.dir!=LEFT)
			snake.dir = RIGHT;
			break;
		}
	}
}

void food_eat()
{
	if (food.is && snake.cool[0].x==food.x && snake.cool[0].y==food.y)
	{
		food.is = false;
		snake.size++;
		snake.coler = food.coler;
	}
	if (!food.is)
	{
		int x = rand() * 7 % 630;
		int y = rand() * 7 % 470;
		food.x = x - x % 10;
		food.y = y - y % 10;
		food.size = rand() % 2 + 5;
		food.coler = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.is = true;
	}
}
	
int main()
{
	srand((unsigned int)time(NULL));
	snake_init();
	while (1)
	{
		snake_dir();
		food_eat();
		snake_move();
		Sleep(220);
		game_draw();
	}
	return 0;
}