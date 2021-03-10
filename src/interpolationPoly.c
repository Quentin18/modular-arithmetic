/**
 * @file interpolationPoly.c
 * @brief Main for polynomial interpolation
 */
#include <stdio.h>
#include <stdlib.h>
#include "modpoly.h"

/**
 * Main for polynomial interpolation.
 */
int main()
{
    polynomial p;
    degree dp;
    modulus m;
    unsigned int n, i;
    integer *x, *y, *z;

    printf("== Polynomial interpolation ==\n");

    /* Init modulus */
    printf("Modulus: ");
    scanf("%u", &m);

    /* Allocate memory */
    printf("n = "); scanf("%u", &n);
    x = (integer*)malloc(n * sizeof(integer));
    y = (integer*)malloc(n * sizeof(integer));
    z = (integer*)malloc(n * sizeof(integer));

    /* Init arrays */
    for (i = 0; i < n; i++)
    {
        printf("x%d = ", i); scanf("%d", &x[i]);
        printf("y%d = ", i); scanf("%d", &y[i]);
    }

    /* Interpolation */
    dp = mp_lagrange_polynomial(x, y, n, p, m);

    /* Print result */
    printf("Lagrange polynomial:\n");
    p_print(p, dp, "L");

    /* Verification: multipoint evaluation */
    printf("Verification:\n");
    mp_fast_multipoint_eval(p, dp, x, z, n, m);
    /* mp_horner_multipoint(p, dp, x, z, n, m); */

    /* Print verification */
    for (i = 0; i < n; i++)
    {
        printf("L(%d) = %d\n", x[i], z[i]);
    }

    /* Free memory */
    free(x);
    free(y);
    free(z);

    return 0;
}
