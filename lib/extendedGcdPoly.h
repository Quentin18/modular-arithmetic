/**
 * @file extendedGcdPoly.h
 * @brief Header file for Extended Euclidean algorithm for polynomials in Fm[x]
 */
#pragma once

#include "modpoly.h"

void mp_extended_gcd(const polynomial a, int da, const polynomial b, int db, polynomial r, int* dr, polynomial u, int* du, polynomial v, int* dv, int m);
void mp_print_extended_gcd(const polynomial a, int da, const polynomial b, int db, polynomial r, int* dr, polynomial u, int* du, polynomial v, int* dv, int m);
