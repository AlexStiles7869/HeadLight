#include <stdint.h>

#include "LED_Group.h"

/**
 * @brief Get the group brightness object
 * 
 * @param led_group 
 * @return int8_t 
 */
uint8_t get_group_brightness(const LED_Group_t* const led_group) {
    return led_group->group_brightness;
}

/**
 * @brief Set the group brightness object
 * 
 * @param led_group 
 * @param group_brightness 
 */
void set_group_brightness(LED_Group_t* const led_group, uint8_t group_brightness) {
    led_group->group_brightness = group_brightness;
}

/**
 * @brief Get the group pin number object
 * 
 * @param led_group 
 * @return int8_t 
 */
uint8_t get_group_pin_number(const LED_Group_t* const led_group) {
    return led_group->group_pin_number;
}

/**
 * @brief Get the group direction object
 * 
 * @param led_group 
 * @return Direction_t 
 */
Direction_t get_group_direction(const LED_Group_t* const led_group) {
    return led_group->direction;
}