/**
 * @file example8.c
 * @brief Example 8: Advanced operations with polynomial arithmetic in Fm[x]/P
 */
#include <stdio.h>
#include "modpolyp.h"

/**
 * Advanced operations with polynomial arithmetic in Fm[x]/P.
 */
int main()
{
    polynomial r, s;
    degree dp, dq, dr, ds, dP;
    modulus m;

    polynomial p = {1, 1, 0, 0, 1};
    polynomial q = {1, 0, 1, 1, 1};
    polynomial P = {1, 0, 1, 0, 0, 1};

    dp = 4, dq = 4, dP = 5, m = 2;

    p_print(p, dp, "P");
    p_print(q, dq, "Q");

    /* Inverse */
    dr = mpp_inv(p, dp, r, m, P, dP);
    p_print(r, dr, "P^-1");

    /* Division */
    ds = mpp_div(p, dp, q, dq, s, m, P, dP);
    p_print(s, ds, "P / Q");

    return 0;
}
