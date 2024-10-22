#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int x = 5; //puts a int on the stack
    int y = x; //y is now 5
    x = 3; //x is now 3. y is still 5
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl; //prints x and y

    int* pointer1 = &x; //pointer1 points to the adrees of x
    cout<<"x: "<<x<<endl;
    cout<<"pointer1: "<<pointer1<<endl;

}