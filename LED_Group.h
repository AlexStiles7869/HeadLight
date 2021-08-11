#ifndef LED_GROUP_H
#define LED_GROUP_H

#include <stdint.h>

typedef enum {
    LEFT = 0,
    RIGHT
} Direction_t;

typedef struct {
    int8_t group_pin_number;
    Direction_t direction;
    int8_t group_brightness;
} LED_Group_t;

int8_t get_group_brightness(const LED_Group_t* const led_group);
void set_group_brightness(LED_Group_t* const led_group, int8_t group_brightness);

int8_t get_group_pin_number(const LED_Group_t* const led_group);

Direction_t get_group_direction(const LED_Group_t* const led_group);

#endif // LED_GROUP_H