/**
 * @file example04.c
 * @brief Example 04: Simple operations with polynomial arithmetic in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Simple operations with polynomial arithmetic in Fm[x].
 */
int main()
{
    polynomial r, s, t;
    degree dp, dq, dr, ds, dt;
    modulus m;

    polynomial p = {7, 4, -3, 1};
    polynomial q = {3, 0, 1};

    dp = 3, dq = 2, m = 4;

    printf("Field: F%d[X]\n", m);
    p_print(p, dp, "P");
    p_print(q, dq, "Q");

    /* Addition */
    dr = mp_add(p, dp, q, dq, r, m);
    p_print(r, dr, "P + Q");

    /* Subtraction */
    ds = mp_sub(p, dp, q, dq, s, m);
    p_print(s, ds, "P - Q");

    /* Multiplication */
    dt = mp_mul(p, dp, q, dq, t, m);
    p_print(t, dt, "P * Q");

    return 0;
}
