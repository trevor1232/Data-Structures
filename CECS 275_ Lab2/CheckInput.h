#ifndef CHECKINPUT_H
#define CHECKINPUT_H

/** 
 * Functions used to check console input for validity.
 *
 * Use:	Place CheckInput files (.h and .cpp) in the same location as your code.
 *	Import the .h file:  #include "CheckInput.h"
 *	Call CheckInput functions in your code.
 *
 * Example:  int num = getPositiveInt();
 *
 * @author Shannon Cleary 2020
 */

/**
 * Checks if the inputted value is an integer.
 * @return the valid input.
 */
int getInt();

/**
 * Checks if the inputted value is a non-negative integer.
 * @return the valid input.
 */
int getPositiveInt();

/**
 * Checks if the inputted value is an integer and 
 * within the specified range (ex: 1-10)
 * @param low lower bound of the range (inclusive).
 * @param high upper bound of the range (inclusive).
 * @return the valid input.
 */
int getIntRange(int low, int high);

/**
 * Checks if the inputted value is a double.
 * @return the valid input.
 */
double getDouble();

//my codes below
//done
/**
 * Takes in a yes/no from the user.
 * @return true if yes (or y), false if no (or n).
 */
bool getYesNo();

#endif
