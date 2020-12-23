# Interactive-Story-Boxes
This repository documents and details the development and creation of interactive story boxes for Factum lab ASBL. 

# The Concept
These interactive story boxes where designed and produced for two projects for Factum lab ASBL :
1) 'Les Botiers Sauvages' for Montenegro LAB Season 2; and
2) 'La Decolonisation dans l'espace public' for the Anderlecht local government. 

With both of these projects, the story boxes where designed to deliver WAV files of people's stories and spoken content should someone come within a distance threshold of the boxes. 
These boxes where conceived to enable 'hands off' interaction through the use of a distance threshold and as such be COVID-friendly interactive projects. 

# Interactive Design & Set-Up
These story boxes are based upon the same software and scripts, with tweaked hardware based upon the use-case. 
The scripts for these story boxes are contained within this repository. 
These two scripts are :
1) An Arduino script ("sonar_player.ino"), for use in conjunction with a HC-SR04 Ultrasound sensor. 
This script calculates distance based upon the Ultrasound readings. Should a certain minimum distance be read with the distance_mm variable, the Arduino shall print "PLAY" as serial. This PLAY serial message shall be read via the serial port "ttyUSB0" on the USB attached Raspberry Pi. </br>
For both projects with Factum lab, an Arduino nano was used with the Ultrasound sensor being read on digital pins 5 & 6.     

2) A SuperCollider script ("BoitiersSonores_InteractiveSystem.scd") designed for use with the Arduino SMS Quark on the Prynth OS. To use this SuperCollider script it is assumed that this set-up has been configured on a Raspberry Pi. 
To install Prynth, you should use the Prynth resources pertaining exclusively to the Rapsberry Pi : https://prynth.github.io/ </br>
Once Prynth is booted and started on your Raspberry Pi and you are connected to an internet connection, you should install the Arduino SMS quark with the following commands within the Prynth IDE : </br>
  Quarks().update ; </br>
  Quarks("Arduino").install ; </br>
Finally, place this prepared Supercollider script into the boot file, upload your WAV file, and address your newly uploaded WAV file within the included script.
You should configure this script as the default boot file for the Prynth by updated the file path for the default.scd Prynth file within the IDE.</br> 
For Factum lab's projects, the Raspberry Pi 3A+ was used.

# The Hardware
Beyond the HC-SR04, Arduino Nano, and Raspberry Pi 3A+ there remaining hardware elements pertained to sound and power. 
Below is a hardware explanation for each project for which these interactive sound boxes where produced, which both had different sound and power choices.
## Les Boitiers Sauvages
For this project, given it was to take place outdoors in the unpredictable belgian weather, the hardware sound choices centered around creating maximum sound volume whilst also protecting the sound emitter and housed electronics. For this reason a 5W surface transducer was chosen, attached to a 5V-5W mono amplifier. The advantage of this approach was the absence of a physical membrane within the sound system, often a vector for inefficencies and too poorly protected for the outside environment.
The amplifier was attached to the Raspberry Pi through a standard mono mini-jack, with the Alsa Mixer settings set to maximum volume. </br>
Given that this project took place in the public space, the system for each Interactive Box was powered through a large Li-Ion power bank. These power banks where sufficient for continous powering throughout the festival weekend. A 5V solar panel was included on each box to prolong the charge life of each system.  

## La Decolonisation dans l'espace public
This project took place in an indoor exhibition space with the opportunity for constant power provision. This informed the different hardware choices. Due to the reduced power constraints and absent weather risk a more traditional speaker and amplifier system was chosen. A TDA7297 amp running 15V - 25W output was chosen, along with a membraned 25W coaxial speaker. This speaker became an integral aesthetic design element for this series of interactive boxes. A mono mini-jack contrinued to be used to connect together the Raspberry Pi and amplifier.
In terms of power supply, these interactive boxes had two seperately powered elements, the 5V powered Raspberry Pi (with daisy-chained Arduino and Ultrasound sensor) and the 15V amplifier power supply. 


# Credits
The interactive system for these Interactive Story Boxes was designed and built by Thomas Desai for Factum lab ASBL, some elements of the interactive system is built upon existing frameworks, code snippets etc.
