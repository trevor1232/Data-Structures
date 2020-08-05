/*
   Name: Trevor Scott
   Date: 04/14/2020
   Program: Lab 8
   Description: This is the .h file for the header file of LinkedList.cpp.
*/


#ifndef LinkedList_h
#define LinkedList_h

#include "square.h"
#include <iostream>
using namespace std;


//linkedlist class
class LinkedList
{
private:
struct Node
{
    //Creates square 
    Square squ;
    
    //The next node to use for linklist
    Node *nextNode;
};
//Firstnode for data value (member)
Node *first;

public:
    //Default constructor
    LinkedList();
    
    //checks to see if the LinkedList is empty if not it will return false
    //@return true if empty false otherwise
    bool isEmpty();
    
    //adds a new square to the end of LinkedList
    void add(Square s);
    
    //Goes through linked list to get the size of the list
    //@return the size of the LinkedList of the object
    int size();
    
    //prints contents of LinkedList
    void print();
    
    //Goes through LinkedList to get value of the data that was selected
    //@param passes in an integer for the index
    //@return value of selected data
    Square get(int sel);
    
    //Goes through LinkedList to find input square "s"
    //@param s target square
    //@return returns index of the first sqaure, if not it will return -1 for false
    int find(Square &s);
    
    //Goes through LinkedList and sets data to an input value from the user
    void set(int i, Square s);
};


#endif 
