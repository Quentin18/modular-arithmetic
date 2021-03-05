/**
 * @file example5.c
 * @brief Example 5: Euclidean division with polynomial arithmetic in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Euclidean division with polynomial arithmetic in Fm[x].
 */
int main()
{
    polynomial q, r;
    degree dp, dd, dq, dr;
    modulus m;

    polynomial p = {2, 0, 0, 1};
    polynomial d = {2, 3, 3};

    dp = 3, dd = 2, m = 7;

    printf("Field: F%d[X]\n", m);
    p_print(p, dp, "P");
    p_print(d, dd, "D");

    /* Quotient */
    dq = mp_div(p, dp, d, dd, q, m);
    p_print(q, dq, "Q");

    /* Remainder */
    dr = mp_mod(p, dp, d, dd, r, m);
    p_print(r, dr, "R");

    return 0;
}
