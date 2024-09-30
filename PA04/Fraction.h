using namespace std; //.h files contain the declerations of functions, classes and variables

class Fraction { //classes are private by defualt
    private:
        int num; //numerator
        int den; //denominator
    public:
        Fraction(int top, int bottom); //Constructor
        //Methods are within a class, functions are outside a class
        int getNum() const; //Const means you wont change anything
        int getDen() const;
        friend ostream &operator <<(ostream &stream, const Fraction &other); //Friend is not a class but has access to the classes private parts
        //your job is to overwrote these operators:
        Fraction operator+(const Fraction & other) const;
        Fraction operator-(const Fraction & other) const;
        Fraction operator*(const Fraction & other) const;
        Fraction operator/(const Fraction & other) const;
        bool operator ==(Fraction &other) const;

};