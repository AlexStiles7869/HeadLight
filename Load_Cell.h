#ifndef LOAD_CELL_H
#define LOAD_CELL_H

#include <stdint.h>
#include <stdbool.h>

#define COMMON_MODE 2.5
#define DEVIATION_VOLTAGE_BREAKPOINT 0.1

typedef struct {
    // State of load cell at given time
    float voltage;
    int8_t strain;
    int8_t angle;

    // Specific details of load cell
    uint8_t pin_number;
    float deviation_voltage_breakpoint;
    float max_voltage;
    uint8_t strain_range;
    uint8_t angle_range;
} Load_Cell_t;

bool poll_sensor(Load_Cell_t* load_cell);

#endif // LOAD_CELL_H