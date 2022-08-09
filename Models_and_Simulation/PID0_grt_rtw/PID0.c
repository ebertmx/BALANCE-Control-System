/*
 * PID0.c
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
#include "rtwtypes.h"
#include "PID0_private.h"
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_PID0_T PID0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PID0_T PID0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PID0_T PID0_Y;

/* Real-time model */
static RT_MODEL_PID0_T PID0_M_;
RT_MODEL_PID0_T *const PID0_M = &PID0_M_;

/* Model step function */
void PID0_step(void)
{
  real_T rtb_DeadZone;
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  int8_T rtb_DeadZone_0;
  int8_T rtb_IntegralGain_0;

  /* Gain: '<S38>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S30>/Filter'
   *  Gain: '<S29>/Derivative Gain'
   *  Inport: '<Root>/u'
   *  Sum: '<S30>/SumD'
   */
  rtb_FilterCoefficient = (PID0_P.PIDController_D * PID0_U.u -
    PID0_DW.Filter_DSTATE) * PID0_P.PIDController_N;

  /* Sum: '<S44>/Sum' incorporates:
   *  DiscreteIntegrator: '<S35>/Integrator'
   *  Gain: '<S40>/Proportional Gain'
   *  Inport: '<Root>/u'
   */
  rtb_DeadZone = (PID0_P.PIDController_P * PID0_U.u + PID0_DW.Integrator_DSTATE)
    + rtb_FilterCoefficient;

  /* Saturate: '<S42>/Saturation' incorporates:
   *  DeadZone: '<S28>/DeadZone'
   */
  if (rtb_DeadZone > PID0_P.PIDController_UpperSaturationLi) {
    /* Outport: '<Root>/y' */
    PID0_Y.y = PID0_P.PIDController_UpperSaturationLi;
    rtb_DeadZone -= PID0_P.PIDController_UpperSaturationLi;
  } else {
    if (rtb_DeadZone < PID0_P.PIDController_LowerSaturationLi) {
      /* Outport: '<Root>/y' */
      PID0_Y.y = PID0_P.PIDController_LowerSaturationLi;
    } else {
      /* Outport: '<Root>/y' */
      PID0_Y.y = rtb_DeadZone;
    }

    if (rtb_DeadZone >= PID0_P.PIDController_LowerSaturationLi) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone -= PID0_P.PIDController_LowerSaturationLi;
    }
  }

  /* End of Saturate: '<S42>/Saturation' */

  /* Gain: '<S32>/Integral Gain' incorporates:
   *  Inport: '<Root>/u'
   */
  rtb_IntegralGain = PID0_P.PIDController_I * PID0_U.u;

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant2'
   *  Constant: '<S26>/Constant5'
   *  RelationalOperator: '<S26>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > PID0_P.Constant5_Value) {
    rtb_DeadZone_0 = PID0_P.Constant_Value;
  } else {
    rtb_DeadZone_0 = PID0_P.Constant2_Value;
  }

  /* End of Switch: '<S26>/Switch1' */

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S26>/Constant3'
   *  Constant: '<S26>/Constant4'
   *  Constant: '<S26>/Constant5'
   *  RelationalOperator: '<S26>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > PID0_P.Constant5_Value) {
    rtb_IntegralGain_0 = PID0_P.Constant3_Value;
  } else {
    rtb_IntegralGain_0 = PID0_P.Constant4_Value;
  }

  /* End of Switch: '<S26>/Switch2' */

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S26>/Constant5'
   *  Logic: '<S26>/AND3'
   *  RelationalOperator: '<S26>/Equal1'
   *  RelationalOperator: '<S26>/Relational Operator'
   */
  if ((PID0_P.Constant5_Value != rtb_DeadZone) && (rtb_DeadZone_0 ==
       rtb_IntegralGain_0)) {
    rtb_IntegralGain = PID0_P.Constant1_Value;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Update for DiscreteIntegrator: '<S35>/Integrator' */
  PID0_DW.Integrator_DSTATE += PID0_P.Integrator_gainval * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S30>/Filter' */
  PID0_DW.Filter_DSTATE += PID0_P.Filter_gainval * rtb_FilterCoefficient;

  /* Matfile logging */
  rt_UpdateTXYLogVars(PID0_M->rtwLogInfo, (&PID0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(PID0_M)!=-1) &&
        !((rtmGetTFinal(PID0_M)-PID0_M->Timing.taskTime0) >
          PID0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PID0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PID0_M->Timing.clockTick0)) {
    ++PID0_M->Timing.clockTickH0;
  }

  PID0_M->Timing.taskTime0 = PID0_M->Timing.clockTick0 *
    PID0_M->Timing.stepSize0 + PID0_M->Timing.clockTickH0 *
    PID0_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void PID0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID0_M, 0,
                sizeof(RT_MODEL_PID0_T));
  rtmSetTFinal(PID0_M, 10.0);
  PID0_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    PID0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PID0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PID0_M->rtwLogInfo, (NULL));
    rtliSetLogT(PID0_M->rtwLogInfo, "tout");
    rtliSetLogX(PID0_M->rtwLogInfo, "");
    rtliSetLogXFinal(PID0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PID0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PID0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(PID0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(PID0_M->rtwLogInfo, 1);
    rtliSetLogY(PID0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(PID0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PID0_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&PID0_DW, 0,
                sizeof(DW_PID0_T));

  /* external inputs */
  PID0_U.u = 0.0;

  /* external outputs */
  PID0_Y.y = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(PID0_M->rtwLogInfo, 0.0, rtmGetTFinal(PID0_M),
    PID0_M->Timing.stepSize0, (&rtmGetErrorStatus(PID0_M)));

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Integrator' */
  PID0_DW.Integrator_DSTATE = PID0_P.PIDController_InitialConditio_e;

  /* InitializeConditions for DiscreteIntegrator: '<S30>/Filter' */
  PID0_DW.Filter_DSTATE = PID0_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void PID0_terminate(void)
{
  /* (no terminate code required) */
}
