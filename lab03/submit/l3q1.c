/* Purpose: Lab exercise 3 Question 1
 * Author: Emmanuel Ojo
 * Date: September 22, 2020
 *
 * Sources: 
 *
 * - While loop: C Programming: A Modern Apporach, 2nd Edition Textbook.
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

int main() {

  /* start with 99 beers*/
  int beerAmount = 99;

  
  /* loop while there is more than 1 beer left, so loop until 1 beer left */
  while (beerAmount > 1) {
    printf("\n");
    printf("%d bottles of beer on the wall,\n", beerAmount);
    printf("%d bottles of beer.\n", beerAmount);
    printf("Take one down, pass it around,\n");

    beerAmount--;
    
    /* if there is 1 beer left, change the english and exit loop */
    switch (beerAmount)
      {
      case 1:
	printf("%d bottle of beer on the wall,\n", beerAmount);
	
	printf("\n");
	printf("%d bottle of beer on the wall,\n", beerAmount);
	printf("%d bottle of beer.\n", beerAmount);
	printf("Take one down, pass it around,\n");
	printf("Zero bottles of beer on the wall.\n");
	break;
      }

    // exit loop
    if (beerAmount == 1) {
      break;
    }
    
    printf("%d bottles of beer on the wall.\n", beerAmount);
  } 

  return 0;
}
