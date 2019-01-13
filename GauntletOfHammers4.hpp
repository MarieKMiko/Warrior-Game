/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Rings class, a derived class from the Space class
 which represents the fourth space in the Warrior Challenge
 game.
*******************************************/

#ifndef GAUNTLETOFHAMMERS4_HPP
#define GAUNTLETOFHAMMERS4_HPP
#include "Space.hpp"
#include "Player.hpp"

class GauntletOfHammers4: public Space
{
  private:
    int hammers;

  public:
    GauntletOfHammers4(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
