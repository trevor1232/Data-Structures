
//Directives
#include <iostream>
#include "CheckInput.h"
using namespace std;

int getInt( ) {
    
    int input = 0;
    bool valid = false;
    while(!valid) {
        if(cin >> input) {
            valid = true;
        } else {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout<< "Invalid Input" << endl;
        }
    }
    return input;
}

/* gets a valid positive integer (including 0) from the user */
int getPositiveInt( ) {
	int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			if(input >= 0) {
				valid = true;
			} else {
				cout<< "Invalid Input" << endl;
			}
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid Input" << endl;
		}
	}
	return input;
}

/* gets a valid integer between the two parameters (inclusive) */
int getIntRange(int low, int high) {
	int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			if(input >= low && input <= high) {
				valid = true;
			} else {
				cout<< "Invalid Input" << endl;
			}
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid Input" << endl;
		}
	}
	return input;
}

/* gets a valid double from the user */
double getDouble( ) {
	double input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			valid = true;
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid Input" << endl;
		}
	}
	return input;
}

/* gets a valid yes/no answer from the user and returns true if yes, false if no */
bool getYesNo( ) {
	string input;
	bool valid = false;
	while(!valid) {
		cin >> input;
		if(input == "yes" || input == "Yes" || input == "YES" || input == "Y" || input == "y") {
			return true;
		} else if(input == "no" || input == "No" || input == "NO" || input == "N" || input == "n") {
			return false;
		} else {
			cout<< "Invalid Input" << endl;
		}
	}
	return false;
}

/*
 *
 *
 *                                      MY CODES ARE BELOW OF MY FUNCTIONS
 *
 *
 */





