/**
 * @file testModInt.c
 * @brief Tests for modular arithmetic for polynomials
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Tests for modular arithmetic for polynomials.
 */
int main()
{
    int dp, dq, dr, ds, dt, du, dv, dw, dx, dy, dz;
    int m1, m2, m3;
    polynomial r, s, t, w, z;

    polynomial p = {7, 4, -3, 1};
    polynomial q = {3, 0, 1};
    polynomial u = {2, 0, 0, 1};
    polynomial v = {2, 3, 3};
    polynomial x = {1, 1, 0, 0, 1};
    polynomial y = {1, 0, 1, 0, 0, 1};

    dp = 3, dq = 2, m1 = 4;
    du = 3, dv = 2, m2 = 7;
    dx = 4, dy = 5, m3 = 2;

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

    /* Advanced operations */
    printf("Field: F%d[X]\n", m2);
    mp_print(u, du, "U");
    mp_print(v, dv, "V");

    /* Division */
    dw = mp_div(u, du, v, dv, w, m2);
    mp_print(w, dw, "U / V");

    printf("Field: F%d[X]\n", m3);
    mp_print(x, dx, "X");
    mp_print(y, dy, "Y");

    /* Inverse */
    dz = mp_inv(x, dx, y, dy, z, m3);
    mp_print(z, dz, "X^-1 mod Y");

    return 0;
}
