/**
 * @file Load_Cell.c
 * @author Alex Stiles
 * @brief Contains the source code for the TAL221 load cell.
 * @version 0.1 alpha
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 * This source file provides the functionality to poll the load cell.
 * Polling the load cell updates the voltage and dependant variables if required.
 * 
 */

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include <stdio.h>

#include "Load_Cell.h"

/**
 * @brief Create a load cell, with the pin set to LOAD_CELL_ANALOG_PIN and the deviation voltage breakpoint to DEVIATION_VOLTAGE_BREAKPOINT
 * 
 * @return Load_Cell_t 
 */
Load_Cell_t init_load_cell(uint8_t load_cell_pin_number) {
    Load_Cell_t load_cell = {
        .voltage = 0, 
        .strain = 0, 
        .angle = 0, 
        .pin_number = load_cell_pin_number, 
        .deviation_voltage_breakpoint = DEVIATION_VOLTAGE_BREAKPOINT, 
        .max_voltage = ARDUINO_MAX_VOLTAGE, 
        .strain_range = STRAIN_RANGE, 
        .angle_range = ANGLE_RANGE
    };


    return load_cell;
}

/**
 * @brief Poll the load cell (by reading the voltage input at the LOAD_CELL_ANALOG_PIN) and compare it to the currently recorded voltage. 
 * The methodology for detecting noise is rudimentary, lacking any requirement for the voltage to remain in a constrained range for a given time, reminiscent of button debouncing. 
 * A more straightforward method is utilised due to hardware filtering using an active low pass filter. See shield schematic for details.
 * 
 * @param load_cell pointer to Load_Cell_t struct
 * @return Whether a voltage deviation was read
 */
bool poll_sensor(Load_Cell_t* load_cell, float read_voltage) {
    bool deviation = false;

    // Compare to the current voltage to see if deviation detected

    if (fabsf(load_cell->voltage - read_voltage) > load_cell->deviation_voltage_breakpoint) {
        // Update the recorded voltage of the load cell
        load_cell->voltage = read_voltage;
        // Update the strain
        load_cell->strain = map_voltage_to_range(load_cell->voltage, load_cell->max_voltage, load_cell->strain_range);
        // Update the angle
        load_cell->angle = map_voltage_to_range(load_cell->voltage, load_cell->max_voltage, load_cell->angle_range);
        deviation = true;
    }

    return deviation;
}