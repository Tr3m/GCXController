# GCX Controller Desktop App

A simple desktop app to control the Voodoo Lab GCX Audio Switcher via MIDI.

![githubScreenshot](https://user-images.githubusercontent.com/58518865/92387528-60965800-f11e-11ea-8729-74215517145e.png)
Developed with the JUCE C++ Framework.

### Usage
This app requires a MIDI Interface.

WARNING: The PEDAL IN jack on the GCX is not a standard MIDI In. It utilizes the two
normally unused pins to provide 9 volts A.C. power for the Voodoo Lab's Ground Control Unit. Before connecting
to a device other than the Ground Control, you must either use a cable without pins 1 and 3
wired, or verify that the MIDI Out of that device conforms to the MIDI specification which
states that pins 1 and 3 are unconnected. Failure to do so can result in severe damage to your
equipment. For more information consult the [GCX Manual](http://www.midimanuals.com/manuals/digital_music_corp/gcx_audio_switcher/user_manual/gcx_audio_manual.pdf).

### Contribute
Feel free to propose changes and/or add features. Future plans include:

* Presets
* Automation

### License

MIT License

Copyright (c) 2020 Manos Labrakis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
