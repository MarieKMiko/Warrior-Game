/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for GauntletOfHammers4, a derived
class of type Space which represents the fourth space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "GauntletOfHammers4.hpp"
#include "Rings3.hpp"
#include "DeepDive8.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for GauntletOfHammers4, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
GauntletOfHammers4:: GauntletOfHammers4(Player* warrior): Space(player)
{
 player=warrior;
 up=nullptr;
 right= nullptr;
 flagColor="red";
 useUpper=2;
 useLower=3;
 upRand=rand()%3+1;
 lowRand=rand()%3+1;
 position=4;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void GauntletOfHammers4::seeObstacle()
{
  cout<<"*** The Gauntlet Of Hammers ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void GauntletOfHammers4::showInfo()
{
  cout<<"You are now at the Gauntlet Of Hammers"<<endl;
  cout<<"You will have to duck and dodge to avoid being smashed."<<endl;
  cout<<"How many hammers do you think you can avoid?"<<endl;
  cout<<"Choose from 1-10"<<endl;
  hammers=intValid(1,10);
  seeFlag=rand()%10+hammers;
  cout<<"There will be "<<hammers<<" hammers in the gauntlet,"<<endl;
  cout<<"and you will have a "<<hammers*10<<"% chance of finding a flag."<<endl;
  cout<<"This will take "<<useUpper<<" points in upper body and "<<endl;
  cout<<useLower<<" points in lower body strength."<<endl;
  cout<<"Ready, "<<player->getName()<<"?"<<endl;
  go();
}

/*******************************************************************
                    go
This function starts the user through the obstacle in this space.
The upper and lower body strength needed are subtracted from the player->
*******************************************************************/
void GauntletOfHammers4::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a red flag
    if (seeFlag>9)
    {
      cout<<"You spot a red flag on the hammer- grab it!"<<endl;
      player->addFlag(flagColor);
    }

    power=rand()%hammers+1;
    if (power<=2)
    {
      cout<<"You spot a power boost behind a hammer- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }
    else
    {
      cout<<"There are so many hammers, you can't find a power boost."<<endl;
    }

    cout<<"You made it past the hammers!"<<endl;
    left=new Rings3(player);
    down=new DeepDive8(player);
    //shows map again and displays next choices
    printMap();

  }
  //if the Player does not have enough strength the do the obstacle
  else
  {
    cout<<"You don't have the necessary strength to complete this task."<<endl;
    cout<<"With your limited strength, you fall on your face."<<endl;
    cout<<"Sorry, game over!"<<endl;
    //the game is over
    player->gameOver(1);
  }

}
