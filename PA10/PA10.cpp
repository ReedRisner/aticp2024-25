#include <vector>
#include <string>
#include <iostream>

using namespace std;

//Just print the answer. Each on a new line
void fizzBuzz(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i;
        if (i % 3 == 0 && i % 5 ==0) {
            cout << "FizzBuzz";
        }
        else if (i % 3 ==0) {
            cout << "Fizz";
        }
        else if (i % 5 == 0) {
            cout << "Buzz";
        }
        else {
            cout << i;
        }
        }

 return;

    }


   


int main() {
    fizzBuzz(5); //Example function call
    return 0;
}