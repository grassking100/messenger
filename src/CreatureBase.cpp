#include "CreatureBase.h"
#include "stdio.h"
void CreatureBase::batchConsciousMove(const Map*m,const City *b)
{
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        Creature* cp=&(*it);
        consciousMove(cp,m,b);
    }
}
void CreatureBase::setCountrysInfo(char info[][30],int* size)
{
    int HarmonyCount=0;
    int CatastropheCount=0;
    int RiverCount=0;
    int AtheismCount=0;
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        Creature* cp=&(*it);
        CountryType ct=cp->getType();
        switch((int)ct)
        {
        case Harmony:
        {
            HarmonyCount++;
            break;
        }
        case Catastrophe:
        {
            CatastropheCount++;
            break;
        }
        case River:
        {
            RiverCount++;
            break;
        }
        case Atheism:
        {
            AtheismCount++;
            break;
        }
        }

        char temp[30];
        strcpy(info[0],"Country info");

        sprintf(temp,"  Harmony count:%5d",HarmonyCount);
        strcpy(info[1],temp);

        sprintf(temp,"  Catastrophe count:%5d",CatastropheCount);
        strcpy(info[2],temp);

        sprintf(temp,"  River count:%5d",RiverCount);
        strcpy(info[3],temp);

        sprintf(temp,"  Atheism count:%5d",AtheismCount);
        strcpy(info[4],temp);
        *size=5;
    }
}
void CreatureBase::consciousMove(Creature *c,const Map*m,const City *b)
{
    int ver=0,hor=0;
    int start=0;
    const int size=1;
    for(int i=-size; i<=size; i++)
    {
        for(int j=-size; j<=size; j++)
        {
            int setN=0;
            Position p(c->getPosition().row+i,c->getPosition().col+j);
            if(g->validate(&p))
            {
                if(b->hasBuilding(p))
                {
                    int type=b->getBuilding(p)->getType();
                    setN=c->getLike(type);
                }
                else
                {
                    start+=BlockNumber;
                    if( hasCreature(p))
                    {
                        int type= getCreature(p)->getType();
                        setN=c->getLike(type+start);
                    }
                    else
                    {
                        start+=CountryNum;
                        int ct=m->getBlock(p)->type;
                        setN=c->getLike(ct+start);
                    }
                }
            }

            if(i!=0)
            {
                ver+=(setN*(i/abs(i)));
            }
            if(j!=0)
            {
                hor+=(setN*(j/abs(j)));
            }
            setN=0;
            start=0;
        }
    }
    int netVer=0,netHor=0;
    ver=c->getBiasV()+ver;
    hor=c->getBiasH()+hor;
    if(ver!=0)
    {
        netVer=ver/abs(ver);
    }
    if(hor!=0)
    {
        netHor=hor/abs(hor);
    }
    Position p( netVer,netHor);
    move(c,p);
}
void  CreatureBase::batchBuilding(City*city)
{
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        Creature* cp=&(*it);
        if(cp->wantDonate())
        {
            Building b;
            if(!city->hasBuilding(cp->getPosition()) && city->localBuildingNum(cp->getPosition())<2)
            {
                cp->buildHouse(&b);
                city->add(&b);
            }
        }

        Building *bp=city->getBuilding(cp->getPosition());
        if(bp!=0)
        {
            if(cp->wantDonate() && cp->getType()==bp->getType())
            {
                cp->donate(bp);
            }
            else
            {
                cp->getBlessing(bp);
            }
        }
    }
}
const Ground<Creature*>* CreatureBase::getGround()const
{
    return g->getGround();
}
CreatureBase::CreatureBase(int row,int col)
{
    Creature*cp=0;
    g=new Ground<Creature*>(row,col,cp);

};

void CreatureBase::add(Creature *c)
{
    Position pos= c->getPosition();
    Creature **cp=g->getObj(pos);
    if( g->validate(&pos) &&*cp ==0)
    {
        farm.push_back(*c);
        *cp=&farm.back();
    }
};
void CreatureBase::randomMove(Creature *c)
{
    Position pN(rand()%3-1,rand()%3-1);
    move(c,pN);
};
void CreatureBase::move(Creature *c,Position change)
{
    Position pN=c->getPosition();
    g->setPosition(&pN,change);
    if(!hasCreature(pN))
    {
        *g->getObj(c->getPosition())=0;
        c->setPosition(pN);
        *g->getObj(pN)=c;
    }
};
void CreatureBase::batchRest(const Ground<Block> *g)
{
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        Creature *cp=&(*it);
        const Block *bp=g->getObj(cp->getPosition());
        cp->rest(bp->type);
    }
}
void CreatureBase::batchReproduct()
{
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        Creature *cp=&(*it);
        if(cp->wantReproduct())
        {
            Position p(cp->getPosition().row+1,cp->getPosition().col);
            if(g->validate(&p)&& !hasCreature(p))
            {
                Creature c;
                cp->reproduce(&c,10,p);
                c.birth();
                add(&c);
            }
        }
    }
}
void CreatureBase::batchMove()
{
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        Creature *cp=&(*it);
        randomMove(cp);

    }
}
void CreatureBase::PrintMap()const
{
    for(int i=0; i<g->RowSize(); i++)
    {
        for(int j=0; j<g->ColSize(); j++)
        {
            Position pos(i,j);
            Creature** cp=g->getObj(pos);
            if(*cp!=0)
            {
                char name[20];
                convertCountryToString((*cp)->getCountry(),name);
                printf("%s",name);
            }
            else
            {
                //printf("0");
            }


        }
        //   printf("\n");
    }
}
void CreatureBase::batchFight()
{
    for ( std::list<Creature>::iterator it = farm.begin() ; it != farm.end(); ++it)
    {
        int startR =-1,startC=-1,endR=1,endC=1;
        Creature *cp=&(*it);
        Position pos=cp->getPosition();
        if(!g->canUp(pos))
        {
            startR=0;
        }
        if(!g->canDown(pos))
        {
            endR=0;
        }
        if(!g->canLeft(pos))
        {
            startC=0;
        }
        if(!g->canRight(pos))
        {
            endR=0;
        }
        for(int r=startR; r<=endR; r++)
        {
            for(int c=startC; c<=endC; c++)
            {
                Position posN(pos.row+r,pos.col+c);
                if(g->validate(&posN))
                {
                    if(hasCreature(posN) && !(r==0 && c==0))
                    {
                        Creature *target=getCreature(posN);
                        if(target!=0 &&cp->wantFight(target))
                        {
                            cp->fight(target);
                        }
                    }
                }

            }
        }

    }

}
void CreatureBase::updateInfos()
{
    for(int i=0; i<CountryNum; i++)
    {
        infos[i].clean();
    }
    for (std::list<Creature>::iterator it=farm.begin(); it!=farm.end(); ++it)
    {
        Creature* cp=&(*it);
        cp->addInfo(&infos[cp->getType()]);
    }
}
bool isDead(const Creature& c)
{
    return c.isDead();
};
