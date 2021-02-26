/**
 * @file modpolyp.h
 * @brief Header file for polynomial arithmetic in Fm[x]/P
 */
#pragma once

#include "polynomial.h"

/* Definition */

int mpp_init(polynomial p, char *name);
void mpp_print(const polynomial p, int dp, char *name);
int mpp_copy(const polynomial p, int dp, polynomial r);

/* Operators */

int mpp_add(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, polynomial P);
int mpp_sub(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, polynomial P);
int mpp_mul(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, polynomial P);
int mpp_inv(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, polynomial P);
int mpp_div(const polynomial p, int dp, const polynomial d, int dd, polynomial q, int m, polynomial P);
