#include "Block.h"

void Block::setBackGround(Climate cl)
{

    int wet=0;
    int cold=1;
    if(cl.temperature-(height*1.5)>0)
    {
        cold=0;
    }

    if(cl.humidity-height>0)
    {
        wet=1;
    }
    if(cl.seaLevel<height)
    {
        if(wet==1 && cold==0)
        {
            type=GRASS;
        }
        if(wet==0 && cold==0)
        {
         type=LAVA;
        }
        if(wet==0 && cold==1)
        {
         type=ROCK;
        }
        if(wet==1 && cold==1)
        {
         type=SNOW;
        }
    }
    else
    {
       type=WATER;
    }

}

char Block::setLegend(int* text,int* backG)
{
    char icon;
    if(type==WATER)
    {
        *text=LIGHT_BLUE;
        *backG=BLUE;
        icon='~';
    }
    else if(type==GRASS)
    {
        *text=YELLOW;
        *backG=GREEN;
        icon= 'v';
    }
    else if(type==LAVA)
    {
        *text=YELLOW;
        *backG=RED;
        icon= '~';
    }
    else if(type==ROCK)
    {
        *text=DARK_GREY;
        *backG=LIGHT_GREY;
        icon='O';
    }
    else
    {
        *text=BLACK;
        *backG=WHITE;
        icon= 'x';
    }
    return icon;
}

