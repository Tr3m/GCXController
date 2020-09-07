/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize(1200, 300);

    addAndMakeVisible(midiOutputListLabel);
    midiOutputListLabel.setText("MIDI Device:", juce::dontSendNotification);
    midiOutputListLabel.attachToComponent(&midiOutputList, true);
    midiOutputListLabel.setAlpha(0.6f);

    lnf1.setColour(PopupMenu::backgroundColourId, Colours::grey.withAlpha(0.6f));
    addAndMakeVisible(midiOutputList);
    midiOutputList.setTextWhenNoChoicesAvailable("No MIDI Outputs Enabled");
    midiOutputList.setLookAndFeel(&lnf1);
    midiOutputList.setColour(ComboBox::backgroundColourId, Colours::grey.withAlpha(0.1f));
    midiOutputList.setColour(ComboBox::outlineColourId, Colours::grey.withAlpha(0.4f));
    midiOutputList.setColour(ComboBox::textColourId, Colours::green.withAlpha(1.0f));
    auto midiInputs = juce::MidiOutput::getAvailableDevices();

    StringArray midiInputNames;

    for (auto input : midiInputs)
        midiInputNames.add(input.name);

    midiOutputList.addItemList(midiInputNames, 1);
    midiOutputList.onChange = [this] { midiOutput = MidiOutput::openDevice(midiOutputList.getSelectedItemIndex()); };

    // find the first enabled device and use that by default
    for (auto input : midiInputs)
    {
        if (deviceManager.isMidiInputDeviceEnabled(input.identifier))
        {
            midiOutput = MidiOutput::openDevice(midiInputs.indexOf(input));
            break;
        }
    }

    // if no enabled devices were found just use the first one in the list
    if (midiOutputList.getSelectedId() == 0)
        midiOutput = MidiOutput::openDevice(0);

 
    for (int i = 0; i < 8; i++) {
        addAndMakeVisible(&loopButton[i]);
        loopButton[i].setColour(TextButton::ColourIds::buttonColourId, Colours::red);
        loopButton[i].setAlpha(0.3f);
        loopButton[i].setLookAndFeel(&myLnf);
        
        
    }

    addAndMakeVisible(&bypassButton);
    bypassButton.setButtonText("Bypass");
    bypassButton.setColour(TextButton::ColourIds::buttonColourId, Colours::darkgrey);
    bypassButton.setColour(TextButton::ColourIds::textColourOffId, Colours::white.withAlpha(1.0f));
    bypassButton.setAlpha(0.5f);
    bypassButton.setLookAndFeel(&lnf2);
    bypassButton.onClick = [this] {bypass();};

    loopButton[0].onClick = [this] {buttonClicked(0);};
    loopButton[1].onClick = [this] {buttonClicked(1);};
    loopButton[2].onClick = [this] {buttonClicked(2);};
    loopButton[3].onClick = [this] {buttonClicked(3);};
    loopButton[4].onClick = [this] {buttonClicked(4);};
    loopButton[5].onClick = [this] {buttonClicked(5);};
    loopButton[6].onClick = [this] {buttonClicked(6);};
    loopButton[7].onClick = [this] {buttonClicked(7);};

    loopButton[0].setLookAndFeel(&myLnf);
   
}

MainComponent::~MainComponent()
{
}

//TextButton& button, bool& loopState

void MainComponent::buttonClicked(int loopNumber)
{
    TextButton& button = loopButton[loopNumber];
    bool& isLoopOn = loopState[loopNumber];

    if (isLoopOn) {
        button.setAlpha(0.3f);
        isLoopOn = false;
        midiOutput->sendMessageNow(MidiMessage::controllerEvent(16, loopNumber + 80, 0));
    }
    else {
       button.setAlpha(0.8f);        
        isLoopOn = true;
        midiOutput->sendMessageNow(MidiMessage::controllerEvent(16, loopNumber + 80, 127));
    }
}

void MainComponent::bypass()
{
    for (int i = 0; i < 8; i++)
    {
        TextButton& button = loopButton[i];
        bool& isLoopOn = loopState[i];

        button.setAlpha(0.3f);
        isLoopOn = false;
        midiOutput->sendMessageNow(MidiMessage::controllerEvent(16, i+80, 0));
    }
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{

    g.fillAll(Colours::darkslateblue);
    g.drawImageAt(unitImage, 0, 0);
    g.setFont (Font (16.0f));
    g.setColour (Colours::white);

    
}

void MainComponent::resized()
{
    loopButton[0].setBounds(679, 158, 17, 25);
    loopButton[1].setBounds(710, 158, 17, 25);
    loopButton[2].setBounds(740, 158, 17, 25);
    loopButton[3].setBounds(771, 158, 17, 25);
    loopButton[4].setBounds(801, 158, 17, 25);
    loopButton[5].setBounds(830, 158, 17, 25);
    loopButton[6].setBounds(861, 158, 17, 25);
    loopButton[7].setBounds(891, 158, 17, 25);

    bypassButton.setBounds(950, 138, 70, 30);

    midiOutputList.setBounds(270, 138, 220, 30);
    
}
