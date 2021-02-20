/**
 * @file mainExtendedGcdInt.c
 * @brief Main for Extended Euclidean algorithm for integers
 */
#include <stdio.h>
#include "extendedGcdInt.h"

/**
 * Main for Extended Euclidean algorithm for integers.
 */
int main()
{
    int a, b, u, v;
    printf("== Extended Euclidean algorithm for integers ==\n");
    printf("a = "); scanf("%d", &a);
    printf("b = "); scanf("%d", &b);
    print_extended_gcd_int(a, b, &u, &v);
    return 0;
}
