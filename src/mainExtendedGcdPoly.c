/**
 * @file mainExtendedGcdInt.c
 * @brief Main for Extended Euclidean algorithm for polynomials
 */
#include <stdio.h>
#include "extendedGcdPoly.h"

/**
 * Main for Extended Euclidean algorithm for polynomials.
 */
int main()
{
    polynomial a, b, r, u, v;
    int da, db, dr, du, dv, m;

    printf("== Extended Euclidean algorithm for polynomials ==\n");

    /* Init polynomials */
    da = mp_init(a, "A");
    db = mp_init(b, "B");
    printf("Modulus: ");
    scanf("%d", &m);

    /* Print polynomials */
    mp_print(a, da, "A");
    mp_print(b, db, "B");

    /* Extended Euclidean algorithm */
    mp_print_extended_gcd(a, da, b, db, r, &dr, u, &du, v, &dv, m);

    return 0;
}
