/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Elliott class, a derived class from the Player class.
*******************************************/

#ifndef ELLIOTT_HPP
#define ELLIOTT_HPP
#include "Player.hpp"
#include <string>

using std::string;

class Elliott: public Player
{
  private:
    std::string name;

  public:
    Elliott();
    void displayInfo();
    std::string getName();
};


#endif
