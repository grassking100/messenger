#include "Map.h"
#include <stdio.h>
#include "typeinfo"
void Map::playerChangeMap(Player* player,char input)
{
    if(checkInput(input,'i'))
    {
        if(player->dust>=1)
        {
            addPatchHeight(player->pos,1,2,2);
            player->dust--;
        }

    }
    else if(checkInput(input,'o'))
    {
        if(player->dust<player->dustMax)
        {
            addPatchHeight(player->pos,-1,2,2);
            player->dust++;
        }

    }
}
void Map::addPatchHeight(Position pos,int height,int sizeR,int sizeC)
{
    for(int i=pos.row-sizeR; i<pos.row+sizeR; i++)
    {
        for(int j=pos.col-sizeC; j<pos.col+sizeC; j++)
        {
            Position p(i,j);
            if(m->validate(&p))
            {
                Block* bp=m->getObj(p);
                setValue(&bp->height,height,0,HeightMax,Force);
            }
        }
    }
}
const Block* Map::getBlock(Position pos)const
{
    if(m->validate(&pos))
    {
        return m->getObj(pos);
    }
    return 0;
}

const Ground<Block>* Map::getGround()const
{
    return m;
}
void Map::update(Climate cl)
{
    for(int i=0; i<m->RowSize(); i++)
    {
        for(int j=0; j<m->ColSize(); j++)
        {
            Block *bp=m->getObj(Position(i,j));
            bp->setBackGround(cl);
        }
    }
}
void Map::print()const
{
    for(int i=0; i<m->RowSize(); i++)
    {
        for(int j=0; j<m->ColSize(); j++)
        {
            int textC=0;
            int groundC=0;
            Block* bp=m->getObj(Position(i,j));
            char type=bp->setLegend(&textC,&groundC);
            SetTextAndBackgroundColor(textC,groundC);
            printf("%c",type);
        }
        printf("\n");
    }
}

void Map::rough(int number,int level)
{
    Position pos(rand()%m->RowSize(),rand()%m->ColSize());
    for(int i=0; i<number; i++)
    {
        int sizeR=rand()%10;
        int sizeC=rand()%10;
        addPatchHeight(pos,level,sizeR,sizeC);
        int r=rand()%m->RowSize()-m->RowSize()/2;
        int c=rand()%m->ColSize()-m->ColSize()/2;
        m->setPosition(&pos,Position(r,c));
    }
}


void Map::print(const Ground<Creature*> *g,const Ground<Building*> *b,const Player *player,int windowRow,int windowCol)const
{
    for(int i=player->pos.row-(windowRow/2); i<player->pos.row+(windowRow/2); i++)
    {
        for(int j=player->pos.col-(windowCol/2); j<player->pos.col+(windowCol/2); j++)
        {
            Position p(i,j);
              int textC=BLACK;
            int groundC=BLACK;
            char type = ' ';
            if(m->validate(p))
            {
                if(player->pos.row==i && player->pos.col==j)
                {
                    textC=BLACK;
                    groundC=ORANGE;
                    type='Y';
                }
                else
                {
                    Creature* cp=*g->getObj(Position(i,j));
                    if(cp!=0)
                    {
                        type=cp->setLegend(&textC,&groundC);
                    }
                    else
                    {
                        const   Building  *bp=*b->getObj(Position(i,j));
                        if(bp!=0)
                        {
                            type=bp->setLegend(&textC,&groundC);
                        }
                        else
                        {
                            Block* bp=m->getObj(Position(i,j));
                            type=bp->setLegend(&textC,&groundC);
                        }
                    }
                }
            }




            SetTextAndBackgroundColor(textC,groundC);
            printf("%c",type);
        }
        printf("\n");
    }
}
