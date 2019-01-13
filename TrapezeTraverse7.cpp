/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for TrapezeTraverse7, a derived
class of type Space which represents the seventh space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "TrapezeTraverse7.hpp"
#include "Snakepit6.hpp"
#include "Rings3.hpp"
#include "FoamPit11.hpp"
#include "DeepDive8.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for TrapezeTraverse7, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
TrapezeTraverse7::TrapezeTraverse7(Player* warrior): Space(player)
{
  player=warrior;
 flagColor="green";
 useUpper=4;
 useLower=2;
 seeFlag=rand()%2+1;
 upRand=rand()%4+2;
 lowRand=rand()%4+2;
 power=rand()%4+1;
 position=7;
 dropChance=rand()%3+1;
}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void TrapezeTraverse7::seeObstacle()
{
  cout<<"*** Trapeze Traverse ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void TrapezeTraverse7::showInfo()
{
  cout<<"You are now at Trapeze Traverse."<<endl;
  cout<<"Use your arms and legs to move from trapeze to trapeze."<<endl;
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
void TrapezeTraverse7::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a blue flag
    if (seeFlag==1)
    {
      cout<<"You spot a green flag on a trapeze- grab it!"<<endl;
      player->addFlag(flagColor);
    }
    //chance of dropping a flag
    if (dropChance==1)
    {
      player->dropFlag();
    }

    if (power==1)
    {
      cout<<"You spot a power boost on a trapeze- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }

    trick = rand()%3+1;
    if (trick>1)
    {
      cout<<"Unexpected trick move!"<<endl;
      cout<<"You spin around a trapeze- wow!"<<endl;
      cout<<"This gives you a burst of energy and +2 lower body strength."<<endl;
      player->addLStrength(2);
    }

    cout<<"You made it to the last trapeze!"<<endl;
    //shows map again and displays next choices
    up=new Rings3(player);
    left=new Snakepit6(player);
    down=new FoamPit11(player);
    right= new DeepDive8(player);
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
