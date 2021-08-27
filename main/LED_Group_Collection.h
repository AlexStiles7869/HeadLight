/**
 * @file LED_Group_Collection.h
 * @author Alex Stiles
 * @brief Provides the types and function prototypes required for the collection of LED groups.
 * @version 0.1
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LED_GROUP_COLLECTION_H
#define LED_GROUP_COLLECTION_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include "voltage.h"

#include "Load_Cell.h"
#include "LED_Group.h"

#define NUM_MODES 2

typedef enum {
    FOLLOW = 0,
    FULL
} Light_Mode_t;

typedef struct {
    LED_Group_t led_groups[2];
    Light_Mode_t mode;
    bool mode_changed;
} LED_Group_Collection_t;

LED_Group_Collection_t init_led_group_collection(uint8_t left_pin_number, uint8_t right_pin_number);
LED_Group_t* get_led_group(LED_Group_Collection_t* led_group_collection, Direction_t direction);
void set_led_group(LED_Group_Collection_t* led_group_collection, LED_Group_t led_group, Direction_t direction);
void set_led_group_brightnesses(LED_Group_Collection_t* led_group_collectionm, Load_Cell_t* load_cell);

#if defined(__cplusplus)
}
#endif

#endif // LED_GROUP_COLLECTION_H