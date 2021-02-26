/**
 * @file extendedGcdPoly.c
 * @brief Extended Euclidean algorithm for polynomials in Fm[x]
 */
#include <stdio.h>
#include "extendedGcdPoly.h"

/**
 * Extended Euclidean algorithm for polynomials in Fm[x].
 * 
 * @param a first polynomial
 * @param da degree of a
 * @param b second polynomial
 * @param db degree of b
 * @param r gcd(a, b) = a * u + b * v
 * @param dr degree of r
 * @param u bezout coefficient of a
 * @param du degree of u
 * @param v bezout coefficient of b
 * @param dv degree of v
 * @param m modulus
 */
void mp_extended_gcd(const polynomial a, int da, const polynomial b, int db, polynomial r, int* dr, polynomial u, int* du, polynomial v, int* dv, int m)
{
    polynomial rp, up, vp, rs, us, vs, q, q_rp, q_up, q_vp;
    int drp, dup, dvp, drs, dus, dvs, dq, dq_rp, dq_up, dq_vp;

    *dr = p_copy(a, da, r);
    *du = 0; u[0] = 1;
    *dv = 0; v[0] = 0;
    drp = p_copy(b, db, rp);
    dup = 0; up[0] = 0;
    dvp = 0; vp[0] = 1;

    while (!(drp == 0 && rp[0] == 0))
    {
        dq = mp_div(r, *dr, rp, drp, q, m);

        dq_rp = mp_mul(q, dq, rp, drp, q_rp, m);
        drs = mp_sub(r, *dr, q_rp, dq_rp, rs, m);
        *dr = p_copy(rp, drp, r);
        drp = p_copy(rs, drs, rp);

        dq_up = mp_mul(q, dq, up, dup, q_up, m);
        dus = mp_sub(u, *du, q_up, dq_up, us, m);
        *du = p_copy(up, dup, u);
        dup = p_copy(us, dus, up);

        dq_vp = mp_mul(q, dq, vp, dvp, q_vp, m);
        dvs = mp_sub(v, *dv, q_vp, dq_vp, vs, m);
        *dv = p_copy(vp, dvp, v);
        dvp = p_copy(vs, dvs, vp);
    }
}

/**
 * Print steps of Extended Euclidean algorithm for polynomials in Fm[x].
 * 
 * @param a first polynomial
 * @param da degree of a
 * @param b second polynomial
 * @param db degree of b
 * @param r gcd(a, b) = a * u + b * v
 * @param dr degree of r
 * @param u bezout coefficient of a
 * @param du degree of u
 * @param v bezout coefficient of b
 * @param dv degree of v
 * @param m modulus
 */
void mp_print_extended_gcd(const polynomial a, int da, const polynomial b, int db, polynomial r, int* dr, polynomial u, int* du, polynomial v, int* dv, int m)
{
    polynomial rp, up, vp, rs, us, vs, q, q_rp, q_up, q_vp;
    int drp, dup, dvp, drs, dus, dvs, dq, dq_rp, dq_up, dq_vp;
    int i = 0;

    *dr = p_copy(a, da, r);
    *du = 0; u[0] = 1;
    *dv = 0; v[0] = 0;
    drp = p_copy(b, db, rp);
    dup = 0; up[0] = 0;
    dvp = 0; vp[0] = 1;

    while (!(drp == 0 && rp[0] == 0))
    {
        printf("== Iteration %d ==\n", i++);
        p_print(r, *dr, "R");
        p_print(u, *du, "U");
        p_print(v, *dv, "V");

        dq = mp_div(r, *dr, rp, drp, q, m);

        dq_rp = mp_mul(q, dq, rp, drp, q_rp, m);
        drs = mp_sub(r, *dr, q_rp, dq_rp, rs, m);
        *dr = p_copy(rp, drp, r);
        drp = p_copy(rs, drs, rp);

        dq_up = mp_mul(q, dq, up, dup, q_up, m);
        dus = mp_sub(u, *du, q_up, dq_up, us, m);
        *du = p_copy(up, dup, u);
        dup = p_copy(us, dus, up);

        dq_vp = mp_mul(q, dq, vp, dvp, q_vp, m);
        dvs = mp_sub(v, *dv, q_vp, dq_vp, vs, m);
        *dv = p_copy(vp, dvp, v);
        dvp = p_copy(vs, dvs, vp);
    }
    printf("== Result ==\n");
    p_print(r, *dr, "R");
    p_print(u, *du, "U");
    p_print(v, *dv, "V");
}
