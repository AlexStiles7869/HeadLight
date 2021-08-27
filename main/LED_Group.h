k ai/**
 * @file LED_Group.h
 * @author Alex Stiles
 * @brief Provides the types and function prototypes required for the LED groups.
 * @version 0.1 alpha
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LED_GROUP_H
#define LED_GROUP_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>

#include "voltage.h"

typedef enum {
    LEFT = 0,
    RIGHT
} Direction_t;

typedef struct {
    uint8_t group_pin_number;
    Direction_t direction;
    uint8_t group_brightness;
} LED_Group_t;

uint8_t get_group_brightness(const LED_Group_t* const led_group);
void set_group_brightness(LED_Group_t* const led_group, uint8_t group_brightness);

uint8_t get_group_pin_number(const LED_Group_t* const led_group);

Direction_t get_group_direction(const LED_Group_t* const led_group);

#if defined(__cplusplus)
}
#endif

#endif // LED_GROUP_H