/**
 * @file polynomial.h
 * @brief Polynomials definition
 */
#pragma once

#include "integer.h"
#include "matrix.h"

/**
 * Maximum degree for polynomials
 */
#define MAX_DEGREE 100

/**
 * Represents a polynomial
 */
typedef integer polynomial[MAX_DEGREE + 1];

/**
 * Represents a degree of a polynomial
 */
typedef unsigned int degree;

degree p_scan(polynomial p, char *name);
void p_write(const polynomial p, degree dp, FILE *file);
void p_print(const polynomial p, degree dp, char *name);
degree p_copy(const polynomial p, degree dp, polynomial r);
integer p_lead(const polynomial p, degree dp);
integer p_const(const polynomial p);

/* Evaluate */

integer p_eval(const polynomial p, degree dp, integer x);
integer p_horner(const polynomial p, degree dp, integer x);

/* Derivate */

degree p_derivate(const polynomial p, degree dp, polynomial r);

/* Test */

int p_are_equal(const polynomial p, degree dp, const polynomial q, degree dq);

/* Resultant */

matrix p_sylvester(const polynomial p, degree dp, const polynomial q, degree dq);
