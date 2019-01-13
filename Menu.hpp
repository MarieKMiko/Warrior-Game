/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Menu class, which gives user input options for the Warrior
challenge game.
*******************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "Player.hpp"
#include "Space.hpp"
#include "WallClimb1.hpp"

class Menu
{
  private:
    Player* person;
    WallClimb1* start;

  public:
    Menu();
    ~Menu();
    void playGame();
    void choosePlayer();

};

#endif
