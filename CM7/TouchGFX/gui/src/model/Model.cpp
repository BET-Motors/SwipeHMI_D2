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
					modelListener->updateMtc2(mtc2);
				break;
			case ID_BMS_VALUES_5:
				if(parseBms1_4(rawMsg, &bms1_4))
					modelListener->updateBms1_4(bms1_4);
				break;
			case ID_BMS_VALUES_6:
				if(parseBms5_8(rawMsg, &bms5_8))
					modelListener->updateBms5_8(bms5_8);
				break;
			case ID_BMS_VALUES_7:
				if(parseBms9_12(rawMsg, &bms9_12))
					modelListener->updateBms9_12(bms9_12);
				break;
			case ID_BMS_VALUES_8:
				if(parseBms13_16(rawMsg, &bms13_16))
					modelListener->updateBms13_16(bms13_16);
				break;
			case ID_BMS_VALUES_9:
				if(parseBms17_20(rawMsg, &bms17_20))
					modelListener->updateBms17_20(bms17_20);
				break;
			case ID_BMS_VALUES_10:
				if(parseBms21_24(rawMsg, &bms21_24))
					modelListener->updateBms21_24(bms21_24);
				break;
			case ID_ELECSYS_POWER_ENERGY_AIRCOMP:
				if(parseEpea(rawMsg, &epea))
					modelListener->updateEpea(epea);
				break;
			case ID_FUSEBOX1:
				if(parseFb1(rawMsg, &fuseBox1))
					modelListener->updateFb1State(fuseBox1);
				break;
			case ID_FUSEBOX2:
				if(parseFb2(rawMsg, &fuseBox2))
					modelListener->updateFb2State(fuseBox2);
				break;
			case ID_FUSEBOXRELAY:
				if(parseFbR(rawMsg, &fbr))
					modelListener->updateFbR(fbr);
				break;
			case ID_IP_LTNG_CHG_PNEMATIC_TX:
				if(parseLcp(rawMsg, &lcp))
					modelListener->udpateLcp(lcp);
				break;
			case ID_BMS_VALUES_3:
				if(parseBms3(rawMsg, &bms3))
					modelListener->updateBms3(bms3);
				break;
			default:
                break;
		}
		processed--;
	}
}

bool Model::parseBms3(CAN_Raw_Msg_t rawMsg, BMS_Values_3_t *_bms) {
	uint64_t rawVal;
    bool changed = false;

	rawVal = UnpackSignal(rawMsg.data, 33, 3);
	if(_bms->E_Lock_Status != rawVal) {
		_bms->E_Lock_Status = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseLcp(CAN_Raw_Msg_t rawMsg, Ip_Ltng_Chg_Pnematic_Tx_t *_lcp) {
	uint64_t rawVal;
    bool changed = false;

	rawVal = UnpackSignal(rawMsg.data, 0, 3);
	if(_lcp->Drv_Program_Sw != rawVal) {
		_lcp->Drv_Program_Sw = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 3, 1);
	if(_lcp->Override_Req != rawVal) {
		_lcp->Override_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 4, 3);
	if(_lcp->Gear_Actuator_Override != rawVal) {
		_lcp->Gear_Actuator_Override = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 7, 4);
	if(_lcp->Level_Control_Req != rawVal) {
		_lcp->Level_Control_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 11, 1);
	if(_lcp->DCDC_Req != rawVal) {
		_lcp->DCDC_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 12, 1);
	if(_lcp->LowBeam_Req != rawVal) {
		_lcp->LowBeam_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 13, 1);
	if(_lcp->HighBeam_Req != rawVal) {
		_lcp->HighBeam_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 14, 1);
	if(_lcp->PosLight_Req != rawVal) {
		_lcp->PosLight_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 15, 1);
	if(_lcp->IntLight_Req != rawVal) {
		_lcp->IntLight_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 1);
	if(_lcp->Chrg_STOP_Req != rawVal) {
		_lcp->Chrg_STOP_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 17, 1);
	if(_lcp->Chrg_PreCond_Req != rawVal) {
		_lcp->Chrg_PreCond_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 18, 1);
	if(_lcp->AirCompressor_Req != rawVal) {
		_lcp->AirCompressor_Req = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 19, 5);
	if(_lcp->MinPressureAir != rawVal) {
		_lcp->MinPressureAir = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	if(_lcp->MaxPressureAir != rawVal) {
		_lcp->MaxPressureAir = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 32);
	if(_lcp->RefSpdSens_Speed != rawVal) {
		_lcp->RefSpdSens_Speed = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseFbR(CAN_Raw_Msg_t rawMsg, FuseBoxRelay_t *_fbr) {
	uint64_t rawVal;
    bool changed = false;

	rawVal = UnpackSignal(rawMsg.data, 0, 2);
	if(_fbr->fbr1_1 != rawVal) {
		_fbr->fbr1_1 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 2, 2);
	if(_fbr->fbr1_2 != rawVal) {
		_fbr->fbr1_2 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 4, 2);
	if(_fbr->fbr1_3 != rawVal) {
		_fbr->fbr1_3 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 6, 2);
	if(_fbr->fbr1_4 != rawVal) {
		_fbr->fbr1_4 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 8, 2);
	if(_fbr->fbr1_5 != rawVal) {
		_fbr->fbr1_5 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 10, 2);
	if(_fbr->fbr1_6 != rawVal) {
		_fbr->fbr1_6 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 12, 2);
	if(_fbr->fbr1_7 != rawVal) {
		_fbr->fbr1_7 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 14, 2);
	if(_fbr->fbr1_8 != rawVal) {
		_fbr->fbr1_8 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 16, 2);
	if(_fbr->fbr1_9 != rawVal) {
		_fbr->fbr1_9 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 18, 2);
	if(_fbr->fbr1_10 != rawVal) {
		_fbr->fbr1_10 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 20, 2);
	if(_fbr->fbr1_11 != rawVal) {
		_fbr->fbr1_11 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 22, 2);
	if(_fbr->fbr1_12 != rawVal) {
		_fbr->fbr1_12 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 24, 2);
	if(_fbr->fbr1_13 != rawVal) {
		_fbr->fbr1_13 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 26, 2);
	if(_fbr->fbr1_14 != rawVal) {
		_fbr->fbr1_14 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 28, 2);
	if(_fbr->fbr2_1 != rawVal) {
		_fbr->fbr2_1 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 30, 2);
	if(_fbr->fbr2_2 != rawVal) {
		_fbr->fbr2_2 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 32, 2);
	if(_fbr->fbr2_3 != rawVal) {
		_fbr->fbr2_3 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 34, 2);
	if(_fbr->fbr2_4 != rawVal) {
		_fbr->fbr2_4 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 36, 2);
	if(_fbr->fbr2_5 != rawVal) {
		_fbr->fbr2_5 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 38, 2);
	if(_fbr->fbr2_6 != rawVal) {
		_fbr->fbr2_6 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 40, 2);
	if(_fbr->fbr2_7 != rawVal) {
		_fbr->fbr2_7 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 42, 2);
	if(_fbr->fbr2_8 != rawVal) {
		_fbr->fbr2_8 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 44, 2);
	if(_fbr->fbr2_9 != rawVal) {
		_fbr->fbr2_9 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 46, 2);
	if(_fbr->fbr2_10 != rawVal) {
		_fbr->fbr2_10 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 48, 2);
	if(_fbr->fbr2_11 != rawVal) {
		_fbr->fbr2_11 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 50, 2);
	if(_fbr->fbr2_12 != rawVal) {
		_fbr->fbr2_12 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 52, 2);
	if(_fbr->fbr2_13 != rawVal) {
		_fbr->fbr2_13 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 54, 2);
	if(_fbr->fbr2_14 != rawVal) {
		_fbr->fbr2_14 = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseFb1(CAN_Raw_Msg_t rawMsg, FuseBox1State_t *_fb1) {
	uint64_t rawVal;
    bool changed = false;

	rawVal = UnpackSignal(rawMsg.data, 0, 2);
	if(_fb1->fuse1 != rawVal) {
		_fb1->fuse1 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 2, 2);
	if(_fb1->fuse2 != rawVal) {
		_fb1->fuse2 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 4, 2);
	if(_fb1->fuse3 != rawVal) {
		_fb1->fuse3 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 6, 2);
	if(_fb1->fuse4 != rawVal) {
		_fb1->fuse4 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 8, 2);
	if(_fb1->fuse5 != rawVal) {
		_fb1->fuse5 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 10, 2);
	if(_fb1->fuse6 != rawVal) {
		_fb1->fuse6 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 12, 2);
	if(_fb1->fuse7 != rawVal) {
		_fb1->fuse7 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 14, 2);
	if(_fb1->fuse8 != rawVal) {
		_fb1->fuse8 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 16, 2);
	if(_fb1->fuse9 != rawVal) {
		_fb1->fuse9 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 18, 2);
	if(_fb1->fuse10 != rawVal) {
		_fb1->fuse10 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 20, 2);
	if(_fb1->fuse11 != rawVal) {
		_fb1->fuse11 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 22, 2);
	if(_fb1->fuse12 != rawVal) {
		_fb1->fuse12 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 24, 2);
	if(_fb1->fuse13 != rawVal) {
		_fb1->fuse13 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 26, 2);
	if(_fb1->fuse14 != rawVal) {
		_fb1->fuse14 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 28, 2);
	if(_fb1->fuse15 != rawVal) {
		_fb1->fuse15 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 30, 2);
	if(_fb1->fuse16 != rawVal) {
		_fb1->fuse16 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 32, 2);
	if(_fb1->fuse17 != rawVal) {
		_fb1->fuse17 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 34, 2);
	if(_fb1->fuse18 != rawVal) {
		_fb1->fuse18 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 36, 2);
	if(_fb1->fuse19 != rawVal) {
		_fb1->fuse19 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 38, 2);
	if(_fb1->fuse20 != rawVal) {
		_fb1->fuse20 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 40, 2);
	if(_fb1->fuse21 != rawVal) {
		_fb1->fuse21 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 42, 2);
	if(_fb1->fuse22 != rawVal) {
		_fb1->fuse22 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 44, 2);
	if(_fb1->fuse23 != rawVal) {
		_fb1->fuse23 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 46, 2);
	if(_fb1->fuse24 != rawVal) {
		_fb1->fuse24 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 48, 2);
	if(_fb1->fuse25 != rawVal) {
		_fb1->fuse25 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 50, 2);
	if(_fb1->fuse26 != rawVal) {
		_fb1->fuse26 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 52, 2);
	if(_fb1->fuse27 != rawVal) {
		_fb1->fuse27 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 54, 2);
	if(_fb1->fuse28 != rawVal) {
		_fb1->fuse28 = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseFb2(CAN_Raw_Msg_t rawMsg, FuseBox2State_t *_fb2) {
	uint64_t rawVal;
    bool changed = false;

	rawVal = UnpackSignal(rawMsg.data, 0, 2);
	if(_fb2->fuse1 != rawVal) {
		_fb2->fuse1 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 2, 2);
	if(_fb2->fuse2 != rawVal) {
		_fb2->fuse2 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 4, 2);
	if(_fb2->fuse3 != rawVal) {
		_fb2->fuse3 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 6, 2);
	if(_fb2->fuse4 != rawVal) {
		_fb2->fuse4 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 8, 2);
	if(_fb2->fuse5 != rawVal) {
		_fb2->fuse5 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 10, 2);
	if(_fb2->fuse6 != rawVal) {
		_fb2->fuse6 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 12, 2);
	if(_fb2->fuse7 != rawVal) {
		_fb2->fuse7 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 14, 2);
	if(_fb2->fuse8 != rawVal) {
		_fb2->fuse8 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 16, 2);
	if(_fb2->fuse9 != rawVal) {
		_fb2->fuse9 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 18, 2);
	if(_fb2->fuse10 != rawVal) {
		_fb2->fuse10 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 20, 2);
	if(_fb2->fuse11 != rawVal) {
		_fb2->fuse11 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 22, 2);
	if(_fb2->fuse12 != rawVal) {
		_fb2->fuse12 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 24, 2);
	if(_fb2->fuse13 != rawVal) {
		_fb2->fuse13 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 26, 2);
	if(_fb2->fuse14 != rawVal) {
		_fb2->fuse14 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 28, 2);
	if(_fb2->fuse15 != rawVal) {
		_fb2->fuse15 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 30, 2);
	if(_fb2->fuse16 != rawVal) {
		_fb2->fuse16 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 32, 2);
	if(_fb2->fuse17 != rawVal) {
		_fb2->fuse17 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 34, 2);
	if(_fb2->fuse18 != rawVal) {
		_fb2->fuse18 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 36, 2);
	if(_fb2->fuse19 != rawVal) {
		_fb2->fuse19 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 38, 2);
	if(_fb2->fuse20 != rawVal) {
		_fb2->fuse20 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 40, 2);
	if(_fb2->fuse21 != rawVal) {
		_fb2->fuse21 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 42, 2);
	if(_fb2->fuse22 != rawVal) {
		_fb2->fuse22 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 44, 2);
	if(_fb2->fuse23 != rawVal) {
		_fb2->fuse23 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 46, 2);
	if(_fb2->fuse24 != rawVal) {
		_fb2->fuse24 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 48, 2);
	if(_fb2->fuse25 != rawVal) {
		_fb2->fuse25 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 50, 2);
	if(_fb2->fuse26 != rawVal) {
		_fb2->fuse26 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 52, 2);
	if(_fb2->fuse27 != rawVal) {
		_fb2->fuse27 = rawVal;
		changed = true;
	}
	rawVal = UnpackSignal(rawMsg.data, 54, 2);
	if(_fb2->fuse28 != rawVal) {
		_fb2->fuse28 = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseEpea(CAN_Raw_Msg_t rawMsg, ElecSys_Power_Energy_AirComp_t *_epea) {
	uint64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 9);
	rawVal = rawVal - 200;
	if(_epea->LV_Current_Act != rawVal) {
		_epea->LV_Current_Act = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 9, 9);
	rawVal = rawVal - 200;
	if(_epea->LV_Power_Act != rawVal) {
		_epea->LV_Power_Act = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 18, 16);
	if(_epea->Airc_speed != rawVal) {
		_epea->Airc_speed = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 34, 10);
	if(_epea->Airc_traction_voltage != rawVal) {
		_epea->Airc_traction_voltage = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 44, 10);
    rawFloat = ((float)rawVal * 0.1f);
    if(fabs(_epea->Airc_torque - rawFloat) > 0.1f) {
        _epea->Airc_torque = rawFloat;
        changed = true;
    }

	rawVal = UnpackSignal(rawMsg.data, 54, 8);
    rawFloat = ((float)rawVal * 0.1f);
    if(fabs(_epea->Airc_power - rawFloat) > 0.1f) {
        _epea->Airc_power = rawFloat;
        changed = true;
    }
	return changed;
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
	rawVal = rawVal - 2500;
	if(_phlp->Pwr_Act_MotRM != rawVal) {
		_phlp->Pwr_Act_MotRM = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 36, 12);
	rawVal = rawVal - 2500;
	if(_phlp->Pwr_Act_MotFL != rawVal) {
		_phlp->Pwr_Act_MotFL = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 12);
	rawVal = rawVal - 2500;
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
	if(_bms->BMS_M1_Temp_min != rawVal) {
		_bms->BMS_M1_Temp_min = rawVal;
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
	if(_bms->BMS_M9_Temp_min != rawVal) {
		_bms->BMS_M9_Temp_min = rawVal;
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
	if(_bms->BMS_M17_Temp_max != rawVal) {
		_bms->BMS_M17_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M17_Temp_max != rawVal) {
		_bms->BMS_M17_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M18_Temp_max != rawVal) {
		_bms->BMS_M18_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M18_Temp_min != rawVal) {
		_bms->BMS_M18_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M19_Temp_max != rawVal) {
		_bms->BMS_M19_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M19_Temp_min != rawVal) {
		_bms->BMS_M19_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M20_Temp_max!= rawVal) {
		_bms->BMS_M20_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M20_Temp_min != rawVal) {
		_bms->BMS_M20_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}

bool Model::parseBms21_24(CAN_Raw_Msg_t rawMsg, BMS_Values_10_t *_bms) {
	int64_t rawVal;
    bool changed = false;
    float rawFloat;

	rawVal = UnpackSignal(rawMsg.data, 0, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M21_Temp_max != rawVal) {
		_bms->BMS_M21_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 8, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M21_Temp_min != rawVal) {
		_bms->BMS_M21_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 16, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M22_Temp_max != rawVal) {
		_bms->BMS_M22_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 24, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M22_Temp_min != rawVal) {
		_bms->BMS_M22_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 32, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M23_Temp_max != rawVal) {
		_bms->BMS_M23_Temp_max = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 40, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M23_Temp_min != rawVal) {
		_bms->BMS_M23_Temp_min = rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 48, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M24_Temp_max!= rawVal) {
		_bms->BMS_M24_Temp_max= rawVal;
		changed = true;
	}

	rawVal = UnpackSignal(rawMsg.data, 56, 8);
	rawVal = rawVal - 50;
	if(_bms->BMS_M24_Temp_min != rawVal) {
		_bms->BMS_M24_Temp_min = rawVal;
		changed = true;
	}

	return changed;
}

void Model::updateDriverIn(DriverInputsTx_t data) {
	updateDriverInputs(data);
}

void Model::updateFuseBoxControl(FuseboxCtrlTx_t data) {
	updateFuseBoxRelayControl(data);
}