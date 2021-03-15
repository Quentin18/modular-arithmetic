/**
 * @file example11.c
 * @brief Example 11: Polynomials interpolation
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Polynomials interpolation.
 */
int main()
{
    int i;
    polynomial p;
    degree dp;
    integer z[4];

    unsigned int n = 4;
    integer x[4] = {2, 5, 3, 4};
    integer y[4] = {1, 2, 3, 6};

    modulus m = 7;

    /* Interpolation */

    dp = mp_fast_interpolation(x, y, n, p, m);
    /* dp = mp_lagrange_polynomial(x, y, n, p, m); */

    printf("Lagrange polynomial:\n");
    p_print(p, dp, "L");

    /* Verification: multipoint evaluation */

    printf("Verification:\n");
    mp_fast_multipoint_eval(p, dp, x, z, n, m);
    /* mp_horner_multipoint(p, dp, x, z, n, m); */

    /* Print result */
    for (i = 0; i < n; i++)
    {
        printf("L(%d) = %d\n", x[i], z[i]);
    }

    return 0;
}
