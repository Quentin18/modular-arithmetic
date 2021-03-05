/**
 * @file extendedGcdPoly.h
 * @brief Header file for Extended Euclidean algorithm for polynomials in Fm[x]
 */
#pragma once

#include "modpoly.h"

void mp_extended_gcd(const polynomial a, degree da, const polynomial b, degree db, polynomial r, degree* dr, polynomial u, degree* du, polynomial v, degree* dv, modulus m);
void mp_print_extended_gcd(const polynomial a, degree da, const polynomial b, degree db, polynomial r, degree* dr, polynomial u, degree* du, polynomial v, degree* dv, modulus m);
