/**
 * @file example7.c
 * @brief Example 7: Simple operations with polynomial arithmetic in Fm[x]/(P)
 */
#include <stdio.h>
#include "modpolyp.h"

/**
 * Simple operations with polynomial arithmetic in Fm[x]/(P).
 */
int main()
{
    polynomial r, s, t;
    degree dp, dq, dr, ds, dt, dP;
    modulus m;

    polynomial p = {2, 2};
    polynomial q = {1, 2};
    polynomial P = {1, 0, 1};

    dp = 1, dq = 1, dP = 2, m = 3;

    p_print(p, dp, "P");
    p_print(q, dq, "Q");

    /* Addition */
    dr = mpp_add(p, dp, q, dq, r, m, P, dP);
    p_print(r, dr, "P + Q");

    /* Subtraction */
    ds = mpp_sub(p, dp, q, dq, s, m, P, dP);
    p_print(s, ds, "P - Q");

    /* Multiplication */
    dt = mpp_mul(p, dp, q, dq, t, m, P, dP);
    p_print(t, dt, "P * Q");

    return 0;
}
