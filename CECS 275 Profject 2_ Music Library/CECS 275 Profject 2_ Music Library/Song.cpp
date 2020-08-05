//
//  Song.cpp
//  PLEASE WORK
//
//  Created by Trevor Scott on 4/26/20.
//  Copyright © 2020 Trevor Scott. All rights reserved.
//

#include <stdio.h>
#include "Song.h"
#include "LinkedList.h"
#include "CheckInput.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


Song::Song(string titlea, string artista,  string yeara, string ratinga)  {

    title  = titlea;
    artist = artista;
    int x = stoi (yeara);
    int y = stoi (ratinga);
    
    year = x;
    rating =y;
}
Song::Song(string titlea, string artista, int yeara, int ratinga)  {

    title  = titlea;
    artist = artista;
    year   = yeara;
    rating = ratinga;

}
Song::Song()  {

    title  = "";
    artist = "";
    year   =  0;
    rating =0;

}
ostream & operator<< (ostream & out, Song mySong)  {

    out << mySong.getTitle()  <<  ","
        << mySong.getArtist() <<  ","
        << mySong.getYear()   << ","
        << mySong.getRating() <<endl;

    return out;

}
istream & operator>> (istream & in, Song & mySong)  {

    string title;
    string artist;
    int rating;
    int year;

    cout << "\nPlease enter a title : ";
    cin.ignore();
    getline(cin, title);
    cin.clear();

    cout << "Please enter an artist : ";
    getline(std::cin, artist);
    cin.clear();

    bool gotInt = false;
    while (!gotInt) {
        cout << "Please enter a year : ";
        if (year=getPositiveInt()) {
            gotInt = true;
        }
        else {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter an integer.\n" << endl;
        }
    }
    
    bool gotInt0 = false;
    while (!gotInt0) {
        cout << "Please enter a rating : ";
        if (rating = getIntRange(1, 5)) {
            gotInt0 = true;
        }
        else {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter an integer.\n" << endl;
        }
    }
    
    mySong.title  = title;
    mySong.artist = artist;
    mySong.year   = year;
    mySong.rating = rating;

    return in;

}

bool Song::operator> (const Song & song)  {

    if(rating > song.rating){
        return true;
    }
    if(rating == song.rating){
        if(artist > song.artist){
            return true;
        }
        if(artist == song.artist){
            if(title > song.title){
                return true;
            }
        }
    }
    return false;
}
    
    
bool Song::operator== (const Song & song)  {

    if (title  == song.title  && artist == song.artist){
        return true;
    }
    else {
        return false;
    }

}
string Song::getTitle()  {
    return title;
}
string Song::getArtist()  {
    return artist;
}
int Song::getYear()  {
    return year;
}

int Song::getRating()  {
    return rating;
}

