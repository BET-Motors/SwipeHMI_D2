#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "fdcan.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	CAN_Raw_Msg_t rawMsg;

    uint32_t processed = 10; // to avoid a storm of messages, process in frames

    while(processed > 0 &&
        osMessageQueueGet(guiMQHandle, &rawMsg, 0, 0) == osOK) {
        switch(rawMsg.id) {
			case ID_PRESS_HYDRAULIC_LIGHT_POWERTRAIN:
				if(parsePressHydLightPt(rawMsg, &phlp))
					modelListener->updatePressHydLightPt(phlp);
				break;	
			case ID_THERMAL_MANAGEMENT_RX_1:
				if(parseThermal1(rawMsg, &thermal1))
					modelListener->updateThermal1(thermal1);
				break;
			case ID_THERMAL_MANAGEMENT_RX_1:
				if(parseThermal2(rawMsg, &thermal2))
					modelListener->updateThermal2(thermal2);
				break;
			default:
                break;
		}
		processed--;
	}
}

bool Model::parsePressHydLightPt(CAN_Raw_Msg_t rawMsg, Press_Hydraulic_Light_PowerTrain_t *_phlp) {
	uint64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 5);
	if(_phlp->Pres_Susp_Front != rawVal) {
		_phlp->Pres_Susp_Front = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 5, 5);
	if(_phlp->Pres_Susp_Rear != rawVal) {
		_phlp->Pres_Susp_Rear = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 10, 5);
	if(_phlp->Pres_Brk_Front != rawVal) {
		_phlp->Pres_Brk_Front = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 15, 5);
	if(_phlp->Pres_Brk_Rear != rawVal) {
		_phlp->Pres_Brk_Rear = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 20, 1);
	if(_phlp->LowBeam_St != rawVal) {
		_phlp->LowBeam_St = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 21, 1);
	if(_phlp->HighBeam_St != rawVal) {
		_phlp->HighBeam_St = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 22, 1);
	if(_phlp->PosLight_St != rawVal) {
		_phlp->PosLight_St = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 23, 1);
	if(_phlp->IntLight_St != rawVal) {
		_phlp->IntLight_St = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 12);
	rawVal = rawVal -2500;
	if(_phlp->Pwr_Act_MotRM != rawVal) {
		_phlp->Pwr_Act_MotRM = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 36, 12);
	rawVal = rawVal -2500;
	if(_phlp->Pwr_Act_MotFL != rawVal) {
		_phlp->Pwr_Act_MotFL = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 12);
	rawVal = rawVal -2500;
	if(_phlp->Pwr_Act_MotFR != rawVal) {
		_phlp->Pwr_Act_MotFR = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseThermal1(CAN_Raw_Msg_t rawMsg, Thermal_Management_Rx_1_t *_thermal1) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_thermal1->BMS_Pack_Temp_max != rawVal) {
		_thermal1->BMS_Pack_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_thermal1->BMS_Pack_Temp_max != rawVal) {
		_thermal1->BMS_Pack_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_thermal1->Temp_Inv_FL != rawVal) {
		_thermal1->Temp_Inv_FL = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_thermal1->Temp_Inv_FR != rawVal) {
		_thermal1->Temp_Inv_FR = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_thermal1->Temp_Inv_RM != rawVal) {
		_thermal1->Temp_Inv_RM = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_thermal1->Temp_EM_FL != rawVal) {
		_thermal1->Temp_EM_FL = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_thermal1->Temp_EM_FR != rawVal) {
		_thermal1->Temp_EM_FR = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_thermal1->Temp_EM_RM != rawVal) {
		_thermal1->Temp_EM_RM = rawVal;
		changed = true;
	}

	return changed;
}
bool Model::parseThermal2(CAN_Raw_Msg_t rawMsg, Thermal_Management_Rx_2_t *_thermal2) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_thermal2->Temp_Battery != rawVal) {
		_thermal2->Temp_Battery = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_thermal2->Temp_Auxilaries != rawVal) {
		_thermal2->Temp_Auxilaries = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_thermal2->Temp_AIR != rawVal) {
		_thermal2->Temp_AIR = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_thermal2->Temp_Powertrain != rawVal) {
		_thermal2->Temp_Powertrain = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 16);
	if(_thermal2->Rad_Fan_Speed != rawVal) {
		_thermal2->Rad_Fan_Speed = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_thermal2->Temp_DCDC != rawVal) {
		_thermal2->Temp_DCDC = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 46, 8);
	rawVal = rawVal - 50;
	if(_thermal2->Temp_ClntPump != rawVal) {
		_thermal2->Temp_ClntPump = rawVal;
		changed = true;
	}

	return changed;
}