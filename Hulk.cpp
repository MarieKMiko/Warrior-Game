/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  Hulk is a derived class of Player.  Hulk is
strong in both upper and lower body.
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Hulk.hpp"

using std::cout;
using std::endl;
using std::string;

/*******************************************************************
                  constructor
  This is the constructor for Hulk, a derived class of Player.
  His upper and lower body strength and name are initilized here.
*******************************************************************/
Hulk::Hulk(): Player()
{
  upper=20;
  lower=20;
  name="Hulk";
}

/*******************************************************************
                  getName
  This function returns the name of the Player type.
*******************************************************************/
std::string Hulk::getName()
{
  return name;
}

/*******************************************************************
                        displayInfo
This function shows information about the Player chosen to complete
the course.  It includes narrative information as well as strength
statistics.
*******************************************************************/
void Hulk::displayInfo()
{
  cout<<"Meet Hulk."<<endl;
  cout<<"Hulk is big and strong."<<endl;
  cout<<"Hulk SMASH obstacle course."<<endl;
  cout<<"Will Hulk be the next winner of WARRIOR CHALLENGE???"<<endl;
  cout<<"Hulk starts with: "<<endl;
  cout<<getUStrength()<<" points in upper body strength"<<endl;
  cout<<getLStrength()<<" points in lower body strength"<<endl;
  cout<<endl;

}
