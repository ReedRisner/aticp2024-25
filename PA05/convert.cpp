// You will need to edit this file and turn this one in.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

// char2int
// Converts from a character to an integer digit
// if character '0'..'9' convert to 0..9
// else if character 'A'..'F' convert to 10..15
// else convert to -1
int char2int(char digit)
{
   // in ASCII code the numbers start from 48. 
   
    if (digit>=0 && digit<58) {
        return digit-48;
    }
    if (digit >64 && digit<71) {
        return digit-55;
    }
    if (digit>96 && digit<103) { 
        return digit-87;
    }
    return 1;

}

// int2char
// Converts from an integer digit to a character
// if integer 0..9 convert to '0'..'9'
// else if integer 10..15 convert to 'A'..'F'
// else convert to 'X'
char int2char(int digit)
{
    char a = 'X'; //defualt set to X

    if (digit >= 0 && digit <= 9) {

        a = digit + '0';
        return a;

    }

    if (digit >= 10 && digit <= 15) {
        
        a = digit - 10 + 'A';
        return a; 
    }
    return a;
}

// Convert integer to string in specified base and print
// 2 <= base <= 16
void int2ascii(int value, int base)
{
    return;
}

// Convert string in specified base to integer and print
// 2 <= base <= 16
void ascii2int(const std::string &ascii, int base)
{
    return;
}