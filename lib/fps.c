/**
 * @file fps.c
 * @brief Formal power series
 */
#include <stdio.h>
#include "fps.h"

/**
 * Print a formal power series in precision n.
 * 
 * @param s fps
 * @param n precision
 * @param name name of s
 */
void fps_print(const fps s, prec n, char *name)
{
    int i;
    integer v;
    printf("%s =", name);
    if (n == 0)
    {
        printf("O(1)\n");
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (s[i] == 0)
        {
            continue;
        }
        if (s[i] < 0)
        {
            v = -s[i];
            printf(" -");
        }
        else
        {
            v = s[i];
            if (i != 0)
            {
                printf(" +");
            }
        }
        if (v != 1 || i == 0)
        {
            printf(" %d", v);
        }
        if (i > 1)
        {
            printf(" z^%d", i);
        }
        else if (i == 1)
        {
            printf(" z");
        }
    }
    if (n == 1)
    {
        printf(" + O(z)\n");
    }
    else
    {
        printf(" + O(z^%d)\n", n);
    }
}

/**
 * Returns 1 if the formal power series s is invertible (if s0 != 0), 0 else.
 * 
 * @param s fps
 * @return 1 if the fps is invertible, 0 else
 */
int fps_is_invertible(const fps s)
{
    return s[0] == 0 ? 0 : 1;
}

/**
 * Inverts a formal power series using the Newton's method.
 * 
 * @param s truncated fps in precision n
 * @param n precision
 * @param u inverse of s in precision n
 * @param m modulus
 */
void fps_newton_inverse(const fps s, prec n, fps u, modulus m)
{
    fps t, ts, v, w;
    degree ds1, ds, dt, dts, dv, dw;
    fps s1 = {1}; ds1 = 0;

    if (n == 1)
    {
        u[0] = mi_inv(s[0], m);
    }
    else
    {
        /* Computes recursively the inverse */
        fps_newton_inverse(s, n / 2, t, m);

        /* Computes u = t + (1 - ts)t */
        dt = n / 2 - 1; ds = n - 1;
        dts = mp_mul(t, dt, s, ds, ts, m);
        dv = mp_sub(s1, ds1, ts, dts, v, m);
        dw = mp_mul(v, dv, t, dt, w, m);
        mp_add(t, dt, w, dw, u, m);
    }

    /* Prints U */
    fps_print(u, n, "U");
}
