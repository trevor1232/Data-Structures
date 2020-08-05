/*
   Name: Trevor Scott
   Date: 03/19/2020
   Program: Project1:  Yaht-Z Game
   Description: This is the .h file for the header file of player.h
*/

#ifndef Player_h
#define Player_h

#include "die.h"

/*Constructs a single player for the game
 */
class Player{
private:
    int points;
    //array of 3 dice like 3 classes of die
    Die dice[3];
    //toss will account for how many times the dice was tossed.
    int toss;
public:
    //Default constructor
    /* Will set the default values
    * @return the values if cases are not satisfied
     */
    Player();
    /* Sorts dice from lowest to highest
    * @return Will return the sorted dice
     */
    void sortDie();
    /* Will get the respected points
    * @return will return points to the integer that called it
     */
    int getPoints();
    /* Prints out the values into D1,D2, and D3
    * @return The values of D(s)
     */
    void displayValues();
    /* Will take turn and implement everything is needed to have a turn, such as: rolling the dice, sorting, displaying values, etc
    * @return Will return if true the dice are or false if not
     */
    void takeTurn();
    //methods for winning
    /* Will get the three dice and see if they're in a series
    * @return Will return if true the dice are or false if not
     */
    bool win1();
    /* Reads to see if there is a pair in the three dice
    * @return Will return if true the dice are or false if not
     */
    bool win2();

    /* Reads to see if there is a three of a kind in the three dice
    * @return Will return if true the dice are or false if not
     */
    bool win3();
};
#endif

