/**
 * @file example1.c
 * @brief Example 1: Extended Euclidean algorithm for integers
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
    int a, b, u, v;
    printf("== Extended Euclidean algorithm for integers ==\n");
    a = 240; b = 46;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    print_extended_gcd_int(a, b, &u, &v);
    return 0;
}
