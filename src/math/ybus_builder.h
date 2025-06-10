/* SPDX-License-Identifier: GPL-3.0-or-later */

#ifndef YBUS_BUILDER_H
#define YBUS_BUILDER_H

#include "complex.h"
#include "../../include/powersimkit/config.h"
#include "../../include/powersimkit/types.h"

void build_ybus(Line *lines, int num_lines, Complex Y[MAX_BUS][MAX_BUS]);
void print_ybus(Complex Y[MAX_BUS][MAX_BUS], int num_bus, Bus *buses);

#endif
