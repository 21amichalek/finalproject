# finalproject
Integrated Entertainment System
by Team Triple A (Austin Gregory, Abigail Michalek, Ashley Pontillo)
Submitted on 03/10/23

Summary of Behavior
-------------------
The integrated entertainment system is the future of party entertainment! Lighting and music are brought together in an all-in-one personalizable system. This system allows for party customization through the use of multiple party modes. The modes will be chosen by the user and can be further customized to fit the specific vibe of the party. The user can personalize the party by choosing different colored lights, strobe intensity, and sounds. If the party needs to be paused for any reason, there is a single input that stops all activities.

The three different party modes are chosen through the serial monitor. The use can select from the following options by pressing the corresponding number key on their computer keyboard:
Mode 1: Chill ----- single colored lighting
Mode 2: Party ----- slow flashing multiple colored lighting
Mode 3: Rave ------- fast flashing multiple colored lighting and music

Once the mode has been chosen, the user can further customize the party by selecting keys on the matrix keypad to select colors of lighting and songs when applicable. Each key on the keypad corresponds with a color of lighting or song. The comphehensive instructions of this correpsondance can be read through the serial monitor.

To stop all party performances, the user can use their hand to inhibit light on the LDR sensor. All lighting and music will turn off. When the user wants to resume the party, they can release their hand and the party will resume.

Code Modules
------------
Each module in the system's code implements a different part of the behavior. The modules are described below:
Entertainment System --- modified textbook Smart Home System module

This module manages the functionality of all the subsystems.
      
Party Features --- written from scratch

This module controls the distinct party modes of the system by implementing their behaviors.
  
User Interface --- modified textbook User Interface module

This module manages the user interface through controlling the lighting, music, and input           recieved from the matrix keypad and serial communication.
  
PC Serial Communication --- modified textbook PC Serial Communication module

This module manages the communication with the PC through sending / receiving data.

Lighting --- written from scratch

This module drives the light implemented by a RGB LED.
  
Music --- written from scratch

This module drives the songs played by a passive buzzer.
  
LDR Sensor --- based on textbook LDR Sensor module

This module reads the output given by a LDR sensor.
  
Display --- based on textbook Display module

This module writes data on the LCD display.
  
Matrix Keypad --- modified textbook Matrix Keypad module

This module reads the keys pressed on the matrix keypad.

Hardware Components
-------------------

Tests Performed
---------------

Other Details
-------------
