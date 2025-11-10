#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#include <Adafruit_NeoPixel.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define LED_PIN 5
#define NUMPIXELS 1

DHT dht(DHTPIN, DHTTYPE);
Adafruit_NeoPixel led(NUMPIXELS, LED_PIN,
NEO_GRB + NEO_KHZ800);

const char* ssid = "Test";
const char* password = "12345678";
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;
const char* topic = "greenhouse/monitor/data";

WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

void setColor(int red, int green, int blue) {
 led.setPixelColor(0,led.Color
 (red,green,blue));
 led.show();
}

void connectWiFi() {
 Serial.print("Connecting");
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
 }
 Serial.println("\nConnected!");
 Serial.print("IP: ");
 Serial.println(WiFi.localIP());
}

void connectMQTT() {
 while (!mqtt.connected()) {
  Serial.print("Connecting to MQTT...");
  if (mqtt.connect("ESP32_Greenhouse")) {
  Serial.println("Connected!");
  mqtt.publish(topic, "{\"status\":\"online\"}");
  } else {
  Serial.print("Failed");
  Serial.println(mqtt.state());
  delay(2000);
  }
 }
}

void setup() {
 Serial.begin(115200);
 dht.begin();
 led.begin();
 setColor(0, 0, 0);
 connectWiFi();
 mqtt.setServer(mqttServer, mqttPort);
}

void loop() {
 if (!mqtt.connected()) connectMQTT();
 mqtt.loop();

 float t = dht.readTemperature();
 float h = dht.readHumidity();

 if (isnan(t) || isnan(h)) {
  Serial.println("Error reading sensor data");
  delay(2000);
  return;
 }

 String tempLevel;
 if (t < 18) {
  tempLevel = "Cold";
  setColor(0, 0, 255);
 } else if (t <= 30) {
  tempLevel = "Optimal";
  setColor(0, 255, 0);
 } else {
  tempLevel = "Too Hot";
  setColor(255, 0, 0);
 }

 String humLevel;
 if (h < 50)
  humLevel = "Dry";
 else if (h <= 70)
  humLevel = "Optimal";
 else
  humLevel = "Humid";

 String payload = 
 "{\"Temperature\":" + String(t, 1) +
 ,\"Humidity\":" + String(h, 1) +
 ",\"TempCondition\":\"" + tempLevel +
 "\",\"HumCondition\":\"" + humLevel + "\"}";

 Serial.println(payload);
 mqtt.publish(topic, payload.c_str());
 delay(5000);}