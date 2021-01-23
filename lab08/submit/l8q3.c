/* Purpose: Lab Exercise 8 Question 3
 * Author: Emmanuel Ojo
 * Date: October 28 2020
 *
 * Sources: 
 *   - CMPUT 201 FALL 2020 Discord Server Discussion
 *   - IEEE Floating Point Converter: https://www.h-schmidt.net/FloatConverter/IEEE754.html
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

int main() {

  float num;
  
  printf("Enter a floating-point number: ");
  scanf("%f", &num);
  
  int* byte = (int *)&num;

  // add 1 to the exponent value to double
  *byte += 8388608;

  // print doubled value
  printf("Doubling becomes: %f\n", num);
  
  return 0;
}
