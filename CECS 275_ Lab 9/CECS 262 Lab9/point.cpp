/*
   Name: Trevor Scott
   Date: 04/19/2020
   Program: Lab 9
   Description: This is to defined an object called point which is simpliy the coordinate system
*/
#include <iostream>
using namespace std;

class Point
{
private:
    //private variables
    int x;
    int y;
    
public:
    Point() //default constructor that sets x and y to 0
    {
        x = 0;
        y = 0;
    };
/*
    Overloaded constructor
    @param xval gets passed into x
    @param yval gets passed into y
    //makes a new point system from the user inputs
*/
    Point( int xVal, int yVal)
    {
        x = xVal;
        y = yVal;
    };
    
    /*
       Retrieves the y value point
       @return y point
    */
    int getY()
    {
        return y;
    }

    //Retrieves the x value point
    //@return x point
    int getX()
    {
        return x;
    }

};
