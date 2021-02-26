/**
 * @file modpolyp.c
 * @brief Polynomial arithmetic implementation in Fm[x]/P
 */
#include <stdio.h>
#include <stdlib.h>
#include "modpolyp.h"
#include "modpoly.h"
#include "modint.h"

/**
 * Init a polynomial with scanf.
 * 
 * @param p polynomial
 * @param name name of p
 * @return degree of p
 */
int mpp_init(polynomial p, char *name)
{
    return p_init(p, name);
}

/**
 * Print a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param name name of p
 */
void mpp_print(const polynomial p, int dp, char *name)
{
    p_print(p, dp, name);
}

/**
 * Copy a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param r copy of p
 * @return degree of r
 */
int mpp_copy(const polynomial p, int dp, polynomial r)
{
    return p_copy(p, dp, r);
}

/**
 * Return the leading term of a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @return leading term of p
 */
int mpp_lead(const polynomial p, int dp)
{
    return p_lead(p, dp);
}

/**
 * Return the constant term of a polynomial.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @return constant term of p
 */
int mpp_const(const polynomial p)
{
    return p_const(p);
}

/**
 * Computes r = (p + q) in Fm[x]/P.
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p + q) in Fm[x]/P
 * @param m modulus for coefficients
 * @param P modulus polynomial
 * @param dP degree of P
 * @return degree of r
 */
int mpp_add(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP)
{
    int dr, ds;
    polynomial s;
    ds = mp_add(p, dp, q, dq, s, m);
    dr = mp_mod(s, ds, P, dP, r, m);
    return dr;
}

/**
 * Computes r = (p - q) in Fm[x]/P.
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p - q) in Fm[x]/P
 * @param m modulus for coefficients
 * @param P modulus polynomial
 * @param dP degree of P
 * @return degree of r
 */
int mpp_sub(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP)
{
    int dr, ds;
    polynomial s;
    ds = mp_sub(p, dp, q, dq, s, m);
    dr = mp_mod(s, ds, P, dP, r, m);
    return dr;
}

/**
 * Computes r = (p * q) in Fm[x]/P.
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p * q) in Fm[x]/P
 * @param m modulus for coefficients
 * @param P modulus polynomial
 * @param dP degree of P
 * @return degree of r
 */
int mpp_mul(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP)
{
    int dr, ds;
    polynomial s;
    ds = mp_mul(p, dp, q, dq, s, m);
    dr = mp_mod(s, ds, P, dP, r, m);
    return dr;
}

/**
 * Computes r = p^-1 in Fm[x]/P.
 *
 * @param p polynomial
 * @param dp degree of p
 * @param r polynomial p^-1 in Fm[x]/P
 * @param m modulus
 * @param P modulus polynomial
 * @param dP degree of P
 * @return degree of r
 */
int mpp_inv(const polynomial p, int dp, polynomial r, int m, const polynomial P, int dP)
{
    polynomial gcd, u;
    int dgcd, du, dr, gcd_inv, i;
    mp_extended_gcd(P, dP, p, dp, gcd, &dgcd, u, &du, r, &dr, m);

    /* Case deg(gcd(P, p)) != 0 */
    if (dgcd != 0)
    {
        fprintf(stderr,
                "Mod Error: p has no inverse modulo P. Exit.\n");
        exit(EXIT_FAILURE);
    }

    /* Case gcd(P, p) != 1 */
    if (mp_const(gcd) != 1)
    {
        gcd_inv = mi_inv(mp_const(gcd), m);
        for (i = 0; i <= dr; i++)
        {
            r[i] = mi_mul(r[i], gcd_inv, m);
        }
    }

    return dr;
}

/**
 * Computes r = (p / q) in Fm[x]/P.
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p / q) in Fm[x]/P
 * @param m modulus for coefficients
 * @param P modulus polynomial
 * @param dP degree of P
 * @return degree of r
 */
int mpp_div(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP)
{
    int dr, dq_inv;
    polynomial q_inv;
    dq_inv = mpp_inv(q, dq, q_inv, m, P, dP);
    dr = mpp_mul(p, dp, q_inv, dq_inv, r, m, P, dP);
    return dr;
}
