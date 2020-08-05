/*
    Name: Trevor Scott
    Date: 01/25/2020
    Program: Lab 1: Guessing Game
    Description: This program is suppose to function as a guessing game from 1 to 100
    where the computer generates a random number, and the user inputs a certain number.
    From there the program evaluates if the number is the same as the random number and if
    not the computer will keep asking to inputs more numbers, keeping track of the tries.
 
 */

//All directives
#include <iostream>
#include "CheckInput.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    /* rand() function generates a random number for us from 1 to 100
    * @return r2 keeps the save random */
    srand(time(NULL));
    int r2 = rand() % 100 + 1; // 1 to 100
    //int i is the user input
    int i;
    int a =1;
    cout << "I'm think thinking of a number from 1 to 100, so guess the value" << endl;
    /* getIntRange function gets the number from the user and check of any invalid syntax
       from user like -1,v, 201, etc. That doesn't fit for the programs needs.
    * @param int low of how low the input integer needs to be for being acceptable.
    * @param int high of how high the input integer needs to be for being acceptable.
    * @return i gets the return value back after going through the function.
    */
    i = getIntRange(1, 100);
    
    //conditional statements
    if( i != r2){
        //looping until user inputs matches random number
        while( i != r2){
            if(i > r2){
                cout << "To High     ";
            }
            else if(i < r2){
                cout << "To Low      ";
            }
            cout << "Please guess again" << endl;
            i = getIntRange(1, 100);
            a++;
            if(i == r2){
                cout << "Yay you got it in " << a << " tries" << endl;
                break;
            }
        }
    }
    cout << "You got it your first try!:)" << endl;
}
            
