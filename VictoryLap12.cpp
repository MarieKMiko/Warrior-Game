/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for VictoryLap12, a derived
class of type Space which represents the third space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "VictoryLap12.hpp"
#include "DeepDive8.hpp"
#include "FoamPit11.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for VictoryLap12, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
VictoryLap12::VictoryLap12(Player* warrior): Space(player)
{
  player=warrior;
 down=nullptr;
 right= nullptr;
 flagColor="blue";
 useUpper=1;
 useLower=2;
 seeFlag=rand()%3+1;
 upRand=rand()%4+1;
 lowRand=rand()%4+1;
 power=rand()%3+1;
 position=12;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void VictoryLap12::seeObstacle()
{
  cout<<"*** Victory Lap ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void VictoryLap12::showInfo()
{
  cout<<"You are now at the Victory Lap."<<endl;
  cout<<"You will have a chance to exit the course when you are done."<<endl;
  cout<<"Each lap will give you a chance to gain a flag."<<endl;
  cout<<"But will take the same number of strength points."<<endl;
  cout<<"1 upper body strength point per lap."<<endl;
  cout<<"And 2 lower body strength points per lap."<<endl;
  cout<<"How many victory laps do you want to take? (1-5)"<<endl;
  laps=intValid(1,5);
  cout<<"This will take "<<useUpper*laps<<" points in upper body and "<<endl;
  cout<<useLower*laps<<" points in lower body strength."<<endl;
  cout<<"Ready, "<<player->getName()<<"?"<<endl;
  go();
}

/*******************************************************************
                    go
This function starts the user through the obstacle in this space.
The upper and lower body strength needed are subtracted from the player->
*******************************************************************/
void VictoryLap12::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper*laps)&&(player->getLStrength()>=useLower*laps))
  {
    for(int i=0; i<laps; i++)
    {
      cout<<"Go "<<player->getName()<<", go!!!"<<endl;
      cout<<"Run, run, run!"<<endl;
      //subtracts the strength required from the Player
      player->subUStrength(useUpper);
      player->subLStrength(useLower);
      //chance of seeing a blue flag
      if (seeFlag==1)
      {
        cout<<"You spot a blue flag as you run by- grab it!"<<endl;
        player->addFlag(flagColor);
      }
    }

    if (power==1)
    {
      cout<<"You spot a power boost as you run by- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }

    cout<<"You can exit the course and finish the game if you move right!"<<endl;
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
  up=new DeepDive8(player);
  left=new FoamPit11(player);
  printMap();
}
