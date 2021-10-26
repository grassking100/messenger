#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "CreatureBase.h"
#include "City.h"
#include "Map.h"
//#include "Climate.h"

class Data
{
    public:
    //Ground g;
    City c;
    CreatureBase cd;
    Map map;
//    Player player;
//    Climate climate;
};

bool freeData(Data *data);
#endif
