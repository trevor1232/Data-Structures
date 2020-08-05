/*
   Name: Trevor Scott
   Date: 04/14/2020
   Program: Lab 8: Linked Lists
   Description: This program's purpose was to utlize are understanding in linked lists, and are overloading operators. We added the squares deimensions and printed their dimensions. This overall gave a better understanding of how these operators, and linked lists work.
*/

//diretives below
#include <iostream>
#include "square.h"
#include "LinkedList.h"
#include <string>
using namespace std;

//function defintion
void printIsEmpty(LinkedList &list)
{
    if (list.isEmpty())
    {
        cout << "List is empty." << endl;
    }
    else
    {
        cout << "List is not empty." << endl;
        cout << "Size = " << list.size() << endl;
    }
}
//main.cpp from based on lab
int main()
{
    LinkedList list;
    Square s1(1,2,3);
    Square s2(2,3,4);
    Square s3(3,4,5);
    Square s4(4,5,6);
    printIsEmpty(list); //"List is empty"
    list.add( s1 );
    list.add( s2 );
    list.add( s3 );
    list.add( s4 );
    printIsEmpty(list);
    list.print();//"List is nnot empty. Size =4"
    cout << "The 1st item in the list is: " << list.get(0) << endl;//Loc=(1,2) L=3
    cout << "The 3rd item in the list is: " << list.get(2) << endl;//Loc=(3,4) L=5
    cout << "Modifyiing List..." << endl;
    Square s5(5, 6, 7);
    list.set(1, s5);
    list.print();//Loc=(2,3) L=4 is replaced w/Loc=(5,6) L=7
    Square s6(6, 7, 8);
    Square s7(3, 4, 5);
    cout << "Square 6 found at loc " << list.find(s6) << endl;//-1
    cout << "Square 7 found at loc " << list.find(s7) << endl;//2
    return 0;
}
