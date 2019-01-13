/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  This is the implementation file for Tightrope2, a derived
class of type Space which represents the second space in the course.
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "Tightrope2.hpp"
#include "WallClimb1.hpp"
#include "Rings3.hpp"
#include "Snakepit6.hpp"
#include "Player.hpp"
#include "intValid.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
This is the constructor for Tightrope2, a Space in the obstacle
course.  It initializes the variables for this space to indicate
the chances of flag and power boost events, and to set the pointers
to the surrounding spaces accordingly.
*******************************************************************/
Tightrope2::Tightrope2(Player* warrior): Space(player)
{
  player=warrior;
 up=nullptr;
 flagColor="red";
 useUpper=0;
 useLower=2;
 seeFlag=rand()%2+1;
 upRand=rand()%5+5;
 lowRand=rand()%5+5;
 power=rand()%10+1;
 position=2;
 dropChance=rand()%5+1;
 sitChance=rand()%5+1;
}


/*******************************************************************
                    seeObstacle
This function allows the user to learn about the surrounding spaces
before committing to doing their next obstacle.  They will know
how much upper and lower body strength they need to complete the task.
*******************************************************************/
void Tightrope2::seeObstacle()
{
  cout<<"*** Tightrope ***"<<endl;
  cout<<"Upper Body Strength Required: "<<useUpper<<endl;
  cout<<"Lower Body Strength Required: "<<useLower<<endl;

}
/*******************************************************************
                    showInfo
This function displays information about the obstacle the user has
chosen to travel to next. It then calls the go function.
*******************************************************************/
void Tightrope2::showInfo()
{
  cout<<"You are now at the Tightrope."<<endl;
  cout<<"Carefully place your feet on the rope and keep your balance."<<endl;
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
void Tightrope2::go()
{
  //if the player has enough upper and lower body strength to proceed
  if ((player->getUStrength()>=useUpper)&&(player->getLStrength()>=useLower))
  {
    cout<<"Go "<<player->getName()<<", go!!!"<<endl;
    //subtracts the strength required from the Player
    player->subUStrength(useUpper);
    player->subLStrength(useLower);
    //chance of seeing a red flag
    if (seeFlag==1)
    {
      cout<<"You spot a red flag on the rope- grab it!"<<endl;
      player->addFlag(flagColor);
    }
    //chance of dropping a flag
    if (dropChance==1)
    {
      player->dropFlag();
    }
    if (power==1)
    {
      cout<<"You spot a power boost on the rope- hit it!"<<endl;
      cout<<"You have added +"<<upRand<<" upper body strength"<<endl;
      cout<<"and +"<<lowRand<<" lower body strength!"<<endl;
      player->addUStrength(upRand);
      player->addLStrength(lowRand);
    }

    //option to rest in exchange for a chance at a power boost
    cout<<"Do you want to sit down on the rope?"<<endl;
    cout<<"You may regain some strength, but you could fall."<<endl;
    cout<<"You'll have to use 1 upper body strength to get back up."<<endl;
    cout<<"1) Sit"<<endl;
    cout<<"2) Keep walking"<<endl;
    int sit=intValid(1,2);
    //if they choose to rest
    if (sit==1)
    {
      if (sitChance==1)
      {
        cout<<"You have fallen!"<<endl;
        cout<<"That's it for you!"<<endl;
        player->gameOver(1);
      }
      else
      {
        cout<<"Your rest has gained you +3 in lower body strength."<<endl;
        player->addLStrength(3);
        cout<<"You did it!"<<endl;
        cout<<"You get back up and make to the end of the tighrope."<<endl;
        //shows map again and displays next choices
        left=new WallClimb1(player);
        down=new Snakepit6(player);
        right= new Rings3(player);
        printMap();
      }
    }
    //if user chooses to keep walking
    else if (sit==2)
    {
      cout<<"You made it to the end of the tightrope!"<<endl;
      left=new WallClimb1(player);
      down=new Snakepit6(player);
      right= new Rings3(player);
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
