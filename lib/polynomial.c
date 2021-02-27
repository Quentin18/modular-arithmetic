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
int p_scan(polynomial p, char *name)
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
void p_print(const polynomial p, int dp, char *name)
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
int p_copy(const polynomial p, int dp, polynomial r)
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
int p_lead(const polynomial p, int dp)
{
    return p[dp];
}

/**
 * Return the constant term of a polynomial.
 * 
 * @param p polynomial
 * @return constant term of p
 */
int p_const(const polynomial p)
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
int p_eval(const polynomial p, int dp, int x)
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
int p_horner(const polynomial p, int dp, int x)
{
    int i;
    int y = 0;
    for (i = dp; i >= 0; i--)
    {
        y = x * y + p[i];
    }
    return y;
}
