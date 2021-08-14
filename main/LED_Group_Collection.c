/**
 * @file LED_Group_Collection.c
 * @author Alex Stiles
 * @brief Contains the source code for manipulating all the induvidual LED groups (see LED_Group.c)
 * @version 0.1 alpha
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 * This source file provides the functionality to add and get induvidual LED groups.
 * It also provides the ability to update the required PWM output to each of the induvidual gruops, given a load voltage.
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "LED_Group_Collection.h"

/**
 * @brief Create a LED group collection, and add an LED group to each direction (LEFT and RIGHT) with the pins set to left_pin_number and right_pin_number respectively.
 * 
 * @param left_pin_number 
 * @param right_pin_number 
 * @return LED_Group_Collection_t 
 */
LED_Group_Collection_t init_led_group_collection(uint8_t left_pin_number, uint8_t right_pin_number) {
    LED_Group_Collection_t led_group_collection = {0}; // {0} is the universal zero initialiser

    LED_Group_t led_group_one = {
        .group_pin_number = left_pin_number, 
        .direction = LEFT, 
        .group_brightness = 0
    };

    LED_Group_t led_group_two = {
        .group_pin_number = right_pin_number,
        .direction = RIGHT,
        .group_brightness = 0
    };

    set_led_group(&led_group_collection, led_group_one, LEFT);
    set_led_group(&led_group_collection, led_group_two, RIGHT);

    return led_group_collection;
}

/**
 * @brief Get a led group
 * 
 * @param led_group_collection 
 * @param direction 
 * @return LED_Group_t* 
 */
LED_Group_t* get_led_group(LED_Group_Collection_t* led_group_collection, Direction_t direction) {
    return &(led_group_collection->led_groups[direction]);
}

/**
 * @brief Set a direction's led group
 * 
 * @param led_group_collection 
 * @param led_group 
 * @param direction 
 */
void set_led_group(LED_Group_Collection_t* led_group_collection, LED_Group_t led_group, Direction_t direction) {
    led_group_collection->led_groups[direction] = led_group;
}

/**
 * @brief Set a led group brightnesses
 * 
 * @param led_group_collection 
 */
void set_led_group_brightnesses(LED_Group_Collection_t* led_group_collection, Load_Cell_t* load_cell) {

    uint8_t group_one_brightness = (uint8_t) round((map_voltage_to_range(load_cell->voltage, load_cell->max_voltage, 1) + 0.5) * ARDUINO_PWM_WRITE_RANGE);
    uint8_t group_two_brightness = (ARDUINO_PWM_WRITE_RANGE - group_one_brightness);

    set_group_brightness(get_led_group(led_group_collection, LEFT), group_one_brightness);
    set_group_brightness(get_led_group(led_group_collection, RIGHT), group_two_brightness);
}
