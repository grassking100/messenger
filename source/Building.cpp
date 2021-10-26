#ifndef BUILDING_CPP_INCLUDED
#define BUILDING_CPP_INCLUDED
#include "Building.h"
bool hasNoFood(const Building &b)
{
    return !b.hasFood();
};
char Building::setLegend(int* text,int* backG) const
{
    if(type==Catastrophe)
    {
        *text=YELLOW;
        *backG=RED;
    }
    else if(type==Harmony)
    {
        *text=RED;
        *backG=PINK;
    }
    else if(type==River)
    {
        *text=BLACK;
        *backG=LIGHT_BLUE;
    }
    else
    {
        *text=BLACK;
        *backG=YELLOW;
    }
    return '@';
}
CountryType Building::getType()const
{
    return type;
}
#endif // BUILDING_CPP_INCLUDED
