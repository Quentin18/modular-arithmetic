/**
 * @file modpoly.c
 * @brief Polynomial arithmetic implementation in Fm[x]
 */
#include <stdio.h>
#include <stdlib.h>
#include "modpoly.h"
#include "modint.h"
#include "extendedGcdPoly.h"

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
 * Return the result of x^n.
 * 
 * @param x integer
 * @param n exponent
 * @return x^n
 */
int power(int x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(x, n - 1);
}

/**
 * Init a polynomial with scanf.
 * 
 * @param p polynomial
 * @param name name of p
 * @return degree of p
 */
int mp_init(polynomial p, char *name)
{
    unsigned int i;
    int dp;
    printf("Degree of %s: ", name);
    scanf("%d", &dp);
    if (dp > MAX_DEGREE)
    {
        fprintf(stderr,
                "Mod Error: max degree for polynomials is %d (%d is too big). Exit.\n", MAX_DEGREE, dp);
        exit(EXIT_FAILURE);
    }    
    for (i = 0; i <= dp; i++)
    {
        printf("%s[%d] = ", name, i);
        scanf("%d", &p[i]);
    }
    return dp;
}

/**
 * Print a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param name name of p
 */
void mp_print(const polynomial p, int dp, char *name)
{
    int i, v;
    printf("%s =", name);
    if (dp == 0)
    {
        printf(" %d\n", p[0]);
        return;
    }
    for (i = dp; i >= 0; i--)
    {
        if (p[i] == 0)
        {
            continue;
        }
        if (p[i] < 0)
        {
            v = -p[i];
            printf(" -");
        }
        else
        {
            v = p[i];
            if (i != dp)
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
            printf(" X^%d", i);
        }
        else if (i == 1)
        {
            printf(" X");
        }
    }
    printf("\n");
}

/**
 * Copy a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param r copy of p
 * @return degree of r
 */
int mp_copy(const polynomial p, int dp, polynomial r)
{
    unsigned int i;
    for (i = 0; i <= dp; i++)
    {
        r[i] = p[i];
    }
    return dp;
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
int mp_add(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m)
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
int mp_sub(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m)
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
int mp_mul(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m)
{
    unsigned int i, j;

    /* Calculate degree dr */
    int dr = dp + dq;
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
 * Computes r = p^-1 in Fm[x]/q.
 *
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial p^-1 in Fm[x]/q
 * @param m modulus
 * @return degree of r
 */
int mp_inv(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m)
{
    polynomial w, u;
    int dw, du, dr;
    mp_extended_gcd(q, dq, p, dp, w, &dw, u, &du, r, &dr, m);
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
int mp_div(const polynomial p, int dp, const polynomial d, int dd, polynomial q, int m)
{
    int i, j, t;
    polynomial r;

    /* Calculate degree dq */
    int dq = dp - dd;
    if (dq < 0)
    {
        fprintf(stderr, "Mod Error: the degree of p (%d) must be greater than the degree of d (%d). Exit.\n", dp, dd);
        exit(EXIT_FAILURE);
    }

    /* Init remainder r */
    mp_copy(p, dp, r);

    for (i = dp; i >= dd; i--)
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
int mp_mod(const polynomial p, int dp, const polynomial d, int dd, polynomial r, int m)
{
    int i, j, t, dr;

    /* Init remainder r */
    dr = mp_copy(p, dp, r);

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
 * Return the leading term of a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @return leading term of p
 */
int mp_lead(const polynomial p, int dp)
{
    return p[dp];
}

/**
 * Return the constant term of a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @return constant term of p
 */
int mp_const(const polynomial p)
{
    return p[0];
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
int mp_eval(const polynomial p, int dp, int x, int m)
{
    unsigned int i;
    int y = 0;
    for (i = 0; i <= dp; i++)
    {
        y += p[i] * power(x, i);
    }
    return mod(y, m);
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
int mp_horner(const polynomial p, int dp, int x, int m)
{
    int i;
    int y = 0;
    for (i = dp; i >= 0; i--)
    {
        y = x * y + p[i];
    }
    return mod(y, m);
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
void mp_horner_multipoint(const polynomial p, int dp, int *x, int *y, int n, int m)
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
void mp_fast_multipoint_eval(const polynomial p, int dp, int *x, int *y, int n, int m)
{
    int i;
    polynomial r;
    int dd = 1;
    polynomial d = {0, 1};
    for (i = 0; i < n; i++)
    {
        d[0] = mod(-x[i], m);
        mp_mod(p, dp, d, dd, r, m);
        y[i] = r[0];
    }
}
