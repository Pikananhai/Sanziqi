#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initialize(char arr[COL][ROW], int col, int row)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < COL; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void panel(char arr[COL][ROW], int col, int row)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char arr[COL][ROW], int col, int row)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("玩家下棋\n请输入坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("坐标被占用\n请重新输入\n\n");
			}
		}
		else
		{
			printf("输入错误坐标\n请重新输入\n\n");
		}
	}
}

void ComputerMove(char arr[COL][ROW], int col, int row)
{
	int x = 0;
	int y = 0;

	printf("电脑下棋\n");
	while (1)
	{
		x = rand() % col;
		y = rand() % row;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'o';
			break;
		}
	}
}

//返回 -- 'A' 继续
//返回 -- 'B' 平局
//返回 -- 'x' 玩家胜利
//返回 -- 'o' 电脑胜利
int Go(char arr[COL][ROW], int col, int row)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char arr[COL][ROW], int col, int row)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < col; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			return arr[i][1];
		}
	}
	for (j = 0; j < row; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[1][j] != ' ')
		{
			return arr[1][j];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	//平局
	if (Go(arr, COL, ROW))
	{
		return 'B';
	}
	return 'A';
}