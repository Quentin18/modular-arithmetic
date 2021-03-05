/**
 * @file evalPoly.c
 * @brief Main for polynomial evaluation
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Main for polynomial evaluation.
 */
int main()
{
    polynomial p;
    degree dp;
    modulus m;
    integer x, y;

    printf("== Polynomial evaluation ==\n");

    /* Init polynomial */
    dp = p_scan(p, "P");
    printf("Modulus: ");
    scanf("%u", &m);

    /* Print polynomial */
    p_print(p, dp, "P");

    /* Evaluate polynomial */
    printf("X = "); scanf("%d", &x);
    y = mp_horner(p, dp, x, m);
    /* y = mp_eval(p, dp, x, m); */

    /* Print result */
    printf("P(%d) = %d\n", x, y);

    return 0;
}
