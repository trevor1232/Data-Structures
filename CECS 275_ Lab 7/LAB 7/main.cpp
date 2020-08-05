/*
   Name: Trevor Scott
   Date: 04/07/2020
   Program: Lab 7: Operator Overloading
   Description: This program was to utlize classes, contructors, and overloaded constructors to perform operations. We had to verify everything that in the fuctions of main.cpp
*/

//directives
#include <iostream>
#include "Rect.h"
#include "CheckInput.h"
using namespace std;
bool testConstructors(){
  Rect r1; //w=0, h=0
  Rect r2(3); //w=3, h=3
  Rect r3(-5); //w=0, h=0
  Rect r4(3, 5);//w=3, h=5
  Rect r5(-3, 5);//w=0, h=5
  Rect r6(3, -5);//w=3, h=0
  Rect r7(-3, -5);//w=0, h=0
  if(r1.getWidth() == 0 && r1.getHeight() == 0){
    if(r2.getWidth() == 3 && r2.getHeight() == 3){
      if(r3.getWidth() == 0 && r3.getHeight() == 0){
        if(r4.getWidth() == 3 && r4.getHeight() == 5){
          if(r5.getWidth() == 0 && r5.getHeight() == 5){
            if(r6.getWidth() == 3 && r6.getHeight() == 0){
              if(r7.getWidth() == 0 && r7.getHeight() == 0){
                cout<<"1. All constructors are correct."<<endl;
                cout<<"2. All get functions are correct."<<endl;
                return true;
              }else{
                cout<<"Constructor 3 is incorrect - assign 0 if value is negative."<<endl;
              }
            }else{
              cout<<"Constructor 3 is incorrect - assign 0 if value is negative."<<endl;
            }
          }else{
            cout<<"Constructor 3 is incorrect - assign 0 if value is negative."<<endl;
          }
        }else{
          cout<<"Constructor 3 is incorrect."<<endl;
        }
      }else{
        cout<<"Constructor 2 is incorrect - assign 0 if value is negative."<<endl;
      }
    }else{
      cout<<"Constructor 2 is incorrect."<<endl;
    }
  }else{
    cout<<"Default constructor is incorrect."<<endl;
  }
  return false;
}
bool testEquals(){
  Rect r1(1,2);
  Rect r2(1,2);
  Rect r3(2,1);
  if(r1==r2 && !(r1==r3)){
    cout<<"3. Overloaded Equals is correct."<<endl;
    return true;
  }else{
    cout<<"Overloaded Equals is incorrect."<<endl;
  }
  return false;
}
void testOps(){
  Rect r1(2,3);
  Rect r2(4,5);
  Rect rSum = r1 + r2; //adding r1 + r2
  Rect eSum(6,8); //expected result of adding r1+r2
    r1*r2;
  Rect eMult(8,15);//result of multiplying r1*r2 (stores back to r1)
  if(rSum == eSum){
    cout<<"4. Overloaded + operator is correct."<<endl;
  }else{
    cout<<"Overloaded + operator is incorrect."<<endl;
  }
  if(r1 == eMult){
    cout<<"5. Overloaded * operator is correct."<<endl;
  }else{
    cout<<"Overloaded * operator is incorrect."<<endl;
  }
  Rect r3(1,2);
  Rect r4(1,5);
  Rect r5(1,2);
    
  if(r3<r2 && r3<r4 && !(r3<r5)){
    cout<<"6. Overloaded < operator is correct."<<endl;
  }else{
    cout<<"Overloaded < operator is incorrect."<<endl;
  }
}

int main() {
  bool pass = false;
  pass = testConstructors();
  if(pass){
      pass = testEquals();
  }
  if(pass){
      testOps();
  }
  Rect r1(1,2);
  cout<<"Your output should look like: 'Rect: [W=1,H=2]'"<<endl;
    cout << r1 << endl;
}
