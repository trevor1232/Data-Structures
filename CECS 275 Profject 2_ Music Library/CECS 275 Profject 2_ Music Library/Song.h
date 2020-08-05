//
//  Song.h
//  PLEASE WORK
//
//  Created by Trevor Scott on 4/26/20.
//  Copyright © 2020 Trevor Scott. All rights reserved.
//

#ifndef Song_h
#define Song_h
#include <string>
#include <vector>

using namespace std;

class Song{
    private:
        //data members
        string title;
        string artist;
        int year;
        int rating;
    
    public:
    /** Song Constructor - Constructs a song with passed in string parameters
        @param titla - title from file.
        @param strista - artist from file.
        @param yeara - album from file..
    @param yeara - album from file..
        */
        Song(string titlea, string artista,  string yeara, string ratinga);
    /** Song Constructor - Constructs a song with passed in string parameters
        @param titla - title from file.
        @param strista - artist from file.
        @param yeara - album from file..
        @param yeara - album from file..
    @param ratinga - album from file..
        */
        Song(string titlea, string artista, int yeara, int ratinga);
    //Default constrcutor
        Song();
    /** Overloaded output operator; enables a formatted output for
    Fraction objects.
    @return out - the io stream with the desired output. */
        friend ostream & operator<< (ostream & out, Song mySong);
    /* Overloaded input operator; allows user inputs to be assigned
    to specific class traits in one call.
    @return in - the input stream with the user's values. */
        friend istream  &operator>> (istream &in, Song & mySong);
    /** Overloaded Greater Than Operator
    @param song - song object.
    @return bool - true or false. */
        bool operator>  (const Song & song);
    /** Overloaded Equivalence Operator
    @param song - song object.
    @return bool - true or false. */
        bool operator== (const Song &song);
    
    //get titles for data members
        string getTitle();
        string getArtist();
        int         getYear();
        int         getRating();
    
    
    
    
};

#endif /* Song_h */
