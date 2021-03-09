/**
 * @file example9.c
 * @brief Example 9: Subproduct tree in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Subproduct tree in Fm[x].
 */
int main()
{
    polynomial r;
    degree dr;
    modulus m;

    integer x[] = {1, 2, 4, 8};
    unsigned int n = 4;
    m = 11;

    dr = mp_subproduct_tree(x, 0, n, r, m);

    p_print(r, dr, "P");

    return 0;
}
