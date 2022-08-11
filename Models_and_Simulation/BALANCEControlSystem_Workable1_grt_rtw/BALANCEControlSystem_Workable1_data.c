/*
 * BALANCEControlSystem_Workable1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BALANCEControlSystem_Workable1".
 *
 * Model version              : 1.72
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Mon Aug  8 18:08:28 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "BALANCEControlSystem_Workable1.h"

/* Block parameters (default storage) */
P_BALANCEControlSystem_Workab_T BALANCEControlSystem_Workable_P = {
  /* Mask Parameter: BallonBeamController_D
   * Referenced by: '<S32>/Derivative Gain'
   */
  0.298180317605175,

  /* Mask Parameter: MotorController1_D
   * Referenced by: '<S82>/Derivative Gain'
   */
  7.31174263119045,

  /* Mask Parameter: BallonBeamController_I
   * Referenced by: '<S35>/Integral Gain'
   */
  0.00984218983062414,

  /* Mask Parameter: MotorController1_I
   * Referenced by: '<S85>/Integral Gain'
   */
  22.2987513395518,

  /* Mask Parameter: BallonBeamController_InitialCon
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: MotorController1_InitialConditi
   * Referenced by: '<S83>/Filter'
   */
  0.0,

  /* Mask Parameter: BallonBeamController_InitialC_n
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: MotorController1_InitialCondi_p
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: BallonBeamController_LowerSatur
   * Referenced by:
   *   '<S45>/Saturation'
   *   '<S31>/DeadZone'
   */
  -0.3,

  /* Mask Parameter: MotorController1_LowerSaturatio
   * Referenced by:
   *   '<S95>/Saturation'
   *   '<S81>/DeadZone'
   */
  -0.9,

  /* Mask Parameter: BallonBeamController_N
   * Referenced by: '<S41>/Filter Coefficient'
   */
  4.92152866164286,

  /* Mask Parameter: MotorController1_N
   * Referenced by: '<S91>/Filter Coefficient'
   */
  25.5040307304801,

  /* Mask Parameter: BallonBeamController_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  0.110647526065682,

  /* Mask Parameter: MotorController1_P
   * Referenced by: '<S93>/Proportional Gain'
   */
  26.4845239685581,

  /* Mask Parameter: BallonBeamController_UpperSatur
   * Referenced by:
   *   '<S45>/Saturation'
   *   '<S31>/DeadZone'
   */
  0.3,

  /* Mask Parameter: MotorController1_UpperSaturatio
   * Referenced by:
   *   '<S95>/Saturation'
   *   '<S81>/DeadZone'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S29>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S79>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Objective Position'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Objective Position'
   */
  0.0,

  /* Expression: 0.173
   * Referenced by: '<Root>/Objective Position'
   */
  0.173,

  /* Computed Parameter: BallandBeamSystemTF_A
   * Referenced by: '<Root>/Ball and Beam System TF'
   */
  { -0.0, -0.0 },

  /* Computed Parameter: BallandBeamSystemTF_C
   * Referenced by: '<Root>/Ball and Beam System TF'
   */
  { 0.0, 6.223 },

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S38>/Integrator'
   */
  0.033333333333333333,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S33>/Filter'
   */
  0.033333333333333333,

  /* Computed Parameter: ActuatorSystemTF1_A
   * Referenced by: '<Root>/Actuator System TF1'
   */
  { -1.4546112115732371E+6, -138300.18083182641, -0.0 },

  /* Computed Parameter: ActuatorSystemTF1_C
   * Referenced by: '<Root>/Actuator System TF1'
   */
  { 0.0, 0.0, 3.0976491862567812E+6 },

  /* Expression: 0
   * Referenced by: '<S29>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S79>/Constant5'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S88>/Integrator'
   */
  0.033333333333333333,

  /* Computed Parameter: Filter_gainval_i
   * Referenced by: '<S83>/Filter'
   */
  0.033333333333333333,

  /* Expression: -0.1
   * Referenced by: '<Root>/Motor Signal Dead Zone1'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Motor Signal Dead Zone1'
   */
  0.1,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S29>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S29>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S29>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S29>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S79>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_f
   * Referenced by: '<S79>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_g
   * Referenced by: '<S79>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_l
   * Referenced by: '<S79>/Constant4'
   */
  -1
};
