#ifndef SCREEN1PRESENTER_HPP
#define SCREEN1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include "fdcan.h"

using namespace touchgfx;

class Screen1View;

class Screen1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen1Presenter(Screen1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen1Presenter() {}
    // virtual void updateDriverControls(DriverInputAndVehicleControl_t data) ;
    virtual void updatePressHydLightPt(Press_Hydraulic_Light_PowerTrain_t data);
    virtual void updateThermal1(Thermal_Management_Rx_1_t data);
    virtual void updateThermal2(Thermal_Management_Rx_2_t data);
    virtual void updateMtc1(Motor_And_Torque_Control_1_t data);
    virtual void updateMtc2(Motor_And_Torque_Control_2_t data);
    virtual void updateBms1_4(BMS_Values_5_t data);
    virtual void updateBms5_8(BMS_Values_6_t data);
    virtual void updateBms9_12(BMS_Values_7_t data);
    virtual void updateBms13_16(BMS_Values_8_t data);
    virtual void updateBms17_20(BMS_Values_9_t data);
    virtual void updateBms21_24(BMS_Values_10_t data);
    virtual void updateEpea(ElecSys_Power_Energy_AirComp_t data);
    virtual void updateFb1State(FuseBox1State_t);
    virtual void updateFb2State(FuseBox2State_t);
    virtual void updateFbR(FuseBoxRelay_t);
    virtual void udpateLcp(Ip_Ltng_Chg_Pnematic_Tx_t data);
    virtual void updateBms3(BMS_Values_3_t data);

    void updateDriverIn_tx(DriverInputsTx_t data);
    void updateFuseBoxRelay(FuseboxCtrlTx_t data);

private:
    Screen1Presenter();

    Screen1View& view;
};

#endif // SCREEN1PRESENTER_HPP
