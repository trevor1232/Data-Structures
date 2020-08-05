/*
   Name: Trevor Scott
   Date: 02/03/2020
   Program: Project1:  Memory Game
   Description: I made a game where you have to match all two pairs of cards from 16, and also the cards are flipped over initially and if two match they will stay flipped over if the two cards are not matched then they will be flipped back into their respectable number.
*/

//directives

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "CheckInput.h"

using namespace std;

/* The menu of the game in which the user inputs what type of cards they want to match
* @return the type of game the user wants to play: numbers, objects, etc.
*/
int getFileChoice();

/* Displays the board of the game
* @param array of values (strings)
* @param array of the boolean 2d array
*/

void displayBoard(string array[4][4], bool array1[4][4]);

/* Reads in the txt files
* @param array of values (strings)
* @param choice from the integer from main
* @return the txt file for the card game
 */

void readFile(string array[4][4], int choice);

/* Will shuffle the deck of cards that was read from readFile
* @param array of values (strings)
* @return the random deck of cards
*/

void shuffle(string array[4][4]);

/* will get the choice from user of which choice they picked.
 @return will return the value that was from pressed by user
*/

int getChoice();

/* Will flip the card that was typed by user
* @param will get choice from user of the value that was entered
* @param array of the boolean 2d array
* @return the card flip from the corresponding number
*/

void flipChoice(int choice, bool array1[4][4]);

/* Will see if the two cards entered are a match if not then will be flipped back down.
* @param choice 1 from user
* @param choice 2 from user
* @param array of the values (strings)
* @return if it's a match
*/

bool isMatch(int choice1, int choice2, string array[4][4]);

/* Will see if the card is already flipped
* @param choice 1 from user
* @param array of the boolean 2d array
* @return if it's flipped or not
*/

bool checkFlip(int choice, bool array1[4][4]);

int main(){
    // two 2d arrays
    int const rows =4;
    int const cols =4;
    string array[4][4];
    bool array1[4][4] = {
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false}
    };
    //where game will start
    cout << "Welcome to the Memory Game!" << endl;
    int GetNum;
    GetNum = getFileChoice();
    int count = 0;
    readFile(array, GetNum);
    shuffle(array);
    
    while(count !=8){
        displayBoard(array, array1);
        int choice1;
        cout << "Please enter the card choice" << endl;
        if(count == 0){
            choice1 = getChoice();
            flipChoice(choice1, array1);
            displayBoard(array, array1);
        }
        bool test1 = true;
        while(test1 == true && count>0){
            choice1 = getChoice();
            test1 = checkFlip(choice1, array1);
            if(!test1){
                flipChoice(choice1, array1);
                displayBoard(array, array1);
            }if(test1){
                cout <<"Invalid"<< endl;
            }
        }
        int choice2;
        cout << "Please enter another card choice" << endl;
        bool test = true;
        while(test == true){
            choice2 = getChoice();
            test = checkFlip(choice2, array1);
            if(!test){
                flipChoice(choice2, array1);
            }
            if(test){
                cout <<"Invalid"<< endl;
            }
        }
        displayBoard(array, array1);
        if(isMatch(choice1, choice2, array)){
            cout << "You found a match!" << endl;
            count++;
            if(count ==8){
                cout << "You Win!" << endl;
                cout << "Would you like to play again?" << endl;
                cout << "1.Yes"<< endl;
                cout << "2.No"<< endl;
                int again;
                again = getIntRange(1, 2);
                if(again==1){
                    return main();
                    count =0;
                    shuffle(array);
                    for(int i =0; i < rows; i++){
                        for( int j =0; j < cols; j++){
                            array1[i][j] = false;
                        }
                    }
                }else{
                    return 0;
                }
            }
        }else{
            cout << "Not Found" << endl;
            flipChoice(choice1, array1);
            flipChoice(choice2, array1);
        }
    }
}

bool checkFlip(int choice, bool array1[4][4]){
    int temp1;
    int temp2;
    temp1 = (choice-1)/4;
    temp2 = (choice-1)%4;
    if(array1[temp1][temp2] == true){
        return true;
    }
    return false;
}

bool isMatch(int choice1, int choice2, string array[4][4]){
    int temp1;
    int temp2;
    temp1 = (choice1-1)/4;
    temp2 = (choice1-1)%4;
    int temp3;
    int temp4;
    temp3 = (choice2-1)/4;
    temp4 = (choice2-1)%4;
    
    if(array[temp1][temp2]==array[temp3][temp4]){
        return true;
    }
   
    return false;
}

void displayBoard(string array[4][4], bool array1[4][4]){
    int count =1;
    for(int i =0; i < 4; i++){
        cout << " +----+ " << " +----+ " << " +----+ " << " +----+" << endl;
        cout << " |    | " << " |    | " << " |    |  " << "|    |" << endl;
        for(int j =0; j < 4; j++){
            if(array1[i][j]){
                cout << " |" << array[i][j] << "| ";
                count++;
            }
            else{
                if(count >= 10){
                    if(count >=13){
                        cout<< " | "<< count++ << " | ";
                    }
                    else{
                        cout<< " |"<< count++ << "  | ";
                    }
                }
                else{
                    cout<< " |"<< count++ << "   | ";
                }
            }
        }
        cout << endl;
        cout << " +----+ " << " +----+ " << " +----+ " << " +----+ " << endl;
    }
}

void flipChoice(int choice, bool array1[4][4]){
    int temp1;
    int temp2;
    temp1 = (choice-1)/4;
    temp2 = (choice-1)%4;
    if(array1[temp1][temp2] == false){
         array1[temp1][temp2] = true;
    }
    else{
         array1[temp1][temp2] = false;
    }
}

int getChoice(){
    int getNum;
    getNum=getIntRange(1, 16);
    return getNum;
}
              
void shuffle(string array[4][4]){
    srand(time(0));
    for(int i =0; i < 100; i++){
        int indexR1 = rand() %4;
        int indexC1 = rand() %4;
        int indexR2 = rand() %4;
        int indexC2 = rand() %4;
        string swap = array[indexR1][indexC1];
        array[indexR1][indexC1] = array[indexR2][indexC2];
        array[indexR2][indexC2] = swap;
    }
}
void readFile(string array[4][4], int choice){
    fstream file;
    string input;
    if( choice == 1){
        file.open("letters.txt", ios::in);
    }
    if( choice == 2){
        file.open("numbers.txt", ios::in);
    }
    if( choice == 3){
        file.open("animals.txt", ios::in);;
    }
    if( choice == 4){
        file.open("objects.txt", ios::in);
    }
    int position = 1;
    int pair = 2;
    while(getline(file, input)){
        for(int i =0; i < pair; i++){
            int rows = (position-1)/4;
            int cols = (position-1)%4;
            array[rows][cols] = input;
            position = 1+position;
        }
    }
    file.close();
}

int getFileChoice(){
    int get;
    cout << "1.  Letters" << endl;
    cout << "2.  Numbers" << endl;
    cout << "3.  Animals" << endl;
    cout << "4.  Objects" << endl;
    get = getIntRange(1, 4);
    return get;
}
