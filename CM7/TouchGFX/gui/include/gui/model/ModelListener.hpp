#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include "fdcan.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    // virtual void updateDriverControls(DriverInputAndVehicleControl_t data) {}
    virtual void updatePressHydLightPt(Press_Hydraulic_Light_PowerTrain_t data) {}
    virtual void updateThermal1(Thermal_Management_Rx_1_t data) {}
    virtual void updateThermal2(Thermal_Management_Rx_2_t data) {}
    virtual void updateMtc1(Motor_And_Torque_Control_1_t data) {}
    virtual void updateMtc2(Motor_And_Torque_Control_2_t data) {}
    virtual void updateBms1_4(BMS_Values_5_t data) {}
    virtual void updateBms5_8(BMS_Values_6_t data) {}
    virtual void updateBms9_12(BMS_Values_7_t data) {}
    virtual void updateBms13_16(BMS_Values_8_t data) {}
    virtual void updateBms17_20(BMS_Values_9_t data) {}
    virtual void updateBms21_24(BMS_Values_10_t data) {}
    virtual void updateEpea(ElecSys_Power_Energy_AirComp_t data) {}
    virtual void updateFb1State(FuseBox1State_t data) {}
    virtual void updateFb2State(FuseBox2State_t data) {}
    virtual void updateFbR(FuseBoxRelay_t data) {}
    virtual void udpateLcp(Ip_Ltng_Chg_Pnematic_Tx_t data) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
