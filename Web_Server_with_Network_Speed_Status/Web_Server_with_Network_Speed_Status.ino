#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>
#include <ESP8266Ping.h>


const char* ssid = "akso";          // Your WiFi SSID
const char* password = "111333555";  // Your WiFi Password
const char* remote_host = "www.google.com"; //Site a ser 'pingado'


int rssiDbm;
#define LED 2
AsyncWebServer server(80);


void recvMsg(uint8_t *data, size_t len) {
  WebSerial.println("Received Data...");
  String d = "";
  for (int i = 0; i < len; i++) {
    d += char(data[i]);
  }
  WebSerial.println(d);
  if (d == "ON") {
    digitalWrite(LED, LOW);
  }
  if (d == "OFF") {
    digitalWrite(LED, HIGH);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  // WebSerial is accessible at "<IP Address>/webserial" in browser
  WebSerial.begin(&server);
  WebSerial.msgCallback(recvMsg);
  server.begin();

}

void loop() {
  if (Ping.ping(remote_host)) {
    rssiDbm = WiFi.RSSI();
    Serial.println("Success!!");
    Serial.println(WiFi.RSSI());
    rssiCondition();

  } else {
    Serial.println("Error :(");
  }
}

void rssiCondition() {
  if (rssiDbm >= -30) {
    WebSerial.println("Conexão ótima, de " + String(rssiDbm) + "dBm's");
  }
  else if(rssiDbm > -67) {
    WebSerial.println("Conexão boa, de " + String(rssiDbm) + "dBm's");
  }
  else if(rssiDbm > -80) {
    WebSerial.println("Conexão aceitável, de " + String(rssiDbm) + "dBm's");
  }
  else{
    WebSerial.println("Conexão ruim, de " + String(rssiDbm) + "dBm's");
  }
}
