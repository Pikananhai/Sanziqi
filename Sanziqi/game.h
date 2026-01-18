#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 3
#define ROW 3

//初始化
void Initialize(char arr[COL][ROW], int col, int row);
//打印面板
void panel(char arr[COL][ROW], int col, int row);
//玩家下棋
void PlayerMove(char arr[COL][ROW], int col, int row);
//电脑下棋
void ComputerMove(char arr[COL][ROW], int col, int row);
//判断输赢
char IsWin(char arr[COL][ROW], int col, int row);
