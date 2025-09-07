#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char* SINRIC_API_KEY = "YOUR_SINRICPRO_API_KEY";

String DEVICE_ID_1 = "deviceId_1_placeholder";
String DEVICE_ID_2 = "deviceId_2_placeholder";
String DEVICE_ID_3 = "deviceId_3_placeholder";
String DEVICE_ID_4 = "deviceId_4_placeholder";

const int RELAY_PIN_1 = D1;
const int RELAY_PIN_2 = D2;
const int RELAY_PIN_3 = D3;
const int RELAY_PIN_4 = D4;

bool relayState1 = false;
bool relayState2 = false;
bool relayState3 = false;
bool relayState4 = false;

bool onPowerState1(const String &deviceId, bool &state) {
  relayState1 = state;
  digitalWrite(RELAY_PIN_1, state ? LOW : HIGH);
  Serial.printf("Device %s -> Relay1 %s\n", deviceId.c_str(), state ? "ON" : "OFF");
  return true;
}

bool onPowerState2(const String &deviceId, bool &state) {
  relayState2 = state;
  digitalWrite(RELAY_PIN_2, state ? LOW : HIGH);
  Serial.printf("Device %s -> Relay2 %s\n", deviceId.c_str(), state ? "ON" : "OFF");
  return true;
}

bool onPowerState3(const String &deviceId, bool &state) {
  relayState3 = state;
  digitalWrite(RELAY_PIN_3, state ? LOW : HIGH);
  Serial.printf("Device %s -> Relay3 %s\n", deviceId.c_str(), state ? "ON" : "OFF");
  return true;
}

bool onPowerState4(const String &deviceId, bool &state) {
  relayState4 = state;
  digitalWrite(RELAY_PIN_4, state ? LOW : HIGH);
  Serial.printf("Device %s -> Relay4 %s\n", deviceId.c_str(), state ? "ON" : "OFF");
  return true;
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(RELAY_PIN_4, OUTPUT);
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);
  digitalWrite(RELAY_PIN_4, HIGH);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  SinricPro.begin(SINRIC_API_KEY);
  SinricPro.switchDevice(DEVICE_ID_1).onPowerState(onPowerState1);
  SinricPro.switchDevice(DEVICE_ID_2).onPowerState(onPowerState2);
  SinricPro.switchDevice(DEVICE_ID_3).onPowerState(onPowerState3);
  SinricPro.switchDevice(DEVICE_ID_4).onPowerState(onPowerState4);

  SinricPro.onConnected([](){
    Serial.println("Connected to SinricPro server");
  });
  SinricPro.onDisconnect([](){
    Serial.println("Disconnected from SinricPro");
  });

  SinricPro.begin();
}

void loop() {
  SinricPro.handle();
}
