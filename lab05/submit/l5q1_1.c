/* Purpose: Lab Exercise 5 Question 1 part 1
 * Author: Emmanuel Ojo
 * Date: October 7 2020
 *
 * Sources: none.
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

float calculate_addition(float num_one, float num_two);

int main() {
  
  float num1 = 5.0;
  float num2 = 5.0;
  
  printf("%f", calculate_addition(num1, num2));
  return 0;
}


float calculate_addition(float num_one, float num_two) {
  return num_one + num_two;
}

