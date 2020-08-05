/*
   Name: Trevor Scott
   Date: 03/19/2020
   Program: Project1:  Yaht-Z Game
   Description: This is the .pp file for the header file of die.h and this code was implemented from studying lecture notes
*/

#include "die.h"

Die::Die(){
    sides =6;
    value = 1;
}

Die::Die(int s){
    sides = s;
    value =1;
}

int Die::roll(){
    //how it gets value for 'value'
    value = rand() % sides +1;
    return value;
}
int Die::getValue(){
    return value;
}
bool Die::setValue(int val){
    if( val > 0 && val <= sides){
        value = val;
        return true;
    }
    return false;
}


