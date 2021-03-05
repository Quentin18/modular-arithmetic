/**
 * @file mainExtendedGcdInt.c
 * @brief Main for Extended Euclidean algorithm for integers
 */
#include <stdio.h>
#include "integer.h"
#include "extendedGcdInt.h"

/**
 * Main for Extended Euclidean algorithm for integers.
 */
int main()
{
    integer a, b, u, v;

    printf("== Extended Euclidean algorithm for integers ==\n");

    /* Init integers */
    i_scan(&a, "a");
    i_scan(&b, "b");

    /* Extended Euclidean algorithm */
    print_extended_gcd_int(a, b, &u, &v);

    return 0;
}
