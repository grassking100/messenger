#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <stdio.h>
#include "Ground.h"
#include "Block.h"
#include "Creature.h"
#include "Player.h"
const int HeightMax=100;
class Map
{
private:
    Ground<Block> *m=0;
    void addPatchHeight(Position pos,int height,int sizeR,int sizeC);
public:
    Map(int row,int col)
    {
        Block b(0,WATER);
        m=new Ground<Block>(row,col,b);
    }
    ~Map()
    {
        m->~Ground();
    }
    void print()const;
    void print(const Ground<Creature*> *g,const Ground<Building*> *b,const Player* player,int windowRow,int windowCol)const;
    void rough(int number,int level);
    void update(Climate cl);
    const Ground<Block>* getGround()const;
    char setLegend(int* text,int* backG);
    const  Block* getBlock(Position pos)const;
    void playerChangeMap(Player* player,char input);
};


#endif // MAP_H_INCLUDED
