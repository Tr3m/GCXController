/*
  ==============================================================================

    myLookAndFeel.h
    Created: 7 Sep 2020 1:22:18pm
    Author:  Manos

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
//==============================================================================

class myLookAndFeel : public LookAndFeel_V4
{
public:
	myLookAndFeel();
    void drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown);

   

private:
    Image buttonOn, buttonOff;
};