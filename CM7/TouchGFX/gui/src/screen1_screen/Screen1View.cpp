#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View():
	radioButtonSelectedCallback(this, &Screen1View::radioButtonSelectedHandler),
	radioButtonSelectedCallback2(this, &Screen1View::radioButtonSelectedHandler2),
	radioButtonSelectedCallback3(this, &Screen1View::radioButtonSelectedHandler3),
	boxClickedCallback(this, &Screen1View::boxClickHandler)
{
	fuse1Mask = 0;
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

	Unicode::snprintf(testToggleBuffer, TESTTOGGLE_SIZE, "%d", 0);
	testToggle.invalidate(); // CRITICAL: The screen won't change without this!

	radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup2.setRadioButtonSelectedHandler(radioButtonSelectedCallback2);
	radioButtonGroup3.setRadioButtonSelectedHandler(radioButtonSelectedCallback3);

	fbR1_1.setClickAction(boxClickedCallback);
	fbR1_2.setClickAction(boxClickedCallback);
	fbR1_3.setClickAction(boxClickedCallback);
	fbR1_4.setClickAction(boxClickedCallback);
	fbR1_5.setClickAction(boxClickedCallback);
	fbR1_6.setClickAction(boxClickedCallback);
	fbR1_7.setClickAction(boxClickedCallback);
	fbR1_8.setClickAction(boxClickedCallback);
	fbR1_9.setClickAction(boxClickedCallback);
	fbR1_10.setClickAction(boxClickedCallback);
	fbR1_11.setClickAction(boxClickedCallback);
	fbR1_12.setClickAction(boxClickedCallback);
	fbR1_14.setClickAction(boxClickedCallback);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View :: handleTickEvent()
{

}

void Screen1View::boxClickHandler(const Box& b, const ClickEvent& evt)
{
    if (&b == &fbR1_1)
    {
		fuse1Mask |= (1 << 0);
    }

	if (&b == &fbR1_2)
    {
		fuse1Mask |= (1 << 1);
    }

	if (&b == &fbR1_3)
    {
		fuse1Mask |= (1 << 2);
    }

	if (&b == &fbR1_4)
    {
		fuse1Mask |= (1 << 3);
    }

	if (&b == &fbR1_5)
    {
		fuse1Mask |= (1 << 4);
    }

	if (&b == &fbR1_6)
    {
		fuse1Mask |= (1 << 5);
    }

	if (&b == &fbR1_7)
    {
		fuse1Mask |= (1 << 6);
    }

	if (&b == &fbR1_8)
    {
		fuse1Mask |= (1 << 7);
    }

	if (&b == &fbR1_9)
    {
		fuse1Mask |= (1 << 8);
    }

	if (&b == &fbR1_10)
    {
		fuse1Mask |= (1 << 9);
    }

	if (&b == &fbR1_11)
    {
		fuse1Mask |= (1 << 10);
    }

	if (&b == &fbR1_12)
    {
		fuse1Mask |= (1 << 11);
    }

	if (&b == &fbR1_13)
    {
		fuse1Mask |= (1 << 12);
    }

	if (&b == &fbR1_14)
    {
		fuse1Mask |= (1 << 13);
    }

	Unicode::snprintf(testToggleBuffer, TESTTOGGLE_SIZE, "%x", fuse1Mask);
	testToggle.invalidate();
}

void Screen1View::setDefaults(Ip_Ltng_Chg_Pnematic_Tx_t data) {
	defaultData = data;
	lcpt.Override_Request = data.Override_Req;
	lcpt.Drive_Program_Sw = data.Drv_Program_Sw;
	lcpt.Gear_Actuator_Override = data.Gear_Actuator_Override;
	lcpt.DCDC_Request = data.DCDC_Req;
	lcpt.Air_Sus_Level_Control_Override = data.Level_Control_Req;
	lcpt.Low_Beam_Req = data.LowBeam_Req;
	lcpt.High_Beam_Req = data.HighBeam_Req;
	lcpt.Position_Light_Req = data.PosLight_Req;
	lcpt.Interior_Light_Req = data.IntLight_Req;
	lcpt.Chrg_STOP_Req = data.Chrg_STOP_Req;
	lcpt.Chrg_PreCond_Req = data.Chrg_PreCond_Req;
	lcpt.AirCompressor_Req = data.AirCompressor_Req;

	dcdcReq.forceState(lcpt.DCDC_Request);
	dcdcReq.invalidate();
	lowBeamToggle.forceState(lcpt.Low_Beam_Req);
	lowBeamToggle.invalidate();
	highBeamToggle.forceState(lcpt.High_Beam_Req);
	highBeamToggle.invalidate();
	intLightsToggle.forceState(lcpt.Interior_Light_Req);
	intLightsToggle.invalidate();
	posLightsToggle.forceState(lcpt.Position_Light_Req);
	posLightsToggle.invalidate();
	stopChargeReq.forceState(lcpt.Chrg_STOP_Req);
	stopChargeReq.invalidate();
	chargePrecondReq.forceState(lcpt.Chrg_PreCond_Req);
	chargePrecondReq.invalidate();

	if (lcpt.Drive_Program_Sw == 0) {
		driveModeEco.setSelected(true); // update the min value
	} else if (lcpt.Drive_Program_Sw == 1) {
		driveModeSnow.setSelected(true);  // update the max value
	} else if(lcpt.Drive_Program_Sw == 2) {
		driveModeSport.setSelected(true); 
	}

	if (lcpt.Gear_Actuator_Override == 0) {
		gearActNeutral.setSelected(true); // update the min value
	} else if (lcpt.Gear_Actuator_Override == 1) {
		gearActG1.setSelected(true);  // update the max value
	} else if(lcpt.Gear_Actuator_Override == 2) {
		gearActG2.setSelected(true); 
	}

	if (lcpt.Air_Sus_Level_Control_Override == 0) {
		airSusNoReq.setSelected(true); // update the min value
	} else if (lcpt.Air_Sus_Level_Control_Override == 1) {
		airSusL1.setSelected(true);  // update the max value
	} else if(lcpt.Air_Sus_Level_Control_Override == 2) {
		airSusL2.setSelected(true); 
	} else if(lcpt.Air_Sus_Level_Control_Override == 3) {
		airSusL3.setSelected(true); 
	}

	Unicode::snprintf(airPressBuffer1, AIRPRESSBUFFER1_SIZE, "%d", data.MinPressureAir);
	Unicode::snprintf(airPressBuffer2, AIRPRESSBUFFER2_SIZE, "%d", data.MaxPressureAir);
	airPress.invalidate();
}

void Screen1View::showBms3Vals(BMS_Values_3_t data) {
	switch(data.E_Lock_Status) {
		case 0:
			chargingState.setBitmap(BITMAP_CHARGEGUN_OFF_ID);
			break;
		case 1:
			chargingState.setBitmap(BITMAP_CHARGEGUN_ON_ID);
			break;
		case 3:
		default:
			chargingState.setBitmap(BITMAP_CHARGEGUN_FAULT_ID);
			break;
	}
	chargingState.invalidate();
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

void Screen1View::showEpea(ElecSys_Power_Energy_AirComp_t data) {
	Unicode::snprintfFloat(lvCurrentBuffer, LVCURRENT_SIZE, "%.1f", data.LV_Current_Act);
	lvCurrent.invalidate();
	Unicode::snprintfFloat(lvVoltageBuffer, LVVOLTAGE_SIZE, "%.1f", data.LV_Power_Act);
	lvVoltage.invalidate();
	Unicode::snprintf(airCompSpeedBuffer, AIRCOMPSPEED_SIZE, "%d", data.Airc_speed);
	airCompSpeed.invalidate();
	Unicode::snprintf(airCompTracVoltBuffer, AIRCOMPSPEED_SIZE, "%d", data.Airc_traction_voltage);
	airCompTracVolt.invalidate();
	Unicode::snprintfFloat(airCompTrqBuffer, AIRCOMPSPEED_SIZE, "%.1f", data.Airc_torque);
	airCompTrq.invalidate();
	Unicode::snprintfFloat(airCompPwrBuffer, AIRCOMPSPEED_SIZE, "%.1f", data.Airc_power);
	airCompPwr.invalidate();
}

void Screen1View::overrRideReqCallback() {
	lcpt.Override_Request ^= 1;
	presenter->updateDriverIn_tx(lcpt);
	// setDefaults(defaultData);
}
void Screen1View::dcdcReqCallback() {
	if(lcpt.Override_Request) {
		lcpt.DCDC_Request ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		dcdcReq.forceState(defaultData.DCDC_Req);
		dcdcReq.invalidate();
	}
}
void Screen1View::toggleLowBeamCallback() {
	if(lcpt.Override_Request) {
		lcpt.Low_Beam_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		lowBeamToggle.forceState(defaultData.LowBeam_Req);
		lowBeamToggle.invalidate();
	}
}
void Screen1View::toggleHighBeamCallback() {
	if(lcpt.Override_Request) {
		lcpt.High_Beam_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		highBeamToggle.forceState(defaultData.HighBeam_Req);
		highBeamToggle.invalidate();
	}
}
void Screen1View::toggleIntLightsCallback() {
	if(lcpt.Override_Request) {
		lcpt.Interior_Light_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		intLightsToggle.forceState(defaultData.IntLight_Req);
		intLightsToggle.invalidate();
	}
}
void Screen1View::posLightsToggleCallback() {
	if(lcpt.Override_Request) {
		lcpt.Position_Light_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		posLightsToggle.forceState(defaultData.PosLight_Req);
		posLightsToggle.invalidate();
	}
}
void Screen1View::hvHeaterEnableCallback() {
	if(lcpt.Override_Request) {
		lcpt.HVHeater_Enable ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	}
}
void Screen1View::heatPumpReqCallback() {
	if(lcpt.Override_Request) {
		lcpt.HeatPump_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	}
}
void Screen1View::heatFoilReqCallback() {
	if(lcpt.Override_Request) {
		lcpt.HeatFoil_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	}
}
void Screen1View::stopChargeReqCallback() {
	if(lcpt.Override_Request) {
		lcpt.Chrg_STOP_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		stopChargeReq.forceState(defaultData.Chrg_STOP_Req);
		stopChargeReq.invalidate();
	}
}
void Screen1View::precondReqCallback() {
	if(lcpt.Override_Request) {
		lcpt.Chrg_PreCond_Req ^= 1;
		presenter->updateDriverIn_tx(lcpt);
	} else {
		chargePrecondReq.forceState(defaultData.Chrg_PreCond_Req);
		chargePrecondReq.invalidate();
	}
}
void Screen1View::relay1StateToggleCallback() {
	if(lcpt.Override_Request) {
		fbr.box1_req = fuse1Mask;
		presenter->updateFuseBoxRelay(fbr);
	} else {
		relay1Toggle.forceState(fbr.box1_req);
		relay1Toggle.invalidate();
	}
}
void Screen1View::relay2StateToggleCallback() {
	if(lcpt.Override_Request) {
		fbr.box2_req ^= 1;
		presenter->updateFuseBoxRelay(fbr);
	} else {
		relay2Toggle.forceState(fbr.box2_req);
		relay2Toggle.invalidate();
	}
}
void Screen1View::radioButtonSelectedHandler(const AbstractButton& src) {
	uint8_t gearActuatorVal = 0;

	if(lcpt.Override_Request) {
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
}
void Screen1View::radioButtonSelectedHandler2(const AbstractButton& src)
{
	uint8_t driveMode = 0;

	if(lcpt.Override_Request) {
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
}
void Screen1View::radioButtonSelectedHandler3(const AbstractButton& src)
{
	uint8_t airSusLevel = 0;

	if(lcpt.Override_Request) {
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
}

void Screen1View::showBms1_4(BMS_Values_5_t data) {
	Unicode::snprintf(battTempM1MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M1_Temp_max);
	battTempM1Max.invalidate();
	Unicode::snprintf(battTempM1MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M1_Temp_min);
	battTempM1Min.invalidate();
	Unicode::snprintf(battTempM2MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M2_Temp_max);
	battTempM2Max.invalidate();
	Unicode::snprintf(battTempM2MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M2_Temp_min);
	battTempM2Min.invalidate();
	Unicode::snprintf(battTempM3MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M3_Temp_max);
	battTempM3Max.invalidate();
	Unicode::snprintf(battTempM3MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M3_Temp_min);
	battTempM3Min.invalidate();
	Unicode::snprintf(battTempM4MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M4_Temp_max);
	battTempM4Max.invalidate();
	Unicode::snprintf(battTempM4MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M4_Temp_min);
	battTempM4Min.invalidate();
}

void Screen1View::showBms5_8(BMS_Values_6_t data) {
	Unicode::snprintf(battTempM5MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M5_Temp_max);
	battTempM5Max.invalidate();
	Unicode::snprintf(battTempM5MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M5_Temp_min);
	battTempM5Min.invalidate();
	Unicode::snprintf(battTempM6MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M6_Temp_max);
	battTempM6Max.invalidate();
	Unicode::snprintf(battTempM6MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M6_Temp_min);
	battTempM6Min.invalidate();
	Unicode::snprintf(battTempM7MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M7_Temp_max);
	battTempM7Max.invalidate();
	Unicode::snprintf(battTempM7MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M7_Temp_min);
	battTempM7Min.invalidate();
	Unicode::snprintf(battTempM8MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M8_Temp_max);
	battTempM8Max.invalidate();
	Unicode::snprintf(battTempM8MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M8_Temp_min);
	battTempM8Min.invalidate();
}

void Screen1View::showBms9_12(BMS_Values_7_t data) {
	Unicode::snprintf(battTempM9MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M9_Temp_max);
	battTempM9Max.invalidate();
	Unicode::snprintf(battTempM9MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M9_Temp_min);
	battTempM9Min.invalidate();
	Unicode::snprintf(battTempM10MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M10_Temp_max);
	battTempM10Max.invalidate();
	Unicode::snprintf(battTempM10MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M10_Temp_min);
	battTempM10Min.invalidate();
	Unicode::snprintf(battTempM11MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M11_Temp_max);
	battTempM11Max.invalidate();
	Unicode::snprintf(battTempM11MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M11_Temp_min);
	battTempM11Min.invalidate();
	Unicode::snprintf(battTempM12MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M12_Temp_max);
	battTempM12Max.invalidate();
	Unicode::snprintf(battTempM12MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M12_Temp_min);
	battTempM12Min.invalidate();
}

void Screen1View::updateBoxColor(touchgfx::Box& box, uint8_t state) {
    switch(state) {
        case 2: // 10 (Fault) - Amber
            box.setColor(touchgfx::Color::getColorFromRGB(255, 191, 0));
            break;
        case 1: // 01 (On) - Green
            box.setColor(touchgfx::Color::getColorFromRGB(0, 230, 118));
            break;
        case 0: // 00 (Off) - White
        default:
            box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
            break;
    }
    box.invalidate(); // Required to trigger the redraw
}

void Screen1View::showFb1(FuseBox1State_t fb1) {
	updateBoxColor(fb1_1, fb1.fuse1);
	updateBoxColor(fb1_2, fb1.fuse2);
	updateBoxColor(fb1_3, fb1.fuse3);
	updateBoxColor(fb1_4, fb1.fuse4);
	updateBoxColor(fb1_5, fb1.fuse5);
	updateBoxColor(fb1_6, fb1.fuse6);
	updateBoxColor(fb1_7, fb1.fuse7);
	updateBoxColor(fb1_8, fb1.fuse8);
	updateBoxColor(fb1_9, fb1.fuse9);
	updateBoxColor(fb1_10, fb1.fuse10);
	updateBoxColor(fb1_11, fb1.fuse11);
	updateBoxColor(fb1_12, fb1.fuse12);
	updateBoxColor(fb1_13, fb1.fuse13);
	updateBoxColor(fb1_14, fb1.fuse14);
	updateBoxColor(fb1_15, fb1.fuse15);
	updateBoxColor(fb1_16, fb1.fuse16);
	updateBoxColor(fb1_17, fb1.fuse17);
	updateBoxColor(fb1_18, fb1.fuse18);
	updateBoxColor(fb1_19, fb1.fuse19);
	updateBoxColor(fb1_20, fb1.fuse20);
	updateBoxColor(fb1_21, fb1.fuse21);
	updateBoxColor(fb1_22, fb1.fuse22);
	updateBoxColor(fb1_23, fb1.fuse23);
	updateBoxColor(fb1_24, fb1.fuse24);
	updateBoxColor(fb1_25, fb1.fuse25);
	updateBoxColor(fb1_26, fb1.fuse26);
	updateBoxColor(fb1_27, fb1.fuse27);
	updateBoxColor(fb1_28, fb1.fuse28);
}

void Screen1View::showFb2(FuseBox2State_t fb2) {
	updateBoxColor(fb2_1, fb2.fuse1);
	updateBoxColor(fb2_2, fb2.fuse2);
	updateBoxColor(fb2_3, fb2.fuse3);
	updateBoxColor(fb2_4, fb2.fuse4);
	updateBoxColor(fb2_5, fb2.fuse5);
	updateBoxColor(fb2_6, fb2.fuse6);
	updateBoxColor(fb2_7, fb2.fuse7);
	updateBoxColor(fb2_8, fb2.fuse8);
	updateBoxColor(fb2_9, fb2.fuse9);
	updateBoxColor(fb2_10, fb2.fuse10);
	updateBoxColor(fb2_11, fb2.fuse11);
	updateBoxColor(fb2_12, fb2.fuse12);
	updateBoxColor(fb2_13, fb2.fuse13);
	updateBoxColor(fb2_14, fb2.fuse14);
	updateBoxColor(fb2_15, fb2.fuse15);
	updateBoxColor(fb2_16, fb2.fuse16);
	updateBoxColor(fb2_17, fb2.fuse17);
	updateBoxColor(fb2_18, fb2.fuse18);
	updateBoxColor(fb2_19, fb2.fuse19);
	updateBoxColor(fb2_20, fb2.fuse20);
	updateBoxColor(fb2_21, fb2.fuse21);
	updateBoxColor(fb2_22, fb2.fuse22);
	updateBoxColor(fb2_23, fb2.fuse23);
	updateBoxColor(fb2_24, fb2.fuse24);
	updateBoxColor(fb2_25, fb2.fuse25);
	updateBoxColor(fb2_26, fb2.fuse26);
	updateBoxColor(fb2_27, fb2.fuse27);
	updateBoxColor(fb2_28, fb2.fuse28);
}

void Screen1View::showFbR(FuseBoxRelay_t fbr) {
	updateBoxColor(fbR1_1, fbr.fbr1_1);
	updateBoxColor(fbR1_2, fbr.fbr1_2);
	updateBoxColor(fbR1_2, fbr.fbr1_3);
	updateBoxColor(fbR1_3, fbr.fbr1_4);
	updateBoxColor(fbR1_4, fbr.fbr1_5);
	updateBoxColor(fbR1_5, fbr.fbr1_6);
	updateBoxColor(fbR1_6, fbr.fbr1_7);
	updateBoxColor(fbR1_7, fbr.fbr1_8);
	updateBoxColor(fbR1_8, fbr.fbr1_9);
	updateBoxColor(fbR1_9, fbr.fbr1_10);
	updateBoxColor(fbR1_10, fbr.fbr1_11);
	updateBoxColor(fbR1_12, fbr.fbr1_12);
	updateBoxColor(fbR1_13, fbr.fbr1_13);
	updateBoxColor(fbR1_14, fbr.fbr1_14);
	updateBoxColor(fbR2_1, fbr.fbr2_1);
	updateBoxColor(fbR2_2, fbr.fbr2_2);
	updateBoxColor(fbR2_2, fbr.fbr2_3);
	updateBoxColor(fbR2_3, fbr.fbr2_4);
	updateBoxColor(fbR2_4, fbr.fbr2_5);
	updateBoxColor(fbR2_5, fbr.fbr2_6);
	updateBoxColor(fbR2_6, fbr.fbr2_7);
	updateBoxColor(fbR2_7, fbr.fbr2_8);
	updateBoxColor(fbR2_8, fbr.fbr2_9);
	updateBoxColor(fbR2_9, fbr.fbr2_10);
	updateBoxColor(fbR2_10, fbr.fbr2_11);
	updateBoxColor(fbR2_12, fbr.fbr2_12);
	updateBoxColor(fbR2_13, fbr.fbr2_13);
	updateBoxColor(fbR2_14, fbr.fbr2_14);
}

void Screen1View::showBms13_16(BMS_Values_8_t data) {
	Unicode::snprintf(battTempM13MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M13_Temp_max);
	battTempM13Max.invalidate();
	Unicode::snprintf(battTempM13MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M13_Temp_min);
	battTempM13Min.invalidate();
	Unicode::snprintf(battTempM14MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M14_Temp_max);
	battTempM14Max.invalidate();
	Unicode::snprintf(battTempM14MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M14_Temp_min);
	battTempM14Min.invalidate();
	Unicode::snprintf(battTempM15MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M15_Temp_max);
	battTempM15Max.invalidate();
	Unicode::snprintf(battTempM15MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M15_Temp_min);
	battTempM15Min.invalidate();
	Unicode::snprintf(battTempM16MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M16_Temp_max);
	battTempM16Max.invalidate();
	Unicode::snprintf(battTempM16MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M16_Temp_min);
	battTempM16Min.invalidate();
}

void Screen1View::showBms17_20(BMS_Values_9_t data) {
	Unicode::snprintf(battTempM17MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M17_Temp_max);
	battTempM17Max.invalidate();
	Unicode::snprintf(battTempM17MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M17_Temp_min);
	battTempM17Min.invalidate();
	Unicode::snprintf(battTempM18MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M18_Temp_max);
	battTempM18Max.invalidate();
	Unicode::snprintf(battTempM18MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M18_Temp_min);
	battTempM18Min.invalidate();
	Unicode::snprintf(battTempM19MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M19_Temp_max);
	battTempM19Max.invalidate();
	Unicode::snprintf(battTempM19MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M19_Temp_min);
	battTempM19Min.invalidate();
	Unicode::snprintf(battTempM20MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M20_Temp_max);
	battTempM20Max.invalidate();
	Unicode::snprintf(battTempM20MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M20_Temp_min);
	battTempM20Min.invalidate();
}

void Screen1View::showBms21_24(BMS_Values_10_t data) {
	Unicode::snprintf(battTempM21MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M21_Temp_max);
	battTempM21Max.invalidate();
	Unicode::snprintf(battTempM21MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M21_Temp_min);
	battTempM21Min.invalidate();
	Unicode::snprintf(battTempM22MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M22_Temp_max);
	battTempM22Max.invalidate();
	Unicode::snprintf(battTempM22MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M22_Temp_min);
	battTempM22Min.invalidate();
	Unicode::snprintf(battTempM23MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M23_Temp_max);
	battTempM23Max.invalidate();
	Unicode::snprintf(battTempM23MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M23_Temp_min);
	battTempM23Min.invalidate();
	Unicode::snprintf(battTempM24MaxBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M24_Temp_max);
	battTempM24Max.invalidate();
	Unicode::snprintf(battTempM24MinBuffer, BATTTEMPM1MAX_SIZE, "%d", data.BMS_M24_Temp_min);
	battTempM24Min.invalidate();
}