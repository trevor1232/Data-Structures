/*
   Name: Trevor Scott
   Date: 04/07/2020
   Program: Lab 7: Operator Overloading
   Description: This is the .pp file for the header file of Rect.h and this code was implemented from studying lecture notes and the rules of overloading operators based on arithmetic(e.g. +,*,..etc).
*/


#include <stdio.h>
#include <iostream>
#include "Rect.h"
using namespace std;

//defing the objects structure.
Rect::Rect(){
    width = 0;
    height = 0;
}

Rect::Rect(int check){
    if(check < 0 ){
        width = 0;
        height = 0;
    }else{
        width = check;
        height = check;
    }
}
Rect::Rect(int w, int h){
    if( w > 0 && h >0){
        width = w;
        height = h;
    }
    if ( w < 0 && h >0){
        width = 0;
        height = h;
    }
    if ( w > 0 && h <0){
        width = w;
        height = 0;
    }
    if( w < 0 && h < 0){
        width =0;
        height =0;
    }
}
int Rect::getHeight(){
    return height;
}
int Rect::getWidth(){
    return width;
}

bool Rect::operator== (const Rect rhs){
    if((this -> height == rhs.height)&&(this ->width == rhs.width)){
        return true;
    }
    return false;
}

Rect Rect:: operator+ (const Rect& rhs){
    Rect temp;
    temp.width = width+rhs.width;
    temp.height = height+rhs.height;
    return temp;
}
//work on other methods below
Rect& Rect::operator*(Rect& r){
    this->width = this->width * r.width;
    this->height = this->height * r.height;
    return *this;
}
bool Rect::operator<(const Rect& r){
    return this->height < r.height|| this->width < r.width;
}
ostream& operator<<(ostream& output, Rect& r)
{
output << "Rect: [W=" << r.width << ", H=" << r.height << "]";
return output;
}
