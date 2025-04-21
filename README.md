# AZ-Visual LDR Test Sketch

This repository contains an Arduino test sketch designed for the AZ-Visual board. The sketch reads light intensity values using an integrated Light Dependent Resistor (LDR) and displays the results on an onboard OLED screen. Additionally, it retrieves and displays temperature and humidity data from the onboard SHT3X sensor.

![21](https://github.com/user-attachments/assets/0d3e0d42-76d3-4713-99b4-570f45314ab2)

## Overview

The AZ-Visual board simplifies prototyping by integrating essential components, including:

- **LDR**: Reads light intensity values.
- **SHT3X Sensor**: Measures temperature and relative humidity.
- **OLED Display**: Shows sensor data directly on the screen.

## Features

1. **Initialization**:
   - The onboard OLED screen initializes automatically with the default I2C address (`0x3C`).
   - A welcome message is displayed before clearing the screen for live data.

2. **Sensor Readings**:
   - Light intensity values are read using the LDR and displayed in real time.
   - Temperature and humidity readings are retrieved from the SHT3X sensor.

3. **Data Display**:
   - Sensor readings are displayed on the OLED screen and printed to the serial monitor for debugging.

## Requirements

- **Board**: AZ-Visual board with integrated LDR, SHT3X sensor, and OLED display.
- **Arduino Libraries**:
  - `WEMOS_SHT3X.h`
  - `Adafruit_SSD1306.h`
  - `Adafruit_GFX.h`
  - Core Arduino libraries (`Wire.h`).

## Usage

1. Connect the AZ-Visual board to your computer via USB.
2. Open the sketch in the Arduino IDE and upload it to the board.
3. Open the serial monitor to view real-time data, or check the onboard OLED screen.
