/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  Elliott is a derived class of Player.  Elliott
has average upper and lower body strength.
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Elliott.hpp"

using std::cout;
using std::endl;
using std::string;

/*******************************************************************
                  constructor
This is the constructor for Elliott, a derived class of Player.
His upper and lower body strength and name are initialized here.
*******************************************************************/
Elliott::Elliott(): Player()
{
  upper=12;
  lower=9;
  name="Elliott";
}

/*******************************************************************
                  getName
  This function returns the name of the Player type.
*******************************************************************/
std::string Elliott::getName()
{
  return name;
}

/*******************************************************************
                  displayInfo
This function shows information about the Player chosen to complete
the course.  It includes narrative information as well as strength
statistics.
*******************************************************************/
void Elliott::displayInfo()
{
  cout<<"Meet Elliott."<<endl;
  cout<<"Elliott is a kid."<<endl;
  cout<<"He takes gymnastics class and skateboarding."<<endl;
  cout<<"He is young, but strong for his age."<<endl;
  cout<<"He will be our junior competitor this year."<<endl;
  cout<<"Will Elliott be the next winner of WARRIOR CHALLENGE???"<<endl;
  cout<<"Elliott starts with: "<<endl;
  cout<<getUStrength()<<" points in upper body strength"<<endl;
  cout<<getLStrength()<<" points in lower body strength"<<endl;
  cout<<endl;

}
