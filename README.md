# WhatsApp Home Automation (ESP8266)

Control home appliances over WhatsApp using an ESP8266 (NodeMCU) and a 4‑channel relay module. This project uses the ThingESP library to parse WhatsApp commands and switch relays for lights and fans.

## Features
- WhatsApp-based command control
- 4 independent relay channels
- Supports LEDs/lights and fans
- Status reporting via chat commands
- Simple, low-cost ESP8266 setup

## Hardware Requirements
- ESP8266 NodeMCU
- 4‑channel relay module
- LEDs or AC appliances (e.g., lights, fans)
- Jumper wires
- 5V power supply for ESP8266
- AC mains supply for appliances

## Wiring
Refer to the detailed wiring guide in [`Wiring-istruction.md`](./Wiring-istruction.md).

**Pin mapping (ESP8266 → Relay → Appliance):**
- D5 (GPIO 14) → IN1 → LED 1
- D6 (GPIO 12) → IN2 → Fan 1
- D7 (GPIO 13) → IN3 → LED 2
- D8 (GPIO 15) → IN4 → Fan 2  
- GND → GND  
- 3.3V → VCC

> ⚠ **Safety:** Always isolate the ESP8266 from high‑voltage AC wiring and power off the circuit before working.

## Software Setup
1. Install the Arduino IDE.
2. Add ESP8266 board support.
3. Install the **ThingESP** library.
4. Open `tvlounch.ino`.

Update your Wi‑Fi and ThingESP credentials:
```cpp
ThingESP8266 thing("YOUR_USERNAME", "YOUR_DEVICE_NAME", "YOUR_DEVICE_KEY");
thing.SetWiFi("YOUR_WIFI_SSID", "YOUR_WIFI_PASSWORD");
```

Upload the sketch to the ESP8266.

## WhatsApp Commands
### Main entry
- `hello!`

### TV Launch (TL)
- `tl` → open TV Launch controls  
- `l1 on` / `l1 off`  
- `l2 on` / `l2 off`  
- `f1 on` / `f1 off`  
- `f2 on` / `f2 off`  

### Status
- `s`
- `status for tv launch`

## Status Output
The system replies with current states:
- TV Launch LED 1 / LED 2
- TV Launch Fan 1 / Fan 2

## Project Structure
- `tvlounch.ino` — main firmware
- `Wiring-istruction.md` — wiring and safety guide
- `LICENSE` — GPL-3.0

## License
This project is licensed under the **GNU GPL v3.0**. See [`LICENSE`](./LICENSE) for details.
