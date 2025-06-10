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

#include <stdio.h>
#include <stdlib.h>

#include "../../include/powersimkit/config.h"
#include "../../include/powersimkit/types.h"
#include "complex.h"

void build_ybus(Line *lines, int num_lines, Complex Y[MAX_BUS][MAX_BUS]) {
    // Inisialisasi nol
    for (int i = 0; i < MAX_BUS; ++i) {
        for (int j = 0; j < MAX_BUS; ++j) {
            Y[i][j] = complex_new(0.0, 0.0);
        }
    }

    // Iterasi setiap line
    for (int idx = 0; idx < num_lines; ++idx) {
        int from = lines[idx].from_bus;
        int to = lines[idx].to_bus;

        double R = lines[idx].r;
        double X = lines[idx].x;
        double B = lines[idx].b;

        // Hitung impedansi dan admitansi
        Complex Z = complex_new(R, X);
        Complex Y_series = complex_div(complex_new(1.0, 0.0), Z);  // Y = 1 / Z
        Complex Y_shunt = complex_new(0.0, B / 2.0);  // Line charging dibagi dua



        // Elemen diagonal
        Y[from][from] = complex_add(Y[from][from], complex_add(Y_series, Y_shunt));
        Y[to][to]     = complex_add(Y[to][to],     complex_add(Y_series, Y_shunt));

        // Elemen off-diagonal
        Y[from][to] = complex_sub(Y[from][to], Y_series);
        Y[to][from] = complex_sub(Y[to][from], Y_series);
    }
}

void print_ybus(Complex Y[MAX_BUS][MAX_BUS], int num_bus, Bus *buses) {
//edit the loop so only cell with valid value printed
    printf("Y-bus matrix (real + j imag):\n");
    for (int i = 0; i < num_bus; ++i) {
        for (int j = 0; j < num_bus; ++j) {
            printf("(%8.4f%+8.4fj) ", Y[buses[i].id][buses[j].id].real, Y[buses[i].id][buses[j].id].imag);
        }
        printf("\n");
    }
}
