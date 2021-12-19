#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Position.h"
#include "Climate.h"
struct Player
{
    public:
    Position pos;
    int row,col;
    int dust=0;
    int dustMax=100;
    int type=0;
    int magic=5;
    int magicCapacity=100;
    Player(int _row,int _col)
    {
        row=_row;
        col=_col;
    }
       void playerChangeClimate(Climate* cl,char input);
    void setPlayerMovement(char input);
    private:
    bool playerCanGoUp();
    bool playerCanGoDown();
    bool playerCanGoLeft();
    bool playerCanGoRight();


};


#endif // PLAYER_H_INCLUDED
