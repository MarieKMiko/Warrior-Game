/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:
*******************************************/
#include <iostream>
#include "Space.hpp"
#include "intValid.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;

/*******************************************************************
                  constructor
*******************************************************************/
Space::Space(Player* warrior)
{
  player=warrior;
}

/*******************************************************************
                    move
*******************************************************************/
void Space::move()
{
 cout<<"Which direction do you want to go next?"<<endl;
 cout<<"1) Up"<<endl;
 cout<<"2) Down"<<endl;
 cout<<"3) Left"<<endl;
 cout<<"4) Right"<<endl;

 bool moveComplete=false;
 while (moveComplete==false)
 {
   int direction=intValid(1,4);
   if ((direction==1)&&(position>4))
   {
     position= position-4;
     up->showInfo();
     moveComplete=true;
   }
   else if ((direction==2)&&(position<9))
   {
     position=position+4;
     down->showInfo();
     moveComplete=true;
   }
   else if ((direction==2)&&(position>=9))
   {
     cout<<"You can't move that way!  Choose again."<<endl;
   }
   else if(direction==3)
   {
     if ((position==1)||(position==3))
     {
       cout<<"You can't move that way!  Choose again."<<endl;
     }
     else if (position==7)
     {
       cout<<"You can't move that way! Choose again."<<endl;
     }
     else
     {
       position=position-1;
       left->showInfo();
       moveComplete=true;
     }
   }
   else if ((direction==4)&&(position%4 != 0))
   {
     position= position+1;
     right->showInfo();
     moveComplete=true;
   }
   else if ((position==12)&&(direction=4))
   {
     cout<<"You have left the board!"<<endl;
     player->wonGame();
     moveComplete=true;
   }
 }
}
/*******************************************************************
                    printMap
This function shows the player where they are in the game.  This helps
them see where they are relative to the end and where they might travel
to next.
*******************************************************************/
void Space::printMap()
{
  cout<<endl;
  cout<<endl;
  cout<<" _____ _____ _____ _____ "<<endl;
  cout<<"|    1|    2|    3|    4|"<<endl;
  cout<<"|     |     |     |     |"<<endl;
  cout<<" ----- ----- ----- ----- "<<endl;
  cout<<"|    5|    6|    7|    8|"<<endl;
  cout<<"|     |     |     |     |"<<endl;
  cout<<" ----- ----- ----- ----- "<<endl;
  cout<<"|    9|   10|   11|   12|"<<endl;
  cout<<"|     |     |     |end->|"<<endl;
  cout<<" ----- ----- ----- ----- "<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"You are currently in space #"<<position<<endl;
  cout<<endl;
  cout<<endl;

bool choiceMade=false;
while (choiceMade==false)
{
  cout<<endl;
  cout<<"Take a look around:"<<endl;
  cout<<endl;
  cout<<"1) See what obstacle is above"<<endl;
  cout<<"2) See what obstacle is below"<<endl;
  cout<<"3) See what obstacle is to the left"<<endl;
  cout<<"4) See what obstacle is to the right"<<endl;
  cout<<"5) Choose a direction to move"<<endl;
  cout<<"6) Check which flags I have gathered"<<endl;
  cout<<"7) Check my strength"<<endl;
  int obstacleView=intValid(1,7);

  if (obstacleView==1)
  {
    if (up==nullptr)
    {
      cout<<"That's off the course!"<<endl;
    }
    else
    {
      up->seeObstacle();
    }
  }
  else if (obstacleView==2)
  {
    if (down==nullptr)
    {
      cout<<"That's off the course!"<<endl;
    }
    else
    {
      down->seeObstacle();
    }
  }
  else if (obstacleView==3)
  {
    if (left==nullptr)
    {
      cout<<"That's off the course!"<<endl;
    }
    else
    {
      left->seeObstacle();
    }
  }
  else if (obstacleView==4)
  {
    if (right==nullptr)
    {
      cout<<"That's off the course!"<<endl;
    }
    else
    {
      right->seeObstacle();
    }
  }
  else if (obstacleView==6)
  {
    player->checkFlags();
  }
  else if (obstacleView==5)
  {
    move();
    choiceMade=true;
  }
  else if (obstacleView==7)
  {
    cout<<endl;
    cout<<"You have: "<<endl;
    cout<<player->getUStrength()<<" in upper body strength and"<<endl;
    cout<<player->getLStrength()<<" in lower body strength."<<endl;
  }
}

}
/*******************************************************************
                destructor
*******************************************************************/
Space::~Space()
{}
