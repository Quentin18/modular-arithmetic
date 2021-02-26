/**
 * @file example6.c
 * @brief Example 6: Extended Euclidean algorithm for polynomials in Fm[x]
 * 
 * Source: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example_2
 */
#include <stdio.h>
#include "extendedGcdPoly.h"

/**
 * Extended Euclidean algorithm for polynomials in Fm[x].
 */
int main()
{
    polynomial r, u, v;
    int da, db, dr, du, dv, m;

    polynomial a = {1, 1, 0, 1, 1, 0, 0, 0, 1};
    polynomial b = {1, 1, 0, 0, 1, 0, 1};

    da = 8; db = 6; m = 2;

    printf("== Extended Euclidean algorithm for polynomials ==\n");

    p_print(a, da, "A");
    p_print(b, db, "B");

    /* Extended Euclidean algorithm */
    mp_print_extended_gcd(a, da, b, db, r, &dr, u, &du, v, &dv, m);

    return 0;
}
