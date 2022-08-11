/*
 * BALANCEControlSystem_Workable1.h
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

#ifndef RTW_HEADER_BALANCEControlSystem_Workable1_h_
#define RTW_HEADER_BALANCEControlSystem_Workable1_h_
#ifndef BALANCEControlSystem_Workable1_COMMON_INCLUDES_
#define BALANCEControlSystem_Workable1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                     /* BALANCEControlSystem_Workable1_COMMON_INCLUDES_ */

#include "BALANCEControlSystem_Workable1_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define BALANCEControlSystem_Workable1_M (BALANCEControlSystem_Workabl_M)

/* Block signals (default storage) */
typedef struct {
  real_T ObjectivePosition;            /* '<Root>/Objective Position' */
  real_T BallPosition;                 /* '<Root>/Ball and Beam System TF' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S43>/Proportional Gain' */
  real_T Integrator;                   /* '<S38>/Integrator' */
  real_T DerivativeGain;               /* '<S32>/Derivative Gain' */
  real_T Filter;                       /* '<S33>/Filter' */
  real_T SumD;                         /* '<S33>/SumD' */
  real_T FilterCoefficient;            /* '<S41>/Filter Coefficient' */
  real_T Sum_l;                        /* '<S47>/Sum' */
  real_T Saturation;                   /* '<S45>/Saturation' */
  real_T ActuatorSystemTF1;            /* '<Root>/Actuator System TF1' */
  real_T AppliedAngle;                 /* '<Root>/ZeroOrder Hold' */
  real_T DeadZone;                     /* '<S31>/DeadZone' */
  real_T IntegralGain;                 /* '<S35>/Integral Gain' */
  real_T Switch;                       /* '<S29>/Switch' */
  real_T Sum1_h;                       /* '<Root>/Sum1' */
  real_T ProportionalGain_n;           /* '<S93>/Proportional Gain' */
  real_T Integrator_c;                 /* '<S88>/Integrator' */
  real_T DerivativeGain_g;             /* '<S82>/Derivative Gain' */
  real_T Filter_h;                     /* '<S83>/Filter' */
  real_T SumD_n;                       /* '<S83>/SumD' */
  real_T FilterCoefficient_p;          /* '<S91>/Filter Coefficient' */
  real_T Sum_f;                        /* '<S97>/Sum' */
  real_T DeadZone_h;                   /* '<S81>/DeadZone' */
  real_T IntegralGain_k;               /* '<S85>/Integral Gain' */
  real_T Switch_k;                     /* '<S79>/Switch' */
  real_T Saturation_m;                 /* '<S95>/Saturation' */
  real_T MotorSignalDeadZone1;         /* '<Root>/Motor Signal Dead Zone1' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T angleout;                     /* '<Root>/MATLAB Function' */
  int8_T Switch1;                      /* '<S29>/Switch1' */
  int8_T Switch2;                      /* '<S29>/Switch2' */
  int8_T Switch1_o;                    /* '<S79>/Switch1' */
  int8_T Switch2_e;                    /* '<S79>/Switch2' */
  boolean_T RelationalOperator;        /* '<S29>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S29>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S29>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S29>/Equal1' */
  boolean_T AND3;                      /* '<S29>/AND3' */
  boolean_T RelationalOperator_n;      /* '<S79>/Relational Operator' */
  boolean_T fixforDTpropagationissue_d;
                                      /* '<S79>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_i;
                                     /* '<S79>/fix for DT propagation issue1' */
  boolean_T Equal1_e;                  /* '<S79>/Equal1' */
  boolean_T AND3_p;                    /* '<S79>/AND3' */
} B_BALANCEControlSystem_Workab_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T Filter_DSTATE;                /* '<S33>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S88>/Integrator' */
  real_T Filter_DSTATE_n;              /* '<S83>/Filter' */
} DW_BALANCEControlSystem_Worka_T;

/* Continuous states (default storage) */
typedef struct {
  real_T BallandBeamSystemTF_CSTATE[2];/* '<Root>/Ball and Beam System TF' */
  real_T ActuatorSystemTF1_CSTATE[3];  /* '<Root>/Actuator System TF1' */
} X_BALANCEControlSystem_Workab_T;

/* State derivatives (default storage) */
typedef struct {
  real_T BallandBeamSystemTF_CSTATE[2];/* '<Root>/Ball and Beam System TF' */
  real_T ActuatorSystemTF1_CSTATE[3];  /* '<Root>/Actuator System TF1' */
} XDot_BALANCEControlSystem_Wor_T;

/* State disabled  */
typedef struct {
  boolean_T BallandBeamSystemTF_CSTATE[2];/* '<Root>/Ball and Beam System TF' */
  boolean_T ActuatorSystemTF1_CSTATE[3];/* '<Root>/Actuator System TF1' */
} XDis_BALANCEControlSystem_Wor_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_BALANCEControlSystem_Workab_T_ {
  real_T BallonBeamController_D;       /* Mask Parameter: BallonBeamController_D
                                        * Referenced by: '<S32>/Derivative Gain'
                                        */
  real_T MotorController1_D;           /* Mask Parameter: MotorController1_D
                                        * Referenced by: '<S82>/Derivative Gain'
                                        */
  real_T BallonBeamController_I;       /* Mask Parameter: BallonBeamController_I
                                        * Referenced by: '<S35>/Integral Gain'
                                        */
  real_T MotorController1_I;           /* Mask Parameter: MotorController1_I
                                        * Referenced by: '<S85>/Integral Gain'
                                        */
  real_T BallonBeamController_InitialCon;
                              /* Mask Parameter: BallonBeamController_InitialCon
                               * Referenced by: '<S33>/Filter'
                               */
  real_T MotorController1_InitialConditi;
                              /* Mask Parameter: MotorController1_InitialConditi
                               * Referenced by: '<S83>/Filter'
                               */
  real_T BallonBeamController_InitialC_n;
                              /* Mask Parameter: BallonBeamController_InitialC_n
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T MotorController1_InitialCondi_p;
                              /* Mask Parameter: MotorController1_InitialCondi_p
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T BallonBeamController_LowerSatur;
                              /* Mask Parameter: BallonBeamController_LowerSatur
                               * Referenced by:
                               *   '<S45>/Saturation'
                               *   '<S31>/DeadZone'
                               */
  real_T MotorController1_LowerSaturatio;
                              /* Mask Parameter: MotorController1_LowerSaturatio
                               * Referenced by:
                               *   '<S95>/Saturation'
                               *   '<S81>/DeadZone'
                               */
  real_T BallonBeamController_N;       /* Mask Parameter: BallonBeamController_N
                                        * Referenced by: '<S41>/Filter Coefficient'
                                        */
  real_T MotorController1_N;           /* Mask Parameter: MotorController1_N
                                        * Referenced by: '<S91>/Filter Coefficient'
                                        */
  real_T BallonBeamController_P;       /* Mask Parameter: BallonBeamController_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  real_T MotorController1_P;           /* Mask Parameter: MotorController1_P
                                        * Referenced by: '<S93>/Proportional Gain'
                                        */
  real_T BallonBeamController_UpperSatur;
                              /* Mask Parameter: BallonBeamController_UpperSatur
                               * Referenced by:
                               *   '<S45>/Saturation'
                               *   '<S31>/DeadZone'
                               */
  real_T MotorController1_UpperSaturatio;
                              /* Mask Parameter: MotorController1_UpperSaturatio
                               * Referenced by:
                               *   '<S95>/Saturation'
                               *   '<S81>/DeadZone'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T ObjectivePosition_Time;       /* Expression: 0
                                        * Referenced by: '<Root>/Objective Position'
                                        */
  real_T ObjectivePosition_Y0;         /* Expression: 0
                                        * Referenced by: '<Root>/Objective Position'
                                        */
  real_T ObjectivePosition_YFinal;     /* Expression: 0.173
                                        * Referenced by: '<Root>/Objective Position'
                                        */
  real_T BallandBeamSystemTF_A[2];  /* Computed Parameter: BallandBeamSystemTF_A
                                     * Referenced by: '<Root>/Ball and Beam System TF'
                                     */
  real_T BallandBeamSystemTF_C[2];  /* Computed Parameter: BallandBeamSystemTF_C
                                     * Referenced by: '<Root>/Ball and Beam System TF'
                                     */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S38>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S33>/Filter'
                                        */
  real_T ActuatorSystemTF1_A[3];      /* Computed Parameter: ActuatorSystemTF1_A
                                       * Referenced by: '<Root>/Actuator System TF1'
                                       */
  real_T ActuatorSystemTF1_C[3];      /* Computed Parameter: ActuatorSystemTF1_C
                                       * Referenced by: '<Root>/Actuator System TF1'
                                       */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S29>/Constant5'
                                        */
  real_T Constant5_Value_p;            /* Expression: 0
                                        * Referenced by: '<S79>/Constant5'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S88>/Integrator'
                                      */
  real_T Filter_gainval_i;             /* Computed Parameter: Filter_gainval_i
                                        * Referenced by: '<S83>/Filter'
                                        */
  real_T MotorSignalDeadZone1_Start;   /* Expression: -0.1
                                        * Referenced by: '<Root>/Motor Signal Dead Zone1'
                                        */
  real_T MotorSignalDeadZone1_End;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Motor Signal Dead Zone1'
                                        */
  int8_T Constant_Value;               /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S29>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S29>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S29>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S29>/Constant4'
                                        */
  int8_T Constant_Value_e;             /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S79>/Constant'
                                        */
  int8_T Constant2_Value_f;            /* Computed Parameter: Constant2_Value_f
                                        * Referenced by: '<S79>/Constant2'
                                        */
  int8_T Constant3_Value_g;            /* Computed Parameter: Constant3_Value_g
                                        * Referenced by: '<S79>/Constant3'
                                        */
  int8_T Constant4_Value_l;            /* Computed Parameter: Constant4_Value_l
                                        * Referenced by: '<S79>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BALANCEControlSystem__T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_BALANCEControlSystem_Workab_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_BALANCEControlSystem_Workab_T BALANCEControlSystem_Workable_P;

/* Block signals (default storage) */
extern B_BALANCEControlSystem_Workab_T BALANCEControlSystem_Workable_B;

/* Continuous states (default storage) */
extern X_BALANCEControlSystem_Workab_T BALANCEControlSystem_Workable_X;

/* Block states (default storage) */
extern DW_BALANCEControlSystem_Worka_T BALANCEControlSystem_Workabl_DW;

/* Model entry point functions */
extern void BALANCEControlSystem_Workable1_initialize(void);
extern void BALANCEControlSystem_Workable1_step(void);
extern void BALANCEControlSystem_Workable1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BALANCEControlSystem_T *const BALANCEControlSystem_Workabl_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Motor Signal Zero-Order Hold ' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BALANCEControlSystem_Workable1'
 * '<S1>'   : 'BALANCEControlSystem_Workable1/BALANCE CV System'
 * '<S2>'   : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller'
 * '<S3>'   : 'BALANCEControlSystem_Workable1/MATLAB Function'
 * '<S4>'   : 'BALANCEControlSystem_Workable1/Motor Controller1'
 * '<S5>'   : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Anti-windup'
 * '<S6>'   : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/D Gain'
 * '<S7>'   : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Filter'
 * '<S8>'   : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Filter ICs'
 * '<S9>'   : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/I Gain'
 * '<S10>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Ideal P Gain'
 * '<S11>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Integrator'
 * '<S13>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Integrator ICs'
 * '<S14>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/N Copy'
 * '<S15>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/N Gain'
 * '<S16>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/P Copy'
 * '<S17>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Parallel P Gain'
 * '<S18>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Reset Signal'
 * '<S19>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Saturation'
 * '<S20>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Saturation Fdbk'
 * '<S21>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Sum'
 * '<S22>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Sum Fdbk'
 * '<S23>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tracking Mode'
 * '<S24>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tracking Mode Sum'
 * '<S25>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tsamp - Integral'
 * '<S26>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tsamp - Ngain'
 * '<S27>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/postSat Signal'
 * '<S28>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/preSat Signal'
 * '<S29>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S30>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S31>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S32>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/D Gain/Internal Parameters'
 * '<S33>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/I Gain/Internal Parameters'
 * '<S36>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Integrator/Discrete'
 * '<S39>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/N Copy/Disabled'
 * '<S41>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/N Gain/Internal Parameters'
 * '<S42>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/P Copy/Disabled'
 * '<S43>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Reset Signal/Disabled'
 * '<S45>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Saturation/Enabled'
 * '<S46>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Sum/Sum_PID'
 * '<S48>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'BALANCEControlSystem_Workable1/Ball on Beam  Controller/preSat Signal/Forward_Path'
 * '<S55>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Anti-windup'
 * '<S56>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/D Gain'
 * '<S57>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Filter'
 * '<S58>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Filter ICs'
 * '<S59>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/I Gain'
 * '<S60>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Ideal P Gain'
 * '<S61>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Ideal P Gain Fdbk'
 * '<S62>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Integrator'
 * '<S63>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Integrator ICs'
 * '<S64>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/N Copy'
 * '<S65>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/N Gain'
 * '<S66>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/P Copy'
 * '<S67>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Parallel P Gain'
 * '<S68>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Reset Signal'
 * '<S69>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Saturation'
 * '<S70>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Saturation Fdbk'
 * '<S71>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Sum'
 * '<S72>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Sum Fdbk'
 * '<S73>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Tracking Mode'
 * '<S74>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Tracking Mode Sum'
 * '<S75>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Tsamp - Integral'
 * '<S76>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Tsamp - Ngain'
 * '<S77>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/postSat Signal'
 * '<S78>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/preSat Signal'
 * '<S79>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S80>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S81>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S82>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/D Gain/Internal Parameters'
 * '<S83>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Filter/Disc. Forward Euler Filter'
 * '<S84>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Filter ICs/Internal IC - Filter'
 * '<S85>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/I Gain/Internal Parameters'
 * '<S86>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Ideal P Gain/Passthrough'
 * '<S87>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Integrator/Discrete'
 * '<S89>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Integrator ICs/Internal IC'
 * '<S90>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/N Copy/Disabled'
 * '<S91>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/N Gain/Internal Parameters'
 * '<S92>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/P Copy/Disabled'
 * '<S93>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Reset Signal/Disabled'
 * '<S95>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Saturation/Enabled'
 * '<S96>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Saturation Fdbk/Disabled'
 * '<S97>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Sum/Sum_PID'
 * '<S98>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Sum Fdbk/Disabled'
 * '<S99>'  : 'BALANCEControlSystem_Workable1/Motor Controller1/Tracking Mode/Disabled'
 * '<S100>' : 'BALANCEControlSystem_Workable1/Motor Controller1/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'BALANCEControlSystem_Workable1/Motor Controller1/Tsamp - Integral/Passthrough'
 * '<S102>' : 'BALANCEControlSystem_Workable1/Motor Controller1/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'BALANCEControlSystem_Workable1/Motor Controller1/postSat Signal/Forward_Path'
 * '<S104>' : 'BALANCEControlSystem_Workable1/Motor Controller1/preSat Signal/Forward_Path'
 */
#endif                        /* RTW_HEADER_BALANCEControlSystem_Workable1_h_ */
