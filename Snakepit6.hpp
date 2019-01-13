/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Snakepit6 class, a derived class from the Space class
 which represents the sixth space in the Warrior Challenge
 game.
*******************************************/

#ifndef SNAKEPIT6_HPP
#define SNAKEPIT6_HPP
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Snakepit6: public Space
{
  private:
    int dropChance;
    int snakes;
    std::string flagColor2;
    std::string flagColor3;
    int biteChance;

  public:
    Snakepit6(Player*);
    void showInfo();
    void go();
    void seeObstacle();

};


#endif
