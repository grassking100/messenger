#ifndef GROUND_H_INCLUDED
#define GROUND_H_INCLUDED
#include "Position.h"
#include <stdlib.h>
#include "Tool.h"
template <class T>
class Ground
{
private:
    const int startRow=0;
    const int startCol=0;
    int rowSize=0;
    int colSize=0;
    T** ground=0;
public:
    const Ground* getGround() const
    {
        return this;
    }

    const  int RowSize()const
    {
        return rowSize;
    };
    const   int ColSize()const
    {
        return colSize;
    };
    ~Ground();
    bool validate(const Position *pos)const
    {
        return checkValue(pos->row,0,rowSize-1) && checkValue(pos->col,0,colSize-1);
    };
    bool validate( Position pos)const
    {
        int rS=RowSize();
        int cS=ColSize();
        return checkValue(pos.row,0,rS-1) && checkValue(pos.col,0,cS-1);
    };
    Ground(int row,int col,auto initial);
    T*getObj(Position pos)
    {
        if(validate(pos))
        {
            return  &ground[pos.row][pos.col];

        }
        else
        {
            return 0;
        }

    }
    const  T*getObj(Position pos) const
    {
        if(validate(&pos))
        {
            return  &ground[pos.row][pos.col];

        }
        else
        {
            return 0;
        }
    }
    void up(Position* pos)
    {
        setValue(&pos->row,-1,0,rowSize-1,Force);
    };
    void down(Position* pos)
    {
        setValue(&pos->row,1,0,rowSize-1,Force);
    };
    void right(Position* pos)
    {
        setValue(&pos->col,1,0,rowSize-1,Force);
    };
    void left(Position* pos)
    {
        setValue(&pos->col,-1,0,rowSize-1,Force);
    };
    bool canUp( Position pos)
    {
        return checkValue(pos.row-1,0,rowSize-1);
    };
    bool canDown(Position pos)
    {
        return checkValue(pos.row+1,0,rowSize-1);
    };
    bool canRight(Position pos)
    {
        return checkValue(pos.col+1,0,rowSize-1);
    };
    bool canLeft(Position pos)
    {
        return checkValue(pos.col-1,0,rowSize-1);
    };
    void setPosition(Position *pos,Position change);


};

template <class T>
void Ground<T>::setPosition(Position *pos,Position change)
{
    setValue(&pos->row,change.row,0,RowSize()-1,Force);
    setValue(&pos->col,change.col,0,ColSize()-1,Force);
}
template <class T>
Ground<T>::Ground(int row,int col,auto initial)
{
    T** bp=(T**)malloc(sizeof(T*)*row);
    if(bp!=0)
    {
        for(int i=0; i<row; i++)
        {
            T* temp=(T*)malloc(sizeof(T)*col);
            if(temp!=0)
            {
                bp[i]=temp;
            }
            else
            {
                for(int j=0; j<i; j++)
                {
                    free(bp[j]);
                }
                free(bp);

            }
        }
        ground=bp;
        rowSize=row;
        colSize=col;
    }
    for(int i=0; i<rowSize; i++)
    {
        for(int j=0; j<colSize; j++)
        {
            ground[i][j]=initial;
        }
    }
}
template <class T>
Ground<T>::~Ground()
{
    for(int i=0; i<rowSize; i++)
    {
        free(ground[i]);
    }
    free(ground);
}


#endif // GROUND_H_INCLUDED
