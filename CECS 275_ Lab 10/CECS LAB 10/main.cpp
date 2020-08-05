/*
   Name: Trevor Scott
   Date: 05/07/2020
   Program: Lab 10 : Music Library
   Description: I couldn't finish this program, I got outside sources but even from that I couldn't. I appreciate any credit I can get from this, thank you, but the project is suppose to use a binary search tree to find words, and count how often they're used in txt. file. Also to display the txt file.
*/

//Directives
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include "Word.h"
#include "BST.h"

using namespace std;

//functions

/**
 WIll print out the word and how often it is used in BST
@param ostream&out - selection from user.
@param BST TREE - object from file to find a song from it's linkedlist node
 */
ostream & operator<< (ostream & out, BST tree);
/**
 WIll print out the tree of Word object in order
@param ostream&out - selection from user.
@param Word-
 */
ostream & operator<< (ostream & out, Word myWord);
BST readFromFile();
/**
 WIll print out eveything in text file
@return the words from text file-
 */
void case1 ();
/**
 WIll print out the frequency of the word that was entered from user
@return the amount of time the word appears
 */
void case2 ();
/**
this will validate the user's input
@return the choice from the three the user wants
 */
int valid();
/**
 A repeating menu for the user until her or she enters 3 to exist
@return The menu
 */
void menu();


int main() {
    BST tree = readFromFile();
    tree.print();
    bool loop = true;
    while (loop) {
        menu();
        int selection = valid();
        switch (selection) {
            case 1 : case1();
             break;
            case 2 : case2();
             break;
            case 3 : loop = false;
             break;
        }
        //case 3
        if(selection==0){
            return 0;
        }
    }
    return 0;
}


void menu() {

    cout << "MENU" << endl;
    cout << endl;
    cout << "Print : 1" << endl;
    cout << "Search: 2" << endl;
    cout << "Quit  : 3" << endl;
}

ostream & operator<< (ostream & out, BST tree)  {
    cout << endl;
    out << "Word : " << tree.click.value->getWord() << endl;
    cout << "Freq : " << tree.click.value->getFreq() << endl;

    return out;

}


BST readFromFile() {

    BST tree;
    vector<Word> wordVec;
    ifstream file;
    file.open ("words.txt");
    string word;

    while (getline(file,word))  {
        Word myWord = Word(word);
        tree.add(myWord);
        cout << myWord << endl;
        cout << tree << endl;
        cout << "here" << endl;
    }
    return tree;
}

ostream & operator<< (ostream & out, Word myWord)  {
    cout << endl;
    out << "Word : " << myWord.word << endl;
    cout << "Freq : " << myWord.freq << endl;

    return out;

}

int valid(){
    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection <= 3)  {
                fail = false;
            }
            else  {
                cout << "Invalid entry, please enter a number between 1 and 3." << endl;
            }
        }
        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and 3." << endl;
        }
    }
    return selection;
}

void case1 (){
    BST tree = readFromFile();
    tree.print();
}
void case2 (){
    BST tree = readFromFile();
  //  int selection = tree.getFreq();
}
