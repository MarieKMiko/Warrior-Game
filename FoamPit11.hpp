/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
FoamPit11 class, a derived class from the Space class
 which represents the eleventh space in the Warrior Challenge
 game.
*******************************************/

#ifndef FOAMPIT11_HPP
#define FOAMPIT11_HPP
#include "Space.hpp"
#include "Player.hpp"

class FoamPit11: public Space
{
  private:
    int dropChance;

  public:
    FoamPit11(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
