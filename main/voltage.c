/**
 * @file voltage.c
 * @author Alex Stiles
 * @brief Provides helper functions when dealing with Arduino voltage
 * @version 0.1
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "math.h"

#include "voltage.h"

float map_voltage_to_range(float voltage, float max_voltage, float range) {
    return ((voltage - 2.5) / max_voltage) * range;
}
