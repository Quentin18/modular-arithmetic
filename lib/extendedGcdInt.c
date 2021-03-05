/**
 * @file extendedGcdInt.c
 * @brief Extended Euclidean algorithm for integers
 */
#include <stdio.h>
#include "extendedGcdInt.h"

/**
 * Extended Euclidean algorithm for integers.
 * 
 * @param a first integer
 * @param b second integer
 * @param u bezout coefficient of a
 * @param v bezout coefficient of b
 * @return r = gcd(a, b) = a * u + b * v
 */
integer extended_gcd_int(integer a, integer b, integer* u, integer* v)
{
    integer r, rp, up, vp, rs, us, vs, q;
    r = a; *u = 1; *v = 0;
    rp = b; up = 0; vp = 1;
    while (rp != 0)
    {
        q = r / rp;
        rs = r - q * rp;
        r = rp;
        rp = rs;
        us = *u - q * up;
        *u = up;
        up = us;
        vs = *v - q * vp;
        *v = vp;
        vp = vs;
    }
    return r;
}

/**
 * Print steps of Extended Euclidean algorithm for integers.
 * 
 * @param a first integer
 * @param b second integer
 * @param u bezout coefficient of a
 * @param v bezout coefficient of b
 * @return r = gcd(a, b) = a * u + b * v
 */
integer print_extended_gcd_int(integer a, integer b, integer* u, integer* v)
{
    integer r, rp, up, vp, rs, us, vs, q;
    int i = 0;
    r = a; *u = 1; *v = 0;
    rp = b; up = 0; vp = 1;
    while (rp != 0)
    {
        printf("== Iteration %d ==\n", i++);
        printf("(r, u, v) = (%d, %d, %d)\n", r, *u, *v);
        q = r / rp;
        rs = r - q * rp;
        r = rp;
        rp = rs;
        us = *u - q * up;
        *u = up;
        up = us;
        vs = *v - q * vp;
        *v = vp;
        vp = vs;
    }
    printf("== Result ==\n");
    printf("(r, u, v) = (%d, %d, %d)\n", r, *u, *v);
    return r;
}
