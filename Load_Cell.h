#ifndef LOAD_CELL_H
#define LOAD_CELL_H

#include <stdint.h>
#include <stdbool.h>

#define COMMON_MODE 2.5
#define DEVIATION_VOLTAGE_BREAKPOINT 0.1

typedef struct {
    // General
    uint8_t pin_number;
    float voltage;
    int8_t strain;

    float deviation_voltage_breakpoint;
    float max_voltage;
    float strain_range;
} Load_Cell_t;

bool poll_sensor(Load_Cell_t* load_cell);

#endif // LOAD_CELL_H