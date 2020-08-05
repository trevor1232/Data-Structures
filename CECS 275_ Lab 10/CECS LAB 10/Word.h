//Word.h file
#ifndef WORD_H
#define WORD_H
//directives
#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

class BST;

class Word {

    private:

    // An object of BST
        friend class BST;
        friend BST readFromFile();
    // Data members!
        string word;
        int    freq;

    public:
    //friend functions
        friend ostream & operator<< (ostream & out, Word * myWord);
        friend ostream & operator<< (ostream & out, Word myWord);
    // Default constructor
        Word();
    //constructor
    ///Param string- will intake from words
        Word(string);
    //constructor
    ///Param int- will intake number for frequency
        Word(string, int);
    
        string getWord();
    // Will get the frequency
        int getFreq();
    //Will make an increment functions
        void increment();
    
    //Overload operators <, <=, and ==
    //This if for word objects
        bool operator<  (const Word & aWord);
        bool operator<= (const Word & aWord);
        bool operator== (const Word & aWord);

};

#endif // WORD_H
