/**
 * @file testModPoly.c
 * @brief Tests for polynomial arithmetic in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Tests for polynomial arithmetic in Fm[x]
 */
int main()
{
    int dp, dq, dr, ds, dt, du, dv, dw;
    int m1, m2;
    polynomial r, s, t, w;

    polynomial p = {7, 4, -3, 1};
    polynomial q = {3, 0, 1};
    polynomial u = {2, 0, 0, 1};
    polynomial v = {2, 3, 3};

    dp = 3, dq = 2, m1 = 4;
    du = 3, dv = 2, m2 = 7;

    /* Simple operations */
    printf("Field: F%d[X]\n", m1);
    mp_print(p, dp, "P");
    mp_print(q, dq, "Q");

    /* Addition */
    dr = mp_add(p, dp, q, dq, r, m1);
    mp_print(r, dr, "P + Q");

    /* Subtraction */
    ds = mp_sub(p, dp, q, dq, s, m1);
    mp_print(s, ds, "P - Q");

    /* Multiplication */
    dt = mp_mul(p, dp, q, dq, t, m1);
    mp_print(t, dt, "(P * Q)");

    /* Advanced operation */
    printf("Field: F%d[X]\n", m2);
    mp_print(u, du, "U");
    mp_print(v, dv, "V");

    /* Division */
    dw = mp_div(u, du, v, dv, w, m2);
    mp_print(w, dw, "U / V");

    return 0;
}
