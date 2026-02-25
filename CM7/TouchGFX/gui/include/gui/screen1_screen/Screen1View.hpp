#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <images/BitmapDatabase.hpp>
#include "fdcan.h"

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    // void showGearSelect(uint8_t prndState);
    void showPressHydLightPt(Press_Hydraulic_Light_PowerTrain_t);
    void showThermal1(Thermal_Management_Rx_1_t);
    void showThermal2(Thermal_Management_Rx_2_t);
protected:
	/* uint8_t steeringToggleVal;
	uint8_t airCompToggleVal;
	uint8_t heaterToggleVal;
	uint8_t dcdcToggleVal;
	uint8_t auxToggleVal;
	uint8_t selectHysterisis;
	uint16_t airCompMinDefaultVal;
	uint16_t airCompMaxDefaultVal;

	void radioButtonSelectedHandler(const AbstractButton& src);

	touchgfx::Callback<Screen1View, const touchgfx::Slider&, int> sliderValueConfirmedCallback;
	touchgfx::Callback<Screen1View, const touchgfx::Slider&, int> sliderValueChangedCallback;
	touchgfx::Callback<Screen1View, const AbstractButton&> radioButtonSelectedCallback; */
	/*
	 * Callback Handler Declarations
	 */
	/* void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
	void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value); */
};

#endif // SCREEN1VIEW_HPP
