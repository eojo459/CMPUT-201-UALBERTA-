/* Purpose: Lab Exercise 5 Question 2
 * Author: Emmanuel Ojo
 * Date: October 7 2020
 *
 * Sources:
 *   - Recursive Fibonacci: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/ 
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdbool.h>

bool checkIndex(int index);
int modifiedFib(int index);

int main() {

  int posIndex;

  // prompt user to enter a position index
  printf("Enter a position index: ");
  scanf("%d", &posIndex);

  // check index, if false terminate, else continue
  if (checkIndex(posIndex) == false) {
    return 0;
  }

  // output term value
  printf("Term %d has a value: %d\n", posIndex, modifiedFib(posIndex));
  
  return 0;
}


/* check if there is a valid index */
bool checkIndex(int index) {

  if (index <= 0) {
    // invalid index
    return false;
  }
  else {
    // valid index
    return true;
  }
}


/* modified fibonacci */
int modifiedFib(int index) {

  // first index = 0
  if (index == 1) {
    return 0;
  }
  // second index = 1
  else if (index == 2) {
    return 1;
  }
  // third index = 2
  else if (index == 3) {
    return 2;
  }
  // continue adding the last 3 numbers to get the current index value
  else {
    return modifiedFib(index - 1) + modifiedFib(index - 2) + modifiedFib(index - 3);
  }
}
