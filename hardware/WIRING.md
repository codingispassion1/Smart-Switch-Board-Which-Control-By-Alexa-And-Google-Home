# Wiring & Connections

## Summary
- NodeMCU 3.3V supply to ESP8266 (do NOT power NodeMCU from 5V on 3.3V pin).
- Relay module needs 5V for coils + GND common with NodeMCU GND.
- Control pins from NodeMCU digital pins to relay IN1..IN4.

## Example connections
- RELAY VCC -> 5V adapter + (do not connect 5V to NodeMCU 5V pin if using separate supply; ensure common GND)
- RELAY GND -> NodeMCU GND (common ground)
- RELAY IN1 -> NodeMCU D1 (GPIO5)
- RELAY IN2 -> NodeMCU D2 (GPIO4)
- RELAY IN3 -> NodeMCU D3 (GPIO0)
- RELAY IN4 -> NodeMCU D4 (GPIO2)

**Note:** Many relay modules are active LOW (meaning writing LOW energizes the relay). Code above assumes active LOW; invert logic if your module is active HIGH.

## Mains wiring (if switching AC)
- If you plan to switch AC mains, put the relay in series with the LIVE wire (phase). NEVER touch live wiring while powered. Use insulated connectors and follow local electrical codes.
