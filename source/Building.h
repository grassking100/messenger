#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED
#include "Country.h"
#include "Tool.h"
#include "Position.h"
const int FoodMax=1000;
class Building
{
private:

    Position pos;
    int food=0;
    int foodCapacity=1000;
    CountryType  type=Atheism;
public:
    int residue()const
    {
        return foodCapacity-food;
    };
    int foodNumber()const
    {
        return food;
    };
    void giveFood(int _food)
    {
        setValue(&food,_food,0,foodCapacity,Force);
    };
    int takeFood(int take)
    {
        if(take>=food)
        {
            int temp=food;
            food=0;
            return temp;
        }
        else
        {
            food-=take;
            return take;
        }
    };

    bool hasFood()const
    {
        return food>0;
    };
    void setType(CountryType _type)
    {
        type=_type;
    };
    Position getPosition()const
    {
        return pos;
    }
    void setPosition(Position _pos)
    {
        pos=_pos;
    }
    char setLegend(int* text,int* backG)const;
    CountryType getType()const ;
};
bool hasNoFood(const Building &b);
#endif // BUILDING_H_INCLUDED
