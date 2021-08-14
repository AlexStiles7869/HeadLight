#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "voltage.h"

#include "LED_Group_Collection.h"
#include "LED_Group.h"
#include "Load_Cell.h"

#define LOAD_CELL_ANALOG_PIN 0

#define LEFT_GROUP_PIN 5
#define RIGHT_GROUP_PIN 6

#if !defined(ARDUINO)

int main(void) {
   LED_Group_Collection_t led_group_collection = init_led_group_collection(LEFT_GROUP_PIN, RIGHT_GROUP_PIN);
   Load_Cell_t load_cell = init_load_cell(LOAD_CELL_ANALOG_PIN);

   if (poll_sensor(&load_cell, 3.75)) {
       set_led_group_brightnesses(&led_group_collection, &load_cell);

       printf("Load Cell Voltage: %.1f/5 V\n", load_cell.voltage);
       printf("Left Group Brightness: %d/255 | Right Group Brightness: %d/255\n", get_group_brightness(get_led_group(&led_group_collection, LEFT)), get_group_brightness(get_led_group(&led_group_collection, RIGHT)));
       printf("Load Cell Strain: %d grams\n", load_cell.strain);
       printf("Head Angle: %d deg\n", load_cell.angle);
   }

   return EXIT_SUCCESS;
}

#endif