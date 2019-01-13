/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for WallClimb1, a derived
class of type Space which represents the first space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "WallClimb1.hpp"
#include "Zipline5.hpp"
#include "Tightrope2.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for WallClimb1, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
WallClimb1::WallClimb1(Player* warrior): Space(player)
{
  player=warrior;
  up=nullptr;
 left=nullptr;
 flagColor="green";
 useUpper=3;
 useLower=3;
 seeFlag=rand()%2+1;
 upRand=rand()%4+1;
 lowRand=rand()%4+1;
 power=rand()%4+1;
 position=1;
 dropChance=rand()%10+1;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void WallClimb1::seeObstacle()
{
  cout<<"*** Wall Climb ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void WallClimb1::showInfo()
{
  cout<<"You are now at the Wall Climb."<<endl;
  cout<<"You must use the handholds and footholds to climb to the top."<<endl;
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
void WallClimb1::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a green flag
    if (seeFlag==2)
    {
      cout<<"You spot a green flag at the top- grab it!"<<endl;
      player->addFlag(flagColor);
    }
    //chance of dropping a flag
    if (dropChance==1)
    {
      player->dropFlag();
    }
    //option to rest in exchange for a chance at a power boost
    cout<<"You make it to the top of the wall!"<<endl;
    cout<<"Stop and rest at the top?"<<endl;
    cout<<"1) Rest"<<endl;
    cout<<"2) Keep going"<<endl;
    int rest=intValid(1,2);
    //if they choose to rest
    if (rest==1)
    {
      cout<<"Your rest has gained you +1 in lower body strength."<<endl;
      cout<<"But it has cost you any chance of finding a power boost here."<<endl;
      //add 1 to lower body strength
      player->addLStrength(1);
    }
    //if they choose to keep going, there is a chance for a power boost
    else if ((rest==2)&&(power==4))
    {
      cout<<"You spot a power boost at the top- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }
    cout<<"You did it!"<<endl;
    down=new Zipline5(player);
    right= new Tightrope2(player);
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
