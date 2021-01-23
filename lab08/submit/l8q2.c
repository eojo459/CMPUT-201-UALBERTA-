/* Purpose: Lab Exercise 8 Question 2
 * Author: Emmanuel Ojo
 * Date: October 23 2020
 *
 * Sources:
 *   - Extended Euclidean Algorithm: https://math.stackexchange.com/questions/1621690/finding-d-gcda-b-finding-integers-m-and-n-d-manb
 *   - https://math.stackexchange.com/questions/981773/algorithm-to-find-the-coefficient-of-gcd-linear-combination
 *   - GCD code: http://webdocs.cs.ualberta.ca/~ghlin/CMPUT201/lab9658037071718557_08.html
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>

void coefficients(int, int, int);

int main() {
  
  int i, j, num1, num2, gcd;
  printf("Enter two positive integers: ");
  scanf("%d%d", &i, &j); // need to validate both being positive

  num1 = i;
  num2 = j;
  
  while (i != j) {
    i > j ? (i -= j) : (j -= i);
  }
  //printf("GCD: %d\n", i);

  gcd = i;

  // find (a,b) from gcd = a*i + b*j
  coefficients(num1, num2, gcd);
  
  return 0;
}

void coefficients(int num1, int num2, int gcd) {

  int largest, smallest;
  int r1, m1, n1, r2, q2, m2, n2, r3, q3, m3, n3;
  int a, q, b, r = -1;
  int n, m;
  
  // check which number is larger
  if (num1 > num2) {
    largest = num1;
    smallest = num2;
  }
  else {
    largest = num2;
    smallest = num1;
  }
  
  // start building the table with default values
  r1 = largest;
  m1 = 1;
  n1 = 0;

  r2 = smallest;
  q2 = (r1 / r2);
  m2 = 0;
  n2 = 1;

  // check a = qb+r
  a = largest; // r1
  b = smallest; // r2

  q = 1;

  while (q*b <= a) {
    q++;
  }
  
  if (q*b > a) {
    q--;
  }

  // check if we have the 0th remainder, if so we are done
  r = a - (q*b);

  if (r == 0) {
    m = m2;
    n = n2;
  }
  else {
  
    // build the rest of the table
    while (r != 0 || r != gcd || r !=1 || r3 !=0 || r3 != gcd || r3 != 1) {
      
      m3 = m1 - (q2 * m2);
      n3 = n1 - (q2 * n2);
      r3 = (m3 * largest) + (n3 * smallest);
      q3 = (r2 / r3);

      // get a and b for a = qb +r
      a = r1;
      b = r2;
      
      // check a = qb + r
      // r = a - qb
      q = 1;
      
      while (q*b <= a) {
	q++;
      }
      
      if (q*b > a) {
	q--;
      }
      
      r = a - q*b;

      // prevent any more rows from being created if they dont need to be created
      if (r == 1 || r == gcd || r == 0) {
	m = m3;
	n = n3;
	break;
      }

      // continue building the table if we haven't reached r = gcd or the end of the table
      r1 = r2;
      m1 = m2;
      n1 = n2;
      
      r2 = r3;
      q2 = q3;
      m2 = m3;
      n2 = n3;
    }
    
  }

  // print out gcd = a*i + b*j
  // where, a == m , b == n
  if (m < 0) {

    if (n < 0) {
      printf("GCD: %d = (%d) * %d + (%d) * %d\n", gcd, m, largest, n, smallest);
    }
    else {
      printf("GCD: %d = (%d) * %d + %d * %d\n", gcd, m, largest, n, smallest);
    }
  }
  else {
    if (n < 0) {
      printf("GCD: %d = %d * %d + (%d) * %d\n", gcd, m, largest, n, smallest);
    }
    else {
      printf("GCD: %d = %d * %d + %d * %d\n", gcd, m, largest, n, smallest);
    }
  }

  return;
}
