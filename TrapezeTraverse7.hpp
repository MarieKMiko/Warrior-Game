/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
TrapezeTraverse7 class, a derived class from the Space class
 which represents the seventh space in the Warrior Challenge
 game.
*******************************************/

#ifndef TRAPEZETRAVERSE7_HPP
#define TRAPEZETRAVERSE7_HPP
#include "Space.hpp"
#include "Player.hpp"

class TrapezeTraverse7: public Space
{
  private:
    int dropChance;
    int trick;

  public:
    TrapezeTraverse7(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
