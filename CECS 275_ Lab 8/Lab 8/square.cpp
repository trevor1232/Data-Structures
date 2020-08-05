/*
   Name: Trevor Scott
   Date: 04/14/2020
   Program: Lab 8
   Description: This is the .cpp file for the file of square.h.
*/

#include <stdio.h>
#include "square.h"

//Default constructor, Initializes w, h, and length to 0
Square::Square(){
    w = 0;
    h = 0;
    length = 0;
}
//Constructor; allows user to input their own values for x, y, and length
Square::Square(int a, int b, int l){
    w = a;
    h = b;
    length = l;
}
//Outputs in the form of ---->"Loc = (x, y) Len = length"
ostream &operator<< (ostream &out, Square sq){
    out << "Loc = (" << sq.w << ", " << sq.h << ") L = " << sq.length << endl;
    return out;
}
//Overloads the == operator to return true if each data value is the same for all of w,h, and length
//@param = a square is passed into the function
//@return = returns true if each of the data values of the members are the same, false otherwise
bool Square::operator==(Square sq){
   return ((this -> w == sq.w) && (this -> h == sq.h) && (this -> length == sq.length));
}

