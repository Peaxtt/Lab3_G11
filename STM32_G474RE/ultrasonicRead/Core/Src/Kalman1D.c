/*
 * Kalman1D.c
 *
 *  Created on: Apr 23, 2026
 *      Author: User
 */


#include "Kalman1D.h"

void Kalman1D_Init(Kalman1D_t *kf, float initial_position, float process_noise, float sensor_noise) {
    kf->x = initial_position;
    kf->p = 100.0f;           // Start with high uncertainty
    kf->q = process_noise;    // Q
    kf->r = sensor_noise;     // R
}

float Kalman1D_Update(Kalman1D_t *kf, float measurement) {
    // ==========================================
    // 1. PREDICT STEP
    // ==========================================
    // Physics model: We assume the object is mostly static, so x = x.
    // We just add the process noise to our uncertainty.
    kf->p = kf->p + kf->q;

    // ==========================================
    // 2. CORRECT STEP
    // ==========================================
    // Calculate Kalman Gain: k = p / (p + r)
    float k = kf->p / (kf->p + kf->r);

    // Update state estimate: x = x + k * (measurement - x)
    kf->x = kf->x + k * (measurement - kf->x);

    // Update uncertainty: p = (1 - k) * p
    kf->p = (1.0f - k) * kf->p;

    return kf->x; // Return the clean distance!
}
