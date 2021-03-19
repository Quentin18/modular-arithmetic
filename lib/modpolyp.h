/**
 * @file modpolyp.h
 * @brief Header file for polynomial arithmetic in Fm[x]/(P)
 */
#pragma once

#include "polynomial.h"
#include "modint.h"

degree mpp_add(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP);
degree mpp_sub(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP);
degree mpp_mul(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m, const polynomial P, degree dP);
degree mpp_inv(const polynomial p, degree dp, polynomial r, modulus m, const polynomial P, degree dP);
degree mpp_div(const polynomial p, degree dp, const polynomial d, degree dd, polynomial q, modulus m, const polynomial P, degree dP);
