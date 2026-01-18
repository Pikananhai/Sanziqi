#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf(" 三子棋\n按1 开始\n按0 结束\n");
	printf("请输入->");
}

void game()
{
	int ret = 0;
	char arr[COL][ROW] = { 0 };
	//初始化
	Initialize(arr, COL, ROW);
	//打印面板
	panel(arr, COL, ROW);
	while (1)
	{
		//玩家下棋
		PlayerMove(arr, COL, ROW);
		panel(arr, COL, ROW);
		//判断输赢
		ret = IsWin(arr, COL, ROW);
		if (ret != 'A')
		{
			break;
		}
		//电脑下棋
		ComputerMove(arr, COL, ROW);
		panel(arr, COL, ROW);
		//判断输赢
		IsWin(arr, COL, ROW);
		if (ret != 'A')
		{
			break;
		}
	}
	switch (ret)
	{
	case 'x':
		printf("玩家赢了\n");
		break;
	case 'o':
		printf("电脑赢了\n");
		break;
	default:
		printf("平局\n");
		break;
	}
	printf("\n");
	panel(arr, COL, ROW);
}

//三子棋
int main()
{
	srand((unsigned int )time(NULL));
	int input = 0;

	do
	{
		menu();//打印菜单
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf(" 选择错误\n请重新选择\n");
			printf("----------\n");
			break;
		}
	} while (input);

		return 0;
}