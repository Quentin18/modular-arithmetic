/**
 * @file euclideanDivisionPoly.c
 * @brief Euclidean division with polynomial arithmetic in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Euclidean division with polynomial arithmetic in Fm[x].
 */
int main()
{
    polynomial p, d, q, r;
    degree dp, dd, dq, dr;
    modulus m;

    printf("== Euclidean division of polynomials ==\n");

    /* Init polynomials */
    dp = p_scan(p, "P");
    dd = p_scan(d, "D");
    printf("Modulus: ");
    scanf("%u", &m);

    /* Print polynomials */
    p_print(p, dp, "P");
    p_print(d, dd, "D");

    printf("== Results ==\n");

    /* Quotient */
    dq = mp_div(p, dp, d, dd, q, m);
    p_print(q, dq, "Q");

    /* Remainder */
    dr = mp_mod(p, dp, d, dd, r, m);
    p_print(r, dr, "R");

    return 0;
}
