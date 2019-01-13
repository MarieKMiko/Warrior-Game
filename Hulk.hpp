/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Hulk class, a derived class from the Player class.
*******************************************/

#ifndef HULK_HPP
#define HULK_HPP
#include "Player.hpp"
#include <string>

using std::string;

class Hulk: public Player
{
  private:
    std::string name;

  public:
    Hulk();
    void displayInfo();
    std::string getName();
};


#endif
