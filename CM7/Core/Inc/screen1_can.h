#ifndef SCREEN1_CAN_H
#define SCREEN1_CAN_H

#include <stdint.h>

// CAN ID: 0x10000001 (268435457)
#define ID_DRIVERINPUT_VEHICLECONTROL_1 0x10000001
typedef struct {
    uint32_t Acc_Ped_Pos;
    uint32_t Brk_Ped_Pos;
    uint32_t PRND_State;
    uint32_t Drv_Program;
    float StWhl_Angl_Act;
    float Whl_Angl_Act;
} DriverInputAndVehicleControl_t;

// CAN ID: 0x10000002 (268435458)
#define ID_DRIVERINPUT_VEHICLECONTROL_2 0x10000002
typedef struct {
    float Sbw_Rack_Pos_Req;
    float Sbw_Rack_Pos_Act;
} DriverInput_VehicleControl_2_t;

// CAN ID: 0x10000003 (268435459)
#define ID_POWERTRAIN_STATUS_READY_ENERGY 0x10000003
typedef struct {
    uint32_t PT_Ready;
    uint32_t DrvTrain_Status;
    uint32_t MIL_Lamp_Status;
    uint32_t Turn_Indicator_State;
    uint32_t HVDisconnect_Press;
    uint32_t Emergency_Press;
    uint32_t Vehicle_State;
    uint32_t HV_Voltage;
    float HV_Current;
    float HV_Power;
} Powertrain_Status_Ready_Energy_t;

// CAN ID: 0x10000004 (268435460)
#define ID_MOTOR_AND_TORQUE_CONTROL_1 0x10000004
typedef struct {
    float Trq_Act_Wheel_FL;
    float Trq_Req_Wheel_FL;
    float Trq_Act_Wheel_FR;
    float Trq_Req_Wheel_FR;
} Motor_And_Torque_Control_1_t;

// CAN ID: 0x10000005 (268435461)
#define ID_MOTOR_AND_TORQUE_CONTROL_2 0x10000005
typedef struct {
    float Trq_Act_Wheel_RM;
    float Trq_Req_Wheel_RM;
    float Pwr_Disp;
    float Trq_Act_Sys;
} Motor_And_Torque_Control_2_t;

// CAN ID: 0x10000006 (268435462)
#define ID_EFFICIENCY_PERFORMANCE_1 0x10000006
typedef struct {
    uint32_t Sys_Eff_Act;
    uint32_t Sys_Eff_Opt;
    float LongAccel;
    float LatAccel;
    uint32_t Rng_Rem;
    uint32_t Rng_Added;
} Efficiency_Performance_1_t;

// CAN ID: 0x10000007 (268435463)


// CAN ID: 0x10000009 (268435465)


// CAN ID: 0x10000010 (268435472)

// CAN ID: 0x10000011 (268435473)
#define ID_AUXILIARY_STATES_LV_SOC 0x10000011
typedef struct {
    uint32_t DCDC_State;
    uint32_t AirComp_State;
    uint32_t Heater_State;
    uint32_t HeatPump_State;
    uint32_t SteerByWire_State;
    float DCDC_HV_Current;
    uint32_t DCDC_HV_Voltage;
    uint32_t SOC_Batt_HV;
    uint32_t LV_Voltage;
} Auxiliary_States_LV_SOC_t;

// CAN ID: 0x10000012 (268435474)
#define ID_BMS_VALUES_1 0x10000012
typedef struct {
    float BMS_Max_DischargeCurrentCont;
    float BMS_Max_DischargeCurrentPeak;
    float BMS_Max_ChargeCurrentCont;
    float BMS_Max_ChargeCurrentPeak;
} BMS_Values_1_t;

// CAN ID: 0x10000013 (268435475)
#define ID_BMS_VALUES_2 0x10000013
typedef struct {
    uint32_t BMS_InsulationValue;
    float BMS_Total_Dsg_Ah;
    float BMS_Total_Chg_Ah;
} BMS_Values_2_t;

// CAN ID: 0x10000014 (268435476)
#define ID_BMS_VALUES_3 0x10000014
typedef struct {
    uint32_t BMS_LV_SupplyVolt;
    uint32_t BMS_Dsg_ContS1_FB;
    uint32_t BMS_Dsg_ContS2_FB;
    uint32_t BMS_HVIL_FB;
    uint32_t BMS_PreCharge_Cont_FB;
    uint32_t BMS_Status;
    uint32_t BMS_FaultLevel;
    float Charge_Time_Rem;
    uint32_t E_Lock_Status;
    uint32_t BMS_Chg_ContFB;
    float Temp_CCS2Charge_Inlet;
    float BMS_PDU_Temp;
    float BMS_TargetTemp;
} BMS_Values_3_t;

// CAN ID: 0x10000015 (268435477)
#define ID_BMS_VALUES_4 0x10000015
typedef struct {
    float BMS_Max_Chg_CurrentLimit;
    float BMS_Max_Chg_VoltageLimit;
    float Charge_Pwr_Lim;
    uint32_t BMS_External_ChargeInfo;
    float BMS_ThermalStatus;
} BMS_Values_4_t;


#endif // SCREEN1_CAN_H
