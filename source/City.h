#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED
#include "Building.h"
#include "Ground.h"
#include <list>
#include "Creature.h"
class City
{
private:
    Ground<Building*> *g=0;
    std::list<Building> building;

public:
    int Size() const;
    City(int row,int col);
    void add(Building *c);
    void deleteDead();
    //Building* getBuilding(Position pos)const;
    const Building* cgetBuilding(Position pos)const;
    Building* getBuilding(Position pos)const;
      const Ground<Building*> * getBuildings()const{return g;};
    bool hasBuilding(Position pos)const;
    int localBuildingNum(Position pos)const;
    const Ground<Building*>* getGround()const;
    void updateStaus();
    ~City();
    void magic(Building *b, Ground<Creature*> * c);
     void Batchmagic( Ground<Creature*> * c);
};

#endif // CITY_H_INCLUDED
