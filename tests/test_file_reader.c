#include <stdio.h>
#include <string.h>
#include "../include/powersimkit/types.h"
#include "../src/io/file_reader.h"

#define MAX_BUSES 10
#define MAX_LINES 10

int test_read_bus_data() {
    Bus buses[MAX_BUSES];
    int count = read_bus_data("examples/bus.csv", buses, MAX_BUSES);
    if (count != 3) {
        printf("FAIL: Expected 3 buses, got %d\n", count);
        return 0;
    }
    if (buses[0].id != 1 || buses[0].type != SLACK) {
        printf("FAIL: Bus 1 data mismatch\n");
        return 0;
    }
    if (buses[1].type != PV) {
        printf("FAIL: Bus 2 type mismatch\n");
        return 0;
    }
    if (buses[2].voltage < 0.99 || buses[2].voltage > 1.01) {
        printf("FAIL: Bus 3 voltage out of range\n");
        return 0;
    }
    printf("PASS: read_bus_data\n");
    return 1;
}

int test_read_line_data() {
    Line lines[MAX_LINES];
    int count = read_line_data("examples/line.csv", lines, MAX_LINES);
    if (count != 3) {
        printf("FAIL: Expected 3 lines, got %d\n", count);
        return 0;
    }
    if (lines[0].from_bus != 1 || lines[0].to_bus != 2) {
        printf("FAIL: Line 1 bus mismatch\n");
        return 0;
    }
    if (lines[1].r <= 0 || lines[1].x <= 0) {
        printf("FAIL: Line 2 R or X nonpositive\n");
        return 0;
    }
    printf("PASS: read_line_data\n");
    return 1;
}

int main() {
    int passed = 0;
    printf("Running test_read_bus_data...\n");
    passed += test_read_bus_data();

    printf("Running test_read_line_data...\n");
    passed += test_read_line_data();

    printf("\n%d/2 tests passed.\n", passed);
    return (passed == 2) ? 0 : 1;
}
