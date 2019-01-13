/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
DeepDive8 class, a derived class from the Space class
 which represents the eighth space in the Warrior Challenge
 game.
*******************************************/

#ifndef DEEPDIVE8_HPP
#define DEEPDIVE8_HPP
#include "Space.hpp"
#include "Player.hpp"

class DeepDive8: public Space
{
  private:
    int water;
    bool diveAgain;

  public:
    DeepDive8(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
