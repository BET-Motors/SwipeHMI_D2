#ifndef MODEL_HPP
#define MODEL_HPP

#include "stdint.h"
#include "fdcan.h"

class ModelListener;

class Model
{
private:
    Press_Hydraulic_Light_PowerTrain_t phlp;
    Thermal_Management_Rx_1_t thermal1;
    Thermal_Management_Rx_2_t thermal2;
    Motor_And_Torque_Control_1_t mtc1;    
    Motor_And_Torque_Control_2_t mtc2;
    BMS_Values_5_t bms1_4;
    BMS_Values_6_t bms5_8;
    BMS_Values_7_t bms9_12;
    BMS_Values_8_t bms13_16;
    BMS_Values_9_t bms17_20;
    BMS_Values_10_t bms21_24;
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
    // bool parseDriverInput1(CAN_Raw_Msg_t, DriverInputAndVehicleControl_t *);
    bool parsePressHydLightPt(CAN_Raw_Msg_t, Press_Hydraulic_Light_PowerTrain_t *);
    bool parseThermal1(CAN_Raw_Msg_t, Thermal_Management_Rx_1_t *);
    bool parseThermal2(CAN_Raw_Msg_t, Thermal_Management_Rx_2_t *);
    bool parsemtc1(CAN_Raw_Msg_t, Motor_And_Torque_Control_1_t *);
    bool parsemtc2(CAN_Raw_Msg_t, Motor_And_Torque_Control_2_t *);
    bool parseBms1_4(CAN_Raw_Msg_t, BMS_Values_5_t *);
    bool parseBms5_8(CAN_Raw_Msg_t, BMS_Values_6_t *);
    bool parseBms9_12(CAN_Raw_Msg_t, BMS_Values_7_t *);
    bool parseBms13_16(CAN_Raw_Msg_t, BMS_Values_8_t *);
    bool parseBms17_20(CAN_Raw_Msg_t, BMS_Values_9_t *);
    bool parseBms21_24(CAN_Raw_Msg_t, BMS_Values_10_t *);
};

#endif // MODEL_HPP
