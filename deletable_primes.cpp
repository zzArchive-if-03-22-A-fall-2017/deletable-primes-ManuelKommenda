/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */

  #include <stdlib.h>
  #include <stdio.h>
  #include <math.h>
  #include "deletable_primes.h"

 unsigned long remove_digit(int index, unsigned long number){
   long to_return = number;
   int to_remove = pow(10, index);
   int to_remove_divide = pow(10, index+1);
   to_return = number / to_remove_divide;
   to_return *= to_remove;
   to_return += number % to_remove;
   return to_return;
 }
int get_ways(unsigned long ways)
 {
   int poissible_ways = 0;
   if (is_the_number_a_prime(ways) == false) {
     return 0;
   }
   if (ways < 10) {
     if (is_the_number_a_prime(ways)) {
       return 1;
     }
     return 0;
   }

   int count = 0;
   int length = get_length(ways);

   while (count < length) {
     long number = remove_digit(count, ways);
     if (is_the_number_a_prime(number)) {
       int returned_ways = get_ways(number);
       poissible_ways += returned_ways;
     }
     count++;
   }
   return poissible_ways;
 }

 bool is_the_number_a_prime(long number){
   if (number == 2) {
     return true;
   }
   else if (number % 2 == 0) {
     return false;
   }

   for (long i = 3; i <= (number/2); i++) {
     if (number % i == 0) {
       return false;
     }
     i++;
   }

   return true;
 }
int get_length(long number){
   int count = 0;
   int to_check = 0;
   do {
     count++;
     to_check = number / pow(10, count);
   } while(to_check != 0);
   return count;
}
