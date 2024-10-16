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
    int nv = value |  (1 << position); //sets the bit at the position to 1
    return nv;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    int nv = value & ~(1 << position); //clears the bit at the position to 0
    return nv;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, int isSigned) {
    int nv = (value >> lo) & ((1 << (hi - lo + 1)) - 1); // shifts the value and masks the bits
    if (isSigned && (nv & (1 << (hi - lo)))) { // if signed and the sign bit is set
        nv |= ~((1 << (hi - lo + 1)) - 1); // sign extend the result
    }
    return nv;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setField (int oldValue, int hi, int lo, int newValue) {
    int mask = ((1 << (hi - lo + 1)) - 1) << lo; // create a mask for the field
    oldValue &= ~mask; // clear the field in the old value
    newValue = (newValue << lo) & mask; // shift the new value into position and mask it
    return oldValue | newValue; // combine the old value with the new field value
}

/** @todo Implement in field.c based on documentation contained in field.h */
int fieldFits (int value, int width, int isSigned) {
    if (isSigned) {
        int min = -(1 << (width - 1));
        int max = (1 << (width - 1)) - 1;
        return value >= min && value <= max;
    } else {
        unsigned int max = (1 << width) - 1;
        return value >= 0 && static_cast<unsigned int>(value) <= max;
    }
}