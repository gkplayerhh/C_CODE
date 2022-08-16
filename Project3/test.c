#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

menu()
{
	printf("#####################\n");
	printf("#### 按1进入游戏 ####\n");
	printf("#### 按0退出游戏 ####\n");
	printf("#####################\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	zero(mine,'0');
	zero(show, '*');
	setmine(mine);
	display(mine);
	move(mine, show);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确数字\n");
		}
	
	} while (input);
	return 0;
}