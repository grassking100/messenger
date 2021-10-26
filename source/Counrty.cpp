#include "Country.h"
#include "stdlib.h"
#include "string.h"
CountryType randomType()
{
    switch(rand()%4)
    {
    case 0:
        return Harmony;
        break;
    case 1:
        return River;
        break;
    case 2:
        return Catastrophe;
        break;
    default:
        return Atheism;
        break;
    }

}
CountryType NumToCountryType(int i)
{
    switch(i)
    {
    case 0:
        return Harmony;
        break;
    case 1:
        return River;
        break;
    case 2:
        return Catastrophe;
        break;
    default:
        return Atheism;
        break;
    }
}
void convertCountryToString(int type,char * str)
{
    if(type==Harmony)
    {
        strcpy(str,"Harmony");
    }
    else if(type==River)
    {
        strcpy(str,"River");
    }
    else if(type==  Catastrophe)
    {
        strcpy(str,"Catastrophe");
    }
    else if(type== Atheism)
    {
        strcpy(str,"Atheism");
    }
}
int convertStringToCountry(int type,const char * str)
{
    if(  strcmp(str,"Harmony")==0)
    {
        return Harmony;
    }
    if(  strcmp(str,"Catastrophe")==0)
    {
        return Catastrophe;
    }
    if(  strcmp(str,"River")==0)
    {
        return River;
    }
    if(  strcmp(str,"Harmony")==0)
    {
        return Harmony;
    }
    if(  strcmp(str,"Atheism")==0)
    {
        return Atheism;
    }
    return -1;
}
