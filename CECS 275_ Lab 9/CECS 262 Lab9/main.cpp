/*
   Name: Trevor Scott
   Date: 04/21/2020
   Program: Lab 9: Stacks
   Description: This program's purpose was to utlize are understanding in linked lists, and are overloading operators. We added the squares deimensions and printed their dimensions. This overall gave a better understanding of how these operators, and linked lists work.
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "stack.h"
using namespace std;

//Fills the array with a '.'
//@param  passes in array
void fill(char array[5][5]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            array[i][j] = '.';
        }
    }
}

//Prints out contents of array
//@param passes in array to be displayed and it might have predefined values in [][]
void print(char array[5][5]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
}

/*
Checks to see if the area can be overridded
@param array that will be wrriten in
@param the point object
@param c  is the counter
 */
void check(char array[5][5], Point p, int c){
    int x = p.getX();
    int y =    p.getY();
    char val = '0' + c;
    array[y][x] = val;
    // I was only able to get it to work with if statements not else if
    if (x - 1 >= 0)
        array[y][x - 1] = val;
    if (x + 1 <= 4)
        array[y][x + 1] = val;
    
    if (y - 1 >= 0)
        array[y - 1][x] = val;
    if (y + 1 <= 4)
        array[y + 1][x] = val;
}

//This code I decided to copy from checkinput since I thought adding it here would take more time
int getIntRange(int low, int high) {
    int input = 0;
    bool valid = false;
    while (!valid) {
        if (cin >> input) {
            if (input >= low && input <= high) {
                valid = true;
            }
            else {
                cout << "Invalid Input" << endl;
            }
        }
        else {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid Input" << endl;
        }
    }
    return input;
}

int main(){
    cout << "Please enter 5 points:" << endl;
    Stack points;
    char area[5][5];
    fill(area);
    int i = 1;
    int xCord;
    int yCord;
    while (i <= 5)
    {
        //Y goes first, then x since
        yCord = getIntRange(0, 4);
        xCord = getIntRange(0, 4);
        Point point(xCord, yCord);
        points.push(point);
        area[yCord][xCord] = '0' + i;
        i++;
    }
    i = 5;
    
    while (i >= 1)
    {
        check(area, points.pop(), i);
        i--;
    }
    print(area);
}
