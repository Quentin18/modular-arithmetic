/**
 * @file example01.c
 * @brief Example 01: Extended Euclidean algorithm for integers
 * 
 * Source: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
 */
#include <stdio.h>
#include "extendedGcdInt.h"

/**
 * Extended Euclidean algorithm for integers.
 */
int main()
{
    integer a, b, u, v;
    a = 240; b = 46;

    printf("== Extended Euclidean algorithm for integers ==\n");
    i_print(a, "a");
    i_print(b, "b");

    /* Extended Euclidean algorithm */
    print_extended_gcd_int(a, b, &u, &v);

    return 0;
}
