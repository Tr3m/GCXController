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
    midiOutputListLabel.setAlwaysOnTop(true);

    lnf1.setColour(PopupMenu::backgroundColourId, Colours::grey.withAlpha(0.6f));
    addAndMakeVisible(midiOutputList);
    midiOutputList.setTextWhenNoChoicesAvailable("No MIDI Outputs Enabled");
    midiOutputList.setLookAndFeel(&lnf1);
    midiOutputList.setColour(ComboBox::backgroundColourId, Colours::grey.withAlpha(0.1f));
    midiOutputList.setColour(ComboBox::outlineColourId, Colours::grey.withAlpha(0.4f));
    midiOutputList.setColour(ComboBox::textColourId, Colours::green.withAlpha(1.0f));
    midiOutputList.setAlwaysOnTop(true);
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
        loopButton[i].setAlpha(0.0f);
        loopButton[i].setLookAndFeel(&lnf1);
        loopButton[i].setAlwaysOnTop(true);

    }

    addAndMakeVisible(&viewToggle);
    viewToggle.setButtonText("Label View");
    viewToggle.setColour(TextButton::ColourIds::buttonColourId, Colours::darkgrey);
    viewToggle.setColour(TextButton::ColourIds::textColourOffId, Colours::white.withAlpha(1.0f));
    viewToggle.setAlpha(0.5f);
    viewToggle.setLookAndFeel(&lnf2);
    viewToggle.onClick = [this] {viewToggleClicked();};
    viewToggle.setAlwaysOnTop(true);

    addAndMakeVisible(&bypassButton);
    bypassButton.setButtonText("Bypass");
    bypassButton.setColour(TextButton::ColourIds::buttonColourId, Colours::darkgrey);
    bypassButton.setColour(TextButton::ColourIds::textColourOffId, Colours::white.withAlpha(1.0f));
    bypassButton.setAlpha(0.5f);
    bypassButton.setLookAndFeel(&lnf2);
    bypassButton.setAlwaysOnTop(true);
    bypassButton.onClick = [this] {bypass();};

    loopButton[0].onClick = [this] {buttonClicked(0);};
    loopButton[1].onClick = [this] {buttonClicked(1);};
    loopButton[2].onClick = [this] {buttonClicked(2);};
    loopButton[3].onClick = [this] {buttonClicked(3);};
    loopButton[4].onClick = [this] {buttonClicked(4);};
    loopButton[5].onClick = [this] {buttonClicked(5);};
    loopButton[6].onClick = [this] {buttonClicked(6);};
    loopButton[7].onClick = [this] {buttonClicked(7);};  
      
}

MainComponent::~MainComponent()
{
}



void MainComponent::buttonClicked(int loopNumber)
{
    TextButton& button = loopButton[loopNumber];
    bool& isLoopOn = loopState[loopNumber];

    if (isLoopOn) {
        if(isOnSimpleView)
            button.setAlpha(0.3f);
        isLoopOn = false;
        midiOutput->sendMessageNow(MidiMessage::controllerEvent(16, loopNumber + 80, 0));
    }
    else {
        if (isOnSimpleView)
            button.setAlpha(0.8f);        
        isLoopOn = true;
        midiOutput->sendMessageNow(MidiMessage::controllerEvent(16, loopNumber + 80, 127));
    }

    repaint();
}

void MainComponent::bypass()
{
    for (int i = 0; i < 8; i++)
    {
        TextButton& button = loopButton[i];
        bool& isLoopOn = loopState[i];

        isLoopOn = false;
        midiOutput->sendMessageNow(MidiMessage::controllerEvent(16, i+80, 0));
        repaint();
    }
}

void MainComponent::viewToggleClicked()
{
    if (!isOnSimpleView)
    {
        setSize(800, 485);
        isOnSimpleView = true;
        midiOutputList.setBounds(180, 10, 220, 30);
        bypassButton.setBounds(420, 10, 70, 30);
        viewToggle.setButtonText("Back");

        std::string line;

        std::ifstream ifs("loops.txt");
        //std::ifstream ifs("../../../../../loops.txt");
       
       
        for (int i = 0; i < 8; i++) {
            addAndMakeVisible(&loopButton[i]);
            loopButton[i].setColour(TextButton::ColourIds::buttonColourId, Colours::red);
            loopButton[i].setAlpha(0.3f);
            loopButton[i].setLookAndFeel(&lnf1);
            getline(ifs, line);
            loopButton[i].setButtonText(line);
            
        }
                        
        for (int i = 0; i <= 3; ++i)
        {
            loopButton[i].setBounds(i * 200, 50, 200, 200);
            bool& isLoopOn = loopState[i];

            if (isLoopOn) 
                loopButton[i].setAlpha(0.8f);                
            else 
                loopButton[i].setAlpha(0.3f);                            
        }
            

        for (int i = 0; i <= 3; ++i)
        {
            loopButton[i + 4].setBounds(i * 200, 250, 200, 200);
            bool& isLoopOn = loopState[i+4];

            if (isLoopOn)
                loopButton[i+4].setAlpha(0.8f);
            else
                loopButton[i+4].setAlpha(0.3f);
        }

        ifs.close();
        repaint();
    }
    else
    {
        setSize(1200, 300);
        isOnSimpleView = false;
        viewToggle.setButtonText("Label View");

        for (int i = 0; i < 8; i++) {
            addAndMakeVisible(&loopButton[i]);
            loopButton[i].setColour(TextButton::ColourIds::buttonColourId, Colours::red);
            loopButton[i].setAlpha(0.3f);
            loopButton[i].setLookAndFeel(&lnf1);
            loopButton[i].setButtonText("");
        }

        for (int i = 0; i <= 3; ++i)
        {
            bool& isLoopOn = loopState[i];

            loopButton[i].setAlpha(0.0f);
            
        }


        for (int i = 0; i <= 3; ++i)
        {
            bool& isLoopOn = loopState[i + 4];
            
            loopButton[i + 4].setAlpha(0.0f);
           
        }

  

        resized();
        repaint();
        
    }
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll(Colours::darkslateblue);

    int initialY = 146;
    int initialX = 0;


    
    if(!isOnSimpleView)
        g.drawImageAt(unitImage, 0, 0);
    g.setFont (Font (16.0f));
    g.setColour (Colours::white);

    if (!isOnSimpleView)
    {
        for (int loop = 0; loop <= 7; ++loop)
        {
            if (loopState[loop])
            {
                if (loop == 0)
                {
                    initialX = 675;
                    g.drawImageAt(led_on, 673, initialY);
                }
                else
                {
                    if(loop < 3)
                        g.drawImageAt(led_on, initialX - 1, initialY);
                    else
                        g.drawImageAt(led_on, initialX, initialY);
                }
            }
            else
            {
                if (loop == 0)
                {
                    initialX = 675;
                    g.drawImageAt(led_off, 673, initialY);
                }
                else
                    if (loop < 3)
                        g.drawImageAt(led_off, initialX - 1, initialY);
                    else
                        g.drawImageAt(led_off, initialX, initialY);
            }

            initialX = initialX + 30;
        }        
    }

    g.setOpacity(0.7);
    g.setFont(15.0);
    g.drawText("Version 1.5", 0, getHeight() - 30, getWidth(), 20, juce::Justification::centred);
}

void MainComponent::resized()
{
    loopButton[0].setBounds(679, 158, 17, 17);
    loopButton[1].setBounds(710, 158, 17, 17);
    loopButton[2].setBounds(740, 158, 17, 17);
    loopButton[3].setBounds(771, 158, 17, 17);
    loopButton[4].setBounds(801, 158, 17, 17);
    loopButton[5].setBounds(830, 158, 17, 17);
    loopButton[6].setBounds(861, 158, 17, 17);
    loopButton[7].setBounds(891, 158, 17, 17);

    bypassButton.setBounds(950, 138, 70, 30);
    viewToggle.setBounds(10, 10, 70, 30);

    midiOutputList.setBounds(270, 138, 220, 30);
    
}
