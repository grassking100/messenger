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
    printf("請選擇加入的陣營\n");
    printf("(1)為Harmony的信徒,成員之間不會打架,但進食慢,寺廟可以恢復信徒的性命,但需耗能量能量\n");
    printf("(2)為River的朋友,成員在寺廟範圍內永保活力與青春,在水上可攝食\n");
    printf("(3)為Catastrophe的戰士,在寺廟範圍內敵人的性命有大量損失\n");
    printf("(4)為Atheism的普通人\n");
    printf("註:選擇任一宗教者,則必須消滅其他宗教\n\n");
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
    printf("這是一款簡單的小遊戲,玩家是上天選擇的使者,要讓自己的陣營存活到最後並滅掉其他敵人\n");
    printf("遊戲中玩家可以做有\n       (1)改變(局部)地型\n       (2)改變全球氣溫\n       (3)改變全球濕度\n       (4)改變海平面\n");
    printf("遊戲中的氣候和地形會引響居民的健康.\n    雪地會加速能量的流失,海洋會減少壽命,岩漿則大量減少能量\n");
    printf("遊戲中的生物可經無性生殖繁衍,並有一定的機率突變,這些生物將依照自己遺傳到的特徵來做出反應\n\n");

    printf("每一種陣營都有它們適應的條件\n每一陣營可建造寺廟來儲存食物\n寺廟可以製造特殊效果\n");
    printf("遊戲中玩家有袋子來裝土,裝滿就不能裝了,魔法值來施魔法,魔法值會隨時間補充\n");
    printf("遊戲中玩家可以透過 w(W) 向上走\n"
           "                   a(A) 向左走\n"
           "                   s(S) 向下走\n"
           "                   d(D) 向右走\n"
           "                   p(P) 來暫停\n\n"
           "********************************************************************************\n"
           "對周圍的地型造成以下影響\n"
           "                   o(O) 降低周圍地型的高度 (將背包中的土倒出來)\n"
           "                   i(I) 提升周圍地型的高度 (將土裝進背包中)\n\n"
           "對全球氣候造成以下影響(需魔法值)\n"
           "                   k(K) 降低濕度 \n"
           "                   j(J) 提升濕度\n"
           "                   n(N) 降低溫度\n"
           "                   m(M) 提升溫度\n"
           "對海平面造成影響(需魔法值)\n"
           "                   2 降低海平面 \n"
           "                   8 提升海平面\n");

    system("pause") ;
    system("cls") ;
}
