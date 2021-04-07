/**
 * @file example14.c
 * @brief Example 14: Resultant
 */
#include <stdio.h>
#include "polynomial.h"

/**
 * Resultant.
 */
int main()
{
    polynomial p = {3, 2, -7, -1, 1};
    degree dp = 4;
    polynomial q = {3, 2, -4, 1};
    degree dq = 3;

    /* Sylvester matrix */
    matrix syl = p_sylvester(p, dp, q, dq);
    dim d = dp + dq;

    /* Resultant */
    integer res = p_resultant(p, dp, q, dq);

    p_print(p, dp, "P");
    p_print(q, dq, "Q");
    mat_print(syl, d, d, "Sylv(P, Q)");
    i_print(res, "Res(P, Q)");

    mat_delete(syl, d);

    return 0;
}
