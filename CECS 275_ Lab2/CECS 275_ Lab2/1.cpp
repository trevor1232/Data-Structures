/*
   Name: Trevor Scott
   Date: 01/28/2020
   Program: Lab 2: Arrays
   Description: The objective for this program is to have the user input ten digits to an array, and then the program will evaluate the array and prompt the user with 8 opitions to do with their array from changing it to finding the maximum value, and more.

*/



/* DisplayValues: Will use size in terms of looping for array to display values.
 * @param num1 will get a pass by refrence array
 * @param num2 will get the pass by int of max_size to loop for array
 */
void DisplayValues(int array[], int size);

/* DisplayReversed: Will use size and have it equal to a variable so it will loop as an opposite way
* compare to DisplayValues.
* @param num1 will get a pass by refrence array
* @param num2 will get the pass by int of max_size to loop for array
*/
void DisplayReversed(int array[], int size);

/* Sum: Will display the sum of the array that is pass to it's parameter. It will return the value
* back into main.
* @param num1 will get a pass by refrence array
* @param num2 will get the pass by int of max_size to loop for array to get it's respected
* elements.
* @return the sum of the array
*/
int Sum(int array[], int size);

/* Maximum: Will display the largest element of the array that is pass to it's parameter, and It will
* return the value back into main.
* @param num1 will get a pass by refrence array
* @param num2 will get the pass by int of max_size to loop for array to get it's respected
* elements.
* @return the max of the array
*/
int Maximum(int array[], int size);

/* Search: Will display the element that was requested to be searched and them return the position
* index of it's location. (base of 1)
* @param num1 will get a pass by refrence array
* @param num2 will get the pass by int of max_size to loop for array to get it's respected
* elements.
* @param num3 will get a refrence from main when user is prompt to enter the number to be searched.
* @return the search index of the array location.
*/
int Search(int array[], int size, int find);

//
/* Insert: Will overwrite whatever element that the user asked to replace for another element
* @param num1 will get a pass by refrence array
* @param num2 will get the pass by int of max_size to loop for array to get it's respected
* elements.
* @param num3 will get a pass by refrence of the value that was prompt to the user and compare it in a
* loop.
*/
void Insert(int array[], int findInt1, int findInt2);

/* PopulateArray: Will display a new array for the user to enter.
* @param num2 will get the pass by int of max_size to loop for array to get it's respected
* elements.
* @param num3 will get a pass by refrence of the value that was prompt to the user and compare it in a
* loop
*/
void PopulateArray(int array[], int size);

/* Menu: Will keep looping until the user enters 8
*/
void Menu();


//Directives
#include <iostream>
#include "CheckInput.h"

using namespace std;
int main(){
    
    // const int max_size sets the max for the array
    const int max_size = 10;
    //An array of a max sixe of 10 since of the int
    int array1[max_size];
    cout << "Hello," << endl;
    
    PopulateArray(array1, max_size);
    

 
    //int pick is for the use to pick from 1 to 8 choices to perform the functions
    int pick;
        
    Menu();
    
    // This will keep looping for the user so they can perfrom another action after the respected  function is executed
    while(pick = getInt()){
        if( pick == 1){
            DisplayValues(array1, max_size);
        }
        if(pick == 2){
            DisplayReversed(array1, max_size);
        }
        if(pick ==3){
            // take1 will take the return value
            int take1;
            take1 = Sum(array1, max_size);
            cout << take1 << endl;
        }
        if(pick==4){
            // take3 will take the return value
            int take3;
            take3 = Maximum(array1, max_size);
            cout << "Your Largest Number is: " << take3 << endl;
        }
        if(pick==5){
            // take2 will take the return value
            int take2;
            // find1 will be passed for the function search() to find the location of the element
            int find1;
            cout << "Please enter the value to be searched : " << endl; // in main ask not here
            cin >> find1;
            take2 = Search(array1, max_size, find1);
            
            if(take2 == -1){
                cout << "ERROR: Element was not found" << endl;
            }if(take2 != -1){
                cout << "Found index at: " << take2 << endl;
            }
        }
        if(pick==6){
            // find2 will be used to pass to the function of the element needed to be found
            int find2;
            int find4;
            cout << "Please enter the location of the value to be replaced, and the new value : " << endl;
            find2 =getIntRange(1, 10);
          //  cout << "Please enter the new value:" <<endl;
            find4= getInt();
            Insert(array1, find2, find4);
        }
        if(pick==7){
            PopulateArray(array1, max_size);
        }
        if(pick == 8){
            exit(0);
        }
        Menu();
    }
}
/*
 *  Note int i is used as a counter
*/
void DisplayValues(int array[], int size){
    for(int i =0; i <size; i++){
        if(i==0){
            cout << array[i];
        }
        else{
            cout << "," << array[i];
        }
    }
    cout << endl;
}


int Sum(int array[], int size){
    int x = 0;
    for(int i =0; i <size; i++){
        x=array[i]+x;
    }
    // cout << x;
    return x;
}


void DisplayReversed(int array[], int size){
    for(int i = size-1; i >= 0; i--){
        
        if(i== size-1){
            cout << array[i];
        }
        else{
            cout << "," << array[i];
        }
    }
    cout << endl;
}


int Search(int array[], int size, int find){
    for ( int i =0; i < size; i++){
        if( find == array[i]){
            return i+1;
        }
    }
    return -1;
}


int Maximum(int array[], int size){
    int findNum = array[0];
    for(int i = 0; i < size; i++){
        if(findNum < array[i]){
           findNum = array[i];
        }
    }
    return findNum;;
}


void Insert(int array[], int findInt1, int findInt2){
    bool valueFound = false;
    for ( int i =0; (i < findInt1) && !valueFound; i++){
        if( findInt1 == array[i]){
            //cout << "Please enter the new value:" <<endl;
            //array[i] = getInt();
            array[i] = findInt2;
            valueFound = true;
            // or break;
        }
    }
}


void PopulateArray(int array[], int size){
    cout << "Please enter 10 digits: " << endl;
    for(int i = 0; i < size; i++){
        array[i] = getInt();
    }
}


void Menu(){
     cout << "Please pick from the menu"<< endl;
     cout <<"1. Display Values" << endl;
     cout <<"2. Display Reversed" << endl;
     cout <<"3. Display Sum" << endl;
     cout <<"4. Display Maximum" << endl;
     cout <<"5. Search for a Value" << endl;
     cout <<"6. Insert new Value" << endl;
     cout <<"7. Reset Values" << endl;
     cout <<"8. Quit" << endl;
}


