# Smart Temperature and Humidity Monitor

## Introduction

This is a simple Arduino-based project that uses a DHT11 (or DHT22) sensor to monitor the temperature and humidity of the environment. The data is displayed on an LCD screen, and an LED and buzzer are triggered if the temperature or humidity exceeds defined thresholds. 

This project was designed to find the humidity level in my 3D printing filament storage box to ensure that the humidity in the air is not impacting the printing material.

![Result of the project](/SmartTempHumidityMonitor.ino "Hardware of the project")

---

## Hardware Setup

### Required Components:
- 1 x Arduino Uno (or compatible board)
- 1 x DHT11 or DHT22 temperature and humidity sensor
- 1 x 16x2 LCD Display (I2C module recommended)
- 1 x LED
- 1 x Buzzer
- Jumper wires
- Breadboard

### Wiring Diagram:
Here is a simple wiring guide:

1. DHT11/DHT22 Sensor:
- VCC → 5V pin on Arduino
- GND → GND pin on Arduino
- Data → Pin 2 on Arduino

2. LCD Display (I2C):
- VCC → 5V pin on Arduino
- GND → GND pin on Arduino
- SDA → A4 (on Arduino Uno)
- SCL → A5 (on Arduino Uno)

3. LED:
- Anode (+) → Pin 13 on Arduino
- Cathode (-) → GND (with 220Ω resistor)

4. Buzzer:
- Positive leg (+) → Pin 12 on Arduino
- Negative leg (-) → GND

## Installation Instructions
Steps to upload the code to your Arduino:

- Install the Required Libraries:
    - Open Arduino IDE.
    - Go to Sketch → Include Library → Manage Libraries.
    - Search and install the following libraries:
        - DHT sensor library by Adafruit
        - LiquidCrystal_I2C by Frank de Brabander
- Connect the Arduino:
    - Connect your Arduino Uno to your computer via the USB cable.
- Upload the Code:
    - Open the SmartTempHumidityMonitor.ino file in Arduino IDE.
    - Select the correct Board (Arduino Uno) and Port under Tools.
    - Click on the Upload button to upload the code to the Arduino.
- Once the code is uploaded, the system will start measuring temperature and humidity and display the results on the LCD.

## Credit
- [Temperature and humidity sensor with Arduino
](https://projecthub.arduino.cc/rudraksh2008/temperature-and-humidity-sensor-with-arduino-1d52a6)