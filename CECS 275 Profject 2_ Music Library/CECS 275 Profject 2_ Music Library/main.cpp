/*
   Name: Trevor Scott
   Date: 04/29/2020
   Program: Project2: Music Library
   Description: This program is designed to perform as a sort of music library where you can search, add, remove, and display songs. It uses a linkedlst search base where it use the nodes to locate specific objects or parts of an object.
*/

//directives
#include <iostream>
#include "Song.h"
#include <sstream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include <vector>
#include "CheckInput.h"
using namespace std;

/**will give a menu for the user to see
 @return will return the selection that the user wants
 */
int menu();

/**
 Will give the songs that are needed to be searched
@param selection - selection from user.
@param LinkedList - object from file to find a song from it's linkedlist node
 */
void searchSong(int selection, LinkedList libObj);
/**
 Will remove the song tthat is in front
@param LinkedList - object from file to find a song from it's linkedlist node
 */
LinkedList removeMenu( LinkedList libObj);
/**
 will give the user  menu to select from the following..
@return will return a valid selection from user
 */
int validateMenu();
/**
 will give the user  menu to select from the following..
@return will return a valid selection from user
 */
int searchMenuValidate();
/**
 Will have the user put in a song to add
@param LinkedList - object from file to find a song from it's linkedlist node
@return a new song for libObj
 */
LinkedList addSong(LinkedList libObj);
/**
 Will have selections for the user to pick, and perform actions
@param selection - selection from user.
@param LinkedList - object from file to find a song from it's linkedlist node
 */
void searchSong(int selection, LinkedList libObj);
/*
 will read from file of songs.txt then have it in a linkedlist
@param LinkedList - Object that will have the data be sent to
 */
void readFile(LinkedList &libObj);
/*
 will write from file of linkedlist and override the txt file
@param LinkedList - Object that will have the data be extracted from
 */
void writeFile(LinkedList &libObj);


 
int main(){
    LinkedList libObj;
    readFile(libObj);
    libObj.sort();
    bool cont = true;
    while (cont)  {
        libObj.sort();
        int selection = menu();
        if (selection == 1)  {
            libObj = addSong(libObj);
        }
        else if (selection == 2){
            libObj = removeMenu( libObj);
            
        }
        else if(selection == 3){
            int selection;
            searchSong(selection, libObj);
        }
        else if (selection == 4){
            libObj.sort();
            cout << "There is a total of: " << libObj.getSize() << " songs"<< endl;
            cout << endl;
            cout << "Songs: " << endl;
            cout << endl;
            cout << libObj<< endl;
        }
        else if (selection == 5){
            cout << "File changes have been saved....." << endl;
            cont = false;
            writeFile(libObj);
        }
    }
    return 0;
}



int menu()  {
    cout << "Music Library Program:" << endl;
    cout << endl;
    cout << "1. Add a Song" << endl;
    cout << "2. Play" << endl;
    cout << "3. Search For A Song" << endl;
    cout << "4. Display" << endl;
    cout << "5. Quit Program" << endl;
    cout << endl;
    int selection = validateMenu();
    return selection;
}



LinkedList removeMenu( LinkedList libObj)  {

    libObj.sort();
    cout << endl;
    cout << endl;
    cout << "Playing Song.... " << endl;
    
    Song get =libObj.removeSongLib();
    cout << get << endl;
    cout << endl;
    return libObj;
}



int validateMenu(){

    bool fail = true;
    int selection;

    while (fail)  {
        if (cin >> selection)  {
            if (selection >= 1 && selection <= 5)  {
                fail = false;
            }
            else  {
                cout << "Invalid entry, please enter a number between 1 and 5." << endl;
            }
        }
        else{
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and 5." << endl;
        }
    }
    return selection;
}



int searchMenuValidate(){
    bool fail = true;
    int selection;

    while (fail){
        if (cin >> selection){
            if (selection >= 1 && selection <= 4){
                fail = false;
            }
            else  {
                cout << "Invalid entry, Please enter a number between 1 and 4." << std::endl;
            }
        }
        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, Please enter a number between 1 and 4." << std::endl;
        }
    }
    return selection;
}



LinkedList addSong(LinkedList libObj)  {
    Song newSong;
    cin >> newSong;
    libObj.addSongLib(newSong);
    cout << endl;
    return libObj;
}



void searchSong(int selection, LinkedList libObj)  {
    cout << endl;
    bool check=false;
        while(!check){
            
            cout << "\nSearch By:" << endl;
            cout << "1: Title & Artist" << endl;
            cout << "2: Artist" << endl;
            cout << "3: Decade" << endl;
            cout << "4: Quit" << endl;
            selection=searchMenuValidate();
            
        if(selection == 1){
            string title;
            string artist;
            cin.ignore();
            cout << "Please type the title of song :" << endl;
            getline(cin, title);
            cin.clear();
            cout << "Please type the artist of song :" << endl;
            getline(cin, artist);
            cin.clear();
            cout << endl;
            Song test =libObj.searchSong(title, artist);
            Song test1;
            if(test == test1){
                cout << "Song Not Found" << endl;
                selection=0;
            } else{
                cout <<"Your Song is: " << test << endl;
                selection=0;
            }
        }
            
        else if (selection == 2)  {
            string artist;
            cout << "\nWhat artist would you like to look for?" << endl;
            cin.ignore();
            getline(cin, artist);
            cin.clear();
            vector<Song> test;
            vector<Song> songList = libObj.searchArtist(artist);
            for (int i = 0; i < songList.size(); i++) {
                cout << songList[i] << endl;
            }
            if(songList.size() == test.size()){
                cout << endl;
                cout << "Song Not Found" << endl;
                selection=0;
            }else{
                selection=0;
            }
        }
            
        else if (selection == 3)  {
            cout << "Please enter a decade" << endl;
            int decade = getPositiveInt();
            while(decade % 10 != 0) {
            cout << "Please enter a decade" << endl;
                decade = getPositiveInt();
            }
            cout << endl;
            vector<Song> test;
            vector<Song> songList = libObj.searchYear(decade);
            for (int i = 0; i < songList.size(); i++) {
                cout << songList[i] << endl;
            }
            if(songList.size() == test.size()){
                cout << endl;
                cout << "Song Not Found" << endl;
                selection=0;
            }else{
                selection=0;
            }
        }
            
        else if(selection == 4){
            check = true;
        }
            
    }
}

void readFile(LinkedList &libObj){
    string rolodex = "songs.txt";
    string input;
    fstream file;
    file.open(rolodex, ios::in);
    string titlea;
    string artista;
    string yeara;
    string ratinga;
    if (!file){
        cout << "No File Located" << endl;
    }
    if(!file.eof()){
        while ((!file.eof())){
            getline(file,titlea, ',' );
            getline(file,artista, ',' );
            getline(file,yeara, ',' );
            getline(file,ratinga);
            Song New(titlea, artista, yeara, ratinga);
            libObj.addSongLib(New);
        }
    }file.close();
}



void writeFile(LinkedList &libObj){
    string rolodex = "songs.txt";
    string input;
    fstream file;
    file.open(rolodex, ios::out);
    string titlea;
    string artista;
    string yeara;
    string ratinga;
    if (!file){
        cout << "No File Located" << endl;
    }
    if(!file.eof()){
            file << libObj << endl;
        
    }file.close();
}
