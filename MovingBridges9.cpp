/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for MovingBridges9, a derived
class of type Space which represents the ninth space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "MovingBridges9.hpp"
#include "Zipline5.hpp"
#include "RopeClimb10.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for MovingBridges9, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
MovingBridges9::MovingBridges9(Player* warrior): Space(player)
{
 player=warrior;
 left=nullptr;
 down=nullptr;
 flagColor="blue";
 useUpper=2;
 useLower=4;
 seeFlag=rand()%3+1;
 upRand=rand()%10+5;
 lowRand=rand()%10+5;
 power=rand()%4+1;
 position=9;
 dropChance=rand()%3+1;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void MovingBridges9::seeObstacle()
{
  cout<<"*** Moving Bridges ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void MovingBridges9::showInfo()
{
  cout<<"You are now at Moving Bridges."<<endl;
  cout<<"You will have to time your jumps from bridge to bridge."<<endl;
  cout<<"There are 5 levels of bridges stacked to the ceiling."<<endl;
  cout<<"How many levels would you like to move through?"<<endl;
  cout<<"Each additional level will cost an extra +1 in lower body strength"<<endl;
  cout<<"But will give you more chances to find flags and power boosts."<<endl;
  cout<<"Enter your chosen number of levels:"<<endl;
  levels=intValid(1,5);
  cout<<"This will take "<<useUpper<<" points in upper body and "<<endl;
  cout<<useLower+(levels-1)<<" points in lower body strength."<<endl;
  cout<<"Ready, "<<player->getName()<<"?"<<endl;
  go();
}

/*******************************************************************
                    go
This function starts the user through the obstacle in this space.
The upper and lower body strength needed are subtracted from the player->
*******************************************************************/
void MovingBridges9::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower+(levels-1)))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower+(levels-1));
    //chance of seeing a blue flag
    for (int i=1; i<=levels; i++)
    {
      cout<<"You are on bridge level #"<<i<<endl;
      cout<<"Jump! Now!"<<endl;
      if (seeFlag==1)
      {
        cout<<"You spot a blue flag on one of the moving bridges- grab it!"<<endl;
        player->addFlag(flagColor);
      }
      //chance of dropping a flag
      if (dropChance==1)
      {
        player->dropFlag();
      }

      if (power==1)
      {
        cout<<"You spot a power boost on a ring- hit it!"<<endl;
        cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
        cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
        player->addUStrength(upRand);
        player->addLStrength(lowRand);
      }
    }
    cout<<"You did it- you run off of the last bridge!"<<endl;
    up= new Zipline5(player);
    right= new RopeClimb10(player);
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
