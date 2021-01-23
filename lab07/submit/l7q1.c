/* Purpose: Lab Exercise 7 Question 1
 * Author: Emmanuel Ojo
 * Date: October 19 2020
 *
 * Sources:
 *   - printing bytes: https://stackoverflow.com/questions/41638330/how-to-print-1-byte-with-printf
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

void byte_value(int *);

int main() {
  int n = 1;
  byte_value(&n);

  printf("Enter an integer: ");
  if (scanf("%d", &n) == 1)
    byte_value(&n);

  return 0;
}

void byte_value(int *p) {
  // fill in the body using only pointer variables
  // printout the memory address of the byte and its unsigned char (integer) value
  // one line for each pair, a total of 4 lines

  unsigned char* byte = (unsigned char*)p;
 
  printf("Memory Address: %p, Byte value: %x\n", byte, byte[0]);
  printf("Memory Address: %p, Byte value: %x\n", byte+1, byte[1]);
  printf("Memory Address: %p, Byte value: %x\n", byte+2, byte[2]);
  printf("Memory Address: %p, Byte value: %x\n", byte+3, byte[3]);
  
  return;
}
