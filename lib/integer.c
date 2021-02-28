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
void i_scan(int *a, char *name)
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
void i_print(int a, char *name)
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
int i_add(int a, int b)
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
int i_sub(int a, int b)
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
int i_mul(int a, int b)
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
int i_div(int a, int b)
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
int i_mod(int a, int b)
{
    return a % b;
}
