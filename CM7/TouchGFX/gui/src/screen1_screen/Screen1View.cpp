#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View():
	radioButtonSelectedCallback(this, &Screen1View::radioButtonSelectedHandler),
	radioButtonSelectedCallback2(this, &Screen1View::radioButtonSelectedHandler2),
	radioButtonSelectedCallback3(this, &Screen1View::radioButtonSelectedHandler3)
{
	
}

void Screen1View::setupScreen()
{
	Screen1ViewBase::setupScreen();
	Unicode::snprintf(susFBuffer, SUSF_SIZE, "%d", 0);
	susF.invalidate();

	Unicode::snprintf(susRBuffer, SUSR_SIZE, "%d", 0);
	susR.invalidate();

	Unicode::snprintf(brkPresFBuffer, BRKPRESF_SIZE, "%d", 0);
	brkPresF.invalidate();

	Unicode::snprintf(brkPresRBuffer, BRKPRESR_SIZE, "%d", 0);
	brkPresR.invalidate();

	radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup2.setRadioButtonSelectedHandler(radioButtonSelectedCallback2);
	radioButtonGroup3.setRadioButtonSelectedHandler(radioButtonSelectedCallback3);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View :: handleTickEvent()
{

}

void Screen1View::showPressHydLightPt(Press_Hydraulic_Light_PowerTrain_t phlp) {
	Unicode::snprintf(susFBuffer, SUSF_SIZE, "%d", phlp.Pres_Susp_Front);
	susF.invalidate();

	Unicode::snprintf(susRBuffer, SUSR_SIZE, "%d", phlp.Pres_Susp_Rear);
	susR.invalidate();

	Unicode::snprintf(brkPresFBuffer, BRKPRESF_SIZE, "%d", phlp.Pres_Brk_Front);
	brkPresF.invalidate();

	Unicode::snprintf(brkPresRBuffer, BRKPRESR_SIZE, "%d", phlp.Pres_Brk_Rear);
	brkPresR.invalidate();
}

void Screen1View::showThermal1(Thermal_Management_Rx_1_t thermal1) {
	Unicode::snprintf(thermalEmFlBuffer, THERMALEMFL_SIZE, "%d", thermal1.Temp_EM_FL);
	thermalEmFl.invalidate();

	Unicode::snprintf(thermalEmFrBuffer, THERMALEMFL_SIZE, "%d", thermal1.Temp_Inv_FR);
	thermalEmFr.invalidate();

	Unicode::snprintf(thermalEmRmBuffer, THERMALEMFL_SIZE, "%d", thermal1.Temp_EM_RM);
	thermalEmRm.invalidate();

	Unicode::snprintf(thermalInvFlBuffer, THERMALEMFL_SIZE, "%d", thermal1.Temp_Inv_FL);
	thermalInvFl.invalidate();

	Unicode::snprintf(thermalInvFrBuffer, THERMALEMFL_SIZE, "%d", thermal1.Temp_Inv_FR);
	thermalInvFr.invalidate();

	Unicode::snprintf(thermalInvRmBuffer, THERMALEMFL_SIZE, "%d", thermal1.Temp_EM_RM);
	thermalInvRm.invalidate();
}

void Screen1View::showThermal2(Thermal_Management_Rx_2_t thermal2) {
	Unicode::snprintf(thermalHvBuffer, THERMALEMFL_SIZE, "%d", thermal2.Temp_Battery);
	thermalHv.invalidate();

	Unicode::snprintf(thermalClntPmpBuffer, THERMALEMFL_SIZE, "%d", thermal2.Temp_ClntPump);
	thermalClntPmp.invalidate();

	Unicode::snprintf(thermalRadFanBuffer, THERMALEMFL_SIZE, "%d", thermal2.Rad_Fan_Speed);
	thermalRadFan.invalidate();

	Unicode::snprintf(thermaldcdcBuffer, THERMALEMFL_SIZE, "%d", thermal2.Temp_DCDC);
	thermaldcdc.invalidate();

	/* Unicode::snprintf(thermalInvFrBuffer, THERMALEMFL_SIZE, "%d", thermal2.Temp_Inv_FR);
	thermalInvFr.invalidate();

	Unicode::snprintf(thermalInvRmBuffer, THERMALEMFL_SIZE, "%d", thermal2.Temp_EM_RM);
	thermalInvRm.invalidate(); */

	/* TODO: MAP THE REMAINIG SIGNALS*/
}

void Screen1View::showMtc1(Motor_And_Torque_Control_1_t mtc1) {
	Unicode::snprintf(drvTrnStatTrqReqFlBuffer, DRVTRNSTATEMFL_SIZE, "%d", mtc1.Trq_Act_Wheel_FL);
	drvTrnStatTrqReqFl.invalidate();

	Unicode::snprintf(drvTrnStatTrqActFlBuffer, DRVTRNSTATEMRM_SIZE, "%d", mtc1.Trq_Req_Wheel_FL);
	drvTrnStatTrqActFl.invalidate();

	Unicode::snprintf(drvTrnStatTrqReqFrBuffer, DRVTRNSTATTRQREQFR_SIZE, "%d", mtc1.Trq_Req_Wheel_FR);
	drvTrnStatTrqReqFr.invalidate();

	Unicode::snprintf(drvTrnStatTrqActFrBuffer, DRVTRNSTATTRQACTFR_SIZE, "%d", mtc1.Trq_Act_Wheel_FR);
	drvTrnStatTrqActFr.invalidate();
}

void Screen1View::showMtc2(Motor_And_Torque_Control_2_t mtc2) {
	Unicode::snprintf(drvTrnStatTrqActRmBuffer, DRVTRNSTATTRQACTRM_SIZE, "%d", mtc2.Trq_Act_Wheel_RM);
	drvTrnStatTrqActRm.invalidate();

	Unicode::snprintf(drvTrnStatTrqReqRmBuffer, DRVTRNSTATTRQREQRM_SIZE, "%d", mtc2.Trq_Req_Wheel_RM);
	drvTrnStatTrqReqRm.invalidate();
}

void Screen1View::overrRideReqCallback() {
	lcpt.Override_Request ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::dcdcReqCallback() {
	lcpt.DCDC_Request ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::toggleLowBeamCallback() {
	lcpt.Low_Beam_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::toggleHighBeamCallback() {
	lcpt.High_Beam_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::toggleIntLightsCallback() {
	lcpt.Interior_Light_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::posLightsToggleCallback() {
	lcpt.Position_Light_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::airSusControlCallback() {
	lcpt.Air_Sus_Level_Control_Override ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::hvHeaterEnableCallback() {
	lcpt.HVHeater_Enable ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::heatPumpReqCallback() {
	lcpt.HeatPump_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::heatFoilReqCallback() {
	lcpt.HeatFoil_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::stopChargeReqCallback() {
	lcpt.Chrg_STOP_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::precondReqCallback() {
	lcpt.Chrg_PreCond_Req ^= 1;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::relayFb1Callback() {
}
void Screen1View::relayFb2Callback() {
}
void Screen1View::radioButtonSelectedHandler(const AbstractButton& src)
{
	uint8_t gearActuatorVal = 0;

    if (&src == &gearActG1) {
    	gearActuatorVal = 1; // update the min value
    } else if (&src == &gearActG2) {
    	gearActuatorVal = 2; // update the max value
    } else if(&src == &gearActNeutral) {
		gearActuatorVal = 0;
	}

	lcpt.Gear_Actuator_Override = gearActuatorVal;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::radioButtonSelectedHandler2(const AbstractButton& src)
{
	uint8_t driveMode = 0;

    if (&src == &driveModeEco) {
    	driveMode = 0; // update the min value
    } else if (&src == &driveModeSnow) {
    	driveMode = 2; // update the max value
    } else if(&src == &driveModeSport) {
		driveMode = 1;
	}

	lcpt.Drive_Program_Sw = driveMode;
	presenter->updateDriverIn_tx(lcpt);
}
void Screen1View::radioButtonSelectedHandler3(const AbstractButton& src)
{
	uint8_t airSusLevel = 0;

    if (&src == &airSusNoReq) {
    	airSusLevel = 0; // update the min value
    } else if (&src == &airSusL1) {
    	airSusLevel = 1; // update the max value
    } else if(&src == &airSusL2) {
		airSusLevel = 2;
	} else if(&src == &airSusL3) {
		airSusLevel = 3;
	}

	lcpt.Air_Sus_Level_Control_Override = airSusLevel;
	presenter->updateDriverIn_tx(lcpt);
}