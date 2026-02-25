#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include "fdcan.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    // virtual void updateDriverControls(DriverInputAndVehicleControl_t data) {}
    virtual void updatePressHydLightPt(Press_Hydraulic_Light_PowerTrain_t data) {}
    virtual void updateThermal1(Thermal_Management_Rx_1_t data) {}
    virtual void updateThermal2(Thermal_Management_Rx_2_t data) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
