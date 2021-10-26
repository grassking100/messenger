#include "Creature.h"
#include "Tool.h"
#include "stdio.h"
#include "stdlib.h"
#include "Block.h"
void Creature::getBlessing(Building*b)
{
    int num=0;
    if(b->foodNumber()>100  &&(getEnergyCapacity()-getEnergy()>100))
    {
        num=100;
    }
    else
    {
        if(b->foodNumber()-(getEnergyCapacity()-getEnergy())>0)
        {
            num=getEnergyCapacity()-getEnergy();

        }
        else
        {
            num=b->foodNumber();
        }
    }
    b->takeFood(num);
    changeFood(num);
}
CountryType Creature::getType()const
{
    return type;
}
void Creature::reproduce(Creature *daughter,int mutationRate,Position pos)
{
    daughter->age=0;
    daughter->setLifeCapacity(life+randTwoSize(mutationRate));
    daughter->setEnergryCapacity(energy+randTwoSize(mutationRate));
    daughter->setAttack(attack+randTwoSize(mutationRate));
    daughter->setDefense(defense+randTwoSize(mutationRate));
    daughter->setAggressive(aggressive+randTwoSize(mutationRate));
    daughter->setLoyalty(loyalty+randTwoSize(mutationRate));
    daughter->setCountry(type);
    daughter->setPosition(pos);
    daughter->setBiasH(randTwoSize(biasBound));
//  daughter->setBiasH(-1);
    daughter->setBiasV(randTwoSize(biasBound));
    const int* likes=cgetLikes();
    int nLike[likeNum]= {};
    for(int i=0; i<likeNum; i++)
    {
        nLike[i]=rand()%3-1+likes[i];
    }
    daughter->setLikes(nLike);

    energy/=2;
}
bool Creature::wantDonate()const
{
    return loyalty*energy>10000 && energy>100;
}
void Creature::donate(Building *b)
{
    if(b->residue()>100)
    {
        b->giveFood(100);
        changeFood(-100);
    }
    else
    {
        if(getEnergy()>b->residue())
        {
            b->giveFood(b->residue());
            changeFood(-b->residue());
        }
        else
        {
            b->giveFood(getEnergy());
            changeFood(-getEnergy());
        }

    }
}
void Creature::buildHouse(Building *b)
{
    b->giveFood(100);
    b->setPosition(pos);
    changeFood(-100);
    b->setType(getType());
    // b.
}
char Creature::setLegend(int* text,int* backG)
{
    if(type==Catastrophe)
    {
        *text=BLACK;
        *backG=RED;
    }
    else if(type==Harmony)
    {
        *text=YELLOW;
        *backG=PINK;
    }
    else if(type==River)
    {
        *text=ORANGE;
        *backG=BLUE;
    }
    else if(type==Atheism)
    {
        *text=BLACK;
        *backG=YELLOW;
    }
    else
    {
        *text=RED;
        *backG=WHITE;
    }
    return 'P';
}
void Creature::rest(int typeB)
{
    if(!isDead())
    {
        if(typeB==GRASS)
        {
            if(type==Harmony)
            {
                  changeFood(2);
            }
            else if( type==River)
            {
                  changeFood(1);
            }
            else
            {
                  changeFood(3);
            }

        }
        else if(typeB==WATER)
        {
            if(type!=River)
            {
                changeLife(-1);
            }
            else
            {
                changeFood(1);
            }
        }
        else if(typeB==SNOW)
        {
            changeFood(-1);
             changeLife(1);
        }
        else if(typeB==LAVA)
        {
            changeLife(-100);
        }
        changeFood(-age/10000);
        age++;
    }

}
int Creature::getLike(int num)
{
    return like[num];
};
const int* Creature::cgetLikes()const
{
    return like;
};
void Creature::changeFood(int change)
{
    setValue(&energy,change,0,energyCapacity,Force);
}
void Creature::changeLife(int change)
{
    setValue(&life,change,0,lifeCapacity,Force);
}
void Creature::ShowInf() const
{
    char c[12];
    convertCountryToString(type,c);
    printf("Life: %d\nEnergy:%d\nAttack:%d\nDefense:%d\nLoyalty:%d\nAggressive:%d\n"
           "Age:%d\nCountry:%s\n",life,energy,  attack,defense,loyalty,aggressive,age,c);
}
void Creature::fight(Creature *c)
{

    if(aggressive>c->aggressive)
    {
        int attack1=attack-c->getDefense();
        changeFood(-attack/10);
        c->changeFood(-c->getDefense()/10);
        if(attack1>0)
        {
            c->changeLife(-attack1);
        }
    }
    else
    {
        int attack2=c->getAttack()-defense;
        changeFood(-defense/10);
        c->changeFood(-c->getAttack()/10);
        if(attack2>0)
        {
            changeLife(-attack2);
        }
    }
    if(isDead())
    {
        c->changeFood(energy);
        dead();
    }
    else if(c->isDead())
    {
        changeFood(c->getEnergy());
        c->dead();
    }
}
void Creature::setLike(int index,int _like)
{
    setValue(&like[index],_like,0,likeMax,Force);
};
void Creature::setLikes(const int* likes)
{
    for(int i=0; i<likeNum; i++)
    {
        setLike(i,likes[i]);
    }

};
void getBasicCreature(Creature *c)
{
    if(c!=0)
    {
        c->setAggressive(rand()%AggressiveMax);
        c->setAttack(rand()%AttackMax);
        c->setDefense(rand()%DefenseMax);
        c->setEnergryCapacity(rand()%EnergyMax);
        c->setLifeCapacity(rand()%LifeMax);
        c->setLoyalty(rand()%LoyaltyMax);

        c->setCountry(randomType());
        int  like[likeNum]= {};
        for(int i=0; i<likeNum; i++)
        {
            int v=rand()%likeMax;
            like[i]=v;
        }
        c->setLikes(like);
    }
}
void Creature:: setLifeCapacity(int v)
{
    setValue(&v,0,0,LifeMax,Force);
    lifeCapacity=v;
};
void Creature:: setEnergryCapacity(int v)
{
    setValue(&v,0,0,FoodMax,Force);
    energyCapacity=v;
};
void Creature:: setAttack(int v)
{
    setValue(&v,0,0,AttackMax,Force);
    attack=v;
};
void Creature::setDefense(int v)
{
    setValue(&v,0,0,DefenseMax,Force);
    defense=v;
};
void Creature:: setAggressive(int v)
{
    setValue(&v,0,0,AggressiveMax,Force);
    aggressive=v;
};
void Creature::setLoyalty(int v)
{
    setValue(&v,0,0,LoyaltyMax,Force);
    loyalty=v;
};
void Creature::setCountry(CountryType c)
{
    type=c;
};
const int Creature::getLifeCapacity()const
{
    return lifeCapacity;
}
const int Creature::getLife()const
{
    return life;
}
const int Creature::getEnergyCapacity()const
{
    return energyCapacity;
}
const int Creature::getEnergy()const
{
    return energy;
}
const int Creature::getAttack()const
{
    return attack;
}
const int Creature::getDefense()const
{
    return defense;
}
const int Creature::getAggressive()const
{
    return aggressive;
}
const int Creature::getLoyalty()const
{
    return loyalty;
}
const int Creature::getCountry()const
{
    return type;
}
const Position Creature:: cgetPosition()const
{
    return pos;
}
Position Creature:: getPosition()const
{
    return pos;
}
