/* Purpose: Lab Exercise 3 Question 3
 * Author: Emmanuel Ojo
 * Date: September 22, 2020
 *
 * Sources:
 *   - rand() and srand() usage: https://stackoverflow.com/questions/41784131/random-number-in-c-with-rand
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // initialize the random seed
  srand(time(NULL));

  // delcare and initialize the variables
  int aliceScore, bobScore, winningScore, diceAmount, diceRoll;
  
  aliceScore = 0;
  bobScore = 0;
  winningScore = 1000;
  diceAmount = 0;
  diceRoll = 0;
  
  while (aliceScore <= winningScore || bobScore <= winningScore) {
    
    // Alice goes first, read in dice amount to roll
    scanf("%d", &diceAmount);
    
    // add dice roll(s) to total score
    for (int i = 0; i < diceAmount; i++) {
      diceRoll = 1 + rand() % 6;
      aliceScore += diceRoll;
    }

    // 2 dice = -5 | 3 dice = -10 | 4 dice = -20 | from overall score
    if (diceAmount == 2) {
      aliceScore -= 5;
    } else if (diceAmount == 3) {
      aliceScore -= 10;
    } else if (diceAmount == 4) {
      aliceScore -= 20;
    }
			       
    //printf("Alice score: %d\n", aliceScore);
    
    // if alice reaches >= 1000 points first, she wins, exit loop
    if (aliceScore >= winningScore) {
      printf("Alice wins with %d points.\n", aliceScore);
      break;
    }
    // else bob goes next...

    
    // Bob goes second
    scanf("%d", &diceAmount);
    
    // add dice roll(s) to total score
    for (int i = 0; i < diceAmount; i++) {
      diceRoll = 1 + rand() % 6;
      bobScore += diceRoll;
    }

    // 2 dice = -5 | 3 dice = -10 | 4 dice = -20 | from overall score
    if (diceAmount == 2) {
      bobScore -= 5;
    } else if (diceAmount == 3) {
      bobScore -= 10;
    } else if (diceAmount == 4) {
      bobScore -= 20;
    }
			       
    //printf("Bob score: %d\n", bobScore);
    
    // if bob reaches >= 1000 points first, he wins, exit loop
    if (bobScore >= winningScore) {
      printf("Bob wins with %d points.\n", bobScore);
      break;
    }
    // else keep repeating the while loop till someone wins..
    
  }
    
  return 0;
}

