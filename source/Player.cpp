#include "Player.h"
#include "Tool.h"
bool Player::playerCanGoUp()
{
    return  checkValue(pos.row-1,0,row-1);
}
bool Player::playerCanGoDown()
{
    return  checkValue(pos.row+1,0,row-1);
}
bool Player::playerCanGoLeft()
{
    return  checkValue(pos.col-1,0,col-1);
}
bool Player::playerCanGoRight()
{
    return  checkValue(pos.col+1,0,col-1);
}
void Player::setPlayerMovement(char input)
{
    if(checkInput(input,'w') )
    {
        if(playerCanGoUp())
        {
            pos.row-=1;
        }
    }
    else if(checkInput(input,'a') )
    {
        if(playerCanGoLeft())
        {
            pos.col-=1;
        }
    }
    else if(checkInput(input,'s') )
    {
        if(playerCanGoDown())
        {

            pos.row+=1;
        }
    }
    else if(checkInput(input,'d') )
    {
        if(playerCanGoRight())
        {
            pos.col+=1;
        }
    }
    else if(checkInput(input,'p'))
    {
        input=' ';
        while(checkInput(input,' ') )
        {
            inputEvent(&input);
        }
    }
}
void Player::playerChangeClimate(Climate* cl,char input)
{
    if(magic>0)
    {
        if(checkInput(input,'j'))
        {
            cl->setHumidity(10);
            magic--;
        }
        else if(checkInput(input,'k'))
        {
            cl->setHumidity(-10);
            magic--;
        }
        else if(checkInput(input,'n'))
        {
            cl->setTemparature(-10);
            magic--;
        }
        else if(checkInput(input,'m'))
        {
            cl->setTemparature(10);
            magic--;
        }
        else if(checkInput(input,'8'))
        {
            cl->setSeaLevel(1);
            magic--;
        }
        else if(checkInput(input,'2'))
        {
            cl->setSeaLevel(-1);
            magic--;
        }
    }
}
