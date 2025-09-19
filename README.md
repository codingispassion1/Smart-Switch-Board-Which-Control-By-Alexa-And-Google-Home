# Smart Switch Board (Alexa & Google Home) — SinricPro + NodeMCU (ESP8266)

**Language:** Hinglish + English  
**Author:** Aniruddh Sharma  

## Overview
This project demonstrates a **4-channel relay-based smart switchboard** that can be controlled through **Alexa** and **Google Home** using the **SinricPro** service and a **NodeMCU (ESP8266)**.

Features:
- 4 Relay channels (ON / OFF)
- Works with Alexa & Google Home via SinricPro
- OTA-friendly Arduino sketch
- Clear wiring diagram and deployment steps
- Ready-to-push GitHub repo (zip provided)

## Hardware
- NodeMCU ESP8266 (e.g., ESP-12E)
- 4-Channel Relay Module (5V)
- 5V Adapter (sufficient current for relays, e.g., 2A)
- Jumper wires, breadboard / perfboard
- Optional: opto-isolated relay module for safety

## Software & Libraries
- Arduino IDE (or PlatformIO)
- Libraries:
  - ESP8266WiFi
  - SinricPro (install from Arduino Library Manager)  
Replace placeholders in the sketch for WiFi, SinricPro API Key and Device IDs.

## Important Safety Note
Relays switch mains voltage if you connect household AC — be careful, follow electrical safety, isolate power when wiring, and consult a qualified electrician if unsure.

## Wiring (summary)
See `hardware/WIRING.md` for detailed wiring and relay pin mapping.

## How to upload (Arduino IDE)
1. Open `src/SmartSwitchBoard.ino` in Arduino IDE.
2. Install the required libraries (Sketch → Include Library → Manage Libraries).
3. Fill in your `WIFI_SSID`, `WIFI_PASS`, `SINRIC_API_KEY` and `DEVICE_IDS` in the sketch.
4. Select board: **NodeMCU 1.0 (ESP-12E Module)** and correct COM port.
5. Upload.

