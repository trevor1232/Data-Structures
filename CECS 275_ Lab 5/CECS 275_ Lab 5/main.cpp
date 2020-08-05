/*
   Name: Trevor Scott
   Date: 02/20/2020
   Program: Lab 5:  Recursion2
   Description: We're given data to then use recursion in our functions to find if the data is correct. I also wanted to point out that I did get help on stack overflow regarding this project for assistance on recursion

*/

#include <iostream>
#include "CheckInput.h"
#include <string>

using namespace std;

//My functions

/* Finds the maximum value in an array
* @param array array of values (sorted or unsorted)
* @param size length of the array
* @return the max valur of the array after he had gone throw another fucntion specifically a recursive functions.
*/
int findMax(int array [], int size);

/* Finds the minimum value in an array
* @param array array of values (sorted or unsorted)
* @param size length of the array
* @return the minimum valur of the array after he had gone throw another fucntion specifically a recursive functions.
*/
int findMin(int array [], int size);


/* Finds the maximum value in an array
 * @param array array of values (sorted or unsorted)
 * @param size length of the array
 * @param i iterator
 * @param max maximum value found so far
 * @return maximum value
 */

int maxArray( int array[], int size, int i, int max );

/* Finds the minimum value in an array
 * @param array array of values (sorted or unsorted)
 * @param size length of the array
 * @param i iterator
 * @param min minimum value found so far
 * @return minimum value
 */
int minArray( int array [], int size, int i, int min );

/* Reverses a string
 * @param s the string to reverse
 * @return the reversed string
 */
string reverseStr( string s );

/* Returns the number of times c appears in the string str
 * @param str string to test
 * @param c character to find
 * @return number of times the character appeared in the string
 */
int charFrequency( string str, char c );

//Write your facade functions findMin & findMax here

int main( ) {
    int array [] = { 46, 22, 7, 58, 91, 55, 31, 84, 12, 78 };
    if( findMax( array, 10 ) == 91 ) {
        cout<< "findMax is correct!" <<endl;
    }
    if( findMin( array, 10 ) == 7 ) {
        cout<< "findMin is correct!" <<endl;
    }
    if( reverseStr( "Hello" ) == "olleH" ) {
        cout<< "reverseString1 is correct!" <<endl;
    }
    if( reverseStr( "pupils" ) == "slipup" ) {
        cout<< "reverseString2 is correct!" <<endl;
    }
    if( charFrequency( "The quick brown fox jumps over the lazy dog.", 'o' ) == 4 ) {
        cout<< "charFrequency1 is correct!" <<endl;
    }
    if( charFrequency( "The quick brown fox jumps over the lazy dog.", 'e' ) == 3 ) {
        cout<< "charFrequency2 is correct!" <<endl;
    }
}

int charFrequency( string str, char c ){
    int temp = str.length()-1;
    if(0 < str.length()){
        if(str.at(temp) != c){
            return charFrequency(str.substr(0,temp), c);
        }
        return 1 + charFrequency(str.substr(0,temp), c);
    }
    return 0;
}

string reverseStr( string s ){
    if(0 < s.length()){
        int temp = s.length()-1;
        return s.at(temp)+reverseStr(s.substr(0,temp));
    }
    return s;
}

int minArray( int array [], int size, int i, int min ){
    if(i < size){
        if(min > array[i]){
            min = array[i];
        }
        return minArray(array, size, i+1, min);
    }
    return min;
}

int findMin(int array [], int size){
    return minArray(array, size, 0, array[0]);
}

int maxArray( int array[], int size, int i, int max ){
    if(i != size){
        if(max < array[i]){
            max = array[i];
        }
        return maxArray(array, size, i+1, max);
    }
    return max;
}

int findMax(int array [], int size){
    return maxArray(array, size, 0, array[0]);
}
