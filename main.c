#include <stdio.h>
#include "src/io/file_reader.h"
#include "src/core/loadflow.h"

int main() {
    Bus buses[MAX_BUSES];
    Line lines[MAX_LINES];
    int bus_count = 0, line_count = 0;

    if (read_buses("examples/buses.csv", buses, &bus_count) != 0 ||
        read_lines("examples/lines.csv", lines, &line_count) != 0) {
        printf("Failed to read input files.\n");
        return 1;
    }

    run_loadflow(buses, bus_count, lines, line_count);

    return 0;
}
