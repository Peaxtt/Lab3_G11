/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testuartread.c
 *
 * Code generated for Simulink model 'testuartread'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Mon Apr 20 01:54:26 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testuartread.h"
#include "testuartread_private.h"

/* Block signals (default storage) */
B_testuartread_T testuartread_B;

/* Block states (default storage) */
DW_testuartread_T testuartread_DW;

/* Real-time model */
static RT_MODEL_testuartread_T testuartread_M_;
RT_MODEL_testuartread_T *const testuartread_M = &testuartread_M_;

/* Model step function */
void testuartread_step(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  testuartread_M->Timing.taskTime0 =
    ((time_T)(++testuartread_M->Timing.clockTick0)) *
    testuartread_M->Timing.stepSize0;
}

/* Model initialize function */
void testuartread_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(testuartread_M, -1);
  testuartread_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  testuartread_M->Sizes.checksums[0] = (3202631455U);
  testuartread_M->Sizes.checksums[1] = (3341456904U);
  testuartread_M->Sizes.checksums[2] = (1789926056U);
  testuartread_M->Sizes.checksums[3] = (4012977012U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    testuartread_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testuartread_M->extModeInfo,
      &testuartread_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testuartread_M->extModeInfo,
                        testuartread_M->Sizes.checksums);
    rteiSetTPtr(testuartread_M->extModeInfo, rtmGetTPtr(testuartread_M));
  }
}

/* Model terminate function */
void testuartread_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
