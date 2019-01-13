/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Space class, an abstract class for the different spaces
in the Warrior Challenge game.
*******************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Player.hpp"

using std::string;

class Space
{
  protected:
    Player* player;
    Space* right;
    Space* left;
    Space* up;
    Space* down;
    int position;
    int seeFlag;
    std::string flagColor;
    int upRand;
    int lowRand;
    int useUpper;
    int useLower;
    int power;


  public:
    Space(Player*);
    ~Space();
    void move();
    void printMap();
    virtual void go()=0;
    virtual void showInfo()=0;
    virtual void seeObstacle()=0;


};


#endif
