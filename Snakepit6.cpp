/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for Snakepit6, a derived
class of type Space which represents the sixth space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "Snakepit6.hpp"
#include "TrapezeTraverse7.hpp"
#include "Tightrope2.hpp"
#include "Zipline5.hpp"
#include "RopeClimb10.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for Snakepit6, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
Snakepit6::Snakepit6(Player* warrior): Space(player)
{
  player=warrior;
 flagColor="blue";
 flagColor2="red";
 flagColor3="green";
 useUpper=1;
 useLower=4;
 seeFlag=rand()%2+1;
 upRand=rand()%4+3;
 lowRand=rand()%4+3;
 power=rand()%2+1;
 position=6;
 dropChance=rand()%3+1;
 biteChance=rand()%5+1;
}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void Snakepit6::seeObstacle()
{
  cout<<"*** Snake Pit ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void Snakepit6::showInfo()
{
  cout<<"You are now at The Snake Pit."<<endl;
  cout<<"You must swim through the pit of snakes."<<endl;
  cout<<endl;
  cout<<"So many, many snakes."<<endl;
  cout<<"If they are venomous, you could be bitten."<<endl;
  cout<<endl;
  cout<<"Would you like the snake pit filled with:"<<endl;
  cout<<"1) Venomous snakes and lots of flags?"<<endl;
  cout<<"2) Friendly snakes and no flags"<<endl;
  snakes=intValid(1,2);
  cout<<"Okay then!"<<endl;
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
void Snakepit6::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a blue flag
    if (snakes==2)
    {
      cout<<"You swim through so many friendly snakes."<<endl;
      cout<<"You make it to the end!"<<endl;
      up= new Tightrope2(player);
      right= new TrapezeTraverse7(player);
      down= new RopeClimb10(player);
      left= new Zipline5(player);
      printMap();
    }
    else if (snakes==1)
    {
      cout<<"You begin your swim through venomous snakes."<<endl;
      if (seeFlag>1)
      {
        cout<<"You spot a red flag in the Snake Pit- grab it!"<<endl;
        player->addFlag(flagColor2);
      }
      cout<<"You continue swimming."<<endl;
      seeFlag=rand()%3+1;
      if (seeFlag==1)
      {
        cout<<"You spot a blue flag in the Snake Pit- grab it!"<<endl;
        player->addFlag(flagColor);
      }
      cout<<"Keep going..."<<endl;
      seeFlag= rand()%2+1;
      if (seeFlag==1)
      {
        cout<<"You spot a green flag in the Snake Pit- grab it!"<<endl;
        player->addFlag(flagColor3);
      }
      cout<<"Keep going..."<<endl;
      seeFlag= rand()%3+1;
      if (seeFlag>1)
      {
        cout<<"You spot a blue flag in the Snake Pit- grab it!"<<endl;
        player->addFlag(flagColor);
      }

      biteChance=rand()%5+1;
      if (biteChance==1)
      {
        cout<<"OUCH!!! You were bitten by a snake!"<<endl;
        cout<<"You leave the course for the hospital."<<endl;
        player->gameOver(1);
      }
      else
      {
        //chance of dropping a flag
        if (dropChance==1)
        {
          player->dropFlag();
        }
        if (power==1)
        {
          cout<<"You spot a power boost behind a snake- hit it!"<<endl;
          cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
          cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
          player->addUStrength(upRand);
          player->addLStrength(lowRand);
        }
        cout<<"You make it to the end of the snake pit!"<<endl;
        up= new Tightrope2(player);
        right= new TrapezeTraverse7(player);
        down= new RopeClimb10(player);
        left= new Zipline5(player);
        printMap();
      }
    }
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
