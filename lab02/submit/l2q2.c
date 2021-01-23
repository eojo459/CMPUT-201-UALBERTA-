/* Purpose: Lab Exercise 2 Part 2 - Determine the amount of $100, $20 bills, toonies and loonies.
 * Author: Emmanuel Ojo
 * Date: September 12, 2020
 * 
 * Sources: 
 * https://www.tutorialspoint.com/cprogramming/c_input_output.htm: to learn how to use the printf() and scanf() functions.
 *
 * https://ideone.com/7wIBAB: to learn how to format the C printf() output.
 * 
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded this program by myself.
 */

#include <stdio.h>

int main() {

  /* declare the variables */
  int fullNum, calcNum;
  int hundredBills, twentyBills, toonies, loonies;

  
  /* user enters full 3 digit number */
  printf("\nEnter a dollar amount: ");
  scanf("%d", &fullNum );

  
  /* calculate how many bills are needed */
  calcNum = fullNum;
  
  hundredBills = (calcNum / 100);
  calcNum = calcNum - (hundredBills * 100);

  twentyBills = (calcNum / 20);
  calcNum = calcNum - (twentyBills * 20);

  toonies = (calcNum / 2);
  calcNum = calcNum - (toonies * 2);

  loonies = calcNum;

  
  /* formatted output, SEE SOURCES */
  printf("$100 bills: %d\n", hundredBills);
  printf("%*s", 12, "$20 bills: ");
  printf("%d\n", twentyBills);
  printf("%*s", 12, "Toonies: ");
  printf("%d\n", toonies);
  printf("%*s", 12, "Loonies: ");
  printf("%d\n\n", loonies);
  
  return 0;
}
  
