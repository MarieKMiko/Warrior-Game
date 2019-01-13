/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:
*******************************************/
#include <iostream>
#include <ctime>
#include "Menu.hpp"
#include "intValid.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "Myrtle.hpp"
#include "Elliott.hpp"
#include "Cecily.hpp"
#include "Hulk.hpp"
#include "Xena.hpp"


using std::cout;
using std::endl;
/*******************************************************************
                  constructor
*******************************************************************/
Menu::Menu()
{
    std::srand(std::time(0));
    cout<<"****** Welcome to WARRIOR CHALLENGE! ********"<<endl;
    cout<<endl;
    cout<<"The goal of this game is to get though the board, "<<endl;
    cout<<"go all the way to space #12, and exit!"<<endl;
    cout<<endl;
    cout<<"You must gather a red, blue, and green flag along the way."<<endl;
    cout<<endl;
    cout<<"If you do not have enough strength to complete an obstacle,"<<endl;
    cout<<"you will fall on your face and lose the game."<<endl;
    cout<<endl;
    cout<<"Ready to play?"<<endl;

    cout<<endl;
    cout<<"1) Play"<<endl;
    cout<<"2) Exit"<<endl;

    int choice=intValid(1,2);
    if (choice==1)
    {
        playGame();
    }
    else if (choice==2)
    {
      cout<<"Goodbye."<<endl;
    }

}

/*******************************************************************
                playGame
If the user chooses to play the game at the start of the Menu,
this function is called.  It loops for each time the user says
they want to play a new game.
*******************************************************************/
void Menu::playGame()
{
  bool playAgain=true;
  while (playAgain==true)
  {
    cout<<"Please choose your player."<<endl;
    choosePlayer();
    cout<<"Let's get started!"<<endl;
    //creates new WallClimb1 and passes Player pointer as a parameter
    start= new WallClimb1(person);
    //showInfo for WallClimb1 space- begins game
    start->showInfo();
    //prompt when game is complete
    cout<<"Play again?"<<endl;
    cout<<"1) Yes"<<endl;
    cout<<"2) No"<<endl;
    int play=intValid(1,2);
    if (play==2)
    {
      playAgain=false;
    }
    //loops again if player chooses to play again
  }
}

/*******************************************************************
                choosePlayer
This function allows the user to see information about possible
character choices.  Once the user has read about the characters
they are considering, they make a choice as to the person they
will be as they go through the course.
*******************************************************************/
void Menu::choosePlayer()
{
  cout<<"Which player do you want?"<<endl;
  cout<<"1) Myrtle (challenging)"<<endl;
  cout<<"2) Elliott (medium)"<<endl;
  cout<<"3) Cecily (medium)"<<endl;
  cout<<"4) Hulk (easy)"<<endl;
  cout<<"5) Xena (easy)"<<endl;

  int playerChoice=intValid(1,5);

  if (playerChoice==1)
  {
      person= new Myrtle();
  }
  else if (playerChoice==2)
  {
    person = new Elliott();
  }
  else if (playerChoice==3)
  {
    person= new Cecily();
  }
  else if (playerChoice==4)
  {
    person = new Hulk();
  }
  else if (playerChoice==5)
  {
    person = new Xena();
  }
  //show information about this Player type
  person->displayInfo();
}
/*******************************************************************
                  destructor
*******************************************************************/
Menu::~Menu(){}
