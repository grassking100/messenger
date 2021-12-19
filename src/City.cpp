#include "City.h"
#include "Building.h"
#include "Ground.h"

void  City::Batchmagic( Ground<Creature*> * c)
{
    for (std::list<Building>::iterator it=building.begin(); it!=building.end(); ++it)
    {
        Building *bp=&(*it);
        magic(bp,c);
    }
}

void City::magic(Building *b,Ground<Creature*> * c)
{
    for(int i=-2; i<=2; i++)
    {
        for(int j=-2; j<=2; j++)
        {
            Position p(b->getPosition().row+i,b->getPosition().col+j);
            if(g->validate(p))
            {
                if(*c->getObj(p)!=0)
                {
                    Creature *cp=*c->getObj(p);
                    if(b->getType()==Harmony && cp->getType()==Harmony)
                    {
                        if(cp->getLife()<(cp->getLifeCapacity()/2) && cp->getEnergy()>=10)
                        {
                            cp->changeLife(10);
                            cp->changeFood(-2);
                        }
                        // cp->changeFood(10);
                    }
                    if(b->getType()==Catastrophe && cp->getType()!=Catastrophe)
                    {
                        cp->dead();
                    }
                    if(b->getType()==Catastrophe && cp->getType()==Catastrophe)
                    {
                         if(cp->getLife()<(cp->getLifeCapacity()/2) && cp->getEnergy()>=20)
                        {
                            cp->changeLife(5);
                            cp->changeFood(-10);
                        }
                    }
                    if(b->getType()==River && cp->getType()==River)
                    {

                        cp->changeFood(1);
                    }
                }
            }
        }
    }
}

City::City(int row,int col)
{
    Building*cp=0;
    g = new Ground<Building*>(row,col,cp);
}
City::~City()
{
    building.clear();
    g->~Ground();
}
const Ground<Building*>* City::getGround()const
{
    return g;
}
void City::add(Building *c)
{
    Position pos=c->getPosition();
    Building **bp=g->getObj(pos);
    if( g->validate(&pos) &&*bp ==0)
    {
        building.push_back(*c);
        *bp=& building.back();
    }
}
void City::updateStaus()
{
    for (std::list<Building>::iterator it=building.begin(); it!=building.end(); ++it)
    {
        (*it).takeFood(1);
    }
}
void City::deleteDead()
{
    for (std::list<Building>::iterator it=building.begin(); it!=building.end(); ++it)
    {
        if(!(*it).hasFood())
        {
            Position pos=(*it).getPosition();
            Building** cp=g->getObj(pos);
            *cp=0;
        }
    }
    building.remove_if(hasNoFood);
}
int City::localBuildingNum(Position pos)const
{
    const int size=2;
    int count=0;
    for(int i=-size; i<size; i++)
    {
        for(int j=-size; j<size; j++)
        {
            Position p(pos.row+i,pos.col+j);
            if(g->validate(&p) )
            {
                if( hasBuilding(p))
                {
                    count++;
                }
            }
        }
    }
    return count;
}
const Building* City::cgetBuilding(Position pos)const
{
    return getBuilding(pos);
}
Building* City::getBuilding(Position pos)const
{
    if(hasBuilding(pos))
    {
        return *g->getObj(pos);
    }
    return 0;
}
bool City::hasBuilding(Position pos)const
{
    return *g->getObj(pos)!=0;
}
