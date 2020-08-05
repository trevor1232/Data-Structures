/*
   Name: Trevor Scott
   Date: 03/19/2020
   Program: Project1:  Yaht-Z Game
   Description: This is the .cpp file for the header file of player.h
*/

#include "Player.h"

Player::Player(){
    //will be default if other conditions are not met
    dice[3];
    points =0;
    toss =3;
}
int Player::getPoints(){
    return points;
}

void Player::sortDie(){
    int temp;
    int min;
    for(int i =0; i<toss; i++){
        min = i;
        for(int j = i+1; j < toss; j++){
            if(dice[j].getValue() < dice[min].getValue()){
                min = j;
            }
        }
        //setting the value of min index position to temp
        temp = dice[min].getValue();
        //sorting the random value of i
        dice[min].setValue(dice[i].getValue());
        //setting back to temp
        dice[min].setValue(temp);
    }
}

void Player::displayValues(){
    //calling to sordie function
    sortDie();
    cout << "Rolling Dice... ";
    for(int i =0; i < toss; i++){
        if(i == 0){
            cout << "D1=" << dice[i].getValue() << " ";
        }
        if(i == 1){
            cout << "D2=" << dice[i].getValue() << " ";
        }
        if(i == 2){
            cout << "D3=" << dice[i].getValue() << " ";
        }
    }
}

bool Player::win1(){
    int d1 = dice[0].getValue();
    int d2 = dice[1].getValue();
    int d3 = dice[2].getValue();
    // all cases to have a series
    if(d3 == d2+1 && d2 == d1+1){
        return true;
    }
    else if( d1 == d2+2 && d3 ==d2+1){
        return true;
    }
    else if( d1 == d2+1 && d3 ==d2+2){
        return true;
    }
    else if( d1 == d2-2 && d3 ==d2-1){
        return true;
    }
    else if( d1 == d2-1 && d3 ==d2-2){
        return true;
    }
    else if( d1 == d2+1 && d3 ==d2-1){
        return true;
    }
    else if( d1 == d2-1 && d3 ==d2+1){
        return true;
    }
    return false;
}

bool Player::win2(){
    int d1 = dice[0].getValue();
    int d2 = dice[1].getValue();
    int d3 = dice[2].getValue();
    if(d1 == d2 || d2==d3 || d1 == d3){
        return true;
    }
    return false;
}
bool Player::win3(){
    int d1 = dice[0].getValue();
    int d2 = dice[1].getValue();
    int d3 = dice[2].getValue();
    if( d1 == d2 && d2 == d3){
        return true;
    }
    return false;
}
//what will actually happen
void Player::takeTurn(){
    for (int i =0; i < toss; i++){
        //random values
        dice[i].roll();
    }
    //display values
    displayValues();
    //cases for wins
    if(win3()){
        cout << endl;
        cout << "You got three of a kind!" << endl;
        points=points+3;
    }
    else if(win2()){
        cout << endl;
        cout << "You got a pair!" << endl;
        points=points+1;
    }
    else if(win1()){
        cout << endl;
        cout << "You got a series of 3!" << endl;
        points=points+2;
    }
    else{
        cout << endl;
        cout << "Awww.   Too Bad" << endl;
    }
    points = getPoints();
    cout << "Score = " << points << endl;
}
