/*
   Name: Trevor Scott
   Date: 03/19/2020
   Program: Project1:  Yaht-Z Game
   Description: This game was made by using classes, functions, and an array of dice. This game's purpose was to find the following:
    matching dies, a series of dies, and three of a kind dice. I separated the respected classes into .h header files and .cpp files. As you keep finding matches you will increment your point total.
*/

//directives
#include <iostream>
#include <ctime>
#include "CheckInput.h"
#include "Player.h"
#include "die.h"
using namespace std;

//main
int main(){
    //menu
    cout << "Welcome to the Yaht-z Game!!!" << endl;
    cout << endl;
    //calling the class and having play as starting it
    Player play;
    bool keepPlaying =true;
    
    //this is to call srand and use it for dice to have random values
    srand(time(NULL));
    while(keepPlaying){
        play.takeTurn();
        cout << "Play again? (Y or N)";
        keepPlaying = getYesNo();
    }
    cout << "Game is over! " << endl;
    cout << "Final Score = " << play.getPoints() << " Points" << endl;
}
 

