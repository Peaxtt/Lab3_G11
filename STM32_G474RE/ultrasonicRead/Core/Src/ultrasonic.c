/*
 * ultrasonic.c
 *
 *  Created on: Apr 15, 2026
 *      Author: User
 */


// ultrasonic.c

// 1. ALWAYS include your own header file first!
// This connects the "kitchen" to the "menu" and brings in the HAL hardware handles.
#include "ultrasonic.h"

// 2. Define any variables that belong to this library
uint32_t sensor_timestamp = 0;
float ConvertedValue_cm=0;

// 3. Write the actual function logic

float ultrasonicRawRead(void)
{
    // Trigger the sensor
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 15);

    // Read the echo time
    uint16_t UltrasonicTime = __HAL_TIM_GET_COMPARE(&htim1, TIM_CHANNEL_2);

    // Calculate and return the distance
    ConvertedValue_cm=(UltrasonicTime / 58.0f);
    return ConvertedValue_cm;
}


