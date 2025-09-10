This is a sketch for the octopus project there

https://www.pcbway.com/project/shareproject/Build_a_Walking_Robot_Theo_Jansen_Style_3D_Printed_Octopod_41bd8bdb.html

This is a custom board based on Arduino Uno R3 coupled with a L293D
motor shield.

An IR transceiver is connected to the pin #12.

IRremote library should be <= 2.6.0 as they changed the interface
greatly later.  To install it from the comman line, run

```arduino-cli lib install "IRremote@2.6.0"```
