/**
 * @file modpoly.c
 * @brief Polynomial arithmetic implementation in Fm[x]
 */
#include <stdio.h>
#include <stdlib.h>
#include "modpoly.h"

/**
 * Return the maximum between a and b.
 * 
 * @param a first integer
 * @param b second integer
 * @return max(a, b)
 */
int max(int a, int b)
{
    return a < b ? b : a;
}

/**
 * Computes r = (p + q) in Fm[x].
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p + q) in Fm[x]
 * @param m modulus
 * @return degree of r
 */
degree mp_add(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m)
{
    unsigned int i;

    /* Calculate polynomial r */
    if (dp < dq)
    {
        for (i = 0; i <= dp; i++)
        {
            r[i] = mi_add(p[i], q[i], m);
        }
        for (i = dp + 1; i <= dq; i++)
        {
            r[i] = mod(q[i], m);
        }
    }
    else
    {
        for (i = 0; i <= dq; i++)
        {
            r[i] = mi_add(p[i], q[i], m);
        }
        for (i = dq + 1; i <= dp; i++)
        {
            r[i] = mod(p[i], m);
        }
    }

    /* Calculate degree dr */
    for (i = max(dp, dq); i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Computes r = (p - q) in Fm[x].
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p - q) in Fm[x]
 * @param m modulus
 * @return degree of r
 */
degree mp_sub(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m)
{
    unsigned int i;

    /* Calculate polynomial r */
    if (dp < dq)
    {
        for (i = 0; i <= dp; i++)
        {
            r[i] = mi_sub(p[i], q[i], m);
        }
        for (i = dp + 1; i <= dq; i++)
        {
            r[i] = mod(q[i], m);
        }
    }
    else
    {
        for (i = 0; i <= dq; i++)
        {
            r[i] = mi_sub(p[i], q[i], m);
        }
        for (i = dq + 1; i <= dp; i++)
        {
            r[i] = mod(p[i], m);
        }
    }
    /* Calculate degree dr */
    for (i = max(dp, dq); i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Computes r = (p * q) in Fm[x].
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p * q) in Fm[x]
 * @param m modulus
 * @return degree of r
 */
degree mp_mul(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m)
{
    unsigned int i, j;

    /* Calculate degree dr */
    degree dr = dp + dq;
    if (dr > MAX_DEGREE)
    {
        fprintf(stderr,
                "Mod Error: max degree for polynomials is %d (%d is too big). Exit.\n", MAX_DEGREE, dr);
        exit(EXIT_FAILURE);
    }   

    /* Initialize r */
    for (i = 0; i <= dr; i++)
    {
        r[i] = 0;
    }

    /* Calculate r */
    for (i = 0; i <= dp; i++)
    {
        for (j = 0; j <= dq; j++)
        {
            r[i + j] = mi_add(r[i + j], mi_mul(p[i], q[j], m), m);
        }
    }
    return dr;
}

/**
 * Computes q = (p / d) in Fm[x].
 * 
 * @param p dividend
 * @param dp degree of p
 * @param d divisor
 * @param dd degree of d
 * @param q quotient
 * @param m modulus
 * @return degree of q
 */
degree mp_div(const polynomial p, degree dp, const polynomial d, degree dd, polynomial q, modulus m)
{
    int i, j;
    integer t;
    polynomial r;

    /* Calculate degree dq */
    int dq = dp - dd;

    /* Case zero polynomial */
    if (dq < 0)
    {
        r[0] = 0;
        return 0;
    }

    /* Init remainder r */
    p_copy(p, dp, r);

    for (i = dp; i >= (int)dd; i--)
    {
        q[i - dd] = t = mi_div(r[i], d[dd], m);
        r[i] = 0;

        for (j = 0; j < dd; j++)
        {
            r[i - dd + j] = mod(r[i - dd + j] - d[j] * t, m);
        }
    }

    return dq;
}

/**
 * Computes r = (p mod d) in Fm[x].
 * 
 * @param p dividend
 * @param dp degree of p
 * @param d divisor
 * @param dd degree of d
 * @param r remainder
 * @param m modulus
 * @return degree of r
 */
degree mp_mod(const polynomial p, degree dp, const polynomial d, degree dd, polynomial r, modulus m)
{
    int i, j, t, dr;

    /* Init remainder r */
    dr = p_copy(p, dp, r);

    for (i = dp; i >= dd; i--)
    {
        t = mi_div(r[i], d[dd], m);
        r[i] = 0;

        for (j = 0; j < dd; j++)
        {
            r[i - dd + j] = mod(r[i - dd + j] - d[j] * t, m);
        }
    }

    /* Calculate degree dr */
    for (i = dr; i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Evaluate a polynomial p at x using naive method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x integer
 * @param m modulus
 * @return p(x) mod m
 */
integer mp_eval(const polynomial p, degree dp, integer x, modulus m)
{
    return mod(p_eval(p, dp, x), m);
}

/**
 * Evaluate a polynomial p at x using Horner’s Method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x integer
 * @param m modulus
 * @return p(x) mod m
 */
integer mp_horner(const polynomial p, degree dp, integer x, modulus m)
{
    return mod(p_horner(p, dp, x), m);
}

/**
 * Evaluate a polynomial p at n points using Horner’s Method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x points
 * @param y p(x)
 * @param n number of points
 * @param m modulus
 */
void mp_horner_multipoint(const polynomial p, degree dp, integer *x, integer *y, unsigned int n, modulus m)
{
    int i;
    for (i = 0; i < n; i++)
    {
        y[i] = mp_horner(p, dp, x[i], m);
    }
}

/**
 * Evaluate a polynomial p at n points using fast evaluation.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x points
 * @param y p(x)
 * @param n number of points
 * @param m modulus
 */
void mp_fast_multipoint_eval(const polynomial p, degree dp, integer *x, integer *y, unsigned int n, modulus m)
{
    /* TODO to modify */
    int i;
    polynomial r;
    degree dd = 1;
    polynomial d = {0, 1};
    for (i = 0; i < n; i++)
    {
        d[0] = mod(-x[i], m);
        mp_mod(p, dp, d, dd, r, m);
        y[i] = r[0];
    }
}
