/**
 * @file example13.c
 * @brief Example 13: Factorization of polynomials
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Factorization of polynomials.
 */
int main()
{
    polynomial q, r;
    degree dq, dr;

    polynomial p = {30, 4, 1, 211, 1};
    degree dp = 4;
    modulus m = 3;

    p_print(p, dp, "P");
    printf("Field: F%d[X]\n", m);

    printf("Factorization:\n");
    mp_berlekamp_facto(p, dp, q, &dq, r, &dr, m);

    return 0;
}
