#ifndef LED_GROUP_COLLECTION_H
#define LED_GROUP_COLLECTION_H

#include "LED_Group.h"

#define COMMON_MODE 2.5

typedef struct {
    LED_Group_t led_groups[2];
} LED_Group_Collection_t;

LED_Group_t* get_led_group(LED_Group_Collection_t* led_group_collection, Direction_t direction);
void set_led_group(LED_Group_Collection_t* led_group_collection, LED_Group_t led_group, Direction_t direction);
void set_led_group_brightnesses(LED_Group_Collection_t* led_group_collectionm, float load_cell_voltage);

#endif // LED_GROUP_COLLECTION_H