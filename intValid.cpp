/******************************************
** Author: Marie Knapp
** Date: November 18th, 2018
** Description: This function checks to see if valid input is given when the user
is prompted to enter an int.  If so, the user input is returned as a
value.
*******************************************/
#include <iostream>
#include "intValid.hpp"

using std::cin;
using std::endl;
using std::cout;

/*******************************************************************
                  intValid
This function checks to see if valid input is given when the user
is prompted to enter an int.  If so, the user input is returned as a
value.  Two int parameters indicating the range of acceptable values
are passed to this function.
*******************************************************************/
int intValid(int low, int high)
{
  bool valid=false;
  int validate;

  while (valid==false)
  {
    //User enters input, stored in an int variable
    cin>> validate;

    //If input is not an int, the input is ignored and the user is prompted again
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout<<"Invalid input- enter again:"<<endl;
    }
    else if ((validate<low)||(validate>high))
    {
      cout<<"Please enter a valid choice."<<endl;
    }
    else
    {
      //End the loop when valid input is given
      valid=true;
    }
  }
  return validate;
}
