//
//THis is the BST.cpp file

//directives

#include <stdio.h>
#include "BST.h"
#include "Word.h"

//adding word to BST
void BST::add(Word val) {
    Node *newNode = new Node;
    newNode->value = &val;
    newNode->left = NULL;
    newNode->right = NULL;
    add( newNode, root);
}

void BST::add(Node *&newNode, Node *&tree) {
    if( tree == NULL ) {
        tree = newNode;
    }
    else if (newNode->value == tree->value) {
        tree->value += 1;
    }
    else if ( newNode->value < tree->value ){
        add( newNode, tree->left );
    }
    else{
        add( newNode, tree->right);
    }
}



void BST::clear( Node *tree ) {
    if( tree != NULL ) {
        clear( tree->left );
        clear( tree->right );
        delete tree;
    }
}

//will print out everything in root
void BST::print() {
    print(root);
    cout<< endl;
}



void BST::print(Node *tree ) {
    if( tree!= NULL ) {
        cout << tree << " ";
        print( tree->left);
        print( tree->right );
    }
}
