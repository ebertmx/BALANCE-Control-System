/*
 * PID0.h
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

#ifndef RTW_HEADER_PID0_h_
#define RTW_HEADER_PID0_h_
#ifndef PID0_COMMON_INCLUDES_
#define PID0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* PID0_COMMON_INCLUDES_ */

#include "PID0_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S35>/Integrator' */
  real_T Filter_DSTATE;                /* '<S30>/Filter' */
} DW_PID0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T u;                            /* '<Root>/u' */
} ExtU_PID0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExtY_PID0_T;

/* Parameters (default storage) */
struct P_PID0_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S29>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S32>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S30>/Filter'
                               */
  real_T PIDController_InitialConditio_e;
                              /* Mask Parameter: PIDController_InitialConditio_e
                               * Referenced by: '<S35>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by:
                               *   '<S42>/Saturation'
                               *   '<S28>/DeadZone'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S38>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S40>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by:
                               *   '<S42>/Saturation'
                               *   '<S28>/DeadZone'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S35>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S30>/Filter'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S26>/Constant5'
                                        */
  int8_T Constant_Value;               /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S26>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S26>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S26>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S26>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PID0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID0_T PID0_P;

/* Block states (default storage) */
extern DW_PID0_T PID0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PID0_T PID0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PID0_T PID0_Y;

/* Model entry point functions */
extern void PID0_initialize(void);
extern void PID0_step(void);
extern void PID0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID0_T *const PID0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('BallandBeam/PID Controller')    - opens subsystem BallandBeam/PID Controller
 * hilite_system('BallandBeam/PID Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BallandBeam'
 * '<S1>'   : 'BallandBeam/PID Controller'
 * '<S2>'   : 'BallandBeam/PID Controller/Anti-windup'
 * '<S3>'   : 'BallandBeam/PID Controller/D Gain'
 * '<S4>'   : 'BallandBeam/PID Controller/Filter'
 * '<S5>'   : 'BallandBeam/PID Controller/Filter ICs'
 * '<S6>'   : 'BallandBeam/PID Controller/I Gain'
 * '<S7>'   : 'BallandBeam/PID Controller/Ideal P Gain'
 * '<S8>'   : 'BallandBeam/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'BallandBeam/PID Controller/Integrator'
 * '<S10>'  : 'BallandBeam/PID Controller/Integrator ICs'
 * '<S11>'  : 'BallandBeam/PID Controller/N Copy'
 * '<S12>'  : 'BallandBeam/PID Controller/N Gain'
 * '<S13>'  : 'BallandBeam/PID Controller/P Copy'
 * '<S14>'  : 'BallandBeam/PID Controller/Parallel P Gain'
 * '<S15>'  : 'BallandBeam/PID Controller/Reset Signal'
 * '<S16>'  : 'BallandBeam/PID Controller/Saturation'
 * '<S17>'  : 'BallandBeam/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'BallandBeam/PID Controller/Sum'
 * '<S19>'  : 'BallandBeam/PID Controller/Sum Fdbk'
 * '<S20>'  : 'BallandBeam/PID Controller/Tracking Mode'
 * '<S21>'  : 'BallandBeam/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'BallandBeam/PID Controller/Tsamp - Integral'
 * '<S23>'  : 'BallandBeam/PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'BallandBeam/PID Controller/postSat Signal'
 * '<S25>'  : 'BallandBeam/PID Controller/preSat Signal'
 * '<S26>'  : 'BallandBeam/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S27>'  : 'BallandBeam/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S28>'  : 'BallandBeam/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S29>'  : 'BallandBeam/PID Controller/D Gain/Internal Parameters'
 * '<S30>'  : 'BallandBeam/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S31>'  : 'BallandBeam/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S32>'  : 'BallandBeam/PID Controller/I Gain/Internal Parameters'
 * '<S33>'  : 'BallandBeam/PID Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'BallandBeam/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'BallandBeam/PID Controller/Integrator/Discrete'
 * '<S36>'  : 'BallandBeam/PID Controller/Integrator ICs/Internal IC'
 * '<S37>'  : 'BallandBeam/PID Controller/N Copy/Disabled'
 * '<S38>'  : 'BallandBeam/PID Controller/N Gain/Internal Parameters'
 * '<S39>'  : 'BallandBeam/PID Controller/P Copy/Disabled'
 * '<S40>'  : 'BallandBeam/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'BallandBeam/PID Controller/Reset Signal/Disabled'
 * '<S42>'  : 'BallandBeam/PID Controller/Saturation/Enabled'
 * '<S43>'  : 'BallandBeam/PID Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'BallandBeam/PID Controller/Sum/Sum_PID'
 * '<S45>'  : 'BallandBeam/PID Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'BallandBeam/PID Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'BallandBeam/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'BallandBeam/PID Controller/Tsamp - Integral/Passthrough'
 * '<S49>'  : 'BallandBeam/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'BallandBeam/PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'BallandBeam/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_PID0_h_ */
