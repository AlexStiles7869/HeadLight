/**
 * @file LED_Group.c
 * @author Alex Stiles
 * @brief Contains the source code for a LED group.
 * @version 0.1
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 * This source file provides the functionality to get and set the group's brightness (from 0 to 255) as required by the Arduino's PWM output.
 * It also provides getters for the group pin number and direction.
 * 
 */

#include <stdint.h>

#include "LED_Group.h"

/**
 * @brief Get the group brightness
 * 
 * @param led_group 
 * @return int8_t 
 */
uint8_t get_group_brightness(const LED_Group_t* const led_group) {
    return led_group->group_brightness;
}

/**
 * @brief Set the group brightness
 * 
 * @param led_group 
 * @param group_brightness 
 */
void set_group_brightness(LED_Group_t* const led_group, uint8_t group_brightness) {
    led_group->group_brightness = group_brightness;
}

/**
 * @brief Get the group pin number
 * 
 * @param led_group 
 * @return int8_t 
 */
uint8_t get_group_pin_number(const LED_Group_t* const led_group) {
    return led_group->group_pin_number;
}

/**
 * @brief Get the group direction
 * 
 * @param led_group 
 * @return Direction_t 
 */
Direction_t get_group_direction(const LED_Group_t* const led_group) {
    return led_group->direction;
}