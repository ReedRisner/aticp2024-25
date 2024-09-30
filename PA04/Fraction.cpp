#include <iostream>
#include <string>
#include <Fraction.h> //this includes the fraction.h file

using namespace std;

//Syntax is ClassName::ClassMethod
Fraction::Fraction(int top, int bottom){
    num = top;
    den = bottom;
    //thus->num + top; //This is how you use the keyword this.
}
//Acessor methods should have "const" in the name because they do not modify the object
int Fraction::getNum() const {
    return num;
}
int Fraction::getDen() const{
    return den;
}