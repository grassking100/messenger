#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED
enum CountryType {Harmony,River,Catastrophe,Atheism,CountryNum};
CountryType randomType();
void convertCountryToString(int type,char * str);
int convertStringToCountry(int type,const char * str);
CountryType NumToCountryType(int i);
class CountryInfo
{
private:
    int life=0;
    int lifeC=0;
    int energyC=0;
    int energy=0;
    int aggressive=0;
    int attack=0;
    int defense=0;
    int count=0;
    CountryType type;
    int loyalty=0;
    int age=0;
public:
    CountryInfo(CountryType _type)
    {
        type=_type;
    }
    void clean()
    {
        lifeC=0;
        energyC=0;
        life=0;
        energy=0;
        aggressive=0;
        attack=0;
        defense=0;
        count=0;
        loyalty=0;
        age=0;
    }
    void addLife(int i)
    {
        life+=i;
    };
    void addAge(int i)
    {
        age+=i;
    };
    void addLifeC(int i)
    {
        lifeC+=i;
    };
    void addEnergyC(int i)
    {
        energyC+=i;
    };

    void addEnergy(int i)
    {
        energy+=i;
    };
    void addAggressive(int i)
    {
        aggressive+=i;
    };
    void addDefense(int i)
    {
        defense+=i;
    };
    void addAttack(int i)
    {
        attack+=i;
    };
    void addCount(int i)
    {
        count+=i;
    };
    void addLoyalty(int i)
    {
        loyalty+=i;
    };
    int getLife()const
    {
        return life;
    };
    int getLifeC()const
    {
        return lifeC;
    };
    int getEnergy()const
    {
        return energy;
    };
    int getEnergyC()const
    {
        return energyC;
    };
    int getAggressive()const
    {
        return aggressive;
    };
    int getDefense()const
    {
        return defense;
    };
    int getAttack()const
    {
        return attack;
    };
    int getCount()const
    {
        return count;
    };
    int getLoyalty()const
    {
        return loyalty;
    };
    CountryType getType()const
    {
        return type;
    };
    int getAge()const
    {
        return age;
    };
};
#endif // COUNTRY_H_INCLUDED
