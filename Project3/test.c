#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

menu()
{
	printf("#####################\n");
	printf("#### ��1������Ϸ ####\n");
	printf("#### ��0�˳���Ϸ ####\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������ȷ����\n");
		}
	
	} while (input);
	return 0;
}