/**
 * @file modpoly.h
 * @brief Header file for polynomial arithmetic in Fm[x]
 */
#pragma once

#include "polynomial.h"
#include "modint.h"
#include "polytree.h"

degree mp_add(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m);
degree mp_sub(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m);
degree mp_mul(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m);
degree mp_div(const polynomial p, degree dp, const polynomial d, degree dd, polynomial q, modulus m);
degree mp_mod(const polynomial p, degree dp, const polynomial d, degree dd, polynomial r, modulus m);

/* Evaluation */

integer mp_eval(const polynomial p, degree dp, integer x, modulus m);
integer mp_horner(const polynomial p, degree dp, integer x, modulus m);
void mp_horner_multipoint(const polynomial p, degree dp, const integer *x, integer *y, unsigned int n, modulus m);

/* Derivation */

degree mp_derivate(const polynomial p, degree dp, polynomial r, modulus m);

/* Interpolation */

degree mp_lagrange_basis(const integer* x, unsigned int n, unsigned int i, polynomial L, modulus m);
degree mp_lagrange_polynomial(const integer* x, const integer* y, unsigned int n, polynomial L, modulus m);

/* Trees */

polynode* mp_subproduct_node(const integer* x, unsigned int n1, unsigned int n2, modulus m);
polytree* mp_subproduct_tree(const integer* x, unsigned int n, modulus m);

/* Fast algorithms */

void mp_fast_multipoint_eval(const polynomial p, degree dp, const integer *x, integer *y, unsigned int n, modulus m);
