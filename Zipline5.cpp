/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for Zipline5, a derived
class of type Space which represents the fifth space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "Snakepit6.hpp"
#include "Zipline5.hpp"
#include "WallClimb1.hpp"
#include "MovingBridges9.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for Zipline5, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
Zipline5::Zipline5(Player* warrior): Space(player)
{
  player=warrior;
  left=nullptr;
 flagColor="green";
 useUpper=2;
 useLower=0;
 seeFlag=rand()%3+1;
 upRand=rand()%2+1;
 lowRand=rand()%4+1;
 power=rand()%2+1;
 zipChance=rand()%4+1;
 position=5;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void Zipline5::seeObstacle()
{
  cout<<"*** Zipline ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void Zipline5::showInfo()
{
  cout<<"You are now at Zipline."<<endl;
  cout<<"Hold on!  Wheeeeeeeee!"<<endl;
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
void Zipline5::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a blue flag
    if (seeFlag>1)
    {
      cout<<"You are about to zip by a green flag- grab it!"<<endl;
      player->addFlag(flagColor);
    }

    if (power==1)
    {
      cout<<"You spot a power boost next to the line- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }

    //option to rest in exchange for a chance at a power boost
    cout<<"Do you want to jump from the zipline to the end?"<<endl;
    cout<<"It will save you 1 point in upper body strength."<<endl;
    cout<<"But you could fall and lose the game."<<endl;
    cout<<"1) Jump!"<<endl;
    cout<<"2) Keep zipping"<<endl;
    int zip=intValid(1,2);
    //if they choose to rest
    if (zip==1)
    {
      if (zipChance==1)
      {
        cout<<"Wrong choice- you fall and break an arm."<<endl;
        player->gameOver(1);
      }
      else
      {

        cout<<"You jump off and reach the end of the line safely!"<<endl;
        cout<<"You keep 1 upper body strength point."<<endl;
        player->addUStrength(1);
        up=new WallClimb1(player);
        down=new MovingBridges9(player);
        right= new Snakepit6(player);
        //shows map again and displays next choices
        printMap();
      }
    }
    else if (zip==2)
    {
      cout<<"You zip down to the end of the line!"<<endl;
      up=new WallClimb1(player);
      down=new MovingBridges9(player);
      right= new Snakepit6(player);
      //shows map again and displays next choices
      printMap();
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
