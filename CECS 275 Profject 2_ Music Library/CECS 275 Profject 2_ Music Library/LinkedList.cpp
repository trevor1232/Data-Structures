
#include <stdio.h>
#include "LinkedList.h"
#include "Song.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

LinkedList::LinkedList(){
        first = NULL;
}

bool LinkedList::isEmpty() {
    
    return first == NULL;
}

Song LinkedList::removeSongLib()  {
    Song returnSong;
    if(first != NULL){
        returnSong = first ->data;
        if(getSize() == 1){
            delete first;
            first = NULL;
        } else {
            Node *tempNode = first->next;
            delete first;
            first = tempNode;
        }
    }
    return returnSong;
}

void LinkedList::addSongLib(Song newSong)  {
    Node *next = new Node;
    next->data=newSong;
    next->next = NULL;
    if (first == NULL)
    {
        first = next;
    }
    else
    {
        Node *n = first;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = next;
    }
}


Song LinkedList::searchSong(string title, string artist)  {
    Node *n=first;
    while(n-> next !=NULL){
        if(title == n->data.getTitle() && artist == n->data.getArtist()){
            return n->data;
        }
        n=n->next;
    }
    return Song();
}

vector<Song> LinkedList::searchArtist(string artist)  {
    vector<Song> songList;
    Node *n = first;
    while(n!=NULL){
        if(n-> data.getArtist() == artist){
            songList.push_back(n->data);
        }
        n = n->next;
    }
    return songList;
}

vector<Song> LinkedList::searchYear(int decade)  {
    vector<Song> decadeList;
    int lowend = decade;
    int highend = decade +9;
    Node *n = first;
    while(n-> next !=NULL){
        if(n->data.getYear() >= lowend && n-> data.getYear()<=highend){
            decadeList.push_back(n->data);
        }
        n=n->next;
    }
    return decadeList;
}

int LinkedList::getSize()  {

    Node *n = first;
    int count = 0;
    while (n != NULL)
    {
        n = n->next;
        count++;
    }
    return count;
}


void LinkedList::sort(){
    bool swapped = false;
    do {
        Node *n = first;
        swapped = false;
        while(n->next !=NULL){
            if(n->next-> data > n->data){
                Song swap = n->data;
                n->data = n->next->data;
                n->next->data = swap;
                swapped = true;
            }
            n= n->next;
        }
    } while(swapped);
}


ostream &operator<<(ostream&out, LinkedList &list){
    
    LinkedList::Node *n;
    n=list.first;
    while(n!=NULL){
        out << n->data.getTitle() << ",";
        out << n->data.getArtist() << ",";
        out << n->data.getYear() << ",";
        out << n->data.getRating() << endl;
        n=n->next;
    }
    return out;
}
