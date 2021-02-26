/**
 * @file testModPolyP.c
 * @brief Tests for polynomial arithmetic in Fm[x]/P
 */
#include <stdio.h>
#include "modpolyp.h"

/**
 * Tests for polynomial arithmetic in Fm[x]/P
 */
int main()
{
    int dp, dq, dr, ds, dt, du, dv;
    int m1, m2;
    int dP1, dP2;
    polynomial r, s, t, v;

    polynomial p = {1, 2};
    polynomial q = {3, -4};
    polynomial P1 = {1, 0, 1};

    polynomial u = {2, 3, 3};
    polynomial P2 = {2, 0, 0, 1};

    dp = 1; dq = 1; dP1 = 2; m1 = 20;
    du = 2, dP2 = 3, m2 = 7;

    mpp_print(p, dp, "P");
    mpp_print(q, dq, "Q");

    /* Addition */
    dr = mpp_add(p, dp, q, dq, r, m1, P1, dP1);
    mpp_print(r, dr, "P + Q");

    /* Subtraction */
    ds = mpp_sub(p, dp, q, dq, s, m1, P1, dP1);
    mpp_print(s, ds, "P - Q");

    /* Multiplication */
    dt = mpp_mul(p, dp, q, dq, t, m1, P1, dP1);
    mpp_print(t, dt, "(P * Q)");

    /* Inverse */
    mpp_print(u, du, "U");
    mpp_print(P2, dP2, "P2");
    dv = mpp_inv(u, du, v, m2, P2, dP2);
    mpp_print(v, dv, "U^-1 mod P2");

    return 0;
}
