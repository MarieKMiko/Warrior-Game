/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
RopeClimb10 class, a derived class from the Space class
 which represents the tenth space in the Warrior Challenge
 game.
*******************************************/

#ifndef ROPECLIMB10_HPP
#define ROPECLIMB10_HPP
#include "Space.hpp"
#include "Player.hpp"

class RopeClimb10: public Space
{
  private:
    int dropChance;

  public:
    RopeClimb10(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
