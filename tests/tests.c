/**
 * @file tests.c
 * @brief Unit tests using MinUnit
 * 
 * Source: https://github.com/siu/minunit
 */
#include "minunit.h"
#include "extendedGcdInt.h"
#include "extendedGcdPoly.h"
#include "modint.h"
#include "modpoly.h"
#include "matrix.h"

/* Extended Euclidean algorithm */
MU_TEST(test_extended_gcd_int)
{
    integer a, b, r, u, v;

    a = 240; b = 46;
    r = extended_gcd_int(a, b, &u, &v);
	mu_check(r == 2);
	mu_check(u == -9);
	mu_check(v = 47);

	a = 251; b = 207;
    r = extended_gcd_int(a, b, &u, &v);
	mu_check(r == 1);
	mu_check(u == 80);
	mu_check(v = -97);
}

/* Modular arithmetic for integers */
MU_TEST(test_modint)
{
    integer a = 3, b = 4;
	modulus m = 5;
	mu_check(mi_add(a, b, m) == 2);
	mu_check(mi_sub(a, b, m) == 4);
	mu_check(mi_mul(a, b, m) == 2);
	mu_check(mi_inv(a, m) == 2);
	mu_check(mi_inv(b, m) == 4);
	mu_check(mi_div(a, b, m) == 2);
}

/* Polynomial arithmetic in Fm[x] */
MU_TEST(test_modpoly)
{
    polynomial r, s, t;
    degree dr, ds, dt;

    modulus m = 4;

    polynomial p = {7, 4, -3, 1};
	degree dp = 3;
    polynomial q = {3, 0, 1};
	degree dq = 2;

	/* Expected polynomials */
	polynomial a = {2, 0, 2, 1};
	degree da = 3;
	polynomial b = {0, 0, 0, 1};
	degree db = 3;
	polynomial c = {1, 0, 2, 3, 1, 1};
	degree dc = 5;

	/* Tests */
    dr = mp_add(p, dp, q, dq, r, m);
	mu_check(p_are_equal(r, dr, a, da));

    ds = mp_sub(p, dp, q, dq, s, m);
	mu_check(p_are_equal(s, ds, b, db));

    dt = mp_mul(p, dp, q, dq, t, m);
	mu_check(p_are_equal(t, dt, c, dc));
}

/* Euclidean division with polynomial arithmetic in Fm[x] */
MU_TEST(test_modpoly_div)
{
    polynomial q, r;
    degree dq, dr;

    modulus m = 7;

    polynomial p = {2, 0, 0, 1};
	degree dp = 3;
    polynomial d = {2, 3, 3};
	degree dd = 2;

	/* Expected polynomials */
	polynomial a = {2, 5};
	degree da = 1;
	polynomial b = {5, 5};
	degree db = 1;

    /* Quotient */
    dq = mp_div(p, dp, d, dd, q, m);
	mu_check(p_are_equal(q, dq, a, da));

    /* Remainder */
    dr = mp_mod(p, dp, d, dd, r, m);
	mu_check(p_are_equal(r, dr, b, db));
}

/* Extended Euclidean algorithm for polynomials in Fm[x] */
MU_TEST(test_extended_gcd_poly)
{
    polynomial r, u, v;
    degree dr, du, dv;

    modulus m = 2;

    polynomial a = {1, 1, 0, 1, 1, 0, 0, 0, 1};
	degree da = 8;
    polynomial b = {1, 1, 0, 0, 1, 0, 1};
	degree db = 6;

	/* Expected polynomials */
	polynomial c = {1};
	degree dc = 0;
	polynomial d = {1, 0, 1, 1, 1, 1};
	degree dd = 5;
	polynomial e = {0, 1, 0, 1, 0, 0, 1, 1};
	degree de = 7;

    mp_extended_gcd(a, da, b, db, r, &dr, u, &du, v, &dv, m);

	mu_check(p_are_equal(r, dr, c, dc));
	mu_check(p_are_equal(u, du, d, dd));
	mu_check(p_are_equal(v, dv, e, de));
}

/* Matrix */
MU_TEST(test_matrix)
{
	dim d = 3;
    matrix m = mat_create(d, d);
    m[0][0] = -2; m[0][1] = 2; m[0][2] = -3;
    m[1][0] = -1; m[1][1] = 1; m[1][2] = 3;
    m[2][0] = 2; m[2][1] = 0; m[2][2] = -1;

	/* Determinant */
    mu_check(mat_det(m, d) == 18);
    mat_delete(m, d);
}

/* Test suite */
MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_extended_gcd_int);
	MU_RUN_TEST(test_modint);
	MU_RUN_TEST(test_modpoly);
	MU_RUN_TEST(test_modpoly_div);
	MU_RUN_TEST(test_extended_gcd_poly);
	MU_RUN_TEST(test_matrix);
}

/**
 * Main for unit tests.
 */
int main()
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
