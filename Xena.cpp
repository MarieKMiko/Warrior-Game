/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description:  Xena is a derived class of Player.  She is strong
in both upper and lower body.
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Xena.hpp"

using std::cout;
using std::endl;
using std::string;

/*******************************************************************
                  constructor
  This is the constructor for Xena, a derived class of Player.
  Her name and upper and lower body strength are initialized here.
*******************************************************************/
Xena::Xena(): Player()
{
  upper=18;
  lower=23;
  name="Xena";
}

/*******************************************************************
                  getName
This function returns the name of the Player type.
*******************************************************************/
std::string Xena::getName()
{
  return name;
}

/*******************************************************************
                      displayInfo
This function shows information about the Player chosen to complete
the course.  It includes narrative information as well as strength
statistics.
*******************************************************************/
void Xena::displayInfo()
{
  cout<<"Meet Xena."<<endl;
  cout<<"Xena is a warrior princess."<<endl;
  cout<<"Will Xena be the next winner of WARRIOR CHALLENGE???"<<endl;
  cout<<"Xena starts with: "<<endl;
  cout<<getUStrength()<<" points in upper body strength"<<endl;
  cout<<getLStrength()<<" points in lower body strength"<<endl;
  cout<<endl;

}
