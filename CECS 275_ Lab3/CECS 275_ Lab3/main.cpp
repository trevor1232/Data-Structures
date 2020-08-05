/*
   Name: Trevor Scott
   Date: 02/07/2020
   Program: Lab 3:  Statistical Analysis
   Description: We're given data from a txt file and it's our job to find the median, average, maximum, minimum, and to sort the grades out.

*/

#include <iostream>
#include <vector>
#include "CheckInput.h"
#include <fstream>
#include <string>

using namespace std;

/* createCopy: will perform get the information from the file then return that to a vector;
* @param is a vector for the information to be sent o
*/

vector<int> createCopy(vector<int>& list);

/* displayGrades: will display all grades in rows and cols fassion
* @param num1 will get a refrence from the vector and return it back to the original one.
*/
void displayGrades(vector<int>&list);

/* sumGrades: Will sort it from least to greatest of grades
* @param num1 will get a refrence from the vector and return it back to the original one.
*/
void sortList(vector<int>&list);

/* sumGrades: Will sum up the numbers in the text file
* @param num1 will get a refrence from the vector and return it back to the original one.
 @return the sum of vectors.
*/
int sumGrades(vector<int>&list);

/* findMedian: Will find the median of the sorted list
* @param num1 will get a refrence from the vector and return it back to the original one.
 @return will return the sum amount
*/
double findMedian(vector<int>&list);

/* displayMenu: WIll show a constant menu for the user to see until the user exits.
*  @return will return the median
*/
void displayMenu();


int main(){
    //a copy vector
    vector<int> copy;
    //function will send a copy to copy
    createCopy(copy);
    
    displayMenu();
    int pick;
    while (pick = getIntRange(1, 6)) {
        // Display Sorted Grades
        if(pick ==1){
            sortList(copy);
            displayGrades(copy);
            
        }
        // Display Average Grade
        if (pick == 2) {
            float sum;
            sum = sumGrades(copy);
            const double value = sum/copy.size();
            cout<<"The average was: " <<fixed << setprecision(1) <<  value << endl;
        }
        // Display Maximum Grade
        if (pick == 3) {
            sortList(copy);
            float max = copy.at(copy.size()-1);
            cout << "The Maximum was : " << fixed << setprecision(1) << max << endl;
        }
        //Display Minimum Grade
        if (pick == 4) {
            sortList(copy);
            float min = copy.at(0);
            cout << "The Minimum was : " << fixed << setprecision(1) << min << endl;
        }
        // Display Median Grade
        if (pick == 5) {
            //double median will recieve the function findMedian();
            sortList(copy);
            double median;
            median = findMedian(copy);
            cout << "The Median is : "  << fixed << setprecision(1)<< median << endl;
        }
        // Quit
        if (pick == 6) {
            exit(0);
        }
        displayMenu();
    }
}

double findMedian(vector<int>&list){
    if(list.size() % 2 == 0){
 
        return (list[list.size()/2-1]+list[list.size()/2])/2.0;
    }
    else{
        return list[list.size()/2.0];
    }
}


void sortList(vector<int>&list){
    bool swapped = false;
    do {
        swapped = false;
        for( int i =0; i < list.size()-1; i ++) {
            if( list[i] > list[i+1]){
                int swap = list[i];
                list[i] = list[i+1];
                list[i + 1] = swap;
                swapped = true;
            }
        }
    } while(swapped);
}

vector<int> createCopy(vector<int> &list) {
    fstream file;
    int input;
    file.open("grades.txt", ios::in);
    if(file){
        while(file >> input){
           // cout << input << endl;
            list.push_back(input);
        }
        file.close();
    }
    else{
        cout << "N/A";
    }
    return list;
}

void displayGrades(vector<int>&list){
    for( int i =0; i < list.size(); i++){
        if(i % 10 == 0){
            cout <<  endl;
        }
        cout <<list[i] << ",";
        if(i == list.size()-1){
            cout <<endl;
        }
    }
}

int sumGrades(vector<int>&list){
    int adder =0;
    for(int i =0; i < list.size(); i++){
        adder=list[i]+adder;
    }
    return adder;
}




void displayMenu() {
    cout << "1. Display Sorted Grades" << endl;
    cout << "2. Display Average Grade" << endl;
    cout << "3. Display Maximum Grade" << endl;
    cout << "4. Display Minimum Grade" << endl;
    cout << "5. Display Median Grade" << endl;
    cout << "6. Quit" << endl;
}
