/* Purpose: Lab Exercise 11 Question 2
 * Author: Emmanuel Ojo
 * Date: November 25, 2020
 *
 * Sources: 
 *   - IEEE Floating Point Converter: https://www.h-schmidt.net/FloatConverter/IEEE754.html
 *   - Masking with hex: https://stackoverflow.com/questions/28242415/c-bit-wise-operations-with-hex-numbers
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

int main() {

  float num;
  
  printf("Enter a floating-point number: ");
  scanf("%f", &num);
  
  int* bit = (int *)&num;
  
  // shift the bits to get to the exponent and add 1, then shift back
  int exponent = (*bit >> 23);
  exponent++;
  exponent = exponent << 23;

  // mask mantissa to remove exponent part
  int mantissa = *bit & 0x7FFFFF;
  
  // combine exponent and mantissa back together
  *bit = exponent | mantissa;

  // print doubled value
  printf("Doubling becomes: %f\n", num);
  
  return 0;
}
