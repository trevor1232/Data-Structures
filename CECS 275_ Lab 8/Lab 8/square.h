/*
   Name: Trevor Scott
   Date: 04/14/2020
   Program: Lab 8
   Description: This is the .h file for the header file of square.cpp.
*/

#ifndef square_h
#define square_h

#include <iostream>
using namespace std;

//the class for Square and of it's definition(s)
class Square
{
    private:
        //Width of square
        int w;
        //Height of square
        int h;
        //Length of square
        int length;
    public:
        //Default constructor
        Square();
        //Constructor of what the user wants
        Square(int a, int b, int l);
    
        //Overloads the == operator to return true if each data value is the same for all of w,h, and length
        //@param = a square is passed into the function
        //@return = returns true if each of the data values of the members are the same, false otherwise
        bool operator==(Square sq);
        
        //Outputs in the form of "Loc = (x, y) Len = length"
        //Also this part I had some assistance from stackoverflow resources.
        //I'd post the link but I can't find where it was
        //@param passed by reference ostream out
        //@param = a square is passed into the function
        //@return the respected data members.
        friend ostream &operator<< (ostream &out, Square sq);
};
#endif
