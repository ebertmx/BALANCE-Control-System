/*
 * BALANCEControlSystem_Workable1.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "BALANCEControlSystem_Workable1_private.h"

/* Block signals (default storage) */
B_BALANCEControlSystem_Workab_T BALANCEControlSystem_Workable_B;

/* Continuous states */
X_BALANCEControlSystem_Workab_T BALANCEControlSystem_Workable_X;

/* Block states (default storage) */
DW_BALANCEControlSystem_Worka_T BALANCEControlSystem_Workabl_DW;

/* Real-time model */
static RT_MODEL_BALANCEControlSystem_T BALANCEControlSystem_Workabl_M_;
RT_MODEL_BALANCEControlSystem_T *const BALANCEControlSystem_Workabl_M =
  &BALANCEControlSystem_Workabl_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  BALANCEControlSystem_Workable1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  BALANCEControlSystem_Workable1_step();
  BALANCEControlSystem_Workable1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  BALANCEControlSystem_Workable1_step();
  BALANCEControlSystem_Workable1_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void BALANCEControlSystem_Workable1_step(void)
{
  real_T currentTime;
  if (rtmIsMajorTimeStep(BALANCEControlSystem_Workabl_M)) {
    /* set solver stop time */
    if (!(BALANCEControlSystem_Workabl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&BALANCEControlSystem_Workabl_M->solverInfo,
                            ((BALANCEControlSystem_Workabl_M->Timing.clockTickH0
        + 1) * BALANCEControlSystem_Workabl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&BALANCEControlSystem_Workabl_M->solverInfo,
                            ((BALANCEControlSystem_Workabl_M->Timing.clockTick0
        + 1) * BALANCEControlSystem_Workabl_M->Timing.stepSize0 +
        BALANCEControlSystem_Workabl_M->Timing.clockTickH0 *
        BALANCEControlSystem_Workabl_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BALANCEControlSystem_Workabl_M)) {
    BALANCEControlSystem_Workabl_M->Timing.t[0] = rtsiGetT
      (&BALANCEControlSystem_Workabl_M->solverInfo);
  }

  /* Step: '<Root>/Objective Position' */
  currentTime = BALANCEControlSystem_Workabl_M->Timing.t[0];
  if (currentTime < BALANCEControlSystem_Workable_P.ObjectivePosition_Time) {
    /* Step: '<Root>/Objective Position' */
    BALANCEControlSystem_Workable_B.ObjectivePosition =
      BALANCEControlSystem_Workable_P.ObjectivePosition_Y0;
  } else {
    /* Step: '<Root>/Objective Position' */
    BALANCEControlSystem_Workable_B.ObjectivePosition =
      BALANCEControlSystem_Workable_P.ObjectivePosition_YFinal;
  }

  /* End of Step: '<Root>/Objective Position' */

  /* TransferFcn: '<Root>/Ball and Beam System TF' */
  BALANCEControlSystem_Workable_B.BallPosition = 0.0;
  BALANCEControlSystem_Workable_B.BallPosition +=
    BALANCEControlSystem_Workable_P.BallandBeamSystemTF_C[0] *
    BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[0];
  BALANCEControlSystem_Workable_B.BallPosition +=
    BALANCEControlSystem_Workable_P.BallandBeamSystemTF_C[1] *
    BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[1];

  /* Sum: '<S1>/Sum1' */
  BALANCEControlSystem_Workable_B.Sum1 =
    BALANCEControlSystem_Workable_B.BallPosition;

  /* Sum: '<Root>/Sum' */
  BALANCEControlSystem_Workable_B.Sum =
    BALANCEControlSystem_Workable_B.ObjectivePosition -
    BALANCEControlSystem_Workable_B.Sum1;

  /* TransferFcn: '<Root>/Actuator System TF1' */
  BALANCEControlSystem_Workable_B.ActuatorSystemTF1 =
    BALANCEControlSystem_Workable_P.ActuatorSystemTF1_C[0] *
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[0];
  BALANCEControlSystem_Workable_B.ActuatorSystemTF1 +=
    BALANCEControlSystem_Workable_P.ActuatorSystemTF1_C[1] *
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[1];
  BALANCEControlSystem_Workable_B.ActuatorSystemTF1 +=
    BALANCEControlSystem_Workable_P.ActuatorSystemTF1_C[2] *
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[2];
  if (rtmIsMajorTimeStep(BALANCEControlSystem_Workabl_M)) {
    real_T u1;
    real_T u2;

    /* Gain: '<S43>/Proportional Gain' */
    BALANCEControlSystem_Workable_B.ProportionalGain =
      BALANCEControlSystem_Workable_P.BallonBeamController_P *
      BALANCEControlSystem_Workable_B.Sum;

    /* DiscreteIntegrator: '<S38>/Integrator' */
    BALANCEControlSystem_Workable_B.Integrator =
      BALANCEControlSystem_Workabl_DW.Integrator_DSTATE;

    /* Gain: '<S32>/Derivative Gain' */
    BALANCEControlSystem_Workable_B.DerivativeGain =
      BALANCEControlSystem_Workable_P.BallonBeamController_D *
      BALANCEControlSystem_Workable_B.Sum;

    /* DiscreteIntegrator: '<S33>/Filter' */
    BALANCEControlSystem_Workable_B.Filter =
      BALANCEControlSystem_Workabl_DW.Filter_DSTATE;

    /* Sum: '<S33>/SumD' */
    BALANCEControlSystem_Workable_B.SumD =
      BALANCEControlSystem_Workable_B.DerivativeGain -
      BALANCEControlSystem_Workable_B.Filter;

    /* Gain: '<S41>/Filter Coefficient' */
    BALANCEControlSystem_Workable_B.FilterCoefficient =
      BALANCEControlSystem_Workable_P.BallonBeamController_N *
      BALANCEControlSystem_Workable_B.SumD;

    /* Sum: '<S47>/Sum' */
    BALANCEControlSystem_Workable_B.Sum_l =
      (BALANCEControlSystem_Workable_B.ProportionalGain +
       BALANCEControlSystem_Workable_B.Integrator) +
      BALANCEControlSystem_Workable_B.FilterCoefficient;

    /* Saturate: '<S45>/Saturation' */
    currentTime = BALANCEControlSystem_Workable_B.Sum_l;
    u1 = BALANCEControlSystem_Workable_P.BallonBeamController_LowerSatur;
    u2 = BALANCEControlSystem_Workable_P.BallonBeamController_UpperSatur;
    if (currentTime > u2) {
      /* Saturate: '<S45>/Saturation' */
      BALANCEControlSystem_Workable_B.Saturation = u2;
    } else if (currentTime < u1) {
      /* Saturate: '<S45>/Saturation' */
      BALANCEControlSystem_Workable_B.Saturation = u1;
    } else {
      /* Saturate: '<S45>/Saturation' */
      BALANCEControlSystem_Workable_B.Saturation = currentTime;
    }

    /* End of Saturate: '<S45>/Saturation' */

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* :  if(abs(anglein)<0.01 && abs(anglein)>0.001) */
    if ((fabs(BALANCEControlSystem_Workable_B.Saturation) < 0.01) && (fabs
         (BALANCEControlSystem_Workable_B.Saturation) > 0.001)) {
      /* :  angleout=sign(anglein)*0.01; */
      currentTime = BALANCEControlSystem_Workable_B.Saturation;
      if (!rtIsNaN(currentTime)) {
        if (currentTime < 0.0) {
          currentTime = -1.0;
        } else {
          currentTime = (currentTime > 0.0);
        }
      }

      BALANCEControlSystem_Workable_B.angleout = currentTime * 0.01;
    } else {
      /* :  else */
      /* :  angleout=anglein; */
      BALANCEControlSystem_Workable_B.angleout =
        BALANCEControlSystem_Workable_B.Saturation;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* ZeroOrderHold: '<Root>/ZeroOrder Hold' */
    BALANCEControlSystem_Workable_B.AppliedAngle =
      BALANCEControlSystem_Workable_B.ActuatorSystemTF1;

    /* DeadZone: '<S31>/DeadZone' */
    if (BALANCEControlSystem_Workable_B.Sum_l >
        BALANCEControlSystem_Workable_P.BallonBeamController_UpperSatur) {
      /* DeadZone: '<S31>/DeadZone' */
      BALANCEControlSystem_Workable_B.DeadZone =
        BALANCEControlSystem_Workable_B.Sum_l -
        BALANCEControlSystem_Workable_P.BallonBeamController_UpperSatur;
    } else if (BALANCEControlSystem_Workable_B.Sum_l >=
               BALANCEControlSystem_Workable_P.BallonBeamController_LowerSatur)
    {
      /* DeadZone: '<S31>/DeadZone' */
      BALANCEControlSystem_Workable_B.DeadZone = 0.0;
    } else {
      /* DeadZone: '<S31>/DeadZone' */
      BALANCEControlSystem_Workable_B.DeadZone =
        BALANCEControlSystem_Workable_B.Sum_l -
        BALANCEControlSystem_Workable_P.BallonBeamController_LowerSatur;
    }

    /* End of DeadZone: '<S31>/DeadZone' */

    /* RelationalOperator: '<S29>/Relational Operator' incorporates:
     *  Constant: '<S29>/Constant5'
     */
    BALANCEControlSystem_Workable_B.RelationalOperator =
      (BALANCEControlSystem_Workable_P.Constant5_Value !=
       BALANCEControlSystem_Workable_B.DeadZone);

    /* RelationalOperator: '<S29>/fix for DT propagation issue' incorporates:
     *  Constant: '<S29>/Constant5'
     */
    BALANCEControlSystem_Workable_B.fixforDTpropagationissue =
      (BALANCEControlSystem_Workable_B.DeadZone >
       BALANCEControlSystem_Workable_P.Constant5_Value);

    /* Switch: '<S29>/Switch1' */
    if (BALANCEControlSystem_Workable_B.fixforDTpropagationissue) {
      /* Switch: '<S29>/Switch1' incorporates:
       *  Constant: '<S29>/Constant'
       */
      BALANCEControlSystem_Workable_B.Switch1 =
        BALANCEControlSystem_Workable_P.Constant_Value;
    } else {
      /* Switch: '<S29>/Switch1' incorporates:
       *  Constant: '<S29>/Constant2'
       */
      BALANCEControlSystem_Workable_B.Switch1 =
        BALANCEControlSystem_Workable_P.Constant2_Value;
    }

    /* End of Switch: '<S29>/Switch1' */

    /* Gain: '<S35>/Integral Gain' */
    BALANCEControlSystem_Workable_B.IntegralGain =
      BALANCEControlSystem_Workable_P.BallonBeamController_I *
      BALANCEControlSystem_Workable_B.Sum;

    /* RelationalOperator: '<S29>/fix for DT propagation issue1' incorporates:
     *  Constant: '<S29>/Constant5'
     */
    BALANCEControlSystem_Workable_B.fixforDTpropagationissue1 =
      (BALANCEControlSystem_Workable_B.IntegralGain >
       BALANCEControlSystem_Workable_P.Constant5_Value);

    /* Switch: '<S29>/Switch2' */
    if (BALANCEControlSystem_Workable_B.fixforDTpropagationissue1) {
      /* Switch: '<S29>/Switch2' incorporates:
       *  Constant: '<S29>/Constant3'
       */
      BALANCEControlSystem_Workable_B.Switch2 =
        BALANCEControlSystem_Workable_P.Constant3_Value;
    } else {
      /* Switch: '<S29>/Switch2' incorporates:
       *  Constant: '<S29>/Constant4'
       */
      BALANCEControlSystem_Workable_B.Switch2 =
        BALANCEControlSystem_Workable_P.Constant4_Value;
    }

    /* End of Switch: '<S29>/Switch2' */

    /* RelationalOperator: '<S29>/Equal1' */
    BALANCEControlSystem_Workable_B.Equal1 =
      (BALANCEControlSystem_Workable_B.Switch1 ==
       BALANCEControlSystem_Workable_B.Switch2);

    /* Logic: '<S29>/AND3' */
    BALANCEControlSystem_Workable_B.AND3 =
      (BALANCEControlSystem_Workable_B.RelationalOperator &&
       BALANCEControlSystem_Workable_B.Equal1);

    /* Switch: '<S29>/Switch' */
    if (BALANCEControlSystem_Workable_B.AND3) {
      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S29>/Constant1'
       */
      BALANCEControlSystem_Workable_B.Switch =
        BALANCEControlSystem_Workable_P.Constant1_Value;
    } else {
      /* Switch: '<S29>/Switch' */
      BALANCEControlSystem_Workable_B.Switch =
        BALANCEControlSystem_Workable_B.IntegralGain;
    }

    /* End of Switch: '<S29>/Switch' */

    /* Sum: '<Root>/Sum1' */
    BALANCEControlSystem_Workable_B.Sum1_h =
      BALANCEControlSystem_Workable_B.angleout -
      BALANCEControlSystem_Workable_B.AppliedAngle;

    /* Gain: '<S93>/Proportional Gain' */
    BALANCEControlSystem_Workable_B.ProportionalGain_n =
      BALANCEControlSystem_Workable_P.MotorController1_P *
      BALANCEControlSystem_Workable_B.Sum1_h;

    /* DiscreteIntegrator: '<S88>/Integrator' */
    BALANCEControlSystem_Workable_B.Integrator_c =
      BALANCEControlSystem_Workabl_DW.Integrator_DSTATE_o;

    /* Gain: '<S82>/Derivative Gain' */
    BALANCEControlSystem_Workable_B.DerivativeGain_g =
      BALANCEControlSystem_Workable_P.MotorController1_D *
      BALANCEControlSystem_Workable_B.Sum1_h;

    /* DiscreteIntegrator: '<S83>/Filter' */
    BALANCEControlSystem_Workable_B.Filter_h =
      BALANCEControlSystem_Workabl_DW.Filter_DSTATE_n;

    /* Sum: '<S83>/SumD' */
    BALANCEControlSystem_Workable_B.SumD_n =
      BALANCEControlSystem_Workable_B.DerivativeGain_g -
      BALANCEControlSystem_Workable_B.Filter_h;

    /* Gain: '<S91>/Filter Coefficient' */
    BALANCEControlSystem_Workable_B.FilterCoefficient_p =
      BALANCEControlSystem_Workable_P.MotorController1_N *
      BALANCEControlSystem_Workable_B.SumD_n;

    /* Sum: '<S97>/Sum' */
    BALANCEControlSystem_Workable_B.Sum_f =
      (BALANCEControlSystem_Workable_B.ProportionalGain_n +
       BALANCEControlSystem_Workable_B.Integrator_c) +
      BALANCEControlSystem_Workable_B.FilterCoefficient_p;

    /* DeadZone: '<S81>/DeadZone' */
    if (BALANCEControlSystem_Workable_B.Sum_f >
        BALANCEControlSystem_Workable_P.MotorController1_UpperSaturatio) {
      /* DeadZone: '<S81>/DeadZone' */
      BALANCEControlSystem_Workable_B.DeadZone_h =
        BALANCEControlSystem_Workable_B.Sum_f -
        BALANCEControlSystem_Workable_P.MotorController1_UpperSaturatio;
    } else if (BALANCEControlSystem_Workable_B.Sum_f >=
               BALANCEControlSystem_Workable_P.MotorController1_LowerSaturatio)
    {
      /* DeadZone: '<S81>/DeadZone' */
      BALANCEControlSystem_Workable_B.DeadZone_h = 0.0;
    } else {
      /* DeadZone: '<S81>/DeadZone' */
      BALANCEControlSystem_Workable_B.DeadZone_h =
        BALANCEControlSystem_Workable_B.Sum_f -
        BALANCEControlSystem_Workable_P.MotorController1_LowerSaturatio;
    }

    /* End of DeadZone: '<S81>/DeadZone' */

    /* RelationalOperator: '<S79>/Relational Operator' incorporates:
     *  Constant: '<S79>/Constant5'
     */
    BALANCEControlSystem_Workable_B.RelationalOperator_n =
      (BALANCEControlSystem_Workable_P.Constant5_Value_p !=
       BALANCEControlSystem_Workable_B.DeadZone_h);

    /* RelationalOperator: '<S79>/fix for DT propagation issue' incorporates:
     *  Constant: '<S79>/Constant5'
     */
    BALANCEControlSystem_Workable_B.fixforDTpropagationissue_d =
      (BALANCEControlSystem_Workable_B.DeadZone_h >
       BALANCEControlSystem_Workable_P.Constant5_Value_p);

    /* Switch: '<S79>/Switch1' */
    if (BALANCEControlSystem_Workable_B.fixforDTpropagationissue_d) {
      /* Switch: '<S79>/Switch1' incorporates:
       *  Constant: '<S79>/Constant'
       */
      BALANCEControlSystem_Workable_B.Switch1_o =
        BALANCEControlSystem_Workable_P.Constant_Value_e;
    } else {
      /* Switch: '<S79>/Switch1' incorporates:
       *  Constant: '<S79>/Constant2'
       */
      BALANCEControlSystem_Workable_B.Switch1_o =
        BALANCEControlSystem_Workable_P.Constant2_Value_f;
    }

    /* End of Switch: '<S79>/Switch1' */

    /* Gain: '<S85>/Integral Gain' */
    BALANCEControlSystem_Workable_B.IntegralGain_k =
      BALANCEControlSystem_Workable_P.MotorController1_I *
      BALANCEControlSystem_Workable_B.Sum1_h;

    /* RelationalOperator: '<S79>/fix for DT propagation issue1' incorporates:
     *  Constant: '<S79>/Constant5'
     */
    BALANCEControlSystem_Workable_B.fixforDTpropagationissue1_i =
      (BALANCEControlSystem_Workable_B.IntegralGain_k >
       BALANCEControlSystem_Workable_P.Constant5_Value_p);

    /* Switch: '<S79>/Switch2' */
    if (BALANCEControlSystem_Workable_B.fixforDTpropagationissue1_i) {
      /* Switch: '<S79>/Switch2' incorporates:
       *  Constant: '<S79>/Constant3'
       */
      BALANCEControlSystem_Workable_B.Switch2_e =
        BALANCEControlSystem_Workable_P.Constant3_Value_g;
    } else {
      /* Switch: '<S79>/Switch2' incorporates:
       *  Constant: '<S79>/Constant4'
       */
      BALANCEControlSystem_Workable_B.Switch2_e =
        BALANCEControlSystem_Workable_P.Constant4_Value_l;
    }

    /* End of Switch: '<S79>/Switch2' */

    /* RelationalOperator: '<S79>/Equal1' */
    BALANCEControlSystem_Workable_B.Equal1_e =
      (BALANCEControlSystem_Workable_B.Switch1_o ==
       BALANCEControlSystem_Workable_B.Switch2_e);

    /* Logic: '<S79>/AND3' */
    BALANCEControlSystem_Workable_B.AND3_p =
      (BALANCEControlSystem_Workable_B.RelationalOperator_n &&
       BALANCEControlSystem_Workable_B.Equal1_e);

    /* Switch: '<S79>/Switch' */
    if (BALANCEControlSystem_Workable_B.AND3_p) {
      /* Switch: '<S79>/Switch' incorporates:
       *  Constant: '<S79>/Constant1'
       */
      BALANCEControlSystem_Workable_B.Switch_k =
        BALANCEControlSystem_Workable_P.Constant1_Value_c;
    } else {
      /* Switch: '<S79>/Switch' */
      BALANCEControlSystem_Workable_B.Switch_k =
        BALANCEControlSystem_Workable_B.IntegralGain_k;
    }

    /* End of Switch: '<S79>/Switch' */

    /* Saturate: '<S95>/Saturation' */
    currentTime = BALANCEControlSystem_Workable_B.Sum_f;
    u1 = BALANCEControlSystem_Workable_P.MotorController1_LowerSaturatio;
    u2 = BALANCEControlSystem_Workable_P.MotorController1_UpperSaturatio;
    if (currentTime > u2) {
      /* Saturate: '<S95>/Saturation' */
      BALANCEControlSystem_Workable_B.Saturation_m = u2;
    } else if (currentTime < u1) {
      /* Saturate: '<S95>/Saturation' */
      BALANCEControlSystem_Workable_B.Saturation_m = u1;
    } else {
      /* Saturate: '<S95>/Saturation' */
      BALANCEControlSystem_Workable_B.Saturation_m = currentTime;
    }

    /* End of Saturate: '<S95>/Saturation' */

    /* DeadZone: '<Root>/Motor Signal Dead Zone1' */
    if (BALANCEControlSystem_Workable_B.Saturation_m >
        BALANCEControlSystem_Workable_P.MotorSignalDeadZone1_End) {
      /* DeadZone: '<Root>/Motor Signal Dead Zone1' */
      BALANCEControlSystem_Workable_B.MotorSignalDeadZone1 =
        BALANCEControlSystem_Workable_B.Saturation_m -
        BALANCEControlSystem_Workable_P.MotorSignalDeadZone1_End;
    } else if (BALANCEControlSystem_Workable_B.Saturation_m >=
               BALANCEControlSystem_Workable_P.MotorSignalDeadZone1_Start) {
      /* DeadZone: '<Root>/Motor Signal Dead Zone1' */
      BALANCEControlSystem_Workable_B.MotorSignalDeadZone1 = 0.0;
    } else {
      /* DeadZone: '<Root>/Motor Signal Dead Zone1' */
      BALANCEControlSystem_Workable_B.MotorSignalDeadZone1 =
        BALANCEControlSystem_Workable_B.Saturation_m -
        BALANCEControlSystem_Workable_P.MotorSignalDeadZone1_Start;
    }

    /* End of DeadZone: '<Root>/Motor Signal Dead Zone1' */

    /* Sum: '<Root>/Sum2' */
    BALANCEControlSystem_Workable_B.Sum2 =
      BALANCEControlSystem_Workable_B.AppliedAngle;
  }

  if (rtmIsMajorTimeStep(BALANCEControlSystem_Workabl_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(BALANCEControlSystem_Workabl_M->rtwLogInfo,
                        (BALANCEControlSystem_Workabl_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(BALANCEControlSystem_Workabl_M)) {
    if (rtmIsMajorTimeStep(BALANCEControlSystem_Workabl_M)) {
      /* Update for DiscreteIntegrator: '<S38>/Integrator' */
      BALANCEControlSystem_Workabl_DW.Integrator_DSTATE +=
        BALANCEControlSystem_Workable_P.Integrator_gainval *
        BALANCEControlSystem_Workable_B.Switch;

      /* Update for DiscreteIntegrator: '<S33>/Filter' */
      BALANCEControlSystem_Workabl_DW.Filter_DSTATE +=
        BALANCEControlSystem_Workable_P.Filter_gainval *
        BALANCEControlSystem_Workable_B.FilterCoefficient;

      /* Update for DiscreteIntegrator: '<S88>/Integrator' */
      BALANCEControlSystem_Workabl_DW.Integrator_DSTATE_o +=
        BALANCEControlSystem_Workable_P.Integrator_gainval_l *
        BALANCEControlSystem_Workable_B.Switch_k;

      /* Update for DiscreteIntegrator: '<S83>/Filter' */
      BALANCEControlSystem_Workabl_DW.Filter_DSTATE_n +=
        BALANCEControlSystem_Workable_P.Filter_gainval_i *
        BALANCEControlSystem_Workable_B.FilterCoefficient_p;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(BALANCEControlSystem_Workabl_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(BALANCEControlSystem_Workabl_M)!=-1) &&
          !((rtmGetTFinal(BALANCEControlSystem_Workabl_M)-
             (((BALANCEControlSystem_Workabl_M->Timing.clockTick1+
                BALANCEControlSystem_Workabl_M->Timing.clockTickH1* 4294967296.0))
              * 0.033333333333333333)) >
            (((BALANCEControlSystem_Workabl_M->Timing.clockTick1+
               BALANCEControlSystem_Workabl_M->Timing.clockTickH1* 4294967296.0))
             * 0.033333333333333333) * (DBL_EPSILON))) {
        rtmSetErrorStatus(BALANCEControlSystem_Workabl_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&BALANCEControlSystem_Workabl_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BALANCEControlSystem_Workabl_M->Timing.clockTick0)) {
      ++BALANCEControlSystem_Workabl_M->Timing.clockTickH0;
    }

    BALANCEControlSystem_Workabl_M->Timing.t[0] = rtsiGetSolverStopTime
      (&BALANCEControlSystem_Workabl_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.033333333333333333s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.033333333333333333, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      BALANCEControlSystem_Workabl_M->Timing.clockTick1++;
      if (!BALANCEControlSystem_Workabl_M->Timing.clockTick1) {
        BALANCEControlSystem_Workabl_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void BALANCEControlSystem_Workable1_derivatives(void)
{
  XDot_BALANCEControlSystem_Wor_T *_rtXdot;
  _rtXdot = ((XDot_BALANCEControlSystem_Wor_T *)
             BALANCEControlSystem_Workabl_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Ball and Beam System TF' */
  _rtXdot->BallandBeamSystemTF_CSTATE[0] =
    BALANCEControlSystem_Workable_P.BallandBeamSystemTF_A[0] *
    BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[0];
  _rtXdot->BallandBeamSystemTF_CSTATE[0] +=
    BALANCEControlSystem_Workable_P.BallandBeamSystemTF_A[1] *
    BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[1];
  _rtXdot->BallandBeamSystemTF_CSTATE[1] =
    BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[0];
  _rtXdot->BallandBeamSystemTF_CSTATE[0] += BALANCEControlSystem_Workable_B.Sum2;

  /* Derivatives for TransferFcn: '<Root>/Actuator System TF1' */
  _rtXdot->ActuatorSystemTF1_CSTATE[0] =
    BALANCEControlSystem_Workable_P.ActuatorSystemTF1_A[0] *
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[0];
  _rtXdot->ActuatorSystemTF1_CSTATE[0] +=
    BALANCEControlSystem_Workable_P.ActuatorSystemTF1_A[1] *
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[1];
  _rtXdot->ActuatorSystemTF1_CSTATE[0] +=
    BALANCEControlSystem_Workable_P.ActuatorSystemTF1_A[2] *
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[2];
  _rtXdot->ActuatorSystemTF1_CSTATE[1] =
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[0];
  _rtXdot->ActuatorSystemTF1_CSTATE[2] =
    BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[1];
  _rtXdot->ActuatorSystemTF1_CSTATE[0] +=
    BALANCEControlSystem_Workable_B.MotorSignalDeadZone1;
}

/* Model initialize function */
void BALANCEControlSystem_Workable1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)BALANCEControlSystem_Workabl_M, 0,
                sizeof(RT_MODEL_BALANCEControlSystem_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BALANCEControlSystem_Workabl_M->solverInfo,
                          &BALANCEControlSystem_Workabl_M->Timing.simTimeStep);
    rtsiSetTPtr(&BALANCEControlSystem_Workabl_M->solverInfo, &rtmGetTPtr
                (BALANCEControlSystem_Workabl_M));
    rtsiSetStepSizePtr(&BALANCEControlSystem_Workabl_M->solverInfo,
                       &BALANCEControlSystem_Workabl_M->Timing.stepSize0);
    rtsiSetdXPtr(&BALANCEControlSystem_Workabl_M->solverInfo,
                 &BALANCEControlSystem_Workabl_M->derivs);
    rtsiSetContStatesPtr(&BALANCEControlSystem_Workabl_M->solverInfo, (real_T **)
                         &BALANCEControlSystem_Workabl_M->contStates);
    rtsiSetNumContStatesPtr(&BALANCEControlSystem_Workabl_M->solverInfo,
      &BALANCEControlSystem_Workabl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&BALANCEControlSystem_Workabl_M->solverInfo,
      &BALANCEControlSystem_Workabl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&BALANCEControlSystem_Workabl_M->solverInfo,
       &BALANCEControlSystem_Workabl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&BALANCEControlSystem_Workabl_M->solverInfo,
       &BALANCEControlSystem_Workabl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&BALANCEControlSystem_Workabl_M->solverInfo,
                          (&rtmGetErrorStatus(BALANCEControlSystem_Workabl_M)));
    rtsiSetRTModelPtr(&BALANCEControlSystem_Workabl_M->solverInfo,
                      BALANCEControlSystem_Workabl_M);
  }

  rtsiSetSimTimeStep(&BALANCEControlSystem_Workabl_M->solverInfo,
                     MAJOR_TIME_STEP);
  BALANCEControlSystem_Workabl_M->intgData.y =
    BALANCEControlSystem_Workabl_M->odeY;
  BALANCEControlSystem_Workabl_M->intgData.f[0] =
    BALANCEControlSystem_Workabl_M->odeF[0];
  BALANCEControlSystem_Workabl_M->intgData.f[1] =
    BALANCEControlSystem_Workabl_M->odeF[1];
  BALANCEControlSystem_Workabl_M->intgData.f[2] =
    BALANCEControlSystem_Workabl_M->odeF[2];
  BALANCEControlSystem_Workabl_M->contStates = ((X_BALANCEControlSystem_Workab_T
    *) &BALANCEControlSystem_Workable_X);
  rtsiSetSolverData(&BALANCEControlSystem_Workabl_M->solverInfo, (void *)
                    &BALANCEControlSystem_Workabl_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange
    (&BALANCEControlSystem_Workabl_M->solverInfo, false);
  rtsiSetSolverName(&BALANCEControlSystem_Workabl_M->solverInfo,"ode3");
  rtmSetTPtr(BALANCEControlSystem_Workabl_M,
             &BALANCEControlSystem_Workabl_M->Timing.tArray[0]);
  rtmSetTFinal(BALANCEControlSystem_Workabl_M, 20.0);
  BALANCEControlSystem_Workabl_M->Timing.stepSize0 = 0.033333333333333333;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    BALANCEControlSystem_Workabl_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(BALANCEControlSystem_Workabl_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(BALANCEControlSystem_Workabl_M->rtwLogInfo, (NULL));
    rtliSetLogT(BALANCEControlSystem_Workabl_M->rtwLogInfo, "tout");
    rtliSetLogX(BALANCEControlSystem_Workabl_M->rtwLogInfo, "");
    rtliSetLogXFinal(BALANCEControlSystem_Workabl_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(BALANCEControlSystem_Workabl_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(BALANCEControlSystem_Workabl_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(BALANCEControlSystem_Workabl_M->rtwLogInfo, 0);
    rtliSetLogDecimation(BALANCEControlSystem_Workabl_M->rtwLogInfo, 1);
    rtliSetLogY(BALANCEControlSystem_Workabl_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(BALANCEControlSystem_Workabl_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(BALANCEControlSystem_Workabl_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &BALANCEControlSystem_Workable_B), 0,
                sizeof(B_BALANCEControlSystem_Workab_T));

  /* states (continuous) */
  {
    (void) memset((void *)&BALANCEControlSystem_Workable_X, 0,
                  sizeof(X_BALANCEControlSystem_Workab_T));
  }

  /* states (dwork) */
  (void) memset((void *)&BALANCEControlSystem_Workabl_DW, 0,
                sizeof(DW_BALANCEControlSystem_Worka_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(BALANCEControlSystem_Workabl_M->rtwLogInfo,
    0.0, rtmGetTFinal(BALANCEControlSystem_Workabl_M),
    BALANCEControlSystem_Workabl_M->Timing.stepSize0, (&rtmGetErrorStatus
    (BALANCEControlSystem_Workabl_M)));

  /* InitializeConditions for TransferFcn: '<Root>/Ball and Beam System TF' */
  BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[0] = 0.0;
  BALANCEControlSystem_Workable_X.BallandBeamSystemTF_CSTATE[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  BALANCEControlSystem_Workabl_DW.Integrator_DSTATE =
    BALANCEControlSystem_Workable_P.BallonBeamController_InitialC_n;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Filter' */
  BALANCEControlSystem_Workabl_DW.Filter_DSTATE =
    BALANCEControlSystem_Workable_P.BallonBeamController_InitialCon;

  /* InitializeConditions for TransferFcn: '<Root>/Actuator System TF1' */
  BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[0] = 0.0;
  BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[1] = 0.0;
  BALANCEControlSystem_Workable_X.ActuatorSystemTF1_CSTATE[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Integrator' */
  BALANCEControlSystem_Workabl_DW.Integrator_DSTATE_o =
    BALANCEControlSystem_Workable_P.MotorController1_InitialCondi_p;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Filter' */
  BALANCEControlSystem_Workabl_DW.Filter_DSTATE_n =
    BALANCEControlSystem_Workable_P.MotorController1_InitialConditi;
}

/* Model terminate function */
void BALANCEControlSystem_Workable1_terminate(void)
{
  /* (no terminate code required) */
}
