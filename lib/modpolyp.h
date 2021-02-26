/**
 * @file modpolyp.h
 * @brief Header file for polynomial arithmetic in Fm[x]/P
 */
#pragma once

#include "polynomial.h"

int mpp_add(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP);
int mpp_sub(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP);
int mpp_mul(const polynomial p, int dp, const polynomial q, int dq, polynomial r, int m, const polynomial P, int dP);
int mpp_inv(const polynomial p, int dp, polynomial r, int m, const polynomial P, int dP);
int mpp_div(const polynomial p, int dp, const polynomial d, int dd, polynomial q, int m, const polynomial P, int dP);
