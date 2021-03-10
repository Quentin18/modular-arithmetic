/**
 * @file example10.c
 * @brief Example 10: Derivation of polynomials
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Derivation of polynomials.
 */
int main()
{
    polynomial r, s;
    degree dr, ds;

    polynomial p = {89, 6, 4, 3};
    degree dp = 3;
    polynomial q = {9, 1, 4, 7, 1};
    degree dq = 4;

    modulus m = 11;

    /* In Q[x] */
    printf("In Q[x]:\n");

    dr = p_derivate(p, dp, r);

    p_print(p, dp, "P");
    p_print(r, dr, "P'");

    /* In Fm[x] */
    printf("In F%u[x]:\n", m);
    ds = mp_derivate(q, dq, s, m);

    p_print(q, dq, "Q");
    p_print(s, ds, "Q'");

    return 0;
}
