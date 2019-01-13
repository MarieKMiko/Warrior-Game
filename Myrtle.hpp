/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Myrtle class, a derived class from the Player class.
*******************************************/

#ifndef MYRTLE_HPP
#define MYRTLE_HPP
#include "Player.hpp"
#include <string>

using std::string;

class Myrtle: public Player
{
  private:
    std::string name;

  public:
    Myrtle();
    void displayInfo();
    std::string getName();
};


#endif
