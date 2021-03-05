/**
 * @file mainExtendedGcdInt.c
 * @brief Main for Extended Euclidean algorithm for polynomials in Fm[x]
 */
#include <stdio.h>
#include "extendedGcdPoly.h"

/**
 * Main for Extended Euclidean algorithm for polynomials in Fm[x].
 */
int main()
{
    polynomial a, b, r, u, v;
    degree da, db, dr, du, dv;
    modulus m;

    printf("== Extended Euclidean algorithm for polynomials ==\n");

    /* Init polynomials */
    da = p_scan(a, "A");
    db = p_scan(b, "B");
    printf("Modulus: ");
    scanf("%u", &m);

    /* Print polynomials */
    p_print(a, da, "A");
    p_print(b, db, "B");

    /* Extended Euclidean algorithm */
    mp_print_extended_gcd(a, da, b, db, r, &dr, u, &du, v, &dv, m);

    return 0;
}
