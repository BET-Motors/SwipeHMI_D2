#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <images/BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>
#include "fdcan.h"

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    void showPressHydLightPt(Press_Hydraulic_Light_PowerTrain_t);
    void showThermal1(Thermal_Management_Rx_1_t);
    void showThermal2(Thermal_Management_Rx_2_t);
	void showMtc1(Motor_And_Torque_Control_1_t);
	void showMtc2(Motor_And_Torque_Control_2_t);
	void showBms1_4(BMS_Values_5_t);
	void showBms5_8(BMS_Values_6_t);
	void showBms9_12(BMS_Values_7_t);
	void showBms13_16(BMS_Values_8_t);
	void showBms17_20(BMS_Values_9_t);
	void showBms21_24(BMS_Values_10_t);
	void showEpea(ElecSys_Power_Energy_AirComp_t);
	void showFb1(FuseBox1State_t);
	void showFb2(FuseBox2State_t);
	void showFbR(FuseBoxRelay_t);

	void overrRideReqCallback();
	void dcdcReqCallback();
	void toggleLowBeamCallback();
	void toggleHighBeamCallback();
	void toggleIntLightsCallback();
	void posLightsToggleCallback();
	void airSusControlCallback();
	void hvHeaterEnableCallback();
	void heatPumpReqCallback();
	void heatFoilReqCallback();
	void stopChargeReqCallback();
	void precondReqCallback();
	void relay1StateToggleCallback();
	void relay2StateToggleCallback();

protected:
	DriverInputsTx_t lcpt;
	FuseboxCtrlTx_t fbr;
	void radioButtonSelectedHandler(const AbstractButton& src);
	touchgfx::Callback<Screen1View, const AbstractButton&> radioButtonSelectedCallback;
	void radioButtonSelectedHandler2(const AbstractButton& src);
	touchgfx::Callback<Screen1View, const AbstractButton&> radioButtonSelectedCallback2;
	void radioButtonSelectedHandler3(const AbstractButton& src);
	touchgfx::Callback<Screen1View, const AbstractButton&> radioButtonSelectedCallback3;
	void updateBoxColor(touchgfx::Box& box, uint8_t state);
};

#endif // SCREEN1VIEW_HPP
