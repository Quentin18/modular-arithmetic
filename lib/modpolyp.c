/**
 * @file modpolyp.c
 * @brief Polynomial arithmetic implementation in Fm[x]/P
 */
#include <stdio.h>
#include <stdlib.h>
#include "modpolyp.h"
#include "modpoly.h"
#include "extendedGcdPoly.h"

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
degree mpp_add(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP)
{
    degree dr, ds;
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
degree mpp_sub(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP)
{
    degree dr, ds;
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
degree mpp_mul(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP)
{
    degree dr, ds;
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
 * @param m modulus for coefficients
 * @param P modulus polynomial
 * @param dP degree of P
 * @return degree of r
 */
degree mpp_inv(const polynomial p, degree dp, polynomial r, modulus m, const polynomial P, degree dP)
{
    polynomial gcd, u;
    degree dgcd, du, dr;
    integer gcd_inv;
    int i;
    mp_extended_gcd(P, dP, p, dp, gcd, &dgcd, u, &du, r, &dr, m);

    /* Case deg(gcd(P, p)) != 0 */
    if (dgcd != 0)
    {
        fprintf(stderr,
                "Mod Error: p has no inverse modulo P. Exit.\n");
        exit(EXIT_FAILURE);
    }

    /* Case gcd(P, p) != 1 */
    if (p_const(gcd) != 1)
    {
        gcd_inv = mi_inv(p_const(gcd), m);
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
degree mpp_div(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP)
{
    degree dr, dq_inv;
    polynomial q_inv;
    dq_inv = mpp_inv(q, dq, q_inv, m, P, dP);
    dr = mpp_mul(p, dp, q_inv, dq_inv, r, m, P, dP);
    return dr;
}
