#ifndef __BETDBCS2_H__
#define __BETDBCS2_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"

#include <stdint.h>

#define ID_PRESS_HYDRAULIC_LIGHT_POWERTRAIN 0x10000009
typedef struct {
    uint32_t Pres_Susp_Front;
    uint32_t Pres_Susp_Rear;
    uint32_t Pres_Brk_Front;
    uint32_t Pres_Brk_Rear;
    uint8_t LowBeam_St;
    uint8_t HighBeam_St;
    uint8_t PosLight_St;
    uint8_t IntLight_St;
    uint32_t Pwr_Act_MotRM;
    uint32_t Pwr_Act_MotFL;
    uint32_t Pwr_Act_MotFR;
} Press_Hydraulic_Light_PowerTrain_t;

#define ID_THERMAL_MANAGEMENT_RX_1 0x10000007
typedef struct {
    int16_t BMS_Pack_Temp_max;
    int16_t BMS_Pack_Temp_min;
    int16_t Temp_Inv_FL;
    int16_t Temp_Inv_FR;
    int16_t Temp_Inv_RM;
    int16_t Temp_EM_FL;
    int16_t Temp_EM_FR;
    int16_t Temp_EM_RM;
} Thermal_Management_Rx_1_t;

// CAN ID: 0x10000008 (268435464)
#define ID_THERMAL_MANAGEMENT_RX_2 0x10000008
typedef struct {
    int16_t Temp_Battery;
    int16_t Temp_Auxilaries;
    int16_t Temp_AIR;
    int16_t Temp_Powertrain;
    uint16_t Rad_Fan_Speed;
    int16_t Temp_DCDC;
    int16_t Temp_ClntPump;
} Thermal_Management_Rx_2_t;

#define ID_MOTOR_AND_TORQUE_CONTROL_1 0x10000004
typedef struct {
    uint16_t Trq_Act_Wheel_FL;
    uint16_t Trq_Req_Wheel_FL;
    uint16_t Trq_Act_Wheel_FR;
    uint16_t Trq_Req_Wheel_FR;
} Motor_And_Torque_Control_1_t;

#define ID_MOTOR_AND_TORQUE_CONTROL_2 0x10000005
typedef struct {
    float Trq_Act_Wheel_RM;
    float Trq_Req_Wheel_RM;
    float Pwr_Disp;
    float Trq_Act_Sys;
} Motor_And_Torque_Control_2_t;

// CAN ID: 0x10000016 (268435478)
#define ID_BMS_VALUES_5 0x10000016
typedef struct {
    uint8_t BMS_M1_Temp_max;
    uint8_t BMS_M1_Temp_min;
    uint8_t BMS_M2_Temp_max;
    uint8_t BMS_M2_Temp_min;
    uint8_t BMS_M3_Temp_max;
    uint8_t BMS_M3_Temp_min;
    uint8_t BMS_M4_Temp_max;
    uint8_t BMS_M4_Temp_min;
} BMS_Values_5_t;

// CAN ID: 0x10000017 (268435479)
#define ID_BMS_VALUES_6 0x10000017
typedef struct {
    uint8_t BMS_M5_Temp_max;
    uint8_t BMS_M5_Temp_min;
    uint8_t BMS_M6_Temp_max;
    uint8_t BMS_M6_Temp_min;
    uint8_t BMS_M7_Temp_max;
    uint8_t BMS_M7_Temp_min;
    uint8_t BMS_M8_Temp_max;
    uint8_t BMS_M8_Temp_min;
} BMS_Values_6_t;

// CAN ID: 0x10000018 (268435480)
#define ID_BMS_VALUES_7 0x10000018
typedef struct {
    uint8_t BMS_M9_Temp_max;
    uint8_t BMS_M9_Temp_min;
    uint8_t BMS_M10_Temp_max;
    uint8_t BMS_M10_Temp_min;
    uint8_t BMS_M11_Temp_max;
    uint8_t BMS_M11_Temp_min;
    uint8_t BMS_M12_Temp_max;
    uint8_t BMS_M12_Temp_min;
} BMS_Values_7_t;

// CAN ID: 0x10000019 (268435481)
#define ID_BMS_VALUES_8 0x10000019
typedef struct {
    uint8_t BMS_M13_Temp_max;
    uint8_t BMS_M13_Temp_min;
    uint8_t BMS_M14_Temp_max;
    uint8_t BMS_M14_Temp_min;
    uint8_t BMS_M15_Temp_max;
    uint8_t BMS_M15_Temp_min;
    uint8_t BMS_M16_Temp_max;
    uint8_t BMS_M16_Temp_min;
} BMS_Values_8_t;

// CAN ID: 0x10000020 (268435488)
#define ID_BMS_VALUES_9 0x10000020
typedef struct {
    uint8_t BMS_M17_Temp_max;
    uint8_t BMS_M17_Temp_min;
    uint8_t BMS_M18_Temp_max;
    uint8_t BMS_M18_Temp_min;
    uint8_t BMS_M19_Temp_max;
    uint8_t BMS_M19_Temp_min;
    uint8_t BMS_M20_Temp_max;
    uint8_t BMS_M20_Temp_min;
} BMS_Values_9_t;

// CAN ID: 0x10000021 (268435489)
#define ID_BMS_VALUES_10 0x10000021
typedef struct {
    uint8_t BMS_M21_Temp_max;
    uint8_t BMS_M21_Temp_min;
    uint8_t BMS_M22_Temp_max;
    uint8_t BMS_M22_Temp_min;
    uint8_t BMS_M23_Temp_max;
    uint8_t BMS_M23_Temp_min;
    uint8_t BMS_M24_Temp_max;
    uint8_t BMS_M24_Temp_min;
} BMS_Values_10_t;

#define ID_DRIVER_INPUTS_TX 0x1001
typedef struct {
    uint8_t Override_Request;               // bit 0 (1 bit)
    uint8_t Drive_Program_Sw;               // bit 1 (3 bits)
    uint8_t Gear_Actuator_Override;         // bit 4 (3 bits)
    uint8_t DCDC_Request;                   // bit 7 (1 bit)
    uint8_t Air_Sus_Level_Control_Override; // bit 8 (4 bits)
    uint8_t Low_Beam_Req;                   // bit 12 (1 bit)
    uint8_t High_Beam_Req;                  // bit 13 (1 bit)
    uint8_t Position_Light_Req;             // bit 14 (1 bit)
    uint8_t Interior_Light_Req;             // bit 15 (1 bit)
    uint8_t HVHeater_Enable;                // bit 16 (1 bit)
    uint8_t HeatPump_Req;                   // bit 17 (1 bit)
    uint8_t HeatFoil_Req;                   // bit 18 (1 bit)
    uint8_t LVvalve1_Req;                   // bit 19 (1 bit)
    uint8_t LVvalve2_Req;                   // bit 20 (1 bit)
    uint8_t LVvalve3_Req;                   // bit 21 (1 bit)
    uint8_t Chrg_STOP_Req;                  // bit 22 (1 bit)
    uint8_t Chrg_PreCond_Req;               // bit 23 (1 bit)
    uint8_t AirCompressor_Req;              // bit 24 (1 bit)
} DriverInputsTx_t;

#ifdef __cplusplus
}
#endif

#endif