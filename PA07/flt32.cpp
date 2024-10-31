#include "field.h"
#include "flt32.h"
#include <cmath>
#include <algorithm>

/** @file flt32.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in flt32.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_sign (flt32 x) {
  return getField(x, 31, 31, 0);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_exp (flt32 x) {
  return getField(x, 30, 23, 0); 
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_val (flt32 x) {
  return getField(x, 23, 0, 0) | (1 << 23); 
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
void flt32_get_all(flt32 x, int* sign, int*exp, int* val) {
	//Assign each to a pointer given in the arguments.
  //This one is already done for you. No need to edit this.
	*sign=flt32_get_sign(x);
	*exp=flt32_get_exp(x);
	*val=flt32_get_val(x);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_left_most_1 (int value) {
  if (value == 0) {
    return -1;
  };
  int position = 0;
  for (int i = 31; i >= 0; --i) {
    if (value & (1 << i)) {
      position = i;
      break;
    }
  }
  return position;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_abs (flt32 x) {
  return x & 0x7FFFFFFF;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_negate (flt32 x) {
  return x ^ 0x80000000;
}



/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_add (flt32 x, flt32 y) {
  
int sign_x = flt32_get_sign(x);
int exp_x = flt32_get_exp(x);
int val_x = flt32_get_val(x);

int sign_y = flt32_get_sign(y);
int exp_y = flt32_get_exp(y);
int val_y = flt32_get_val(y);

if (exp_x < exp_y) {
  int temp_sign = sign_x;
  int temp_exp = exp_x;
  int temp_val = val_x;
  sign_x = sign_y;
  exp_x = exp_y;
  val_x = val_y;
  sign_y = temp_sign;
  exp_y = temp_exp;
  val_y = temp_val;
}

int exp_diff = exp_x - exp_y;
val_y >>= exp_diff;

int result_val = val_x + (sign_x == sign_y ? val_y : -val_y);
int result_sign = result_val < 0 ? 1 : 0;
result_val = std::abs(result_val);

int result_exp = exp_x;
if (result_val & (1 << 24)) {
  result_val >>= 1;
  result_exp++;
} else {
  int left_most = flt32_left_most_1(result_val);
  if (left_most != -1) {
    int shift = 23 - left_most;
    result_val <<= shift;
    result_exp -= shift;
  }
}

result_val &= ~(1 << 23);
return (result_sign << 31) | (result_exp << 23) | result_val;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_sub (flt32 x, flt32 y) {
  return flt32_add(x, flt32_negate(y));
}