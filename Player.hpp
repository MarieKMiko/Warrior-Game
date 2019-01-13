/******************************************
** Author: Marie Knapp
** Date: December 4th, 2018
** Description: This is the specification file for the
Player class, an abstract class for the possible Player types
in the Warrior Challenge game.
*******************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>

using std::string;

class Player
{
  protected:
    //upper and lower body strength are in the derived classes
    //flag stack containter
    std::vector<std::string> flags;
    //denotes if player has flags in all three colors;
    bool winningColors;
    //player upper and lower body strength
    int upper;
    int lower;


  public:
    Player();
    ~Player();
    virtual void displayInfo()=0;
    virtual std::string getName()=0;
    int getUStrength();
    int getLStrength();
    void subUStrength(int);
    void subLStrength(int);
    void addUStrength(int);
    void addLStrength(int);
    void gameOver(int);
    void wonGame();
    void dropFlag();
    void addFlag(std::string);
    bool checkFlags();


};


#endif
