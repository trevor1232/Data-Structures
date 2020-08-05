//
//  LinkedList.h
//  PLEASE WORK
//
//  Created by Trevor Scott on 4/26/20.
//  Copyright © 2020 Trevor Scott. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <vector>
#include "Song.h"
using namespace std;

class LinkedList  {
private:
    //data members
    struct Node{
        Song data;
        Node *next;
    };
    Node *first;
    
public:
    //Default Constructor
    LinkedList();
    /**
     will see if the node is empty
    @return returns true or false
     */
    bool isEmpty();
    /**
     Will add a song to a inkedlist
    @param selection - a object of the class Song.
     */
    void addSongLib(Song newSong);
    //Will return the size of the object of linkedlist
    int getSize();
    /**
     Will remove the song that is in front (the head)
     */
    Song removeSongLib();
    /**
     Will search for the matching songs of the respected title, and artist
    @param selection - a object of the class Song.
    @param selection - a object of the class Song.
     */
    Song searchSong(string title, string artist);
    /**
     Will search for the matching songs of the respected artist
    @param selection - a object of the class Song.
     */
    vector<Song> searchArtist(string artist);
    /**
     Will search for the matching songs of the respected decade
    @param selection - a value passed from pain to dearch for that decade
     */
    vector<Song> searchYear(int year);
    /**
     Will sort out all songs from ratings, highest to lowest
     */

    void sort();
    /**
     Will print out the Lnkedlist of songs.
    @param selection - passed from main the refrence of a linkedlist to analyze
     */
    friend ostream &operator<<(ostream&out, LinkedList &list);
};
#endif /* LinkedList_h */
