#ifndef SCREEN2_CAN_H
#define SCREEN2_CAN_H

#include <stdint.h>

// CAN ID: 0x10000016 (268435478)
#define ID_BMS_VALUES_5 0x10000016
typedef struct {
    float BMS_M1_Temp_max;
    float BMS_M1_Temp_min;
    float BMS_M2_Temp_max;
    float BMS_M2_Temp_min;
    float BMS_M3_Temp_max;
    float BMS_M3_Temp_min;
    float BMS_M4_Temp_max;
    float BMS_M4_Temp_min;
} BMS_Values_5_t;

// CAN ID: 0x10000017 (268435479)
#define ID_BMS_VALUES_6 0x10000017
typedef struct {
    float BMS_M5_Temp_max;
    float BMS_M5_Temp_min;
    float BMS_M6_Temp_max;
    float BMS_M6_Temp_min;
    float BMS_M7_Temp_max;
    float BMS_M7_Temp_min;
    float BMS_M8_Temp_max;
    float BMS_M8_Temp_min;
} BMS_Values_6_t;

// CAN ID: 0x10000018 (268435480)
#define ID_BMS_VALUES_7 0x10000018
typedef struct {
    float BMS_M9_Temp_max;
    float BMS_M9_Temp_min;
    float BMS_M10_Temp_max;
    float BMS_M10_Temp_min;
    float BMS_M11_Temp_max;
    float BMS_M11_Temp_min;
    float BMS_M12_Temp_max;
    float BMS_M12_Temp_min;
} BMS_Values_7_t;

// CAN ID: 0x10000019 (268435481)
#define ID_BMS_VALUES_8 0x10000019
typedef struct {
    float BMS_M13_Temp_max;
    float BMS_M13_Temp_min;
    float BMS_M14_Temp_max;
    float BMS_M14_Temp_min;
    float BMS_M15_Temp_max;
    float BMS_M15_Temp_min;
    float BMS_M16_Temp_max;
    float BMS_M16_Temp_min;
} BMS_Values_8_t;

// CAN ID: 0x10000020 (268435488)
#define ID_BMS_VALUES_9 0x10000020
typedef struct {
    float BMS_M17_Temp_max;
    float BMS_M17_Temp_min;
    float BMS_M18_Temp_max;
    float BMS_M18_Temp_min;
    float BMS_M19_Temp_max;
    float BMS_M19_Temp_min;
    float BMS_M20_Temp_max;
    float BMS_M20_Temp_min;
} BMS_Values_9_t;

// CAN ID: 0x10000021 (268435489)
#define ID_BMS_VALUES_10 0x10000021
typedef struct {
    float BMS_M21_Temp_max;
    float BMS_M21_Temp_min;
    float BMS_M22_Temp_max;
    float BMS_M22_Temp_min;
    float BMS_M23_Temp_max;
    float BMS_M23_Temp_min;
    float BMS_M24_Temp_max;
    float BMS_M24_Temp_min;
} BMS_Values_10_t;

// CAN ID: 0x10000022 (268435490)
#define ID_GEARBOX_PARKBRAKE_TEMP 0x10000022
typedef struct {
    uint32_t ParkBrake_Status;
    uint32_t SuctionPump_Rear_Status;
    uint32_t SuctionPump_Front_Status;
    uint32_t GearShift_FL_Act_Pos;
    uint32_t GearShift_FR_Act_Pos;
    uint32_t GearBoxFrontOilPumps_Status;
    float Temp_Gearbox_FL_IN;
    float Temp_Gearbox_FL_OUT;
    float Temp_Gearbox_FR_IN;
    float Temp_Gearbox_FR_OUT;
    float Temp_Gearbox_R_IN;
    float Temp_Gearbox_R_OUT;
} Gearbox_Parkbrake_Temp_t;

// CAN ID: 0x10000023 (268435491)
#define ID_VEHICLE_STATE 0x10000023
typedef struct {
    uint32_t Odometer;
    float Speed;
} Vehicle_State_t;

// CAN ID: 0x10000024 (268435492)
#define ID_IP_LTNG_CHG_PNEMATIC_TX 0x10000024
typedef struct {
    uint32_t Drv_Program_Sw;
    uint32_t Override_Req;
    uint32_t Gear_Actuator_Override;
    uint32_t Level_Control_Req;
    uint32_t DCDC_Req;
    uint32_t LowBeam_Req;
    uint32_t HighBeam_Req;
    uint32_t PosLight_Req;
    uint32_t IntLight_Req;
    uint32_t Chrg_STOP_Req;
    uint32_t Chrg_PreCond_Req;
    uint32_t AirCompressor_Req;
    uint32_t MinPressureAir;
    uint32_t MaxPressureAir;
    uint32_t RefSpdSens_Speed;
} Ip_Ltng_Chg_Pnematic_Tx_t;

// CAN ID: 0x10000025 (268435493)
#define ID_THERMAL_MANAGEMENT_TX_1 0x10000025
typedef struct {
    uint32_t HVHeaterEnable;
    uint32_t HeatPump_Req;
    uint32_t HeatFoil_Req;
    uint32_t LVvalve1_Req;
    uint32_t LVvalve2_Req;
    uint32_t LVvalve3_Req;
    float HVHeater_TargetCoolantTemp;
    float LowerLimit_HeatPump;
    float UpperLimit_HeatPump;
    float UpperLimit_ActiveHeatup;
} Thermal_Management_Tx_1_t;

// CAN ID: 0x10000026 (268435494)
#define ID_RELAY_FUSEBOX_CONTROL_TX 0x10000026
typedef struct {
    uint32_t Box1_Req;
    uint32_t Box2_Req;
    float LowerLimit_HeatPump;
    float UpperLimit_HeatPump;
    float UpperLimit_ActiveHeatup;
    float MinPressureAir;
    float MaxPressureAir;
} Relay_Fusebox_Control_Tx_t;

// CAN ID: 0x10000027 (268435495)
#define ID_VCU_GENERALFAULTS_1 0x10000027
typedef struct {
    uint64_t statusMask;
} VCU_GeneralFaults_1_t;

// CAN ID: 0x10000028 (268435496)
#define ID_VCU_GENERALFAULTS_2 0x10000028
typedef struct {
    uint64_t statusMask;
} VCU_GeneralFaults_2_t;

// CAN ID: 0x10000029 (268435497)
#define ID_VCU_COMPONENTFAULTS_1 0x10000029
typedef struct {
    uint64_t statusMask;
} VCU_ComponentFaults_1_t;


#endif // SCREEN2_CAN_H
