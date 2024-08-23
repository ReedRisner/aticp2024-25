#include <iostream>

using namespace std;

int main(int agrc, char const *argv[]) {
    //argc is the number of strings given to this program
    //argv is the array of strings
    cout<<"Hello, World!"<<endl;  //print statement
    //This is a comment
    /*
    This is a multiline comment
    */
    int x =3; //making variable
    cout<<"The number x is"<<x<<endl;
    int y = 0; //always set a variable because if not it is null
    cout<<"Please enter a number of y: "; //input
    cin>>y;
    cout<<"The number y is "<<y<<endl; //output
    /*
    Data types in C++ are:
        int, float (better decimals), double, bool, and char
    */
   int a;
   cout<<"The value of a is "<<a<<endl;
}
