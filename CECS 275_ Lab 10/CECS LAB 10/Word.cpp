//
//  Word.cpp
//  CECS LAB 10
//
//  Created by Trevor Scott on 5/5/20.
//  Copyright © 2020 Trevor Scott. All rights reserved.
//

#include <stdio.h>
#include "Word.h"
#include "BST.h"

Word::Word() {
    word = "";
    freq = 1;
}

Word::Word(string input) {
    word = input;
    freq = 1;
}

Word::Word(string input, int amount) {
    word = input;
    freq = amount;
}


ostream & operator<< (ostream & out, Word * myWord)  {
    out << "Word : " << myWord->word << "\n" << "Freq : " << myWord->freq << endl;
    return out;
}


bool Word::operator< (const Word & aWord)  {

    return (word < aWord.word);

}

bool Word::operator<=  (const Word & aWord)  {
    return (word <= aWord.word);
}

bool Word::operator== (const Word & aWord)  {
    return (word == aWord.word);
}

string Word::getWord() {
    return word;
}

int Word::getFreq() {
    return freq;
}

void Word::increment() {
    freq += 1;
}


