#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement six functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file. For example, methods you write may need a mask value.
 *  You might write a method to compute mask for you and use it wherever
 *  it is needed as oposed to just puting the code in line.
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
    return (value >> position) & 1; //shifts it to the right by value and then does a bitwise and with 1
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
    return value |= 1 << position; //sets the bit at the position to 1
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, int isSigned) {
    return 0;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setField (int oldValue, int hi, int lo, int newValue) {
    return 0;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int fieldFits (int value, int width, int isSigned) {
    return 0;
}
