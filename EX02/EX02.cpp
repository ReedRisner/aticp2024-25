#include <iostream>
#include <vector>

using namespace std;

//struct

struct Table{
    int numberOfLegs;
    int height;
    bool sturdy;
    int getLegs() {
        return numberOfLegs;
    }
};


// You can declare a function
int timesTwo(int num);

//This is called pass by value
//It maeks a copy of the variable so it doesnt change outside the function
void changeThis(int x) {
    x = 3;
    cout<<x<<endl;
}


//Pass by reference, will be the actual reference to it
//Passing reference uses the & sign
void actuallyChange(int &x) {
    x =3;
    cout<<x<<endl;
}

int main(int argc, char const *argv[]) {
    int x = 5;
    int y = timesTwo(x);
    cout<<y<<endl;

    int a = 10;
    actuallyChange(a);
    cout<<a<<endl;

    int b = 10;
    changeThis(b);
    cout<<b<<endl;

    Table foo;
    foo.numberOfLegs=5;
    cout<<foo.getLegs()<<endl;
}

int timesTwo(int num) {
    return num*2;
}