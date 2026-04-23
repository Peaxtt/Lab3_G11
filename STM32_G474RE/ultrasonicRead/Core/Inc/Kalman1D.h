/*
 * Kalman1D.h
 *
 *  Created on: Apr 23, 2026
 *      Author: User
 */

#ifndef INC_KALMAN1D_H_
#define INC_KALMAN1D_H_

typedef struct {
    float x; // State Estimate (Clean Distance)
    float p; // Estimate Uncertainty
    float q; // Process Noise (How much the object randomly moves)
    float r; // Measurement Noise (How noisy the sensor is)
} Kalman1D_t;

void Kalman1D_Init(Kalman1D_t *kf, float initial_position, float process_noise, float sensor_noise);
float Kalman1D_Update(Kalman1D_t *kf, float measurement);

#endif /* INC_KALMAN1D_H_ */
