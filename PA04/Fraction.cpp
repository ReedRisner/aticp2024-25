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
ostream &operator <<(ostream &stream, const Fraction &other) {

    stream << other.num << "/" << other.den;
    return stream;

    }

Fraction Fraction::operator+ (const Fraction& other) const {
    int newNum = num*other.den+den*other.num;
    int newDen = den*other.den;
    return Fraction(newNum, newDen);
}
Fraction Fraction::operator- (const Fraction& other) const {
    int newNum = num*other.den-den*other.num;
    int newDen = den*other.den;
    return Fraction(newNum, newDen);
}
Fraction Fraction::operator* (const Fraction& other) const {
    int newNum = num*other.num;
    int newDen = den*other.den;
    return Fraction(newNum, newDen);
}
Fraction Fraction::operator/ (const Fraction& other) const {
    int newNum = num*other.den;
    int newDen = den/other.num;
    return Fraction(newNum, newDen);
}
bool Fraction::operator ==(Fraction &other) const{
    if (float (num / den) == float(other.num / other.den)) {
       return(true);  
    }
    else {
        return false;
    }
   
}


    
