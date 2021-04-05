/**
 * @file polynomial.c
 * @brief Polynomials implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

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
degree p_scan(polynomial p, char *name)
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
 * Write a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param file file
 */
void p_write(const polynomial p, degree dp, FILE *file)
{
    int i;
    integer v;
    if (dp == 0)
    {
        fprintf(file, " %d", p[0]);
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
            fprintf(file, " -");
        }
        else
        {
            v = p[i];
            if (i != dp)
            {
                fprintf(file, " +");
            }
        }
        if (v != 1 || i == 0)
        {
            fprintf(file, " %d", v);
        }
        if (i > 1)
        {
            fprintf(file, " X^%d", i);
        }
        else if (i == 1)
        {
            fprintf(file, " X");
        }
    }
}

/**
 * Print a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param name name of p
 */
void p_print(const polynomial p, degree dp, char *name)
{
    printf("%s =", name);
    p_write(p, dp, stdout);
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
degree p_copy(const polynomial p, degree dp, polynomial r)
{
    unsigned int i;
    for (i = 0; i <= dp; i++)
    {
        r[i] = p[i];
    }
    return dp;
}

/**
 * Return the leading term of a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @return leading term of p
 */
integer p_lead(const polynomial p, degree dp)
{
    return p[dp];
}

/**
 * Return the constant term of a polynomial.
 * 
 * @param p polynomial
 * @return constant term of p
 */
integer p_const(const polynomial p)
{
    return p[0];
}

/**
 * Evaluate a polynomial p at x using naive method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x integer
 * @return p(x)
 */
integer p_eval(const polynomial p, degree dp, integer x)
{
    unsigned int i;
    int y = 0;
    for (i = 0; i <= dp; i++)
    {
        y += p[i] * power(x, i);
    }
    return y;
}

/**
 * Evaluate a polynomial p at x using Horner’s Method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x integer
 * @return p(x)
 */
integer p_horner(const polynomial p, degree dp, integer x)
{
    int i;
    int y = 0;
    for (i = dp; i >= 0; i--)
    {
        y = x * y + p[i];
    }
    return y;
}

/**
 * Derivate a polynomial p.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param r derivative of p
 * @return degree of r
 */
degree p_derivate(const polynomial p, degree dp, polynomial r)
{
    int i;
    degree dr;

    /* Case constant polynomial */
    if (dp == 0)
    {
        r[0] = 0;
        return 0;
    }

    dr = dp - 1;
    for (i = 0; i <= dr; i++)
    {
        r[i] = p[i + 1] * (i + 1);
    }

    return dr;
}

/**
 * Return 1 if the polynomials p and q are equal, 0 else.
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @return p == q
 */
int p_are_equal(const polynomial p, degree dp, const polynomial q, degree dq)
{
    unsigned int i;

    /* Test degree */
    if (dp != dq)
    {
        return 0;
    }

    /* Test coefficients */
    for (i = 0; i <= dp; i++)
    {
        if (p[i] != q[i])
        {
            return 0;
        }
    }

    return 1;
}

/**
 * Creates the Sylvester matrix of two polynomials p and q.
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @return Sylvester matrix of p and q
 */
matrix p_sylvester(const polynomial p, degree dp, const polynomial q, degree dq)
{
    int i, j;

    /* Create matrix */
    dim d = dp + dq;
    matrix s = mat_zeros(d, d);

    /* First polynomial */
    for (i = 0; i < d - dp; i++)
    {
        for (j = 0; j <= dp; j++)
        {
            s[i][i + j] = p[dp - j];
        }
    }

    /* Second polynomial */
    for (i = d - dp; i < d; i++)
    {
        for (j = 0; j <= dq; j++)
        {
            s[i][i - (d - dp) + j] = q[dq - j];
        }
    }

    return s;
}
