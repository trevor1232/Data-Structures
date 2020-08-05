/*
   Name: Trevor Scott
   Date: 04/14/2020
   Program: Lab 8
   Description: This is the .cpp file for the file of LinkedList.h.
*/

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;


LinkedList::LinkedList(){
    first = NULL;
}

//Adds a "new" square to the end of the list which is like how adding the of a array or vector
//@param passes in sqaure from user
void LinkedList::add(Square s){
    Node *newNode = new Node;
    newNode->squ = s;
    newNode->nextNode = NULL;
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        Node *n = first;
        while (n->nextNode != NULL)
        {
            n = n->nextNode;
        }
        n->nextNode = newNode;
    }
}

bool LinkedList::isEmpty(){
    return first == NULL;
}

//Goes through linked list to get the size of the list
//@return the size of the LinkedList of the object
int LinkedList::size(){
    Node *n = first;
    int count = 0;
    while (n != NULL)
    {
        n = n->nextNode; count++;
    }
    return count;
}

//Displays elements of a LinkedList
//prints all of them out
void LinkedList::print()
{
    Node *n = first;
    while (n != NULL)
    {
        cout << n->squ << "";
        n = n->nextNode;
    }
    cout << endl;
}

//Goes through LinkedList to get value of the data that was selected
//@param passes in an integer for the index
//@return value of selected data
Square LinkedList::get(int sel){
    if (sel >= 0 && sel < size())
    {
        Node *n = first;
        for (int j = 0; j < sel; j++)
        {
            n = n->nextNode;
        }
        return n->squ;
    }
    return Square();
}

//Goes through list and sets the data to input value in a respected object from user
//@param i passes in integer i for the index
//@param s passes in a user input s the square class
void LinkedList::set(int i, Square s){
    if (i >= 0 && i < size())
    {
        Node *n = first;
        for (int j = 0; j < i; j++ )
        {
            n = n->nextNode;
        }
        n->squ = s;
    }
}

//Goes through LinkedList to find input square "s"
//@param s target square
//@return returns index of the first sqaure, if not it will return -1 for false
int LinkedList::find(Square &s){
    Node *currentN = first;
    int index = 0;
    while(currentN)
    {
        if (currentN->squ == s)
        {
            return index;
        }
        index++;
        currentN = currentN->nextNode;
    }
    return -1;
}
