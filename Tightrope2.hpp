/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Tightrope class, a derived class from the Space class
 which represents the second space in the Warrior Challenge
 game.
*******************************************/

#ifndef Tightrope2_HPP
#define Tightrope2_HPP
#include "Space.hpp"
#include "Player.hpp"

class Tightrope2: public Space
{
  private:
    int dropChance;
    int sitChance;

  public:
    Tightrope2(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
