/* Purpose: Lab Exercise 2 Part 3 - Window washing service
 * Author: Emmanuel Ojo
 * Date: September 12, 2020
 *
 * Sources: CMPUT 201 lecture notes
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

int main() {

  /* declare our variables */
  int windows;
  float windowPrice, serviceCharge, totalCost, totalDiscountAmount, discount;

  
  /* ask user for input */
  printf("\nHow many windows do you have: ");
  scanf("%d", &windows);

  
  /* declare our service prices */
  windowPrice = 8.00;
  serviceCharge = 25.00;
  totalCost = 0.00;


  /* calculate cost */
  if (windows >= 0 && windows <= 24) {
    /* full price */

    totalCost = (windowPrice * windows) + serviceCharge;
  }
  else if (windows >= 25 && windows <= 49) {
    /* 5% off */

    discount = 0.05;
    totalCost = windowPrice * windows;
    totalDiscountAmount = totalCost * discount;
    totalCost = (totalCost - totalDiscountAmount) + serviceCharge;
  }
  else if (windows >= 50 && windows <= 99) {
    /* 10% off */

    discount = 0.10;
    totalCost = windowPrice * windows;
    totalDiscountAmount = totalCost * discount;
    totalCost = (totalCost - totalDiscountAmount) + serviceCharge;
  }
  else if (windows >= 100 && windows <= 499) {
    /* 20% off */

    discount = 0.20;
    totalCost = windowPrice * windows;
    totalDiscountAmount = totalCost * discount;
    totalCost = (totalCost - totalDiscountAmount) + serviceCharge;
  }
  else {
    /* 40% off */

    discount = 0.40;
    totalCost = windowPrice * windows;
    totalDiscountAmount = totalCost * discount;
    totalCost = (totalCost - totalDiscountAmount) + serviceCharge;
  }


  /* formatted output */
  printf("Your estimate for window cleaning is: $%.1f\n\n", totalCost);

  
  return 0;
}
