#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
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

	if(phlp.HighBeam_St) {
		lowHighBeam.setBitmap(BITMAP_HIGHBEAM_ID);
	} else if(phlp.LowBeam_St) {
		lowHighBeam.setBitmap(BITMAP_LOWBEAM_ID);
	} else {
		lowHighBeam.setBitmap(BITMAP_HEADLIGHTSINACTIVE_ID);
	}

	lowHighBeam.invalidate();

	if(phlp.PosLight_St) {
		posLight.setBitmap(BITMAP_POSLIGHTSACTIVE_ID);
		
	} else {
		posLight.setBitmap(BITMAP_POSLIGHTSINACTIVE_ID);
	}

	posLight.invalidate();

	if(phlp.IntLight_St) {
		intLight.setBitmap(BITMAP_INTLIGHTACTIVE_ID);
	} else {
		intLight.setBitmap(BITMAP_INTLIGHTINACTIVE_ID);
	}
	intLight.invalidate();
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
	/* typedef struct {
    int16_t Temp_Battery;
    int16_t Temp_Auxilaries;
    int16_t Temp_AIR;
    int16_t Temp_Powertrain;
    uint16_t Rad_Fan_Speed;
    int16_t Temp_DCDC;
    int16_t Temp_ClntPump;
} Thermal_Management_Rx_2_t; */
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