# EV Battery Thermal Monitoring & Overheat Alert System

## Project Description

An embedded temperature monitoring and overheat alert prototype developed using Arduino Uno and an NTC thermistor. The system continuously reads temperature through the microcontroller's ADC, processes the sensor data, and activates visual and audible alerts when the temperature exceeds a predefined safety threshold.

The project was developed and validated using the Wokwi simulation environment.

---

## Tech Stack

- Embedded C / Arduino C++
- Arduino Uno
- NTC Thermistor
- ADC
- GPIO
- Serial UART
- LED
- Buzzer
- Wokwi Simulator

---
## Normal Operation — 35°C
The system correctly identifies the temperature as normal and keeps both warning outputs disabled.

## Overheat Detection — 45°C
The system detects the over-temperature condition and activates both the LED and buzzer.

---

## Project Screenshots
### Normal Condition

### Overheat Condition

## Learning Outcomes
Through this project, I gained practical experience with:
- Microcontroller ADC interfacing
- GPIO control
- Analog sensor processing
- Embedded C programming
- Threshold-based fault detection
- Modular firmware design
- Embedded system testing and validation

## Future Improvements
- Add an LCD/OLED display
- Implement data logging
- Add multiple temperature sensors
- Replace threshold logic with configurable safety limits
- Implement the system on physical hardware


## System Architecture

```text
        NTC Temperature Sensor
                  |
                  v
             Arduino A0
                  |
                  v
              ADC Reading
                  |
                  v
        Temperature Calculation
                  |
                  v
          Threshold Detection
             /          \
            /            \
       < 40°C           >= 40°C
          |                |
          v                v
       NORMAL           OVERHEAT
          |                |
          v                v
      LED OFF          LED ON
      Buzzer OFF       Buzzer ON
