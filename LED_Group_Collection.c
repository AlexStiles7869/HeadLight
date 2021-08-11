#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "LED_Group_Collection.h"

/**
 * @brief Get the led group object
 * 
 * @param led_group_collection 
 * @param direction 
 * @return LED_Group_t* 
 */
LED_Group_t* get_led_group(LED_Group_Collection_t* led_group_collection, Direction_t direction) {
    return &(led_group_collection->led_groups[direction]);
}

/**
 * @brief Set the led group object
 * 
 * @param led_group_collection 
 * @param led_group 
 * @param direction 
 */
void set_led_group(LED_Group_Collection_t* led_group_collection, LED_Group_t led_group, Direction_t direction) {
    led_group_collection->led_groups[direction] = led_group;
}

/**
 * @brief Set the led group brightnesses object
 * 
 * @param led_group_collection 
 */
void set_led_group_brightnesses(LED_Group_Collection_t* led_group_collection, float load_cell_voltage) {

    uint8_t group_one_brightness = (uint8_t) round((((COMMON_MODE - load_cell_voltage) / (5)) + 0.5) * 255);
    uint8_t group_two_brightness = (255 - group_one_brightness);

    set_group_brightness(get_led_group(led_group_collection, LEFT), group_one_brightness);
    set_group_brightness(get_led_group(led_group_collection, RIGHT), group_two_brightness);
}
