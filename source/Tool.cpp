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
    printf("�п�ܥ[�J���}��\n");
    printf("(1)��Harmony���H�{,�����������|���[,���i���C,�x�q�i�H��_�H�{���ʩR,���ݯӯ�q��q\n");
    printf("(2)��River���B��,�����b�x�q�d�򤺥ëO���O�P�C�K,�b���W�i�᭹\n");
    printf("(3)��Catastrophe���Ԥh,�b�x�q�d�򤺼ĤH���ʩR���j�q�l��\n");
    printf("(4)��Atheism�����q�H\n");
    printf("��:��ܥ��@�v�Ъ�,�h����������L�v��\n\n");
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
    printf("�o�O�@��²�檺�p�C��,���a�O�W�ѿ�ܪ��Ϫ�,�n���ۤv���}��s����̫�÷�����L�ĤH\n");
    printf("�C�������a�i�H����\n       (1)����(����)�a��\n       (2)���ܥ��y���\n       (3)���ܥ��y���\n       (4)���ܮ�����\n");
    printf("�C��������ԩM�a�η|���T�~�������d.\n    ���a�|�[�t��q���y��,���v�|��ֹةR,���߫h�j�q��֯�q\n");
    printf("�C�������ͪ��i�g�L�ʥʹ��c�l,�æ��@�w�����v����,�o�ǥͪ��N�̷Ӧۤv��Ǩ쪺�S�x�Ӱ��X����\n\n");

    printf("�C�@�ذ}�糣�����̾A��������\n�C�@�}��i�سy�x�q���x�s����\n�x�q�i�H�s�y�S��ĪG\n");
    printf("�C�������a���U�l�Ӹˤg,�˺��N����ˤF,�]�k�ȨӬI�]�k,�]�k�ȷ|�H�ɶ��ɥR\n");
    printf("�C�������a�i�H�z�L w(W) �V�W��\n"
           "                   a(A) �V����\n"
           "                   s(S) �V�U��\n"
           "                   d(D) �V�k��\n"
           "                   p(P) �ӼȰ�\n\n"
           "********************************************************************************\n"
           "��P�򪺦a���y���H�U�v�T\n"
           "                   o(O) ���C�P��a�������� (�N�I�]�����g�˥X��)\n"
           "                   i(I) ���ɩP��a�������� (�N�g�˶i�I�]��)\n\n"
           "����y��Գy���H�U�v�T(���]�k��)\n"
           "                   k(K) ���C��� \n"
           "                   j(J) �������\n"
           "                   n(N) ���C�ū�\n"
           "                   m(M) ���ɷū�\n"
           "��������y���v�T(���]�k��)\n"
           "                   2 ���C������ \n"
           "                   8 ���ɮ�����\n");

    system("pause") ;
    system("cls") ;
}
