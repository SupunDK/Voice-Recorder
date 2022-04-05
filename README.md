# Voice Recorder

## Product Overview

The Voice Recorder was created using the ATmega328P microcontroller that samples a given sound at 8 kHz frequency and saves them in an SD card in an 8-bit format. The recordings are saved as .wav files, therefore they can be both played by the speakers in the device and by plugging the SD card into a computer or any other supported device. The Voice Recorder has an LCD display for the User Interface and five buttons (Up, Down, Select, Menu) which can be used to navigate through the user interface and initiate recording and playing. The recordings can be played in three different modes. They are,
 
1) Normal Voice - The recording is played back without any spectral changes
2) Alvin Voice - The recording is played at a slightly faster pace and a higher pitch
3) Batman Voice - The recording is played at a slightly slower pace and a lower pitch

<br>

## Product Preview
https://user-images.githubusercontent.com/16956863/161778575-4fdca970-c014-47e3-9d3d-a61ed9c73238.mp4

<br>

## Enclosure Design
<p align="center"><img src="https://user-images.githubusercontent.com/16956863/161778129-7fa4e17f-045b-482a-8bf0-313dc95e12c8.jpeg" width="400" height="400"></p>

<br>

## PCB Design

3D View                    |  Top Layer                | Bottom Layer
:-------------------------:|:-------------------------:|:-------------------------:
<img src="https://user-images.githubusercontent.com/16956863/161779993-4e135e68-3457-47ec-bc12-ed7463440c4b.jpeg" width="300" height="400"> | <img src="https://user-images.githubusercontent.com/16956863/161780456-ea9fc618-a690-4cb2-9c5e-99c8b7a0171b.jpeg" width="300" height="400"> | <img src="https://user-images.githubusercontent.com/16956863/161780442-40b11708-466f-4270-989b-b988bc75d7ac.jpeg" width="300" height="400">

<br>

## Components

- ATmega328P with 16 MHz Crystal Oscillator
- SD Card Module
- 16x2 LCD Display with I2C Module
- MAX4466 Mircophone Module
- MCP4725 DAC Module
- PAM8403 3W Audio Amplifier
- 4Ω 2W Speaker

