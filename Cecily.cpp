/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  Cecily is a derived class of Player.  Cecily
has average upper and lower body strength.
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Cecily.hpp"

using std::cout;
using std::endl;
using std::string;

/*******************************************************************
                  constructor
This is the constructor for Cecily, a derived class of Player.
Cecilys name and strength statistics are included.
*******************************************************************/
Cecily::Cecily(): Player()
{
  upper=9;
  lower=13;
  name="Cecily";
}

/*******************************************************************
                  getName
  This function returns the name of the Player type.
*******************************************************************/
std::string Cecily::getName()
{
  return name;
}

/*******************************************************************
                  displayInfo
This function shows information about the Player chosen to complete
the course.  It includes narrative information as well as strength
statistics.
*******************************************************************/
void Cecily::displayInfo()
{
  cout<<"Meet Cecily."<<endl;
  cout<<"Cecily is a ballerina."<<endl;
  cout<<"She has a lot of energy and speed."<<endl;
  cout<<"She can jump and spin as much as necessary."<<endl;
  cout<<"Will Cecily be the next winner of WARRIOR CHALLENGE???"<<endl;
  cout<<"Cecily starts with: "<<endl;
  cout<<getUStrength()<<" points in upper body strength"<<endl;
  cout<<getLStrength()<<" points in lower body strength"<<endl;
  cout<<endl;

}
