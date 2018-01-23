Ten features from ElDominio (aka Norman Paulino)
---
These features can be tried out all at once in this branch or individually in each their own branch.

Clicking on a link will take you to a branch with only the individual feature and possible dependents.

#### Proposed additions to code which include:
- [Tacho gauge sweeping] on key on (very probably should be flagged as an option, makes car misfire if started while gauge is sweeping)
- [Idle timing control] - allows use of timing to increase torque on RPM drop, and A/C request
  - This is integrated with A/C control
- [A/C control] - allows control of the A/C clutch using an A/C request input, compensates for compressor load through timing and idle valve, has conditions to check for on/off A/C pressure switches, need to add evap temp control too
- reduces [dwell on WOT] to allows better dwell control in idle and cruising, very crude but still worked great
- [simple VVL control] - activates VVL on an output at the set conditions, has a fuel correction for when lift activates
- [CEL control] - CEL lights on at 0RPM, and when TPS is under the minimum ADC or above maximum (not really, I just though about this), and activates at a set RPM to function as a shift light
- [dual fan support] - secondary cooling fan turns on 7 degrees after the main fan
  - This is integrated with A/C control
- [high idle request] - holds idle valve at a given position for some time after RPMs drop to evade engine stalling
- [DFCO wait] - waits for 2 seconds before cutting fuel, for when going in and out of DFCO
- [temp gauge control for XRS] - Loop used in Toyota Corolla XRS to emulate a PWM at 2.4Hz

[Tacho gauge sweeping]: ../../tree/ElDominio-tachsweep
[Idle timing control]: ../../tree/ElDominio-idleadv
[A/C control]: ../../tree/ElDominio-ACCtrl
[dwell on WOT]: ../../tree/ElDominio-WOTdwell
[simple VVL control]: ../../tree/ElDominio-VVLCtrl
[CEL control]: ../../tree/ElDominio-CELCtrl
[dual fan support]: ../../tree/ElDominio-dualfan
[high idle request]: ../../tree/ElDominio-highidlereq
[DFCO wait]: ../../tree/ElDominio-DFCOwait
[temp gauge control for XRS]: ../../tree/ElDominio-XRSgauge

Speeduino
=========

FAQ:
=========

Q: Speeduino, didn't you used to be called something else?

A: Initial aim was for a simple DIY ECU for go-karts and the original project title was kartduino. As it became apparent that we wanted to extend support to larger vehicles, the name became a bit misleading.
The important ideas though remain the same and the priority is still SIMPLICITY! The code is written with simplicity above all else in mind and all areas are well commented. The project can be loaded directly into the Arduino IDE and compiled with only a single additional library needing to be added. Where code is complex or low level, a high level pseudo code example is given to explain what is being performed. 

========================================================================

Q: Arduino ECU,pffft, heard THAT before. Does this one actually work?

A: Yep! 1, 2, 4, 6 and 8 cylinder engines have all run, fuel and ignition, off Speeduino. 

========================================================================

Q: So what can it do?

A: Take a look at this page for details: http://speeduino.com/wiki/index.php/Overview

========================================================================

Q: Target platform?

A: Arduino Mega (Or other ATmega1280 / ATmega2560 powered SKU) will be required. Standard arduino models are not suitable for multi-cylinder engines due to their lack of 16-bit timers. The shield board has been designed around the Mega and it is not expected that there will be a non-Mega variant. 

========================================================================

Q: I'm trying to get started or need some general help. What should I do?

A: Support is all through the forum at: http://speeduino.com/forum

========================================================================

Q: I must know more! How can I contact you?

A: Come and visit the forum : http://speeduino.com/forum

If you still need some more info, feel free to drop me a line: noisymime (AT) gmail (dot) com
