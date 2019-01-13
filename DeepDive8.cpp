/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for DeepDive8, a derived
class of type Space which represents the eighth space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "DeepDive8.hpp"
#include "TrapezeTraverse7.hpp"
#include "VictoryLap12.hpp"
#include "GauntletOfHammers4.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for DeepDive8, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
DeepDive8::DeepDive8(Player* warrior): Space(player)
{
  player=warrior;
 right=nullptr;
 flagColor="red";
 useUpper=3;
 useLower=3;
 seeFlag=rand()%5+1;
 upRand=rand()%3+1;
 lowRand=rand()%3+1;
 power=rand()%2+1;
 water=rand()%2+1;
 position=8;
 diveAgain=true;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void DeepDive8::seeObstacle()
{
  cout<<"*** Deep Dive ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void DeepDive8::showInfo()
{
  cout<<"You are now at the Deep Dive."<<endl;
  cout<<"Jump into the water and go deep, "<<endl;
  cout<<"and don't forget to take a breath first."<<endl;
  cout<<"This will take "<<useUpper<<" points in upper body and "<<endl;
  cout<<useLower<<" points in lower body strength."<<endl;
  cout<<"Unless you need to come up for a breath..."<<endl;
  cout<<"Ready, "<<player->getName()<<"?"<<endl;
  go();
}

/*******************************************************************
                    go
This function starts the user through the obstacle in this space.
The upper and lower body strength needed are subtracted from the player->
*******************************************************************/
void DeepDive8::go()
{
  bool diveFinish=false;
  while (diveAgain==true)
  {
    //if the player has enough upper and lower body strength to proceed
    if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
    {
      cout<<"You are at the edge of the water."<<endl;
      cout<<"You dive in!"<<endl;
      cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
      player->subUStrength(useUpper);
      player->subLStrength(useLower);
      //chance of seeing a red flag
      if (seeFlag>2)
      {
        cout<<"You spot a red flag under the water- grab it!"<<endl;
        if (water==1)
        {
          player->addFlag(flagColor);
          diveAgain=false;
          diveFinish=true;
        }
        else
        {
          cout<<"But it is so hard to grab- you need a breath!"<<endl;
          cout<<"You need to leave the flag and dive down again!"<<endl;
          water=rand()%2+1;
          seeFlag=rand()%5+1;
        }
      }
      else if (seeFlag<=2)
      {
        diveAgain=false;
        diveFinish=true;
      }

      if (power==1)
      {
        cout<<"You spot a power boost under the water- hit it!"<<endl;
        cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
        cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
        player->addUStrength(upRand);
        player->addLStrength(lowRand);
        //reset power to 50% chance for next dive
        power=rand()%2+1;
      }
    }
    //if the Player does not have enough strength the do the obstacle
    else
    {
      cout<<"You don't have the necessary strength to complete this task."<<endl;
      cout<<"With your limited strength, you fall on your face."<<endl;
      cout<<"Sorry, game over!"<<endl;
      //the game is over
      diveAgain=false;
      player->gameOver(1);
    }
  }
  if (diveFinish==true)
  {
    cout<<"You have completed the Deep Dive!"<<endl;
    up=new GauntletOfHammers4(player);
    left=new TrapezeTraverse7(player);
    down=new VictoryLap12(player);
    printMap();
  }
}
