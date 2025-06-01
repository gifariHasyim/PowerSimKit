#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_reader.h"

#define LINE_LEN 256

BusType parse_bus_type(const char *type_str) {
    if (strcmp(type_str, "Slack") == 0) return SLACK;
    if (strcmp(type_str, "PV") == 0) return PV;
    if (strcmp(type_str, "PQ") == 0) return PQ;
    return UNKNOWN;
}

int read_bus_data(const char *filename, Bus *buses, int max_buses) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening bus file");
        return -1;
    }

    char line[LINE_LEN];
    int count = 0;

    fgets(line, LINE_LEN, file); // Skip header
    while (fgets(line, LINE_LEN, file) && count < max_buses) {
        int id;
        char type_str[16];
        double v, angle, p_in, q_in, p_out, q_out;

        sscanf(line, "%d,%15[^,],%lf,%lf,%lf,%lf,%lf,%lf",
               &id, type_str, &v, &angle, &p_in, &q_in, &p_out, &q_out);

        buses[count].id = id;
        buses[count].type = parse_bus_type(type_str);
        buses[count].voltage = v;
        buses[count].angle = angle;
        buses[count].p_in = p_in;
        buses[count].q_in = q_in;
        buses[count].p_out = p_out;
        buses[count].q_out = q_out;
        count++;
    }

    fclose(file);
    return count;
}

int read_line_data(const char *filename, Line *lines, int max_lines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening line file");
        return -1;
    }

    char line[LINE_LEN];
    int count = 0;

    fgets(line, LINE_LEN, file); // Skip header
    while (fgets(line, LINE_LEN, file) && count < max_lines) {
        int from, to;
        double r, x, b;
        sscanf(line, "%d,%d,%lf,%lf,%lf", &from, &to, &r, &x, &b);

        lines[count].from_bus = from;
        lines[count].to_bus = to;
        lines[count].r = r;
        lines[count].x = x;
        lines[count].b = b;
        count++;
    }

    fclose(file);
    return count;
}
