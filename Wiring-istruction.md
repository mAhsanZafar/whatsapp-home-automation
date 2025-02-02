# Wiring Instructions for ESP8266 Home Automation System

## Components Required
- **ESP8266 NodeMCU**
- **4-Channel Relay Module**
- **LED Bulbs (or any AC appliance)**
- **Fans (or any AC appliance)**
- **Jumper Wires**
- **Power Supply (5V for ESP8266, 220V AC for Appliances)**

---

## Pin Configuration
| ESP8266 (NodeMCU) | Relay Module | Appliance |
|--------------------|-------------|-----------|
| D5 (GPIO 14)      | IN1         | LED 1 (Bulb 1) |
| D6 (GPIO 12)      | IN2         | LED 2 (Bulb 2) |
| D7 (GPIO 13)      | IN3         | Fan 1 |
| D8 (GPIO 15)      | IN4         | Fan 2 |
| GND               | GND         | - |
| 3.3V              | VCC         | - |

---

## Wiring Diagram
1. **ESP8266 to Relay Module:**
   - Connect **D5** to **IN1** (controls LED 1)
   - Connect **D6** to **IN2** (controls LED 2)
   - Connect **D7** to **IN3** (controls Fan 1)
   - Connect **D8** to **IN4** (controls Fan 2)
   - Connect **GND** of ESP8266 to **GND** of Relay Module
   - Connect **3.3V** of ESP8266 to **VCC** of Relay Module

2. **Relay Module to Appliances:**
   - Each relay acts as a switch for the connected appliance (LEDs or Fans)
   - Connect **COM (Common)** to the **Live (L) wire** of AC supply
   - Connect **NO (Normally Open)** to one terminal of the appliance
   - The other terminal of the appliance should be connected to **Neutral (N)** of AC supply

---

## Powering the ESP8266
- Use a **5V power adapter** to supply power to ESP8266 via **Micro-USB or Vin & GND**
- Ensure proper isolation between **ESP8266 (low voltage side)** and **AC appliances (high voltage side)**

**⚠ Safety Precautions:**
- Always turn off the power before wiring AC appliances.
- Use a proper **relay module** that can handle the current and voltage rating of your appliances.
- Keep ESP8266 and low-voltage components isolated from the AC wiring to prevent electrical hazards.

---

### Example Circuit Diagram
![image](https://github.com/user-attachments/assets/fdd07941-7455-4540-b8ff-4c4c5f465da2)

---

## Testing the Setup
1. Power on the ESP8266 and ensure it connects to WiFi.
2. Use the provided commands (**L1 ON, L1 OFF, F1 ON, F1 OFF, etc.**) to control the appliances.
3. Check the relay clicks when commands are executed.
4. Ensure LEDs and fans turn ON/OFF correctly.

Now your **ESP8266 Home Automation System** is ready! 🚀

