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
    int dp, m, x, y;

    printf("== Polynomial evaluation ==\n");

    /* Init polynomial */
    dp = mp_init(p, "P");
    printf("Modulus: ");
    scanf("%d", &m);

    /* Print polynomial */
    mp_print(p, dp, "P");

    /* Evaluate polynomial */
    printf("X = "); scanf("%d", &x);
    y = mp_horner(p, dp, x, m);
    /* y = mp_eval(p, dp, x, m); */

    /* Print result */
    printf("P(%d) = %d\n", x, y);

    return 0;
}
