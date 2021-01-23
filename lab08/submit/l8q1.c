/* Purpose: Lab Exercise 8 Question 1
 * Author: Emmanuel Ojo
 * Date: October 28 2020
 *
 * Sources:
 *   - Array of pointers and malloc: https://stackoverflow.com/questions/3508686/taking-strings-as-input-into-an-array-of-pointers-to-strings-and-displaying-them
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_LEN 100
#define NUM_OF_THINGS 11

void roll(char *[]);

int main(int argc, char *argv[]) {

  // initialize the random seed
  srand(time(NULL));

  // pointer to strings and line length string
  char *things[NUM_OF_THINGS], lineLength[STR_LEN];
  
  // populate the things array from things.txt
  for (int i=0; i < NUM_OF_THINGS; i++) {

    // read line and allocate required space in array 
    if (fgets(lineLength, STR_LEN, stdin) != NULL) {
      things[i] = malloc(strlen(lineLength));
      strcpy(things[i], lineLength);
    }
    
  }

  // randomly pick a thing to do from the list every time '/n' is detected
  roll(things);
  
  return 0;
}


void roll(char *list[]) {

  int chance;
  char temp;
  
  while ((temp = getchar()) != EOF) {
     
    if (temp == '\n') {
      
      // randomly pick a number from 0 - 10 and pick an item from the list 
      chance = rand() % 11;
      printf("%s\n", list[chance]);
    }
  }
  
}

