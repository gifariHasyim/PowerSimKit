/*
 * PowerSimKit - Power System Simulation Toolkit
 * Copyright (C) 2025 gifariHasyim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY. See the LICENSE file for more details.
 */

#include "complex.h"
#include <math.h>

Complex complex_new(double real, double imag) {
    Complex z = {real, imag};
    return z;
}

Complex complex_add(Complex a, Complex b) {
    return complex_new(a.real + b.real, a.imag + b.imag);
}

Complex complex_sub(Complex a, Complex b) {
    return complex_new(a.real - b.real, a.imag - b.imag);
}

Complex complex_mul(Complex a, Complex b) {
    return complex_new(
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    );
}

Complex complex_div(Complex a, Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    return complex_new(
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    );
}

Complex complex_inv(double r, double x) {
    double denom = r * r + x * x;
    return complex_new(r / denom, -x / denom);
}
