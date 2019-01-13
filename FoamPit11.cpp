/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for FoamPit11, a derived
class of type Space which represents the eleventh space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "FoamPit11.hpp"
#include "VictoryLap12.hpp"
#include "RopeClimb10.hpp"
#include "TrapezeTraverse7.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for FoamPit11, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
FoamPit11::FoamPit11(Player* warrior):Space(player)
{
  player=warrior;
 down=nullptr;
 flagColor="red";
 useUpper=2;
 useLower=2;
 seeFlag=rand()%5+1;
 upRand=rand()%4+1;
 lowRand=rand()%4+1;
 power=rand()%2+1;
 position=11;
 dropChance=rand()%3+1;

}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void FoamPit11::seeObstacle()
{
  cout<<"*** Foam Pit ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void FoamPit11::showInfo()
{
  cout<<"You are now at Foam Pit."<<endl;
  cout<<"Move as fast as you can through the foam!"<<endl;
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
void FoamPit11::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    cout<<"Move, move, move!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a blue flag
    if (seeFlag==1)
    {
      cout<<"You spot a red flag in the foam- grab it!"<<endl;
      player->addFlag(flagColor);
    }

    //chance of dropping a flag
    if (dropChance==1)
    {
      player->dropFlag();
    }

    cout<<"Keep searching the foam for flags?"<<endl;
    cout<<"1) Yes, keep searching"<<endl;
    cout<<"2) No, just keep moving"<<endl;
    int search=intValid(1,2);

    if (search==1)
    {
      if(seeFlag==2)
      {
        cout<<"You spot a red flag in the foam- grab it!"<<endl;
        player->addFlag(flagColor);
      }
      else if (seeFlag==3)
      {
        cout<<"You spot a blue flag in the foam- grab it!"<<endl;
        player->addFlag("blue");
      }
      //chance of dropping a flag
      dropChance=rand()%3+1;
      if (dropChance==1)
      {
        player->dropFlag();
      }

      seeFlag=rand()%5+1;
      if (seeFlag>2)
      {
        cout<<"You spot a red flag in the foam- grab it!"<<endl;
        player->addFlag(flagColor);
      }
      else if (seeFlag==1)
      {
        cout<<"You spot a blue flag in the foam- grab it!"<<endl;
        player->addFlag("blue");
      }
      //chance of dropping a flag
      dropChance=rand()%3+1;
      if (dropChance==1)
      {
        player->dropFlag();
      }
    }
    else if (search==1)
    {
      cout<<"Keep moving!"<<endl;
    }


    if (power==1)
    {
      cout<<"You spot a power boost in the foam- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }

    cout<<"Keep searching the foam for power boosts?"<<endl;
    cout<<"1) Yes, keep searching"<<endl;
    cout<<"2) No, just keep moving"<<endl;
    int searchPow=intValid(1,2);
    power=rand()%2+1;

    if (searchPow==1)
    {
      //chance of dropping a flag
      dropChance=rand()%3+1;
      if (dropChance==1)
      {
        player->dropFlag();
      }

      if (power==1)
      {
        cout<<"You spot a power boost in the foam- hit it!"<<endl;
        cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
        cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
        player->addUStrength(upRand);
        player->addLStrength(lowRand);
      }

      power=rand()%4+1;
      if (power==1)
      {
        cout<<"You spot a power boost in the foam- hit it!"<<endl;
        cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
        cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
        player->addUStrength(upRand);
        player->addLStrength(lowRand);
      }

      power=rand()%5+1;
      if (power==1)
      {
        cout<<"You spot a power boost in the foam- hit it!"<<endl;
        cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
        cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
        player->addUStrength(upRand);
        player->addLStrength(lowRand);
      }
    }
    else if (searchPow==2)
    {
      cout<<"Keep moving- you're almost to the end!"<<endl;
    }
    cout<<"......and you've made it!"<<endl;
    up=new TrapezeTraverse7(player);
    left=new RopeClimb10(player);
    right= new VictoryLap12(player);
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
