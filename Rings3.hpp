/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Rings class, a derived class from the Space class
 which represents the third space in the Warrior Challenge
 game.
*******************************************/

#ifndef RINGS3_HPP
#define RINGS3_HPP
#include "Space.hpp"
#include "Player.hpp"

class Rings3: public Space
{
  private:
    int dropChance;
    int hangChance;

  public:
    Rings3(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
