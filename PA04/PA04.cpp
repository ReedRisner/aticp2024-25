#include <iostream>
#include <Fraction.h>

using namespace std;

int main(int argc, char const *argv[]) {
    Fraction foo(3,4);
    //It is not Fraction foo = new Fraction(3,2);
    cout<<foo.getNum()<<"/"<<foo.getDen()<<endl;
    cout<<foo<<endl;
    Fraction bar (1,2);
    cout<<foo<<" + "<<bar<<" = "<<foo+bar<<endl;
    cout<<foo<<" - "<<bar<<" = "<<foo-bar<<endl;
    cout<<foo<<" * "<<bar<<" = "<<foo*bar<<endl;
    cout<<foo<<" / "<<bar<<" = "<<foo/bar<<endl;
    cout<<foo<<" == "<<bar<< " = "<<(foo==bar)<<endl;

}
