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

#ifdef __cplusplus
}
#endif

#endif