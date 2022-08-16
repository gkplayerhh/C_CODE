#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void zero(char board[ROWS][COLS],char set)
{
	int a;
	for (a = 0; a < ROWS; a++)
	{
		int b;
		for (b = 0; b < COLS; b++)
		{
			board[a][b] = set;
		}
	}
}

void display(char board[ROWS][COLS])
{
	int a;
	for (a = 0; a <= ROW; a++)
	{
		printf("%d ", a);
	}
	printf("\n");
	for (a = 1; a <= ROW; a++)
	{
		int b;
		printf("%d ", a);
		for (b = 1; b <= COL; b++)
		{
			printf("%c ",board[a][b]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS])
{
	int count=NUMBER;
	while (count)
	{
		int a = rand() % ROW + 1;
		int b = rand() % COL + 1;
		if (board[a][b] != '1')
		{
			board[a][b] = '1';
			count--;
		}
	}
}

void move(char board1[ROWS][COLS], char board2[ROWS][COLS])
{
	while (1)
	{
		int x;
		int y;
		display(board2);
		printf("输入坐标\n");
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board1[x][y] == '1')
			{
				printf("你踩雷了\n");
					break;
			}
			if (board2[x][y] != '*')
			{
				printf("该坐标已被占用\n");
			}
			else
			{
				open(board1, board2,x,y);
			}
			
		}
		else
		{
			printf("输入坐标不在范围内\n");
		}
		
		if (flags(board2) == 1)
		{
			printf("玩家获胜\n");
			break;
		}
	}
}

void open(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y)
{
	int ret = count(board1, x, y);
	if (ret != 0)
	{
		board2[x][y] = ret + '0';
	}
	else if (ret == 0 && board2[x][y] != ' ')
	{
		board2[x][y] = ' ';
		int a;
		for (a = x - 1; a <= x + 1; a++)
		{
			int b;
			for (b = y - 1; b <= y + 1; b++)
			{
				if(a<=ROW && a>=1 && b>=1 && b<=COL)
				open(board1, board2, a, b);
			}
		}
	}
	else if(board2[x][y]==' ')
	{
		return;
	}
}

int count(char board1[ROWS][COLS], int x, int y)
{
	int g=0;
	int a;
	for (a = x-1; a <= x+1; a++)
	{
		int b;
		for (b = y-1; b <= y+1; b++)
		{
			if (board1[a][b] == '1')
				g++;
		}
	}
	return g;
}

int flags(char board2[ROWS][COLS])
{
	int i = 0, flag = 0;
	for (i = 1; i <= ROW; i++)
	{
		int j = 0;
		for (j = 1; j <= COL; j++)
		{
			if (board2[i][j] == '*')
				flag++;
		}
	}
	if (flag==NUMBER)
	return 1;
}
	
