#include<stdio.h>
#include<stdlib.h>
#define ROW 9
#define ROWS ROW+2
#define COL 9
#define COLS COL+2
#define NUMBER 10
void zero(char board[ROWS][COLS],char set);
void display(char board[ROWS][COLS]);
void setmine(char board[ROWS][COLS]);
void move(char board1[ROWS][COLS], char board2[ROWS][COLS]);
void open(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y);