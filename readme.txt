-------------------------------------------------------------------------------
Step Sequencer
-------------------------------------------------------------------------------

Requirements
------------
Tool: ModusToolbox™ IDE
Programming Language: C


Supported Kits
--------------
PSoC 6 BLE Pioneer Kit


Overview
--------
In this code implemented sound sequencer with 4 different patterns and 
16 steps. This project use CapSense slider, buttons and E-INK display
to provide user interface which used to set up DMA descriptors and to  
set and enable DAC clock. Audio output use array of chained in loop 
DMA descriptors used for transfer data directly to DAC which triggers 
them after every update. Software driven peripheral clock triggers DAC 
to update value. DAC uses OpAmp as buffer, and connected directly to 
analog output pin.

