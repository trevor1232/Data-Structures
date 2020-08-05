/*
   Name: Trevor Scott
   Date: 04/19/2020
   Program: Lab 9
   Description: This is the .cpp file for the header file of stack.h.
*/
#include <iostream>
#include "stack.h"

int Stack::size(){
    int sizeS = 0;
    Node *findLast = top;
    while (findLast != NULL)
    {
        findLast = findLast->next;
        sizeS++;
    }
    return sizeS;
}

void Stack::push( Point val ){
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = top;
    top = newNode;
}

Point Stack::pop(){
    Point retVal;
    if( top != NULL )
    {
        retVal = top->value;
        Node *temp = top->next;
        delete top;
        top = temp;
    }
    return retVal;
}


