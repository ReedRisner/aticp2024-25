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
};