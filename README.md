# GCX Controller Desktop App

A simple desktop app to control the Voodoo Lab GCX Audio Switcher via MIDI.

![githubScreenshot](https://user-images.githubusercontent.com/58518865/118499943-0bd8c180-b730-11eb-8593-8138b31c44de.png)

![githubScreenshot](https://user-images.githubusercontent.com/58518865/118500022-1b580a80-b730-11eb-9c2f-681e725e834d.png)
Developed with the JUCE C++ Framework.

### Usage
This app requires a MIDI Interface.

WARNING: The PEDAL IN jack on the GCX is not a standard MIDI In. It utilizes the two
normally unused pins to provide 9 volts A.C. power for the Voodoo Lab's Ground Control Unit. Before connecting
to a device other than the Ground Control, you must either use a cable without pins 1 and 3
wired, or verify that the MIDI Out of that device conforms to the MIDI specification which
states that pins 1 and 3 are unconnected. Failure to do so can result in severe damage to your
equipment. For more information consult the [GCX Manual](http://www.midimanuals.com/manuals/digital_music_corp/gcx_audio_switcher/user_manual/gcx_audio_manual.pdf).
