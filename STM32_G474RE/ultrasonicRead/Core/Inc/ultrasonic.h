/*
 * ultrasonic.h
 *
 *  Created on: Apr 15, 2026
 *      Author: User
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_


#include "main.h"

// Tell this library that main.c has the hardware handles
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef hlpuart1;

// Your custom variables and functions
extern uint32_t sensor_timestamp;
extern uint16_t UltrasonicTime,UltrasonicPeriod;
extern float ConvertedValue_cm;

float ultrasonicRawRead(void);





#endif /* INC_ULTRASONIC_H_ */
