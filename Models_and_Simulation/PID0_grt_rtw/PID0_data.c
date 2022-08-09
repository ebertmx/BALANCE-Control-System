/*
 * PID0_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID0".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sat Aug  6 14:50:41 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID0.h"

/* Block parameters (default storage) */
P_PID0_T PID0_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S29>/Derivative Gain'
   */
  0.251701852841353,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S32>/Integral Gain'
   */
  0.00224651366953076,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S30>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_e
   * Referenced by: '<S35>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by:
   *   '<S42>/Saturation'
   *   '<S28>/DeadZone'
   */
  -0.3,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S38>/Filter Coefficient'
   */
  5.45397025421619,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S40>/Proportional Gain'
   */
  0.0479872756441392,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by:
   *   '<S42>/Saturation'
   *   '<S28>/DeadZone'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<S26>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S35>/Integrator'
   */
  0.2,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S30>/Filter'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S26>/Constant5'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S26>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S26>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S26>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S26>/Constant4'
   */
  -1
};
