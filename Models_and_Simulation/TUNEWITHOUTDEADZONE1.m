%% Create system data with slTuner interface
TunedBlocks = {'BALANCEControlSystem/Motor Controller1'; ...
               'BALANCEControlSystem/Ball on Beam  Controller'};
AnalysisPoints = {'BALANCEControlSystem/Objective Position/1'; ...
                  'BALANCEControlSystem/BALANCE CV System/1'};
% Specify the custom options
Options = slTunerOptions('AreParamsTunable',false);
% Create the slTuner object
CL0 = slTuner('BALANCEControlSystem',TunedBlocks,AnalysisPoints,Options);

%% Create tuning goal to shape how the closed-loop system responds to a specific input signal
% Inputs and outputs
Inputs = {'BALANCEControlSystem/Objective Position/1'};
Outputs = {'BALANCEControlSystem/BALANCE CV System/1'};
% Tuning goal specifications
Tau = 2; % Time constant
% Create tuning goal for step tracking
StepTrackingGoal1 = TuningGoal.StepTracking(Inputs,Outputs,Tau);
StepTrackingGoal1.Name = 'StepTrackingGoal1'; % Tuning goal name

%% Create option set for systune command
Options = systuneOptions();
Options.Display = 'off'; % Tuning display level ('final', 'sub', 'iter', 'off')

%% Set soft and hard goals
SoftGoals = [ StepTrackingGoal1 ];
HardGoals = [];

%% Tune the parameters with soft and hard goals
[CL1,fSoft,gHard,Info] = systune(CL0,SoftGoals,HardGoals,Options);

%% View tuning results
% viewSpec([SoftGoals;HardGoals],CL1);
