/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for Rings3, a derived
class of type Space which represents the third space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "Rings3.hpp"
#include "TrapezeTraverse7.hpp"
#include "Tightrope2.hpp"
#include "GauntletOfHammers4.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for Rings3, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
Rings3::Rings3(Player* warrior): Space(player)
{
  player=warrior;
 up=nullptr;
 flagColor="blue";
 useUpper=4;
 useLower=0;
 seeFlag=rand()%4+1;
 upRand=rand()%4+1;
 lowRand=rand()%4+1;
 power=rand()%4+1;
 position=3;
 dropChance=rand()%3+1;
 hangChance=rand()%2+1;
}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void Rings3::seeObstacle()
{
  cout<<"*** Rings ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void Rings3::showInfo()
{
  cout<<"You are now at Rings."<<endl;
  cout<<"You will swing from ring to ring to get to the end."<<endl;
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
void Rings3::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a blue flag
    if (seeFlag<1)
    {
      cout<<"You spot a blue flag on one of the rings- grab it!"<<endl;
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

    //option to rest in exchange for a chance at a power boost
    cout<<"Hang by your ankles for a moment?"<<endl;
    cout<<"You will be able to spot another flag, but you may fall."<<endl;
    cout<<"1) Hang by ankles"<<endl;
    cout<<"2) Keep going"<<endl;
    int hang=intValid(1,2);
    //if they choose to rest
    if (hang==1)
    {
      if (hangChance==1)
      {
        cout<<"Wrong choice- you fall on your head."<<endl;
        player->gameOver(1);
      }
      else
      {
        cout<<"You spot a green flag!"<<endl;
        //add a flag to the vector
        player->addFlag("green");
        cout<<"You did it!"<<endl;
        left=new Tightrope2(player);
        down=new TrapezeTraverse7(player);
        right= new GauntletOfHammers4(player);
        //shows map again and displays next choices
        printMap();
      }
    }
    else if (hang==2)
    {
      cout<<"You made it to the last ring!"<<endl;
      //shows map again and displays next choices
      left=new Tightrope2(player);
      down=new TrapezeTraverse7(player);
      right= new GauntletOfHammers4(player);
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
