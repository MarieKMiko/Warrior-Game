/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
WallClimb class, a derived class from the Space class
 which represents the first space in the Warrior Challenge
 game.
*******************************************/

#ifndef WALLCLIMB1_HPP
#define WALLCLIMB1_HPP
#include "Space.hpp"
#include "Player.hpp"

class WallClimb1: public Space
{
  private:
    int dropChance;

  public:
    WallClimb1(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
