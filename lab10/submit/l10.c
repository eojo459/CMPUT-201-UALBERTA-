/* Purpose: Lab Exercise 10
 * Author: Emmanuel Ojo
 * Date: November 17 2020
 *
 * Sources:
 *   - Command line arguments: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
 *   - Parsing command line arguments: https://stackoverflow.com/questions/9642732/parsing-command-line-arguments-in-c
 *   - Convert string to float: https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_74/rtref/itof.htm
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

bool verifyInput(char [], int);
bool checkDecimal(char [], int);
void printMessage(bool, int, char* []);

FILE *fp;

int main(int argc, char *argv[]) {

  fp = fopen("example_run.txt", "a");
  
  if (argc == 4) {
    
    long unsigned int length1 = strlen(argv[2]);
    long unsigned int length2 = strlen(argv[3]);
    char myString1[length1];
    char myString2[length2];
    strcpy(myString1, argv[2]);
    strcpy(myString2, argv[3]);

    bool decimal = false;
    
    // verify input data
    if (verifyInput(myString1, length1) == false || verifyInput(myString2, length2) == false) {
      fprintf(fp, "./l10 %s %s %s\n", argv[1], argv[2], argv[3]);
      fprintf(fp, "Usage: ./l10 [add|sub|mul|div|mod|pow|log Num Num]\n\n");
      printf("Usage: ./l10 [add|sub|mul|div|mod|pow|log Num Num]\n");
      return 0;
    }

    // indicate if we have a float or not
    if (checkDecimal(myString1, length1) == true || checkDecimal(myString2, length2) == true ) {
      decimal = true;
    }

    // call the arithmetic functions
    if (strcmp(argv[1], "add") == 0) {
      printMessage(decimal, 0, argv);
    }
    else if (strcmp(argv[1], "sub") == 0) {
      printMessage(decimal, 1, argv);
    }
    else if (strcmp(argv[1], "mul") == 0) {
      printMessage(decimal, 2, argv);
    }
    else if (strcmp(argv[1], "div") == 0) {
      printMessage(decimal, 3, argv);
    }
    else if (strcmp(argv[1], "mod") == 0) {
      printMessage(decimal, 4, argv);
    }
    else if (strcmp(argv[1], "pow") == 0) {
      printMessage(decimal, 5, argv);
    }
    else if (strcmp(argv[1], "log") == 0) {
      printMessage(decimal, 6, argv);
    }
    else {
      // error or unknown command
      fprintf(fp, "./l10 %s %s %s\n", argv[1], argv[2], argv[3]);
      fprintf(fp, "Usage: ./l10 [add|sub|mul|div|mod|pow|log Num Num]\n\n");
      printf("Usage: ./l10 [add|sub|mul|div|mod|pow|log Num Num]\n");
    }
  }
  else {
    // error or not enough arguments
    fprintf(fp, "./l10 %s %s %s\n", argv[1], argv[2], argv[3]);
    fprintf(fp, "Usage: ./l10 [add|sub|mul|div|mod|pow|log Num Num]\n\n");
    printf("Usage: ./l10 [add|sub|mul|div|mod|pow|log Num Num]\n");
  }
  
  return 0;
}

// check if input is valid (no letters / non numbers)
bool verifyInput(char string[], int length) {
  for (int i = 0; i < length; i++) {
    if (isdigit(string[i]) == 0) {
      if (string[i] != '.' && string[i] != '-') {
	return false;
      }
    }
  }
  // valid input
  return true;
}

// check if we need to do integer or float operations
bool checkDecimal(char string[], int length) {
  for (int i = 0; i < length; i++) {
    if (isdigit(string[i]) == 0) {
      if (string[i] == '.') {
	return true;
      }
    }
  }
  // no decimal was found
  return false;
}

// print messages for the different arithmetic operations
void printMessage(bool decimal, int option, char* argv[]) {

  float numf1, numf2;
  int num1, num2;

  // print float arithmetic values
  if (decimal == true) {
    
    // convert string arguments to floats
    numf1 = atof(argv[2]);
    numf2 = atof(argv[3]);
   
    if (option == 0) {
      fprintf(fp, "./l10 add %g %g\n", numf1, numf2);
      fprintf(fp, "addition for %g, %g is %f\n\n", numf1, numf2, numf1 + numf2);
      printf("addition for %g, %g is %f\n", numf1, numf2, numf1 + numf2);
    }
    else if (option == 1) {
      fprintf(fp, "./l10 sub %g %g\n", numf1, numf2);
      fprintf(fp, "subtraction for %g, %g is %f\n\n", numf1, numf2, numf1 - numf2);
      printf("subtraction for %g, %g is %f\n", numf1, numf2, numf1 - numf2);
    }
    else if (option == 2) {
      fprintf(fp, "./l10 mul %g %g\n", numf1, numf2);
      fprintf(fp, "multiplication for %g, %g is %f\n\n", numf1, numf2, numf1 * numf2);
      printf("multiplication for %g, %g is %f\n", numf1, numf2, numf1 * numf2);
    }
    else if (option == 3) {

      // check for division by 0
      if (numf2 == 0) {
	fprintf(fp, "./l10 div %g %g\n", numf1, numf2);
	fprintf(fp, "division cannot be performed for %g, %.1f\n\n", numf1, numf2);
	printf("division cannot be performed for %g, %.1f\n", numf1, numf2);
      }
      else {
	fprintf(fp, "./l10 div %g %g\n", numf1, numf2);
	fprintf(fp, "division for %g, %g is %f\n\n", numf1, numf2, numf1 / numf2);
	printf("division for %g, %g is %f\n", numf1, numf2, numf1 / numf2);
      }
    }
    else if (option == 4) {
      fprintf(fp, "./l10 mod %g %g\n", numf1, numf2);
      fprintf(fp, "modulo for %g, %g is %f\n\n", numf1, numf2, fmod(numf1, numf2));
      printf("modulo for %g, %g is %f\n", numf1, numf2, fmod(numf1, numf2));
    }
    else if (option == 5) {
      fprintf(fp, "./l10 pow %g %g\n", numf1, numf2);
      fprintf(fp, "power for %g, %g is %f\n\n", numf1, numf2, pow(numf1, numf2));
      printf("power for %g, %g is %f\n", numf1, numf2, pow(numf1, numf2));
    }
    else if (option == 6) {
      fprintf(fp, "./l10 log %g %g\n", numf1, numf2);
      fprintf(fp, "logarithm for %g, %g is %f\n\n", numf1, numf2, log10f(numf2)/log10f(numf1));
      printf("logarithm for %g, %g is %f\n", numf1, numf2, log10f(numf2)/log10f(numf1));
    }
    
  }
  // print integer arithmetic values
  else {
    
    // convert string arguments to integers
    num1 = atoi(argv[2]);
    num2 = atoi(argv[3]);

    if (option == 0) {
      fprintf(fp, "./l10 add %d %d\n", num1, num2);
      fprintf(fp, "addition for %d, %d is %d\n\n", num1, num2, num1 + num2);
      printf("addition for %d, %d is %d\n", num1, num2, num1 + num2);
    }
    else if (option == 1) {
      fprintf(fp, "./l10 sub %d %d\n", num1, num2);
      fprintf(fp, "subtraction for %d, %d is %d\n\n", num1, num2, num1 - num2);
      printf("subtraction for %d, %d is %d\n", num1, num2, num1 - num2);
    }
    else if (option == 2) {
      fprintf(fp, "./l10 mul %d %d\n", num1, num2);
      fprintf(fp, "multiplication for %d, %d is %d\n\n", num1, num2, num1 * num2);
      printf("multiplication for %d, %d is %d\n", num1, num2, num1 * num2);
    }
    else if (option == 3) {
      
      // check for division by 0
      fprintf(fp, "./l10 div %d %d\n", num1, num2);
      
      if (num2 == 0) {
	fprintf(fp, "division cannot be performed for %d, %d\n\n", num1, num2);
	printf("division cannot be performed for %d, %d\n", num1, num2);
      }
      else {
	fprintf(fp, "division for %d, %d is %d\n\n", num1, num2, num1 / num2);
	printf("division for %d, %d is %d\n", num1, num2, num1 / num2);
      }
    }
    else if (option == 4) {
      fprintf(fp, "./l10 mod %d %d\n", num1, num2);
      fprintf(fp, "modulo for %d, %d is %d\n\n", num1, num2, num1 % num2);
      printf("modulo for %d, %d is %d\n", num1, num2, num1 % num2);
    }
    else if (option == 5) {
      fprintf(fp, "./l10 pow %d %d\n", num1, num2);
      fprintf(fp, "power for %d, %d is %d\n\n", num1, num2, (int)pow(num1,num2));
      printf("power for %d, %d is %d\n", num1, num2, (int)pow(num1,num2));
    }
    else if (option == 6) {
      fprintf(fp, "./l10 log %d %d\n", num1, num2);
      fprintf(fp, "logarithm for %d, %d is %f\n\n", num1, num2, (log10f(num2)/log10f(num1)));
      printf("logarithm for %d, %d is %f\n", num1, num2, (log10f(num2)/log10f(num1)));
    }
  }
  
  return;
}
