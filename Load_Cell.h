#ifndef LOAD_CELL_H
#define LOAD_CELL_H

#include <stdint.h>
#include <stdbool.h>

#define DEVIATION_VOLTAGE_BREAKPOINT 0.1

typedef struct {
    // General
    uint8_t pin_number;
    float voltage;

    float deviation_voltage_breakpoint;
} Load_Cell_t;

bool poll_sensor(Load_Cell_t* load_cell);

float get_voltage(Load_Cell_t* load_cell);
void set_voltage(Load_Cell_t* load_cell, float voltage);

#endif // LOAD_CELL_H