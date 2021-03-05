/**
 * @file multipointEvalPoly.c
 * @brief Main for polynomial multipoint evaluation
 */
#include <stdio.h>
#include <stdlib.h>
#include "modpoly.h"

/**
 * Main for polynomial multipoint evaluation.
 */
int main()
{
    polynomial p;
    degree dp;
    modulus m;
    unsigned int n, i;
    integer *x, *y;

    printf("== Polynomial multipoint evaluation ==\n");

    /* Init polynomial */
    dp = p_scan(p, "P");
    printf("Modulus: ");
    scanf("%u", &m);

    /* Print polynomial */
    p_print(p, dp, "P");

    /* Allocate memory */
    printf("n = "); scanf("%u", &n);
    x = (integer*)malloc(n * sizeof(integer));
    y = (integer*)malloc(n * sizeof(integer));

    /* Init x array */
    for (i = 0; i < n; i++)
    {
        printf("x%d = ", i); scanf("%d", &x[i]);
    }

    /* Evaluate polynomial */
    mp_fast_multipoint_eval(p, dp, x, y, n, m);
    /* mp_horner_multipoint(p, dp, x, y, n, m); */

    /* Print result */
    printf("== Result ==\n");
    for (i = 0; i < n; i++)
    {
        printf("P(%d) = %d\n", x[i], y[i]);
    }

    /* Free memory */
    free(x);
    free(y);

    return 0;
}
