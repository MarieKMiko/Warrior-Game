/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
MovingBridges9 class, a derived class from the Space class
 which represents the ninth space in the Warrior Challenge
 game.
*******************************************/

#ifndef MOVINGBRIDGES9_HPP
#define MOVINGBRIDGES9_HPP
#include "Space.hpp"
#include "Player.hpp"

class MovingBridges9: public Space
{
  private:
    int dropChance;
    int levels;

  public:
    MovingBridges9(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
