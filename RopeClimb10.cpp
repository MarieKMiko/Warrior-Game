/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for RopeClimb10, a derived
class of type Space which represents the third space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "RopeClimb10.hpp"
#include "MovingBridges9.hpp"
#include "FoamPit11.hpp"
#include "Snakepit6.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for RopeClimb10, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
RopeClimb10::RopeClimb10(Player* warrior):Space(player)
{
  player=warrior;
 down=nullptr;
 flagColor="green";
 useUpper=5;
 useLower=1;
 seeFlag=rand()%5+1;
 upRand=rand()%4+1;
 lowRand=rand()%4+1;
 power=rand()%5+1;
 position=10;
 dropChance=rand()%3+1;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void RopeClimb10::seeObstacle()
{
  cout<<"*** Rope Climb ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void RopeClimb10::showInfo()
{
  cout<<"You are now at Rope Climb."<<endl;
  cout<<"Climb to the top to check for a flag!"<<endl;
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
void RopeClimb10::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    cout<<"Climb, climb, climb!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a blue flag
    if (seeFlag>1)
    {
      cout<<"You spot a green flag at the top- grab it!"<<endl;
      player->addFlag(flagColor);
    }
    //chance of dropping a flag
    if (dropChance==1)
    {
      player->dropFlag();
    }

    if (power>1)
    {
      cout<<"You spot a power boost at the top of the rope- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }
    up=new Snakepit6(player);
    left=new MovingBridges9(player);
    right= new FoamPit11(player);
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
