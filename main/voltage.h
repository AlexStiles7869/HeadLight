/**
 * @file voltage.h
 * @author Alex Stiles
 * @brief  Contains definations regarding the max voltage provided by the arduino and the common mode.
 * @version 1
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef VOLTAGE_H
#define VOLTAGE_H

#define ARDUINO_MAX_VOLTAGE 5
#define ARDUINO_PWM_READ_RANGE 1023
#define ARDUINO_PWM_WRITE_RANGE 255
#define COMMON_MODE_VOLTAGE 2.5

float map_voltage_to_range(float voltage, float max_voltage, float range);

#endif // VOLTAGE_H