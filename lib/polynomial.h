/**
 * @file polynomial.h
 * @brief Polynomials definition
 */
#pragma once

/**
 * Maximum degree for polynomials
 */
#define MAX_DEGREE 100

/**
 * Represents a polynomial
 */
typedef int polynomial[MAX_DEGREE + 1];

int p_scan(polynomial p, char *name);
void p_print(const polynomial p, int dp, char *name);
int p_copy(const polynomial p, int dp, polynomial r);
int p_lead(const polynomial p, int dp);
int p_const(const polynomial p);

/* Evaluate */

int p_eval(const polynomial p, int dp, int x);
int p_horner(const polynomial p, int dp, int x);
