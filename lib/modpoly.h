/**
 * @file modpoly.h
 * @brief Header file for modular arithmetic with polynomials
 */
#pragma once

/* Maximum degree for polynomials */
#define MAX_DEGREE 100

/* Represents a polynomial */
typedef int polynomial[MAX_DEGREE + 1];

int mp_init(polynomial p, char *name);
void mp_print(const polynomial p, int dp, char *name);
int mp_copy(const polynomial p, int dp, polynomial r);
int mp_add(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m);
int mp_sub(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m);
int mp_mul(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m);
int mp_inv(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m);
int mp_div(const polynomial p, int dp, const polynomial d, int dd, polynomial q, int m);
int mp_lead(const polynomial p, int dp);
int mp_const(const polynomial p);
int mp_eval(const polynomial p, int dp, int x, int m);
int mp_horner(const polynomial p, int dp, int x, int m);
void mp_horner_multipoint(const polynomial p, int dp, int *x, int *y, int n, int m);
