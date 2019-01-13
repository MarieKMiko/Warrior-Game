/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Cecily class, a derived class from the Player class.
*******************************************/

#ifndef CECILY_HPP
#define CECILY_HPP
#include "Player.hpp"
#include <string>

using std::string;

class Cecily: public Player
{
  private:
    std::string name;

  public:
    Cecily();
    void displayInfo();
    std::string getName();
};


#endif
