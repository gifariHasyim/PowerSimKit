/* SPDX-License-Identifier: GPL-3.0-or-later */

#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    double real;
    double imag;
} Complex;

Complex complex_new(double real, double imag);
Complex complex_add(Complex a, Complex b);
Complex complex_sub(Complex a, Complex b);
Complex complex_mul(Complex a, Complex b);
Complex complex_div(Complex a, Complex b);
Complex complex_inv(double r, double x);

#endif
