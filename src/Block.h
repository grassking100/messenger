#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include "Tool.h"
#include "Climate.h"
enum BlockType {GRASS,LAVA,SNOW,ROCK,WATER,E_RIVER,E_HARMONY,E_CATS,H_RIVER,H_HARMONY,H_CATS,BlockNumber};
class Block
{
public:
    int height=0;
    BlockType type=WATER;
    char setLegend(int* text,int* backG);
    Block(int _height,BlockType _type)
    {
        height=_height;
        type=_type;
    };
   // void setBackGround();
    void setBackGround(Climate cl);
};
#endif // BLOCK_H_INCLUDED
