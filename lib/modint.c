/**
 * @file modint.c
 * @brief Modular arithmetic implementation for integers
 */
#include "modint.h"
#include "extendedGcdInt.h"

/**
 * Computes a mod m. It works with negative numbers.
 * 
 * @param a integer
 * @param m modulus
 * @return a mod m
 */
int mod(int a, int m)
{
    int r = a % m;
    return r < 0 ? r + m : r;
}

/**
 * Computes (a + b) mod m.
 * 
 * @param a first integer
 * @param b second integer
 * @param m modulus
 * @return (a + b) mod m
 */
int mi_add(int a, int b, int m)
{
    return mod(a + b, m);
}

/**
 * Computes (a - b) mod m.
 * 
 * @param a first integer
 * @param b second integer
 * @param m modulus
 * @return (a - b) mod m
 */
int mi_sub(int a, int b, int m)
{
    return mod(a - b, m);
}

/**
 * Computes (a * b) mod m.
 * 
 * @param a first integer
 * @param b second integer
 * @param m modulus
 * @return (a * b) mod m
 */
int mi_mul(int a, int b, int m)
{
    return mod(a * b, m);
}

/**
 * Computes a^-1 mod m.
 * 
 * @param a integer
 * @param m modulus
 * @return a^-1 mod m
 */
int mi_inv(int a, int m)
{
    int u, v;
    extended_gcd_int(m, a, &u, &v);
    return mod(v, m);
}

/**
 * Computes (a / b) mod m.
 * 
 * @param a first integer
 * @param b second integer
 * @param m modulus
 * @return (a / b) mod m
 */
int mi_div(int a, int b, int m)
{
    return mi_mul(a, mi_inv(b, m), m);
}
