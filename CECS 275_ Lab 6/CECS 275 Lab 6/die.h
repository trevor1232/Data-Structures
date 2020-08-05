/*
   Name: Trevor Scott
   Date: 03/19/2020
   Program: Project1:  Yaht-Z Game
   Description: This is the .h file for the header file of die.h.
*/

#ifndef die_h
#define die_h
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
/*Constructs a single dice for the game
*/
class Die {
private:
    /* The number of sides of the die*/
    int sides;
    /*   The value shown on the die  */
    int value;
    
public:
    //Default Constructor
    /*   Constructs the die with 6 sides  */
    Die();
    /*   Constructs the die with sides s
        @param s the number of sides on the die
     */
    Die(int s);
    //Methods
    /*  Rolls the die
       @return the new value of the die
    */
    int roll();
    /*  Returns the value of the die
       @return the value of the die
    */
    int getValue();
    //See if it's true
    /*  Changes the value of the die if val is valid
        @param val the number of sides on the die
       @return true if vald, false otherwise
    */
    bool setValue( int val);
};

#endif /* die_h */


