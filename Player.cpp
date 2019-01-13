/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

using std::cout;
using std::endl;
using std::string;

/*******************************************************************
                  constructor
*******************************************************************/
Player::Player()
{
  winningColors=false;
}

/*******************************************************************
                      getUStrength
This function returns the value of the player's upper body strength.
*******************************************************************/
int Player::getUStrength()
{
  return upper;
}
/*******************************************************************
                  getLStrength
This function returns the value of the player's lower body strength.
*******************************************************************/
int Player::getLStrength()
{
  return lower;
}
/*******************************************************************
                  subUStrength
This function takes an int parameter and subtracts that value from
the player's upper body strength.
*******************************************************************/
void Player::subUStrength(int minus)
{
  upper= upper-minus;
}
/*******************************************************************
                  subLStrength
This function takes an int parameter and subtracts that value from
the player's lower body strength.
*******************************************************************/
void Player::subLStrength(int minus)
{
  lower=lower-minus;
}
/*******************************************************************
                  addUStrength
This function takes an int parameter and adds that value to
the player's upper body strength.
*******************************************************************/
void Player::addUStrength(int plus)
{
  upper=upper+plus;
}
/*******************************************************************
                  addLStrength
This function takes an int parameter and adds that value to
the player's lower body strength.
*******************************************************************/
void Player::addLStrength(int plus)
{
  lower=lower+plus;
}

/*******************************************************************
                    addFlag
This function is called when a player finds a flag in a Space.
The color of the flag is added as a string to the vector.
*******************************************************************/
void Player::addFlag(std::string color)
{
  flags.push_back(color);
}

/*******************************************************************
                    dropFlag
This function is called by some Spaces when the player drops a flag.
The most recently added flag to the vector is dropped.
*******************************************************************/
void Player::dropFlag()
{
  if (!flags.empty())
  {
    cout<<"Oh no, watch your flag!"<<endl;
    cout<<"You have dropped a flag into the abyss."<<endl;
    flags.pop_back();
    //ensure that checkFlags checks the most recent status
    winningColors=false;
  }
}

/*******************************************************************
                    checkFlags
This function checks the flags saved in the vector as strings.
If there is at least one green, red, and blue flag, the function
returns "true." If not, it returns "false."  Flags gathered are
displayed in a list of colors.
*******************************************************************/
bool Player::checkFlags()
{
  //looking for all three colors
  std::string target1= "green";
  std::string target2= "red";
  std::string target3= "blue";
  bool hasGreen=false;
  bool hasRed=false;
  bool hasBlue=false;
  if (flags.empty())
  {
    cout<<"You haven't gathered any flags."<<endl;
  }
  else
  {
    int size=flags.size();
    cout<<"You have gathered "<<size<<" flags in the following colors:"<<endl;
    cout<<endl;
    for (int i=0; i<size; i++)
    {
      cout<<flags[i]<<endl;
      if (flags[i]==target1)
      {
        //if a green flag is found
        hasGreen=true;
      }
      else if(flags[i]==target2)
      {
        //if a red flag is found
        hasRed=true;
      }
      else if (flags[i]==target3)
      {
        //if a blue flag is found
        hasBlue=true;
      }
    }
    //if the vector has a green and a red flag
    if ((hasGreen==true)&&(hasRed==true))
    {
      //and also a blue flag
      if (hasBlue==true)
      {
        //all colors are present
        cout<<"You have gathered all three colors!"<<endl;
        //bool winningColors is changed to true
        winningColors=true;
      }
    }
  }
  cout<<endl;
  return winningColors;
}
/*******************************************************************
                    gameOver
This function is called when the game ends and the player has not
won.  It shows the user what the final stats were for flags and
strength.  The Menu class will then ask the user if they want
to play again.
*******************************************************************/
void Player::gameOver(int reason)
{
  //if the reason is due to a loss of strength in the game
  if (reason==1)
  {
    cout<<"That's it for you! Let's see how you did."<<endl;
    bool ohWell=checkFlags();
    if (ohWell==true)
    {
      cout<<"That's too bad!  You had the flags."<<endl;
    }
  }
  else if (reason==2)
  {
    //will display for loss of strength or for exiting after space #12
    cout<<"You were left with "<<upper<<" points in upper body strength"<<endl;
    cout<<"and "<<lower<<" points in lower body strength."<<endl;
    cout<<"Better luck next time!"<<endl;
  }
  else if (reason==3)
  {
    cout<<endl;
    cout<<"Congratulations, winner!"<<endl;
  }
}
/*******************************************************************
                    wonGame
This function is called when the player reaches Space #12
(VictoryLap12) and chooses to exit the board.  The player's flags
are checked to ensure one of each color is in the vector.  If so,
they have won the game.  If not, gameOver is called.
*******************************************************************/
void Player::wonGame()
{
  cout<<"You have made it to the end of the course!"<<endl;
  cout<<"But did you gather a flag in three different colors?"<<endl;
  if (checkFlags())
  {
    cout<<"You have won the WARRIOR CHALLENGE!!!"<<endl;
    cout<<endl;
  cout<<  "    _______________"<<endl;
  cout<<  "   |@@@@|     |####|"<<endl;
  cout<<  "   |@@@@|     |####|"<<endl;
  cout<<  "   |@@@@|     |####|"<<endl;
  cout<<  "   |@@@@|     |####/"<<endl;
  cout<<  "    |@@@|     |###/"<<endl;
  cout<<  "     `@@|_____|##'"<<endl;
  cout<<  "          (O)"<<endl;
  cout<<  "       .-'''''-."<<endl;
  cout<<  "     .'  * * *  `."<<endl;
  cout<<  "    :  *       *  :"<<endl;
  cout<<  "   : ~  WARRIOR  ~ :"<<endl;
  cout<<  "   : ~ CHALLENGE ~ :"<<endl;
  cout<<  "    :  *   #1  *  :"<<endl;
  cout<<  "     `.  * * *  .'"<<endl;
  cout<<  "       `-.....-'"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<  "       Credit:  asciiart.eu "<<endl;
  cout<<  "       Art by Joan G. Stark"<<endl;

  gameOver(3);
  }
  else
  {
    cout<<"Sorry, you did not gather the needed flags!"<<endl;
    //parameter passed to gameOver is 2 because flags have already been checked
    gameOver(2);
  }
}
/*******************************************************************
                    destructor
*******************************************************************/
Player::~Player()
{}
