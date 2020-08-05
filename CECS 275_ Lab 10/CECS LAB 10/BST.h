//BST.h file

#ifndef BST_H
#define BST_H
//Directives
#include <iostream>
#include "Word.h"

using namespace std;

//gets a class of Word
class Word;

// Class of BST
class BST {

    //private functions and data members
    private:
        
    //Sturcture Node
    //And node pointers
        struct Node {
            Word *value;
            Node *left;
            Node *right;
        }click;
        Node *root;
        void add( Node *&, Node *& );
        void print( Node * );
        void clear( Node * );

    public:
    /**
    WIll make a friend class of word
    */
       friend class Word;
    //Will read from file
       friend BST readFromFile();
    
       friend ostream & operator<< (ostream & out, BST tree);

    //WIll make root to NULL
        BST() {
            root = NULL;
        }
    //WIll check if root is empty
        bool isEmpty() {
            return root == NULL;
        }
    /**
        will add a object word to binary tree
    @param word - selection from user.
     */
        void add( Word );
    //Will print out the tree.
        void print();
    //will clear everything out everything from tree!
        void clear( ){
            clear( root );
        }

};

#endif
