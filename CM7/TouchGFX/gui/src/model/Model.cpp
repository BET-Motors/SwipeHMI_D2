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
			case ID_THERMAL_MANAGEMENT_RX_2:
				if(parseThermal2(rawMsg, &thermal2))
					modelListener->updateThermal2(thermal2);
				break;
			case ID_MOTOR_AND_TORQUE_CONTROL_1:
				if(parsemtc1(rawMsg, &mtc1))
					modelListener->updateMtc1(mtc1);
				break;
			case ID_MOTOR_AND_TORQUE_CONTROL_2:
				if(parsemtc2(rawMsg, &mtc2))
					modelListener->updateMtc2(mtc1);
				break;
			case ID_BMS_VALUES_5:
				if(parseBms1_4(rawMsg, &bms1_4))
					modelListener->updateBms1_4(bms1_4);
				break;
			case ID_BMS_VALUES_6:
				if(parseBms1_4(rawMsg, &bms5_8))
					modelListener->updateBms5_8(bms5_8);
				break;
			case ID_BMS_VALUES_7:
				if(parseBms1_4(rawMsg, &bms9_12))
					modelListener->updateBms9_12(bms9_12);
				break;
			case ID_BMS_VALUES_8:
				if(parseBms1_4(rawMsg, &bms13_16))
					modelListener->updateBms13_16(bms13_16);
				break;
			case ID_BMS_VALUES_9:
				if(parseBms1_4(rawMsg, &bms17_20))
					modelListener->updateBms17_20(bms17_20);
				break;
			case ID_BMS_VALUES_10:
				if(parseBms1_4(rawMsg, &bms21_24))
					modelListener->updateBms21_24(bms21_24);
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

bool Model::parsemtc1(CAN_Raw_Msg_t rawMsg, Motor_And_Torque_Control_1_t *_mtc) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Act_Wheel_FL != rawVal) {
		_mtc->Trq_Req_Wheel_FL = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Req_Wheel_FL != rawVal) {
		_mtc->Trq_Req_Wheel_FL = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Act_Wheel_FR != rawVal) {
		_mtc->Trq_Act_Wheel_FR = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Req_Wheel_FR != rawVal) {
		_mtc->Trq_Req_Wheel_FR = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parsemtc2(CAN_Raw_Msg_t rawMsg, Motor_And_Torque_Control_2_t *_mtc) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Act_Wheel_RM != rawVal) {
		_mtc->Trq_Act_Wheel_RM = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Req_Wheel_RM != rawVal) {
		_mtc->Trq_Req_Wheel_RM = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 16);
	rawVal = rawVal - 2500;
	if(_mtc->Pwr_Disp != rawVal) {
		_mtc->Pwr_Disp = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 16);
	rawVal = rawVal - 5000;
	if(_mtc->Trq_Act_Sys != rawVal) {
		_mtc->Trq_Act_Sys = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseBms1_4(CAN_Raw_Msg_t rawMsg, BMS_Values_5_t *_bms) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M1_Temp_max != rawVal) {
		_bms->BMS_M1_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M1_Temp_max != rawVal) {
		_bms->BMS_M1_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M2_Temp_max != rawVal) {
		_bms->BMS_M2_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M2_Temp_min != rawVal) {
		_bms->BMS_M2_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M3_Temp_max != rawVal) {
		_bms->BMS_M3_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M3_Temp_min != rawVal) {
		_bms->BMS_M3_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M4_Temp_max!= rawVal) {
		_bms->BMS_M4_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M4_Temp_min != rawVal) {
		_bms->BMS_M4_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseBms5_8(CAN_Raw_Msg_t rawMsg, BMS_Values_6_t *_bms) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M5_Temp_max != rawVal) {
		_bms->BMS_M5_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M5_Temp_max != rawVal) {
		_bms->BMS_M5_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M6_Temp_max != rawVal) {
		_bms->BMS_M6_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M6_Temp_min != rawVal) {
		_bms->BMS_M6_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M7_Temp_max != rawVal) {
		_bms->BMS_M7_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M7_Temp_min != rawVal) {
		_bms->BMS_M7_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M8_Temp_max!= rawVal) {
		_bms->BMS_M8_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M8_Temp_min != rawVal) {
		_bms->BMS_M8_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseBms9_12(CAN_Raw_Msg_t rawMsg, BMS_Values_7_t *_bms) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M9_Temp_max != rawVal) {
		_bms->BMS_M9_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M9_Temp_max != rawVal) {
		_bms->BMS_M9_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M10_Temp_max != rawVal) {
		_bms->BMS_M10_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M10_Temp_min != rawVal) {
		_bms->BMS_M10_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M11_Temp_max != rawVal) {
		_bms->BMS_M11_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M11_Temp_min != rawVal) {
		_bms->BMS_M11_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M12_Temp_max!= rawVal) {
		_bms->BMS_M12_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M12_Temp_min != rawVal) {
		_bms->BMS_M12_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseBms13_16(CAN_Raw_Msg_t rawMsg, BMS_Values_8_t *_bms) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M13_Temp_max != rawVal) {
		_bms->BMS_M13_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M13_Temp_max != rawVal) {
		_bms->BMS_M13_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M14_Temp_max != rawVal) {
		_bms->BMS_M14_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M14_Temp_min != rawVal) {
		_bms->BMS_M14_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M15_Temp_max != rawVal) {
		_bms->BMS_M15_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M15_Temp_min != rawVal) {
		_bms->BMS_M15_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M16_Temp_max!= rawVal) {
		_bms->BMS_M16_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M16_Temp_min != rawVal) {
		_bms->BMS_M16_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseBms17_20(CAN_Raw_Msg_t rawMsg, BMS_Values_9_t *_bms) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M13_Temp_max != rawVal) {
		_bms->BMS_M13_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M13_Temp_max != rawVal) {
		_bms->BMS_M13_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M14_Temp_max != rawVal) {
		_bms->BMS_M14_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M14_Temp_min != rawVal) {
		_bms->BMS_M14_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M15_Temp_max != rawVal) {
		_bms->BMS_M15_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M15_Temp_min != rawVal) {
		_bms->BMS_M15_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M16_Temp_max!= rawVal) {
		_bms->BMS_M16_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M16_Temp_min != rawVal) {
		_bms->BMS_M16_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}