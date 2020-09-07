/*
  ==============================================================================

    myLookAndFeel.cpp
    Created: 7 Sep 2020 1:22:18pm
    Author:  Manos

  ==============================================================================
*/

#include "myLookAndFeel.h"
//==============================================================================

myLookAndFeel::myLookAndFeel()
{
    buttonOn = ImageFileFormat::loadFrom(BinaryData::Button_png, BinaryData::Button_pngSize);
}


void myLookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour, bool isMouseOverButton, bool isButtonDown)
{
    auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                                          .withMultipliedAlpha      (button.isEnabled() ? 0.9f : 0.5f);

        if (isButtonDown || isMouseOverButton)
            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);

        auto width  = button.getWidth()  - 1.0f;
        auto height = button.getHeight() - 1.0f;

        if (width > 0 && height > 0)
        {
            g.drawImage(buttonOn, 0, 0, width, height, 0, 0, width, height, false);
        }
}