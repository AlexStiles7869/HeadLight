/**
 * @file Load_Cell.h
 * @author Alex Stiles
 * @brief Provides the types and function prototypes required for the TAL221 load cell.
 * @version 0.1 alpha
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LOAD_CELL_H
#define LOAD_CELL_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "voltage.h"

#define STRAIN_RANGE 200
#define ANGLE_RANGE 180
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

Load_Cell_t init_load_cell(uint8_t load_cell_pin_number);
bool poll_sensor(Load_Cell_t* load_cell, float read_voltage);

#if defined(__cplusplus)
}
#endif

#endif // LOAD_CELL_H