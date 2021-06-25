# GCX Controller Desktop App

A simple desktop app to control the Voodoo Lab GCX Audio Switcher via MIDI.


<p align="center">
<img src="https://user-images.githubusercontent.com/58518865/123427465-55d58280-d5cd-11eb-898e-1f16ee0606e1.png"/>
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/58518865/123427469-5706af80-d5cd-11eb-88f3-22f37bdd126b.png"/>
</p>

Developed using the JUCE C++ Framework.

### Usage
This app requires a MIDI Interface.

WARNING: The PEDAL IN jack on the GCX is not a standard MIDI In. It utilizes the two
normally unused pins to provide 9 volts A.C. power for the Voodoo Lab's Ground Control Unit. Before connecting
to a device other than the Ground Control, you must either use a cable without pins 1 and 3
wired, or verify that the MIDI Out of that device conforms to the MIDI specification which
states that pins 1 and 3 are unconnected. Failure to do so can result in severe damage to your
equipment. For more information consult the [GCX Manual](http://www.midimanuals.com/manuals/digital_music_corp/gcx_audio_switcher/user_manual/gcx_audio_manual.pdf).
