/* SPDX-License-Identifier: GPL-3.0-or-later */

#ifndef FILE_READER_H
#define FILE_READER_H

#include "../include/powersimkit/types.h"

int read_bus_data(const char *filename, Bus *buses, int max_buses);
int read_line_data(const char *filename, Line *lines, int max_lines);

BusType parse_bus_type(const char *type_str);

#endif
