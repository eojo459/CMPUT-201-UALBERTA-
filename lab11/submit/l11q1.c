/* Purpose: Lab Exercise 11 Question 1
 * Author: Emmanuel Ojo
 * Date: November 25, 2020
 *
 * Sources:
 *   - Copy file contents: https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/
 *   - Format specifier: https://www.geeksforgeeks.org/using-variable-format-specifier-c/
 *   - Print leading 0's: https://stackoverflow.com/questions/153890/printing-leading-0s-in-c
 *   - Resetting file pointer: https://stackoverflow.com/questions/32366665/resetting-pointer-to-the-start-of-file
 *   - Count digits in number: https://www.programiz.com/c-programming/examples/digits-count
 *   - snprintf: https://stackoverflow.com/questions/7315936/which-of-sprintf-snprintf-is-more-secure
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <string.h>

void printOutput(int, int, FILE*, FILE*);

FILE *file1, *file2;

int main(int argc, char *argv[]) {

  // check for the arguments
  if (argc == 2) {
    
    //char fileName[100], c;
    int fileAmount, digits = 0, temp;
    
    file1 = fopen(argv[1], "r");

    // check if input file exists
    if (file1 == NULL) {
      printf("Error opening the file %s\n", argv[1]);
      return 0;
    }

    // ask user to enter n amount of files
    printf("Enter the number of output files: ");
    scanf("%d", &fileAmount);

    // check for 0 or negative number of files
    if (fileAmount <= 0) {
      printf("Number of files cannot be 0 or negative.\n");
      return 0;
    }
    
    // get digits (find k)
    temp = fileAmount;
    
    while (temp != 0) {
      temp /= 10;
      digits++;
    }
    
    if (digits == 1) {
      digits = 2;
    }

    // copy data from input file to n files
    printOutput(fileAmount, digits, file1, file2);
    
    printf("Contents copied from %s to %d files\n", argv[1], fileAmount);
    fclose(file1);
    
  }
  else {
    printf("Usage: ./l11q1 [filename].txt\n");
  }

  return 0;
}

void printOutput(int n, int k, FILE* input, FILE* output) {

  char fileName[100], c;

  for (int i = 1; i <= n; i++) {
    
    // create file name with outputXXX...X.txt
    snprintf(fileName, sizeof(fileName), "output%0*d.txt", k, i);
  
    output = fopen(fileName, "w");

    fprintf(output, "Content of %s: \n", fileName);

    fputc('\n', output);

    // copy content from input file to new file
    c = fgetc(input);
    
    while (c != EOF) {
      fputc(c, output);
      c = fgetc(input);
    }
    
    fclose(output);

    // reset pointer back to beginning of input file
    fseek(input, 0, SEEK_SET);
  }
}
