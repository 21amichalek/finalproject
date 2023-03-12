# ECE-218 Final Design Project
## Integrated Entertainment System

#### by Team Triple A (Austin Gregory, Abigail Michalek, Ashley Pontillo)

Submitted on 03/11/23

Summary of Behavior
-------------------
The integrated entertainment system is the future of party entertainment! Lighting and music are brought together in an all-in-one, personalizable system. This system allows for party customization through the use of multiple party modes. The modes will be chosen by the user and can be further customized to fit the specific vibe of the party. The user can personalize the party by choosing different colored lights, strobe intensity, and sounds. If the party needs to be paused for any reason, there is a single input that stops all activities.

The three different party modes are chosen through the serial monitor. The user can select from the following options by pressing the corresponding number key on their computer keyboard:
#### Mode 1: Chill ----- single colored customizable lighting
#### Mode 2: Party ----- slow flashing multiple colored lighting
#### Mode 3: Rave ------- fast flashing multiple colored lighting and customizable music

Once the mode has been chosen, the user can further customize the party by selecting keys on the matrix keypad to select colors of lighting and songs, when applicable. Each key on the keypad corresponds with a color of lighting or song. Seven different colors and four songs can be chosen. The comprehensive instructions of this correspondence can be read through the serial monitor. The lighting colors and song choices are shown below with their associated key on the matrix keypad:

#### Colors
- Red --> 1
- Yellow --> 2
- Green --> 3
- Blue --> 4
- Indigo --> 5
- Purple --> 6
- White --> 7

#### Songs
- 1: Hot Cross Buns --> A
- 2: Twinkle Twinkle Little Star --> B
- 3: Happy Birthday --> C
- 4: Mary Had a Little Lamb --> D

The customization selections the user makes will be shown on the LCD display. The mode, lighting colors, and song number will be displayed.

To stop all party performances, the user can use their hand to inhibit light on the LDR sensor. All lighting and music will turn off. When the user wants to resume the party, they can release their hand, and the party will resume.

Code Modules
------------
Each module in the system's code implements a different part of the behavior. The modules are described below:
#### Entertainment System --- modified textbook Smart Home System module
This module manages the functionality of all the subsystems.

#### Party Features --- written from scratch
This module controls the distinct party modes of the system by implementing their behaviors.
  
#### User Interface --- modified textbook User Interface module
This module manages the user interface through controlling the lighting, music, and input received from the matrix keypad and serial communication.
  
#### PC Serial Communication --- modified textbook PC Serial Communication module
This module manages the communication with the PC through sending / receiving data.

#### Lighting --- written from scratch
This module drives the light implemented by an RGB LED.
    
#### Music --- written from scratch
This module drives the songs played by a passive buzzer.
    
#### LDR Sensor --- based on textbook LDR Sensor module
This module reads the output given by a LDR sensor.
   
#### Display --- based on textbook Display module
This module writes data on the LCD display.
    
#### Matrix Keypad --- modified textbook Matrix Keypad module
This module reads the keys pressed on the matrix keypad.

Hardware Components
-------------------
The hardware this system requires and the pin connections are shown in the schematic below.
![Hardware Schematic](https://lh3.googleusercontent.com/kEasagN08I37e5mX_3HTPFbunfxhqe9EgBodsjEhgqVYuyBt04OjoYGvARiIrNsAxBQx2bYkxcrl-uSowxyZJbQ8Qk8oaPN85uCqph3TpQ)
*The LEDs in the schematic are facing the wrong direction*

Each component shown in the schematic is listed below, along with their corresponding pin connections to the NUCLEO board:
#### - 4x4 Matrix Keypad
  - R1 --> PB_3
  - R2 --> PB_5
  - R3 --> PC_7
  - R4 --> PA_15
  - C1 --> PB_12
  - C2 --> PB_13
  - C3 --> PB_15
  - C4 --> PC_6
#### - 16x2 LCD Display
  - VSS --> GND
  - VDD --> 5V
  - VO --> 10K Trimpot Potentiometer (5V and GND)
  - RS --> D8
  - RW --> GND
  - E --> D9
  - D0 --> D0
  - D1 --> D1
  - D2 --> D2
  - D3 --> D3
  - D4 --> D4
  - D5 --> D5
  - D6 --> D7
  - A --> 1k resistor --> 5V
  - K --> GND
#### - RGB LED
  - Red --> 150 resistor --> PB_4
  - Green --> 150 resistor --> PA_0
  - Blue --> 130 resistor --> PD_12
  - GND --> GND
#### - Passive Buzzer
  - positive --> 5V
  - negative --> PB_11
#### - LDR Sensor
  - positive --> 3.3V
  - negative --> A2 and 10k resistor --> GND
#### - Serial Monitor
  - connected through UART communication

Tests Performed
---------------
WRITE LATER
A description of the tests you performed on the system, and the results.

Other Details
-------------
The music modules uses varying frequncies to change the sound output of the buzzer. Each freuqueny is assigned to a variable representing the note it should resemble. The notes we use were found in a github .h file used where the purpose of their project is to have a buzzer play different songs through aurduino. We only used their frequency values for the notes and did utilie and other functions or libraries. 

Link to .h file with notes: https://github.com/bhagman/Tone/blob/master/Tone.h
