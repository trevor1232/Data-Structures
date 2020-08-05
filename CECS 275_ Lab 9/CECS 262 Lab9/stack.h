/*
   Name: Trevor Scott
   Date: 04/19/2020
   Program: Lab 9
   Description: This is the .h file for the header file of stack.cpp.
*/

#ifndef stack_h
#define stack_h
#include <iostream>
#include "point.cpp"
using namespace std;


class Stack
{
private:
    
    struct Node{
        //value of the point
        Point value;
        //points to new node
        Node *next;
    };
    //points at node of the top, the new one of the tail.
    Node *top;
    
public:
    //default
    Stack(){
        top = NULL;
    }

    //checks to see ifempty of object stack
    bool isEmpty(){
        return top == NULL;
    }
    
    Point peek(){
        return top->value;
    }

    void push(Point);
    //Removes the point of the top
    //@return new point
    Point pop();
    //Gets the size of the stack
    //@return size
    int size();
    void printStack();
    

};

#endif /* stack_h */
