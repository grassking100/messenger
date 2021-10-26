#ifndef CREATUREBASE_H_INCLUDED
#define CREATUREBASE_H_INCLUDED
#include <list>
#include "Creature.h"
#include "Ground.h"
#include <stdio.h>
#include "Block.h"
#include "City.h"
#include "Map.h"
//#include "GameInfo.h"
bool isDead(const Creature& c);
class CreatureBase
{
private:
    CountryInfo infos[CountryNum]=
    {
        CountryInfo(NumToCountryType(0)),
        CountryInfo(NumToCountryType(1)),
        CountryInfo(NumToCountryType(2)),
        CountryInfo(NumToCountryType(3))
    };
    Ground<Creature*> *g=0;
    std::list<Creature> farm;
public:
    const CountryInfo* getInfos()const
    {
        return infos;
    }
     Ground<Creature*> * getCreatures()const{return g;};
    void updateInfos();
    int Size() const
    {
        return farm.size();
    };
    void deleteDead()
    {
        for (std::list<Creature>::iterator it=farm.begin(); it!=farm.end(); ++it)
        {
            if((*it).isDead())
            {
                Position pos=(*it).getPosition();
                Creature** cp=g->getObj(pos);
                *cp=0;
            }
        }
        farm.remove_if(isDead);
    };
    void add(Creature *c);
    CreatureBase(int row,int col);
    ~CreatureBase()
    {
        farm.clear();
        g->~Ground();
    };
    void setCountrysInfo(char info[][30],int* size);
//    void setCountryInfo(CountryType type,GameInfo *info);
    Creature* getCreature(Position pos)
    {
        if(hasCreature(pos))
        {
            return *g->getObj(pos);
        }
        return 0;

    }
    bool hasCreature(Position pos)const
    {
        return *g->getObj(pos)!=0;
    }
    void randomMove(Creature *c);
    void consciousMove(Creature *c,const Map *m,const City *b);
    const Ground<Creature*>* getGround()const;
    void batchMove();
    void batchFight();
    void batchRest(const Ground<Block> *g);
    void PrintMap()const;
    void batchReproduct();
    void batchBuilding(City*city);
    void move(Creature *c,Position change);
    void batchConsciousMove(const Map*m,const City *b);
//   void Consiuo
};


#endif // CREATUREBASE_H_INCLUDED
