/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: Myrtle is a derived class of Player.
She is a weak Player and so is more challenging than others.
*******************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Myrtle.hpp"

using std::cout;
using std::endl;
using std::string;

/*******************************************************************
                  constructor
This is the constructor for Myrtle, a derived class of Player.
Myrtle's name and strength statistics are included.
*******************************************************************/
Myrtle::Myrtle(): Player()
{
  upper=3;
  lower=4;
  name="Myrtle";
}

/*******************************************************************
                  getName
This function returns the name of the Player type.
*******************************************************************/
std::string Myrtle::getName()
{
  return name;
}

/*******************************************************************
                  displayInfo
This function shows information about the Player chosen to complete
the course.  It includes narrative information as well as strength
statistics.
*******************************************************************/
void Myrtle::displayInfo()
{
  cout<<"Meet Myrtle."<<endl;
  cout<<"Myrtle enjoys watching Wheel of Fortune."<<endl;
  cout<<"She spends a lot of time with her seven cats."<<endl;
  cout<<"Sometimes she prints out funny jokes from her computer and takes"<<endl;
  cout<<"pictures of them to mail to her grandson."<<endl;
  cout<<"Myrtle got lost on her way to the grocery store today."<<endl;
  cout<<"We believe in you, Myrtle!"<<endl;
  cout<<"Will Myrtle be the next winner of WARRIOR CHALLENGE???"<<endl;
  cout<<"Myrtle starts with: "<<endl;
  cout<<getUStrength()<<" points in upper body strength"<<endl;
  cout<<getLStrength()<<" points in lower body strength"<<endl;
  cout<<endl;

}
