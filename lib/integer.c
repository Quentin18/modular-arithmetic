/**
 * @file integer.c
 * @brief Integer arithmetic
 */
#include <stdio.h>
#include "integer.h"

/**
 * Init an integer with scanf.
 * 
 * @param a integer
 * @param name name of a
 */
void i_scan(integer *a, char *name)
{
    printf("%s = ", name);
    scanf("%d", a);
}

/**
 * Print an integer.
 * 
 * @param a integer
 * @param name name of a
 */
void i_print(integer a, char *name)
{
    printf("%s = %d\n", name, a);
}


/**
 * Computes a + b.
 * 
 * @param a first integer
 * @param b second integer
 * @return a + b
 */
integer i_add(integer a, integer b)
{
    return a + b;
}

/**
 * Computes a - b.
 * 
 * @param a first integer
 * @param b second integer
 * @return a - b
 */
integer i_sub(integer a, integer b)
{
    return a - b;
}

/**
 * Computes a * b.
 * 
 * @param a first integer
 * @param b second integer
 * @return a * b
 */
integer i_mul(integer a, integer b)
{
    return a * b;
}

/**
 * Computes a / b.
 * 
 * @param a first integer
 * @param b second integer
 * @return a / b
 */
integer i_div(integer a, integer b)
{
    return a / b;
}

/**
 * Computes a % b.
 * 
 * @param a first integer
 * @param b second integer
 * @return a % b
 */
integer i_mod(integer a, integer b)
{
    return a % b;
}
