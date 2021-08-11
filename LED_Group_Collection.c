#include <stdint.h>

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
    set_group_brightness(get_led_group(led_group_collection, LEFT), 45);
    set_group_brightness(get_led_group(led_group_collection, RIGHT), 55);
}
