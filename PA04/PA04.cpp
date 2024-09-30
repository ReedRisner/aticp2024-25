#include <iostream>
#include <Fraction.h>

using namespace std;

int main(int argc, char const *argv[]) {
    Fraction foo(3,2);
    //It is not Fraction foo = new Fraction(3,2);
    cout<<foo.getNum()<<"/"<<foo.getDen()<<endl;
}
