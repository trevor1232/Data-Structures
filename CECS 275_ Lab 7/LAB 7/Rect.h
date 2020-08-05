/*
   Name: Trevor Scott
   Date: 04/07/2020
   Program: Lab 7: Operator Overloading
   Description: This is the .h file for the header file of Rect.cpp.
*/


#ifndef Rect_h
#define Rect_h

#include <iostream>
using namespace std;
//contructs a single rectangle Class
class Rect{
private:
    //private variables
    int width;
    int height;
public:
    //Default constructor
    /* Will set the default values
    * @return will assume values will be 0 if not integer values are assigned.
     */
    Rect();
    /*   Constructs the Rect with values that are assigned to it
       @param w is the width intake
       @param h is the height intake
    */
    Rect(int w, int h);
    /*   Constructs the Rect with values that are assigned to it
       @param check is the value that will be assigned for Rect's width and height
    */
    Rect(int check);
    /*   Will get the width of an object
       @return will return the respected width for the object
    */
    int getWidth();
    /*   Will get the height of an object
       @return will return the respected height for the object
    */
    int getHeight();
    /*   Will see if the two objects have the same respected values
       @Param The object and it's respected private values.
       @return true if they have the same values, false if not.
    */
    bool operator== (const Rect rhs);
    /*   Will add the values of two objects of their respected values
       @Param The object and it's respected private values which remain a constant  reference, which means that the reference itself cannot be modified
       @return the new object to the variable that called it.
    */
    Rect operator+ (const Rect& rhs);
    //& needed to change originl
    /*   Will multiply the values of two objects of their respected values
       @Param The object and it's respected private values, which the object is passed as a reference
       @return the new object to the variable that called it which is the reference of R1 which will modify that object.
    */
    Rect& operator*( Rect& r);
    /*   Will see if the two objects have a different of comparison in terms of their values of width, and height.
       @Param The object and it's respected private values which are constant reference, which means that the reference itself cannot be modified
       @return true if the left hand side is less than the right, false otherwise.
    */
    bool operator<(const Rect& r);
    friend ostream& operator<<(ostream& output, Rect& r);

};
#endif /* Rect_h */
