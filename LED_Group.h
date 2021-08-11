#ifndef LED_GROUP_H
#define LED_GROUP_H

#define COMMON_MODE 2.5
#include <stdint.h>

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

#endif // LED_GROUP_H