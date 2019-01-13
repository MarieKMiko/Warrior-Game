/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Xena class, a derived class from the Player class.
*******************************************/

#ifndef XENA_HPP
#define XENA_HPP
#include "Player.hpp"
#include <string>

using std::string;

class Xena: public Player
{
  private:
    std::string name;

  public:
    Xena();
    void displayInfo();
    std::string getName();
};


#endif
