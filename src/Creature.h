#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED
#include "Position.h"
#include "Country.h"
#include "Block.h"
#include "Building.h"
const int LifeMax=1000;
const int EnergyMax=1000;
const int AttackMax=1000;
const int DefenseMax=1000;
const int AggressiveMax=1000;
const int LoyaltyMax=100;
const int likeMax=10;
const int likeNum=CountryNum*2+BlockNumber;
const int biasBound=1;
class Creature
{
private:
    Position pos;
    int life=0;
    int lifeCapacity=0;
    int energy=0;
    int energyCapacity=0;
    int attack=0;
    int defense=0;
    int age=0;
    int aggressive=0;
    int loyalty=50;
    CountryType type=Atheism;
    int like[likeNum]= {0};
    int biasH=0;
    int biasV=0;
public:
    void setPosition(Position _pos)
    {
        pos=_pos;
    };
    void addInfo(CountryInfo * info)
    {
        info->addLife(life);
        info->addEnergy(energy);
        info->addAggressive(aggressive);
        info->addAttack(attack);
        info->addDefense(defense);
        info->addLoyalty(loyalty);
        info->addCount(1);
        info->addLifeC(lifeCapacity);
        info->addEnergyC(energyCapacity);
        info->addAge(age);
    }
    void setBiasH(int b)
    {
        setValue(&biasH,b,-biasBound,biasBound,Force);
    };
    int  getBiasH()
    {
        return biasH;
    };
    void setBiasV(int b)
    {
        setValue(&biasV,b,-biasBound,biasBound,Force);
    };
    int  getBiasV()
    {
        return biasV;
    };
    void donate(Building *b);
    void setAge(int num) {};
    const int* cgetLikes()const;
    void setLifeCapacity(int v);
    void setEnergryCapacity(int v);
    void setAttack(int v);
    void setDefense(int v);
    void setAggressive(int v);
    void setLoyalty(int v);
    void setCountry(CountryType c);
    const Position cgetPosition()const;
    Position getPosition()const;
    const int getLifeCapacity()const;
    const int getLife()const;
    void setLike(int index,int like);
    void setLikes(const int* likes);
    const int getEnergyCapacity()const;
    const int getEnergy()const;
    const int getAttack()const;
    const int getDefense()const;
    const int getAggressive()const;
    const int getLoyalty()const;
    const int getCountry()const;
    bool isDead() const
    {
        return life<=0 || energy<=0;
    };
    void dead()
    {
        life=0;
        energy=0;
    };
    int getAge()
    {
        return age;
    };
    void rest(int typeB);
    void changeFood(int change);
    void ShowInf() const;
    void changeLife(int change);
    void birth()
    {
        life=lifeCapacity/2;
        energy=energyCapacity/2;
    };
    bool wantFight(const Creature* c)const
    {

        if(type==c->getType() && type==Harmony)
        {
            return false;
        }
     return (aggressive<life+defense+attack )||(c->getAggressive()<+c->getLife()+c->getDefense()+c->getAttack());
    };
    void fight(Creature *c);
    char setLegend(int* text,int* backG);
    void reproduce(Creature *daughter,int mutationRate,Position pos);
    bool wantReproduct()
    {
        return energy==energyCapacity&& !isDead();
    };
    bool wantDonate()const;
    void buildHouse(Building *b);
    int getLike(int num);
    CountryType getType()const ;
    void getBlessing(Building*b);
};
void getBasicCreature(Creature *c);

#endif // CREATURE_H_INCLUDED
