#ifndef GAMEINFO_H_INCLUDED
#define GAMEINFO_H_INCLUDED
#include "Tool.h"
#include "Data.h"
#include "Player.h"
const  int rowS=10;
const  int colS=30;
class GameInfo
{
public:
    const static int rowSize=10;
    const static int colSize=30;
    char info[rowSize][colSize]= {};
    int size=0;
    int backC=BLACK;
    int textC=WHITE;
    void printInfo(int row,int col);
    void cleanInfo(int row,int col);
    void setInfo(const CountryInfo* info);
    void setLegendInfo();
    void setActionInfo();
    void setClimateInfo();
    void setPlayerInfo(const Player* player);
    void setClimateInfo(const Climate* climate);
};
class Panel
{
public:
    int row=0;
    int col=0;
    GameInfo panel[3][3];
    void setInfo(int row,int col,const GameInfo* info);
    void showPanel(Panel panel);
    void showPanel();
    void setInfos(const CountryInfo* _info,const Player* player,const Climate *climate);

};

//void setClimateInfo(const Climate* climate,char info[][30],int* size);

void showCountry(const Data *data,GameInfo *info,CountryType type);

#endif // GAMEINFO_H_INCLUDED
