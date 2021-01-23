/* Purpose: Lab Exercise 7 Question 3
 * Author: Emmanuel Ojo
 * Date: October 21 2020
 *
 * Sources:
 *   - ternary base 3: https://www.geeksforgeeks.org/ternary-number-system-or-base-3-numbers/
 *   - balanced ternary: https://www.geeksforgeeks.org/balanced-ternary-number-system/
 *   - balanced ternary: http://userpages.wittenberg.edu/bshelburne/BalancedTernaryTalkSu09.pdf
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

void coefficient(int, int);

int main() {
 
  int number, remainder = 0;
  
  // user enters positive number
  printf("Enter a positive integer: ");
  scanf("%d", &number);

  //printf("the number %d has %d digits", number, digits);
  coefficient(number, remainder);

  return 0;
}


void coefficient(int num, int remainder) {
  
  // base case
  if (num == 0) {
    return;
  }

  // mod num by 3 to get remainder
  remainder = num % 3;
  
  num /= 3;

  // replace 2's with -1
  if (remainder == 2) {
    remainder = -1;
    num++;
  }

  if (remainder == 0) {
    printf("0 ");
  }
  else {
    if (remainder == 1) {
      printf("1 ");
    }
    else {
      printf("-1 ");
    }
  }
 
  // recursive call until all numbers have been converted
  coefficient(num, remainder);

}
