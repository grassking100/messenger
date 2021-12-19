#include "Tool.h"
#include <stdio.h>
bool checkValue(int source,int lb,int ub)
{
    return source>=lb && source<=ub;
}
int randTwoSize(int bound)
{
    return rand()%(bound*2+1)-bound;
};
void setValue(int* source,int change,int lb,int ub,Mode mode)
{
    if(checkValue((*source)+change,lb,ub))
    {
        *source+=change;
        return ;
    }
    if(mode==Force)
    {
        if((*source)+change>=ub)
        {
            *source=ub;
        }
        else
        {
            *source=lb;
        }
    }
}
bool checkInput(char input,char target)
{
    return tolower(target)==tolower(input);
}
int batchMul(int* arr,int size)
{
    int count=0;
    for(int i=0; i<size; i++)
    {
        count+=arr[i];
    }
    return count;
};
void inputEvent(char *input)
{
    if(kbhit())
    {
        *input=getch();
    }
}
void Copy(const int*source,int*target,int num)
{
    for(int i=0; i<num; i++)
    {
        target[i]=source[i];
    }
}
void setPaintPosition(int row, int col)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = col;
    scrn.Y = row;
    SetConsoleCursorPosition(hOuput,scrn);
}
void SetTextAndBackgroundColor(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
char showMode()
{
    printf("Please select your clan:\n");
    printf("1. Clan Harmony: The creature in this clan would not fight each other. They eat slower than creatures in other classes. The temple could recover their health by consuming energy.\n");
    printf("2. Clan River: The creature in this clan could eat in the river and stay young forever near the temple.\n");
    printf("3. Clan Catastrophe: The temple could damage creatures in other clans.\n");
    printf("4. Atheism: Nothing special.\n");
    char input=' ';
    bool ok=false;
    while(!ok)
    {
        input=getch();
        if('1'<=input && input<='4')
        {
            printf("\nYour choose is (%c)\n",input);
            ok=true;
        }
        else
        {
            printf("Wrong input\n");
        }

    }
    system("pause") ;
    system("cls") ;
    return input;
}
void showIntroduction()
{
    printf("***********************Welcome to the messenger.******************************\n\n");
    printf("Player could change the weather and landscape, these could affect create status.\n");
    printf("The snow would accelerate the decrease of the energy, the ocean would decrease the life, and the lava would hurt create largely.\n");
    printf("Every creature could reproduce asexually, their genetic code would pass to its offspring with some mutation.\n");
    printf("The genetic code would affect its properties.\n");
    printf("Every clan has its special properties.\n");
    printf("The creature could build temples to create special effects or store the food.\n");
    system("pause") ;
    system("cls") ;
}
