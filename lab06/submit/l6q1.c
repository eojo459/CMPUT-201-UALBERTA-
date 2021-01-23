/* Purpose: Lab Exercise 6 Question 1
 * Author: Emmanuel Ojo
 * Date: October 13, 2020
 *
 * Sources:
 *   - Array and pointers: https://www.programiz.com/c-programming/c-pointers-arrays
 *   - File IO: https://www.tutorialspoint.com/cprogramming/c_file_io.htm
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdlib.h>
#define N 10

int main() {

  // create file pointer
  FILE *outputFile;

  // open output file
  outputFile = fopen("output.txt","w");
  
  int b[N];
  int *a = &b[0];
  int *p = a, *q = a + N - 1;
  for (int i = N-1; i >= 0 ; i--) {
    *(a + i) = i + 1;
  }
  
  while (p < q) {
    int temp = *p;
    *p++ = *q;
    *q-- = temp;
  }

  // insert for-loop here
  for (int i = 0; i < N; i++) {

    // print to file
    fprintf(outputFile, "%d ", *(a++));
  }

  // close file
  fclose(outputFile);

  
  return 0;
}
