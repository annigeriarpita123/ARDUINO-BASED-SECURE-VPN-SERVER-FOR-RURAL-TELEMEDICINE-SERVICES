# Arduino Based Secure VPN Server for Rural Telemedicine Services

## Project Overview

This project is an IoT-based healthcare monitoring system designed for rural telemedicine services. It monitors a patient's vital health parameters such as Heart Rate, SpO₂ (Blood Oxygen Level), and Body Temperature using biomedical sensors. The collected data is processed by an Arduino Uno and transmitted securely through an ESP8266 Wi-Fi module to the Blynk IoT platform using a secure VPN connection. The system enables doctors to remotely monitor patients in real time.

---

## Objectives

- Monitor patient health continuously.
- Measure Heart Rate, SpO₂, and Body Temperature.
- Send health data securely over the Internet.
- Generate alerts during abnormal conditions.
- Support remote healthcare in rural areas.

---

## Hardware Requirements

- Arduino Uno
- ESP8266 Wi-Fi Module
- MAX30100 Pulse Oximeter Sensor
- DS18B20 Temperature Sensor
- 16x2 LCD Display
- LED
- Buzzer
- Regulated Power Supply
- USB Cable
- Connecting Wires

---

## Software Requirements

- Arduino IDE
- Blynk IoT Platform
- Embedded C Programming Language

---

## Libraries Used

```cpp
#include <SoftwareSerial.h>
#include <Wire.h>
#include <MAX30100_PulseOximeter.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal595.h>
```

---

## Variables Used

| Variable | Description |
|----------|-------------|
| HeartRate | Stores heart rate value (BPM) |
| SpO2 | Stores oxygen saturation (%) |
| glucose_level | Estimated glucose value |
| tempC | Body temperature in Celsius |
| tempF | Body temperature in Fahrenheit |
| tsLastReport | Timer for sensor updates |
| cdata | Stores sensor data before transmission |
| LED | Status indicator LED |

---

## Salient Features

- Real-time patient monitoring
- Secure VPN communication
- IoT cloud integration
- Remote monitoring using Blynk
- LCD display for live data
- Automatic emergency alert generation
- Low-cost healthcare solution
- Suitable for rural healthcare

---

## Working Principle

1. Arduino initializes all sensors.
2. Heart Rate, SpO₂, and Temperature are measured.
3. Sensor values are processed.
4. Data is displayed on the LCD.
5. Data is transmitted through ESP8266.
6. Information is uploaded to the Blynk Cloud.
7. If abnormal values are detected, an alert is generated.

---

## Compilation Procedure

1. Install Arduino IDE.
2. Install all required libraries.
3. Open the project (.ino) file.
4. Select **Arduino Uno** from **Tools → Board**.
5. Select the correct COM Port.
6. Verify the program.
7. Upload the code to Arduino Uno.

---

## Hardware Requirements for Running

- Arduino Uno
- USB Cable
- ESP8266 Wi-Fi Module
- MAX30100 Sensor
- DS18B20 Temperature Sensor
- LCD Display
- Power Supply (5V)

---

## Software Requirements for Running

- Windows 10/11
- Arduino IDE 2.x
- Blynk Mobile App
- USB Driver for Arduino
- Internet Connection

---

## Folder Structure

```
Project/
│
├── README.md
├── Arduino_Code.ino
├── Circuit_Diagram.png
├── Images/
├── Libraries/
└── Report.pdf
```

---

## Applications

- Rural Healthcare
- Remote Patient Monitoring
- Telemedicine
- Hospitals
- Elderly Care
- Home Healthcare

---

## Advantages

- Low Cost
- Secure Data Transmission
- Real-Time Monitoring
- Easy to Use
- Portable
- Remote Access

---

## Future Scope

- AI-based disease prediction
- Mobile application integration
- GPS emergency tracking
- Cloud database storage
- Doctor notification through SMS

---

## Developed By

**Bhoomika Reddy**

Department of Computer Science and Engineering

---

## License

This project is developed for academic and educational purposes.