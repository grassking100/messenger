#include "Creature.h"
#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include "CreatureBase.h"
#include <stdlib.h>
#include "Map.h"
#include "Building.h"
#include "City.h"
#include "Data.h"
#include "GameInfo.h"
#include "Climate.h"

int main()
{
    int iter=0;
    //FILE* number=fopen("number.csv","w");
    //fprintf(number,"iter,h,r,c,a\n");
    Start:
    char input=' ';
    Climate climate;
    system("mode 650");
    int windowCol=50;
    int windowRow=30;
    const int x=150,y=150;
    Player player(x,y);
    srand(time(0));
    showIntroduction();
    int mode=showMode()-'1';
    player.type=NumToCountryType(mode);
    Map m(x,y);
    m.rough(500,4);
    City city(x,y);
    CreatureBase cb(x,y);
    Creature c;
    GameInfo info;
    Panel p;
    p.col=windowCol+1;
    for(int i=0; i<100; i++)
    {
        getBasicCreature(&c);
        c.birth();
        c.setPosition(Position(rand()%x,rand()%y));
        cb.add(&c);
    }

    int count=0;
    cb.updateInfos();
    const CountryInfo *cf=cb.getInfos();
    int countryNumber=CountryNum;

    while(cf[mode].getCount()>0  && !checkInput(input,'t') && countryNumber!=1)
    {
        count++;
        input=' ';
        inputEvent(&input);
        player.setPlayerMovement(input);
        setPaintPosition(0,0);
        cb.batchConsciousMove(&m,&city);
        cb.batchFight();
        cb.batchRest(m.getGround());
        cb.batchReproduct();
        m.print(cb.getGround(),city.getGround(),&player,windowRow,windowCol);
        cb.deleteDead();
        cb.batchBuilding(&city);
        city.deleteDead();
        city.updateStaus();
        cb.updateInfos();
        cf=cb.getInfos();
        p.setInfos(cf,&player,&climate);
        p.showPanel();
        m.playerChangeMap(&player,input);
        player.playerChangeClimate(&climate,input);
        m.update(climate);
        city.Batchmagic(cb.getCreatures());
        if(count%10==0)
        {
            if(player.magic<player.magicCapacity)
            {
                player.magic++;
            }
            count=0;
        }
        countryNumber=0;
        for(int i=0; i<CountryNum; i++)
        {
            if(cf[i].getCount()>0)
            {
                 countryNumber+=1;
            }

        }
        //fprintf(number,"%d,%d,%d,%d,%d\n",iter,cf[Harmony].getCount(),cf[River].getCount(),cf[Catastrophe].getCount(),cf[Atheism].getCount());
        iter++;
    }
    //fclose(number);
    system("cls");
    SetTextAndBackgroundColor(WHITE,BLACK);
    if(checkInput(input,'t'))
    {
        printf("Leave the game\n");
    }
    else
    {
        if(cf[mode].getCount()>0)
        {
            printf("Congratulation!!!You win the battle\nNow,Your people will rule the world\n");
        }
        else
        {
            printf("Sorry your people are all dead\nGame over!");
            printf("\n\nHarmony has %d people\n",cf[Harmony].getCount());
            printf("Catastrophe has %d people\n",cf[Catastrophe].getCount());
            printf("River has %d people\n",cf[River].getCount());
            printf("Atheism has %d people\n",cf[Atheism].getCount());
        }
    }
    bool out=false;
    char sure;
    printf("Are you sure to close the game??? (Y/N)\n");
    while(!out)
    {

        scanf("%c",&sure);
        if(checkInput(sure,'Y'))
        {
            out=true;
        }
          if(checkInput(sure,'N'))
        {
             goto Start;
        }
    }
    return 0;
}

