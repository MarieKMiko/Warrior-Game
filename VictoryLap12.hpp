/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
VictoryLap12 class, a derived class from the Space class
 which represents the twelfth space in the Warrior Challenge
 game.
*******************************************/

#ifndef VICTORYLAP12_HPP
#define VICTORYLAP12_HPP
#include "Space.hpp"
#include "Player.hpp"

class VictoryLap12: public Space
{
  private:
    int laps;

  public:
    VictoryLap12(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
