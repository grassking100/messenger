#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED
#include <windows.h>
#include <conio.h>
#include "ctype.h"
#include <stdio.h>
enum Mode {Force,UnForce};
void setValue(int* source,int change,int lb,int ub,Mode mode);
bool checkValue(int source,int lb,int ub);
void setPaintPosition(int row, int col);
enum Color {BLACK=0,BLUE=1,GREEN=2,CYAN=3,RED=4,DARK_PINK=5,BROWN=6,LIGHT_GREY=7,DARK_GREY=8,PURPLE=9,LIGHT_GREEN=10
,LIGHT_BLUE=11,ORANGE=12,PINK=13,YELLOW=14,WHITE=15
           };
void SetTextAndBackgroundColor(int ForgC, int BackC);
void Copy(const int*source,int*target,int num);
int randTwoSize(int bound);
void showIntroduction();
void inputEvent(char *input);

bool checkInput(char input,char target);
int batchMul(int* arr,int size);
char showMode();
#endif // TOOL_H_INCLUDED
