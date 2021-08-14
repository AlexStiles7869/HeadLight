/**
 * @file main.ino
 * @author Alex Stiles
 * @details
 * @brief Entry point. Contains high level logic and polling loop.
 * @version 0.1 alpha
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021
 * 
 * The entry point for compilation when compiling on Arduino. 
 * Contains the setup() and loop() functions required for the Arduino. 
 * C headers included are appropriately linked.
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "voltage.h"

#include "LED_Group_Collection.h"
#include "LED_Group.h"
#include "Load_Cell.h"

#define LOAD_CELL_ANALOG_PIN 0 // Should be A0, but this works for testing as well so leaving as 0.

#define LEFT_GROUP_PIN 5
#define RIGHT_GROUP_PIN 6

LED_Group_Collection_t led_group_collection;
Load_Cell_t load_cell;

float read_load_cell_voltage() {
    return (analogRead(LOAD_CELL_ANALOG_PIN) / (float) ARDUINO_PWM_READ_RANGE) * ARDUINO_MAX_VOLTAGE;
}

void update_led_group_pwm_signals() {
    set_led_group_brightnesses(&led_group_collection, &load_cell);

    Serial.println("Left: " + String(get_group_brightness(get_led_group(&led_group_collection, LEFT))));
    Serial.println("Right: " + String(get_group_brightness(get_led_group(&led_group_collection, RIGHT))));
    
    analogWrite(LEFT_GROUP_PIN, get_group_brightness(get_led_group(&led_group_collection, LEFT)));
    analogWrite(RIGHT_GROUP_PIN, get_group_brightness(get_led_group(&led_group_collection, RIGHT)));
}

void setup() {
    Serial.begin(9600);

    led_group_collection = init_led_group_collection(LEFT_GROUP_PIN, RIGHT_GROUP_PIN);
    load_cell = init_load_cell(LOAD_CELL_ANALOG_PIN);

    pinMode(LOAD_CELL_ANALOG_PIN, INPUT);

    pinMode(LEFT_GROUP_PIN, OUTPUT);
    pinMode(RIGHT_GROUP_PIN, OUTPUT);
}

void loop() {
    if (poll_sensor(&load_cell, read_load_cell_voltage())) {
         update_led_group_pwm_signals();

      Serial.println("Load Cell Voltage: " + String(load_cell.voltage));
      Serial.println("Load Cell Strain: " + String(load_cell.strain));
      Serial.println("Load Cell Angle: " + String(load_cell.angle));
    }

    delay(50);
}
