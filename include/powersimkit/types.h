#ifndef TYPES_H
#define TYPES_H

typedef enum {
    SLACK,
    PV,
    PQ,
    UNKNOWN
} BusType;

typedef struct {
    int id;
    BusType type;
    double voltage;
    double angle;
    double p_in, q_in;
    double p_out, q_out;
} Bus;

typedef struct {
    int from_bus;
    int to_bus;
    double r;  // resistance
    double x;  // reactance
    double b;  // total line charging
} Line;

#endif
