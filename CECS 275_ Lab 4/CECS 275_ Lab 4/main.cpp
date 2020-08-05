/*
   Name: Trevor Scott
   Date: 02/16/2020
   Program: Lab 4:  Recursion
   Description: We're given data to then use recursion in our functions to find if the data is correct. I also wanted to point out that I did get help on stack overflow regarding this project for assistance on recursion

*/

//directives
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


/**Finds the Sum of the digits of num
 * @param num value to find the sum of
 * @return the sum of the digits
 */
int addDigits(int num);

/**Finds the nth Fibonacci value
 * @param f1 n-2 Fibonacci value
 * @param f2 n-1 Fibonacci value
 * @param c  counter
 * @param n  the number c should count up to
 * @return  the nth Fibonacci value
 * */

int revFibonacci(int f1, int f2, int c, int n);
/**Converts a binary string to decimal
 * @param bin the binary string
 * @return the decimal value
 */
int binToDec(string bin);

int main() {
    if(addDigits(428) == 14) {
        cout << "1. addDigits1 is correct!" << endl;
    }
    if(addDigits(321) == 6) {
        cout << "2. addDigits2 is correct!" << endl;
    }
    if(revFibonacci(0,1,1,5) == 5) {
        cout << "3. revFib1 is correct!" << endl;
    }
    if(revFibonacci(0,1,1,10) == 55) {
        cout << "4. revFib2 is correct!" << endl;
    }
    if(binToDec("1101100") == 108) {
        cout << "5. binToDec1 is correct!" << endl;
    }
    if(binToDec("1011101") == 93) {
        cout << "6. binToDec2 is correct!" << endl;
    }
}

int addDigits( int num )
{
    if (num != 0)
    {
        return (num % 10 + addDigits(num/10));
    }
    else
    {
        return 0;
    }
}
int revFibonacci( int f1, int f2, int c, int n )
{
    if (c == n -1)
    {
        return (f1 + f2);
    }
    return revFibonacci(f2, f1+ f2, c + 1, n);
}

int binToDec(string bin)
{
    //variables
    int decimal = bin.length() -1;
    int base = 2;
    if (decimal == 0)
    {
        if (bin[0] == '1')
        {
            return 1;
        }
        return 0;
    }
    
    else
    {
        if (bin[0] == '1')
        {
            return (pow(base, decimal)) + binToDec(bin.substr(1, bin.length() - 1));
        }
        return binToDec(bin.substr(1, bin.length() - 1));
    }
}
