#ifndef MODEL_HPP
#define MODEL_HPP

#include "stdint.h"
#include "fdcan.h"

class ModelListener;

class Model
{
private:
    Press_Hydraulic_Light_PowerTrain_t phlp;
    Thermal_Management_Rx_1_t thermal1;
    Thermal_Management_Rx_2_t thermal2;
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
    // bool parseDriverInput1(CAN_Raw_Msg_t, DriverInputAndVehicleControl_t *);
    bool parsePressHydLightPt(CAN_Raw_Msg_t, Press_Hydraulic_Light_PowerTrain_t *);
    bool parseThermal1(CAN_Raw_Msg_t, Thermal_Management_Rx_1_t *);
    bool parseThermal2(CAN_Raw_Msg_t, Thermal_Management_Rx_2_t *);
};

#endif // MODEL_HPP
