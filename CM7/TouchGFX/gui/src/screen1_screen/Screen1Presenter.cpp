#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

/*  */

void Screen1Presenter::updatePressHydLightPt(Press_Hydraulic_Light_PowerTrain_t data) {
	view.showPressHydLightPt(data);
}

void Screen1Presenter::updateThermal1(Thermal_Management_Rx_1_t data) {
	view.showThermal1(data);
}

void Screen1Presenter::updateThermal2(Thermal_Management_Rx_2_t data) {
	view.showThermal2(data);
}

void Screen1Presenter::updateMtc1(Motor_And_Torque_Control_1_t data) {
	view.showMtc1(data);
}

void Screen1Presenter::updateMtc2(Motor_And_Torque_Control_2_t data) {
	view.showMtc2(data);
}

void Screen1Presenter::updateEpea(ElecSys_Power_Energy_AirComp_t data) {
	view.showEpea(data);
}

void Screen1Presenter::updateDriverIn_tx(DriverInputsTx_t data) {
	model->updateDriverIn(data);
}
void Screen1Presenter::updateFuseBoxRelay(FuseboxCtrlTx_t data) {
	model->updateFuseBoxControl(data);
}
void Screen1Presenter::updateBms1_4(BMS_Values_5_t data) {
	view.showBms1_4(data);
}
void Screen1Presenter::updateBms5_8(BMS_Values_6_t data) {
	view.showBms5_8(data);
}
void Screen1Presenter::updateBms9_12(BMS_Values_7_t data) {
	view.showBms9_12(data);
}
void Screen1Presenter::updateBms13_16(BMS_Values_8_t data) {
	view.showBms13_16(data);
}
void Screen1Presenter::updateFb1State(FuseBox1State_t data) {
	view.showFb1(data);
}
void Screen1Presenter::updateFb2State(FuseBox2State_t data) {
	view.showFb2(data);
}
void Screen1Presenter::updateFbR(FuseBoxRelay_t data) {
	view.showFbR(data);
}
void Screen1Presenter::updateBms17_20(BMS_Values_9_t data) {}
void Screen1Presenter::updateBms21_24(BMS_Values_10_t data) {}