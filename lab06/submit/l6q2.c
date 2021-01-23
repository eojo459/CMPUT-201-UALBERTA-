/* Purpose: Lab Exercise 6 Question 2
 * Author: Emmanuel Ojo
 * Date: Octobe 14 2020
 *
 * Sources:
 *   - Quick sort: https://www.programiz.com/dsa/quick-sort
 *   - Insertion sort: https://www.programiz.com/dsa/insertion-sort
 *   - Bubble sort: https://www.programiz.com/dsa/bubble-sort
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

void printArray(int arrayLen, int arrayInt[]);
void printStats(int comparisonNum, int movesNum);
void bubbleSort(int arrayLen, int arrayInt[], int* comparisonNum, int* movesNum);
void insertionSort(int arrayLen, int arrayInt[], int* comparisonNum, int* movesNum);
void mergeSort(int arrayLen, int arrayInt[], int* comparisonNum, int* movesNum);
void quickSort(int arrayInt[], int left, int right, int* comparisonNum, int* movesNum);
void swap(int* arrayPos1, int* arrayPos2, int* movesNum);
int split(int arrayInt[], int left, int right, int* comparisonNum, int* movesNum);

int main() {

  // user's option that they picked
  char option;

  // declare array size & other variables
  int arrayLength, numComps = 0, numMoves = 0;
  
  printf("Enter the length of the array: ");
  scanf("%d", &arrayLength);

  // create the array of integers with specifed size from user
  int numArray[arrayLength];

  // fill array with integers
  printf("Enter the %d integers to be sorted: ", arrayLength);

  for (int i = 0; i < arrayLength; i++) {
    scanf("%d", &numArray[i]);
  }
  
  // get rid of '/n' and garbage in buffer
  getchar();

  // user selects sorting algorithm
  printf("Select from (a)ll | (b)ubblesort | (i)nsertionsort | (m)ergesort | (q)uicksort: ");
  scanf("%c", &option);

  if (option == 'a') {
    // run all sorting algorithms
    printf("All");
  }
  else if (option == 'b') {
    //run bubblesort algorithm
    printf("Bubblesort is deployed ...\n");
    bubbleSort(arrayLength, numArray, &numComps, &numMoves);
    printArray(arrayLength, numArray);
    printStats(numComps, numMoves);
  }
  else if (option == 'i') {
    // run insertionsort algorithm
    printf("Insertionsort is deployed ...\n");
    insertionSort(arrayLength, numArray, &numComps, &numMoves);
    printArray(arrayLength, numArray);
    printStats(numComps, numMoves);
  }
  else if (option == 'm') {
    // run mergesort algorithm
    printf("merge");
  }
  else if (option == 'q') {
    // run quicksort algorithm
    printf("Quicksort is deployed ...");
    quickSort(numArray, 0, arrayLength - 1, &numComps, &numMoves);
    printArray(arrayLength, numArray);
    printStats(numComps, numMoves);
  }
  else {
    printf("unknown option picked");
  }
			 
  return 0;
}


// print an array on a single line
void printArray(int arrayLen, int arrayInt[]) {

  printf("\nIn sorted non-decreasing order: ");
  for (int i = 0; i < arrayLen; i++) {
    printf("%d ", arrayInt[i]);
  }
  printf("\n");
  
  return;
}

// print comparison and move stats
void printStats(int comparisonNum, int movesNum) {

  printf("Number of comparisons: %d\n", comparisonNum);
  printf("Number of moves: %d\n", movesNum);
  
  return;
}

// bubble sort algorithm
void bubbleSort(int arrayLen, int arrayInt[], int* comparisonNum, int* movesNum) {
  
  // loop through the whole array
  for (int i = 0; i < arrayLen; i++) {

    // comparison loop
    for(int j = 0; j < arrayLen - i - 1; j++) {

      // swap if current value > next value
      if (arrayInt[j] > arrayInt[j + 1]) {
	int temp = arrayInt[j];
	arrayInt[j] = arrayInt[j + 1];
	arrayInt[j + 1] = temp;

	// increment comparison and move counter
	(*comparisonNum)++;
	*movesNum += 2;
      }
      else {
	(*comparisonNum)++;
      }
    }
  }

  return;
}


void insertionSort(int arrayLen, int arrayInt[], int* comparisonNum, int* movesNum) {
  
  for (int i = 1; i < arrayLen; i++) {
    int target = arrayInt[i];
    int j = i - 1;

    // compare target with each element until a smaller element is found
    while (target < arrayInt[j]) {
      arrayInt[j + 1] = arrayInt[j];
      j--;
      
      (*comparisonNum)++;
      (*movesNum)++;
    }
    
    // replace value with target
    arrayInt[j + 1] = target;

    (*comparisonNum)++;
  }
  
  return;
}

void mergeSort(int arrayLen, int arrayInt[], int* comparisonNum, int* movesNum) {

  return;
}

void quickSort(int arrayInt[], int left, int right, int* comparisonNum, int* movesNum) {

  if (left >= right) {
    return;
  }

  // pivot position
  int middle = split(arrayInt, left, right, comparisonNum, movesNum);

  // sort elements left of pivot
  quickSort(arrayInt, left, middle - 1, comparisonNum, movesNum);

  // sort elements right of pivot
  quickSort(arrayInt, middle, right, comparisonNum, movesNum);
  
  return;
}

// swap 2 items in an arrow
void swap(int* arrayPos1, int* arrayPos2, int* movesNum) {

  int temp = *arrayPos1;
  *arrayPos1 = *arrayPos2;
  *arrayPos2 = temp;

  // increment moves count
  *movesNum += 2;
  
  return;
}

int split(int arrayInt[], int left, int right, int* comparisonNum, int* movesNum) {

  // pivot point
  int pivot = arrayInt[right];
  int low = (left - 1);

  // put smaller int's on the left of pivot, bigger int's on right of pivot
  for (int i = left; i < right; i++) {
    if (arrayInt[i] <= pivot) {
      low++;
      swap(&arrayInt[low], &arrayInt[i], movesNum);

      // increment comparison count
      (*comparisonNum)++;
    }
    else {
      (*comparisonNum)++;
    }
  }
  
  swap(&arrayInt[low + 1], &arrayInt[right], movesNum);
  
  return(low + 1);
}
