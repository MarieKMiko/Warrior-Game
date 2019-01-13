/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Zipline class, a derived class from the Space class
 which represents the fifth space in the Warrior Challenge
 game.
*******************************************/

#ifndef ZIPLINE5_HPP
#define ZIPLINE5_HPP
#include "Space.hpp"
#include "Player.hpp"

class Zipline5: public Space
{
  private:
    int zipChance;

  public:
    Zipline5(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
