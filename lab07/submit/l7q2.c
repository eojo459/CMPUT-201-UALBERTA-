/* Purpose: Lab Exercise 7 Question 2
 * Author: Emmanuel Ojo
 * Date: October 19 2020
 *
 * Sources:
 *   - https://www.programiz.com/c-programming/c-pointers-arrays
 *   - https://www.geeksforgeeks.org/pointer-array-array-pointer/
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdbool.h>

int helper(int *, int, int);

int main() {

  int arrayLength;
  
  // user enters array length
  printf("Enter the length of the array: ");
  scanf("%d", &arrayLength);

  // create array
  int numbers[arrayLength];

  // create pointer to array
  int *pNumbers = &numbers[0];
  
  // populate array
  printf("Enter %d distinct positive integers: ", arrayLength);

  for(int i=0; i < arrayLength; i++) {
    scanf("%d", &numbers[i]);
  }
  
  helper(pNumbers, arrayLength, 0);
  
  return 0;
}


int helper(int *arrayPointer, int length, int num2) {

  // keep track of the indices we've already printed..
  int selectedIndices[length];

  // p1 points to numbers[0] , p2 points to numbers[p1+1]
  int *p1 = arrayPointer, *p2 = arrayPointer + 1;
  
  int count = 1, lowIndex = 0, maxIndex = 1;
  bool selected = false;

  // initialize array with -1 so it doesn't conflict with indices
  for(int i=0; i < length; i++) {
    selectedIndices[i] = -1;
  }
  
  // loop through the whole array
  for(int total=0; total < length; total++) {
    p1 = arrayPointer;
    p2 = arrayPointer + 1;
    
    // while there are still elements to compare, keep looping
    while (count < length) {

      selected = false;
      
      // check if p1 has been selected
      for(int i=0; i < length; i++) {
	if (lowIndex == selectedIndices[i]) {
	  selected = true;
	  break;
	}
      }

      // if selected, move p1 forward, lowIndex++
      if (selected == true) {
	p1++;
	lowIndex++;
      }
      
      // reset flag and check if p2 has been selected
      selected = false;

      for(int i=0; i < length; i++) {
	if (maxIndex == selectedIndices[i]) {
	  selected = true;
	  break;
	}
      }

      // if selected, move p2 forward, maxIndex++, start from top again
      if (selected == true) {
	p2++;
	maxIndex++;
      }
      else {
	// if p1 == p2, move p2 forward, maxIndex++, start from top again
	if (p1 == p2) {
	  p2++;
	  maxIndex++;
	}
	else {
	  
	  // check if p1 is still the lowest number,
	  // if so move p2 forward and keep comparing, else p2 is lowest so p1 = p2
	  if ((*p1 < *p2) == true) {
	    p2++;
	    maxIndex++;
	  }
	  else {
	    p1 = p2;
	    lowIndex = maxIndex;
	    p2++;
	    maxIndex++;
	  }
	}
      }
      
      // increase count, compare next values
      count++;
    }

    // add current lowest index to a new array, reset values and repeat
    selectedIndices[total] = lowIndex;
    count = 1;
    lowIndex = 0;
    maxIndex = 1;
  }

  // print index order
  printf("Index Order: ");
  for(int i=0; i < length; i++) {
    printf("%d ", selectedIndices[i]);  
  }
  
  return 1;
}
