
#include "GameInfo.h"
#include "string.h"
#include "stdio.h"
#include "Data.h"
void GameInfo::setClimateInfo(const Climate* climate)
{
    char temp[30];
    strcpy(info[0],"Climate info");

    sprintf(temp,"  Humidity:%5d",climate->humidity);
    strcpy(info[1],temp);

    sprintf(temp,"  Temperature:%5d",climate->temperature);
    strcpy(info[2],temp);

    sprintf(temp,"  Sea Level:%5d",climate->seaLevel);
    strcpy(info[3],temp);
    strcpy(info[4],"");
    strcpy(info[5],"");
    strcpy(info[6],"");
    strcpy(info[7],"");
}
void GameInfo::setInfo(const CountryInfo* _info)
{
    if(_info->getType()==Harmony)
    {
        backC=PINK;
    }
    else if(_info->getType()==Catastrophe)
    {
        backC=RED;
    }
    else if(_info->getType()==River)
    {
        backC=PURPLE;
    }
    else if(_info->getType()==Atheism)
    {
        backC=YELLOW;
        textC=BLACK;
    }
    char typeInfo[30];
    convertCountryToString(_info->getType(),typeInfo);
    sprintf(info[0],"%s info",typeInfo);
    char temp[30];
    if(_info->getCount()>0)
    {
        int creatureCount=_info->getCount();
        sprintf(temp,"  Creature count:%5d",_info->getCount());
        strcpy(info[1],temp);

        sprintf(temp,"  Life:(%5d/%5d)",_info->getLife()/creatureCount,_info->getLifeC()/creatureCount);
        strcpy(info[2],temp);

        sprintf(temp,"  Energy:(%5d/%5d)",_info->getEnergy()/creatureCount,_info->getEnergyC()/creatureCount);

        strcpy(info[3],temp);

        sprintf(temp,"  Attack %5d Defense %5d",_info->getAttack()/creatureCount,_info->getDefense()/creatureCount);
        strcpy(info[4],temp);

        sprintf(temp,"  Aggressive %5d",_info->getAggressive()/creatureCount);
        strcpy(info[5],temp);

        sprintf(temp,"  Loyalty %5d",_info->getLoyalty()/creatureCount);
        strcpy(info[6],temp);

        sprintf(temp,"  Age %5d",_info->getAge()/creatureCount);
        strcpy(info[7],temp);
    }
    else
    {
        strcpy(info[1],"xxx Extinction xxx          ");
        for(int i=0; i<6; i++)
        {
            strcpy(info[2+i],"                            ");
        }
    }
}
void Panel::setInfo(int row,int col,const GameInfo* info)
{
    panel[row][col]=*info;
}

void Panel::setInfos(const CountryInfo* _info,const Player* player,const Climate *climate)
{
    GameInfo info;
    for(int i=0; i<=1; i++)
    {
        for(int j=1; j<=2; j++)
        {
            info.setInfo(&_info[i*2+j-1]);
            setInfo(i,j,&info);
        }
    }
    info.setPlayerInfo(player);
    setInfo(0,0,&info);

    info.setClimateInfo(climate);
    setInfo(1,0,&info);

    info.setLegendInfo();
    setInfo(2,0,&info);
    info.setClimateInfo();
    setInfo(2,1,&info);
    info.setActionInfo();
    setInfo(2,2,&info);
}
void setPanel(Panel *panel,int row,int col,const Data* data)
{
    panel->col=col;
    panel->row=row;
    GameInfo environment;
    panel->panel[0][0]=environment;

    GameInfo infoH;
    infoH.backC=PINK;
    panel->panel[0][1]=infoH;

    GameInfo infoC;
    infoC.backC=RED;
    panel->panel[0][2]=infoC;

    GameInfo infoL;
    infoC.backC=WHITE;
    infoC.textC=BLACK;
    panel->panel[1][0]=infoL;

    GameInfo infoR;
    infoR.backC=PURPLE;
    panel->panel[1][1]=infoR;

    GameInfo infoA;
    infoA.backC=YELLOW;
    infoA.textC=BLACK;
    panel->panel[1][2]=infoA;

    GameInfo infoG;
    panel->panel[2][1]=infoG;

    GameInfo infoAc;
    panel->panel[2][0]=infoAc;


}
void Panel::showPanel()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            panel[i][j].printInfo(row+rowS*i,col+colS*j);
        }
    }
}

void GameInfo::setPlayerInfo(const Player* player)
{
    char temp[30];
    strcpy(info[0],"Player info");

    char type[20];
    convertCountryToString(player->type,type);
    sprintf(temp,"  Player type:%s",type);
    strcpy(info[1],temp);

    sprintf(temp,"  Position(%4d,%4d)",player->pos.row, player->pos.col);
    strcpy(info[2],temp);

    sprintf(temp,"  Magic: %4d/%4d",player->magic,player->magicCapacity );
    strcpy(info[3],temp);

    sprintf(temp,"  Bag: %4d/%4d",player->dust,player->dustMax);
    strcpy(info[4],temp);

    strcpy(info[5],"");
    strcpy(info[6],"");
    strcpy(info[7],"");
}

void GameInfo::printInfo(int row,int col)
{
    for(int i=0; i<rowSize; i++)
    {
        setPaintPosition(row+i,col);
        SetTextAndBackgroundColor(textC,backC);
        printf("%s",info[i]);
    }
}
void  GameInfo::cleanInfo(int row,int col)
{
    GameInfo info= {};
    for(int i=0; i<info.rowSize; i++)
    {
        setPaintPosition(row+i,col);
        printf("%s",info.info[i]);
    }
}
void GameInfo::setLegendInfo()
{
    strcpy(info[0],"Map Legend");
    strcpy(info[1],"@       Temple");
    strcpy(info[2],"v        Grass");
    strcpy(info[3],"~(blue)  River");
    strcpy(info[4],"x         Snow");
    strcpy(info[5],"P     Creature");
    strcpy(info[6],"Y       Player");
    strcpy(info[7],"~(red)    Lava");
}

void GameInfo::setActionInfo()
{
    strcpy(info[0],"Control key");
    strcpy(info[1],"Walk up: w(W)");
    strcpy(info[2],"Walk left: a(A)");
    strcpy(info[3],"Walk down: s(S)");
    strcpy(info[4],"Walk right: d(D)");
    strcpy(info[5],"Pause: p(P)");
    strcpy(info[6],"Help: h(H)");
    strcpy(info[7],"");
    strcpy(info[8],"");
}

void GameInfo::setClimateInfo()
{
    strcpy(info[0], "Climate Ground key");
    strcpy(info[1], "Decrease height: o(O)");
    strcpy(info[2], "Increase height: i(I)");
    strcpy(info[3], "Decrease humidity: k(K)");
    strcpy(info[4], "Increase humidity: j(J)");
    strcpy(info[5], "Decrease temperature: n(N)");
    strcpy(info[6], "Increase temperature: m(M)");
    strcpy(info[7], "Decrease sea level: 2");
    strcpy(info[8], "Increase sea level: 8");
}
