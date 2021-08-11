#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include <stdio.h>

#include "Load_Cell.h"

/**
 * @brief Poll the load cell (by reading the voltage input at the LOAD_CELL_ANALOG_PIN) and compare it to the currently recorded voltage. 
 * The methodology for detecting noise is rudimentary, lacking any requirement for the voltage to remain in a constrained range for a given time, reminiscent of button debouncing. 
 * A more straightforward method is utilised due to hardware filtering using an active low pass filter. See shield schematic for details.
 * 
 * @param load_cell pointer to Load_Cell_t struct
 * @return Whether a voltage deviation was read
 */
bool poll_sensor(Load_Cell_t* load_cell) {
    bool deviation = false;

    // Read the analog voltage of the load cell

    float read_voltage = 0;

    // Compare to the current voltage to see if deviation detected

    if (fabsf(load_cell->voltage - read_voltage) > load_cell->deviation_voltage_breakpoint) {
        // Update the recorded voltage of the load cell
        load_cell->voltage = read_voltage;
        // Update the strain
        load_cell->strain = round(((load_cell->voltage - COMMON_MODE)/(load_cell->max_voltage)) * load_cell->strain_range);
        deviation = true;
    }

    return deviation;
}