/* Purpose: Lab Exercise #3, Question 2
 * Author: Emmanuel Ojo
 * Date: September 18, 2020
 *
 * Sources:
 *  - Write to txt file: https://stackoverflow.com/questions/11573974/write-to-txt-file 
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

  /* declare the file I/O streams */;
  FILE *outputFile;
  outputFile = fopen("20_output.txt", "w");
 
  int numbers[20];
  int largestNum, secondLargestNum;
  

  // prompt user to enter 20 numbers
  printf("Enter 20 numbers: \n");

  
  /* fill the numbers[20] array with the numbers from the .txt file */
  for (int i = 0; i < 20; i++) {
    scanf("%d ", &numbers[i]);
  }

  /* start traversing the array to find largest and 2nd largest #'s */
  largestNum = 0;
  secondLargestNum = 0;
  
  for (int i = 0; i < 20; i++) {
    
    if (numbers[i] > largestNum) {
      
      largestNum = numbers[i];
      
    } else if (numbers[i] < largestNum && numbers[i] > secondLargestNum) {
      
      secondLargestNum = numbers[i];
    }
    
  }
  
  /* output to the 20_output.txt file */
  printf("Largest: %d\n", largestNum);
  printf("Second Largest: %d\n", secondLargestNum);
  fprintf(outputFile, "Largest: %d\n", largestNum);
  fprintf(outputFile, "Second Largest: %d\n", secondLargestNum);
  
  
  /* close output file */
  fclose(outputFile);
 
  return 0;
}
