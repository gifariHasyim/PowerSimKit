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
#include "../include/powersimkit/types.h"
#include "io/file_reader.h"

#define MAX_BUSES 100
#define MAX_LINES 100

int main() {
    char bus_file[256], line_file[256];
    Bus buses[MAX_BUSES];
    Line lines[MAX_LINES];

    printf("Enter bus CSV file path: ");
    scanf("%255s", bus_file);
    printf("Enter line CSV file path: ");
    scanf("%255s", line_file);

    int bus_count = read_bus_data(bus_file, buses, MAX_BUSES);
    int line_count = read_line_data(line_file, lines, MAX_LINES);

    printf("\nLoaded %d buses and %d lines.\n", bus_count, line_count);
    for (int i = 0; i < bus_count; i++) {
        printf("Bus %d: Type=%d, V=%.3f, Angle=%.2f, Pin=%.2f, Qin=%.2f\n",
               buses[i].id, buses[i].type, buses[i].voltage,
               buses[i].angle, buses[i].p_in, buses[i].q_in);
    }

    for (int i = 0; i < line_count; i++) {
        printf("Line from %d to %d: R=%.4f, X=%.4f, B=%.4f\n",
               lines[i].from_bus, lines[i].to_bus,
               lines[i].r, lines[i].x, lines[i].b);
    }

    return 0;
}
