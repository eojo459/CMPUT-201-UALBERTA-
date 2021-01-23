/* Purpose: Lab Exercise 5 Question 3
 * Author: Emmanuel Ojo
 * Date: October 7 2020
 *
 * Sources: none
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void counter(int size, int array[][size]);
void swap(int size, int array[][size], int row, int pos1, int pos2);
bool checkSize(int size);
void printArray(int size, int array[][size]);
void balance(int size, int array[][size]);
void initialization(int size, int array[][size]);

int main() {

  // matrix size
  int nMatrix;

  // prompt user to enter matrix size, even positive integers only
  printf("Enter the size of a matrix, a positive even integer: ");
  scanf("%d", &nMatrix);

  // check if valid size is entered, if not then terminate
  if (checkSize(nMatrix) == false) {
    return 0;
  }

  // create the n x n matrix array
  int matrixArray[nMatrix][nMatrix];
  
  initialization(nMatrix, matrixArray);

  // print initial array
  printArray(nMatrix, matrixArray);
  
  // balance matrix
  balance(nMatrix, matrixArray);
  
  printf("Final balanced matrix:\n");

  // print balanced matrix
  printArray(nMatrix, matrixArray);

  /*
  printf("\n");
  counter(nMatrix, matrixArray);
  */
  
  return 0;
}


/* counter */
void counter(int size, int array[][size]) {

  int column = 0, zeroCount = 0, oneCount = 0;

  while (column < size) {
  
    // count how many 0's and 1's are in each column
    for (int i = 0; i < size; i++) {
      
      if (array[i][column] == 0) {
	zeroCount += 1;
      }
      else {
	oneCount += 1;
      }
    }

    printf("Column %d: %d zeros and %d ones\n", column, zeroCount, oneCount);
    zeroCount = 0;
    oneCount = 0;
    column++;
  }
  return;
}

/* swap 2 positions in the same row */
void swap(int size, int array[][size], int row, int pos1, int pos2) {

  int temp;
  temp = array[row][pos2];
  array[row][pos2] = array[row][pos1];
  array[row][pos1] = temp;
  
  return;
  
}


/* check if integer is a positive even int from [2,80] */
bool checkSize(int size) {

  if (size % 2 != 0 || size < 2 || size > 80) {
    return false;
  }
  else {
    return true;
  }
}


/* print out the array */
void printArray(int size, int array[][size]) {

  // print out the completed matrix row
  for (int row = 0; row < size; row++) {
    
    for (int column = 0; column < size; column++) {
      printf("%d", array[row][column]);
    }
    
    printf("\n");
  }
}


/* balance the array */
void balance(int size, int array[][size]) {

  int oneCount = 0, zeroCount = 0, column = 0;
  
  // start with first column, go down the row
  while (column < size) {

    // count how many 0's and 1's are in each column
    for (int i = 0; i < size; i++) {

      if (array[i][column] == 0) {
	zeroCount += 1;
      }
      else {
	oneCount += 1;
      }
    }

    // if column needs to be balanced (more 0's than 1's)
    if (zeroCount > oneCount) {

      // find a row that isnt a 1, start from there
      for (int i = 0; i < size; i++) {
	if (array[i][column] != 1) {

	  // find a column with a 1 and swap
	  for (int j = column; j < size; j++) {
	    
	    if (array[i][j] == 1) {
	      swap(size, array, i, column, j);
	      zeroCount--;
	      oneCount++;
	      break;
	    }
	  }
	}

	// if even number of 1's and 0's then exit loop and got to next column
	if (zeroCount == oneCount) {
	  break;
	}
      }
    }
    // if column needs to be balanced (more 1's than 0's)
    else if (oneCount > zeroCount) {

      // find a row that isnt a 0, start from there
      for (int i = 0; i < size; i++) {
	if (array[i][column] != 0) {

	  // find a column with a 0 and swap
	  for (int j = column; j < size; j++) {
	    
	    if (array[i][j] == 0) {
	      swap(size, array, i, column, j);
	      zeroCount++;
	      oneCount--;
	      break;
	    }
	  }
	}

	// if even number of 1's and 0's then exit loop and got to next column
	if (zeroCount == oneCount) {
	  break;
	}
      }
    }

    // reset values for next column
    oneCount = 0;
    zeroCount = 0;
    column++;
  }

  return;
}


/* generate an n x n (0,1) matrix */
void initialization(int size, int array[][size]) {

  int zeros, ones, value;

  srand(time(NULL));
  
  // n/2 1's and n/2 0's
  zeros = size/2;
  ones = size/2;

  int totalCount = 0, zeroCount = 0, onesCount = 0, rowCount = 0, columnsFilled = 0;

  // keep looping until every spot in the array matrix is filled with a 0 or 1
  while (totalCount < (size * size)) {

    // fill the rows
    while (columnsFilled < size) {

      // generate random value 0 or 1
      value = rand() % 2;
      
      // if we get a 0 and we still need more zeros, keep generating more 0's
      if (value == 0 && (zeroCount < zeros)) {
	array[rowCount][columnsFilled] = value;
	columnsFilled++;
	zeroCount++;
	totalCount++;
      }
      
      // if we get a 1 and we still need more ones, keep generating more 1's
      if (value == 1 && (onesCount < ones)) {
	array[rowCount][columnsFilled] = value;
	columnsFilled++;
	onesCount++;
	totalCount++;
      }
    }
    
    // reset and do next row
    columnsFilled = 0;
    zeroCount = 0;
    onesCount = 0;
    rowCount++;
  }
  
  return;
}
