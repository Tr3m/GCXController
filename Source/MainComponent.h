/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <fstream>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void buttonClicked(int loopNumber);
    void bypass();
    void viewToggleClicked();
   
   

private:
    //==============================================================================
    Image unitImage = ImageFileFormat::loadFrom(BinaryData::GCX_png, BinaryData::GCX_pngSize);
    

    TextButton loopButton[8];
    TextButton bypassButton;
    juce::TextButton viewToggle;

    bool isOnSimpleView{ false };

    bool loopState[8] = { false };
    int loopCC[8] = { 80, 81, 82, 83, 84, 85, 86, 87 };

    Image led_off = juce::ImageFileFormat::loadFrom(BinaryData::led_off_png, BinaryData::led_off_pngSize);
    Image led_on = juce::ImageFileFormat::loadFrom(BinaryData::led_on_png, BinaryData::led_on_pngSize);

    AudioDeviceManager deviceManager;
    ComboBox midiOutputList;
    Label midiOutputListLabel;
   
    std::unique_ptr<MidiOutput> midiOutput;

    LookAndFeel_V4 lnf1;
    LookAndFeel_V2 lnf2;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
