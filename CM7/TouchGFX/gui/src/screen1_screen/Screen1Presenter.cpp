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