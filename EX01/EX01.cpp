#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
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
   cout<<"The value of a is "<<a<<endl; //a is uninitialized and gets an error

   //You can convert a double to an int without casting

   double b = 5.3;
   int c = b;
   cout<<"b is: "<<b<<endl<<"c is: "<<c<<endl;

   string name = "Reed Risner"; //Strings start with a lwercase in Java
   cout<<"My name is "<<name<<endl;

   //We have arguments. Don't worry about the syntax, but know this is how you use it. 

   cout<<"You gave "<<argc<<" arguments and they are:"<<endl;

   for(int i = 0; i<argc; i++) {
    cout<<argv[i]<<endl;
   }

   //Most of the time you will take command line arguments insead of cin
   //the thing aboive is an array. never use arrays, you should use vectors instead
   //Here's why: 
   int daArray[] = {2,4,6,8};
   cout<<"Number at position 2 is "<<daArray[2]<<endl;

   //You are allowed to go past the array's bounds. Very dangerous!
   //C++ does not do error checking, nor can you check for the suze
   //When you make an array, C++ allocates that amount of memory. End of Story

   //Vectors are like ArrayList

   vector<int> foo; //vector called foo
   foo.push_back(53); //Adds the number 53
   foo.push_back(5);
   foo.push_back(7);
   cout<<foo[0]<<endl; //Access like a vector
   cout<<foo.size()<<endl; //gets the size of th evector
   foo.pop_back(); //Gets rid of the last item
   foo[0]=2; //Changes the value at position 0 to 2
   for(unsigned int i=0; i<foo.size(); i++) {  //Unsigned means it is negative and
       cout<<foo[i]<<endl;
}

return 0;
}