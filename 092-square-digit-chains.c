/*
  Problem:

  A number chain is created by continuously adding the square of the digits
  in a number to form a new number until it has been seen before.

  For example,

  44 → 32 → 13 → 10 → 1 → 1
  85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

  Therefore any chain that arrives at 1 or 89 will become stuck in an endless
  loop. What is most amazing is that EVERY starting number will eventually
  arrive at 1 or 89.

  How many starting numbers below ten million will arrive at 89?
*/

#include <stdio.h>

/* In a number with no more than 7 digits, maximum sum of digit squares is no
more than 7*9*9. We will store the ultimate values (89 or 1) for everything up
to that number. */

#define MAX (7*9*9)

int ultimate_sums_of_digit_squares[MAX+1];

int
square(int n)
{
  return n*n;
}

int
sum_of_digit_squares(int n)
{
  char digits[10];
  char *c = digits;
  int sum = 0;

  sprintf(digits, "%d", n);

  while (*c) {
    sum += square(*c-'0');
    c++;
  }

  return sum;
}

int
main(int argc, char *argv[])
{
  int total = 0;

  /* Prefill ultimate_sums_of_digit_squares. */
  for (int m = 1; m <= MAX; m++) {
    int n = m;
    while (n!=89 && n!=1)
      n = sum_of_digit_squares(n);
    ultimate_sums_of_digit_squares[m] = n;
  }

  for (int n = 1; n < 10000000; n++)
    if (ultimate_sums_of_digit_squares[sum_of_digit_squares(n)] == 89)
      total++;

  printf("%d\n", total);
}
