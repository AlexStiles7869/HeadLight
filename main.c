#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "LED_Group_Collection.h"
#include "LED_Group.h"
#include "Load_Cell.h"

#define LOAD_CELL_ANALOG_PIN 0 // Should be A0, but this works for testing as well so leaving as 0.

#define LEFT_GROUP_PIN 5
#define RIGHT_GROUP_PIN 6

/**
 * @brief 
 * 
 * @return LED_Group_Collection_t 
 */
LED_Group_Collection_t init_led_group_collection() {
    LED_Group_Collection_t led_group_collection = {0}; // {0} is the universal zero initialiser

    LED_Group_t led_group_one = {.group_pin_number = LEFT_GROUP_PIN, .direction = LEFT, .group_brightness = 0};
    LED_Group_t led_group_two = {.group_pin_number = RIGHT_GROUP_PIN, .direction = RIGHT, .group_brightness = 0};

    set_led_group(&led_group_collection, led_group_one, LEFT);
    set_led_group(&led_group_collection, led_group_two, RIGHT);

    return led_group_collection;
}

/**
 * @brief 
 * 
 * @return Load_Cell_t 
 */
Load_Cell_t init_load_cell() {
    Load_Cell_t load_cell = {.pin_number = LOAD_CELL_ANALOG_PIN, .voltage = 0, .deviation_voltage_breakpoint = DEVIATION_VOLTAGE_BREAKPOINT};

    return load_cell;
}

int main(void) {
    /*
    TODO:
    - Clean up pointer usage for LED_Group_t and LED_Group_Collection_t
    - Write appropriate descriptions of all functions
    - Attempt to compile specifically for Arduino
        - Check memory usage (not using dynamic memory at all so should be fine)
    - Create amplification / filtering stage circuit to properly test integration with greater system
    */
    LED_Group_Collection_t led_group_collection = init_led_group_collection();
    Load_Cell_t load_cell = init_load_cell();

    printf("Load Cell Voltage: %.1f/5 V\n", load_cell.voltage);
    printf("Left Group Brightness: %d/100 | Right Group Brightness: %d/100\n", get_group_brightness(get_led_group(&led_group_collection, LEFT)), get_group_brightness(get_led_group(&led_group_collection, RIGHT)));
    
    load_cell.voltage = 3.3;

    set_led_group_brightnesses(&led_group_collection, load_cell.voltage);
    
    printf("Load Cell Voltage: %.1f/5 V\n", load_cell.voltage);
    printf("Left Group Brightness: %d/100 | Right Group Brightness: %d/100\n", get_group_brightness(get_led_group(&led_group_collection, LEFT)), get_group_brightness(get_led_group(&led_group_collection, RIGHT)));

    return EXIT_SUCCESS;
}