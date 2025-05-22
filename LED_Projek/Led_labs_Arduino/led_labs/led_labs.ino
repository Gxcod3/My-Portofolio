// D4, D5, D19, & D18.
// 3V3, GND

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid ="A55";
const char* password ="123456789011@";

const int espLed = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 19;
const int ledPin4 = 18;

bool dapurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;
bool toiletLedState = false;

void setup() {
  Serial.begin(115200);

  pinMode(espLed, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  
  WiFi.begin(ssid, password);
  Serial.print("connecting to wifi a55...");

  while(WiFi.status() != WL_CONNECTED) {
    digitalWrite(espLed, LOW);
    delay(1000);
    Serial.print(".");
  }
  digitalWrite(espLed, HIGH);
  Serial.println("");
  Serial.println("connected to WiFi network!: ");
  Serial.println(WiFi.localIP());

  server.on("/dapur", HTTP_GET, getDapurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET, getMakanLed);
  server.on("/toilet", HTTP_GET, getToiletLed);

  server.on("/dapur", HTTP_POST, setDapurLed);
  server.on("/tamu", HTTP_POST, setTamuLed);
  server.on("/makan", HTTP_POST, setMakanLed);
  server.on("/toilet", HTTP_POST, setToiletLed);

  server.on("/dapur", HTTP_OPTIONS, handleOptions);
  server.on("/tamu", HTTP_OPTIONS, handleOptions);
  server.on("/makan", HTTP_OPTIONS, handleOptions);
  server.on("/toilet", HTTP_OPTIONS, handleOptions);


  server.begin();
  Serial.println("Server started...");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void setDapurLed() {
  dapurLedState = !dapurLedState;
  // true -> high (nyala)
  // false -> low (mati)
  digitalWrite(ledPin1, dapurLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void setTamuLed() {
  tamuLedState = !tamuLedState;
  digitalWrite(ledPin2, tamuLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void setMakanLed() {
  makanLedState = !makanLedState;
  digitalWrite(ledPin3, makanLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void setToiletLed() {
  toiletLedState = !toiletLedState;
  digitalWrite(ledPin4, toiletLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", toiletLedState ? "ON" : "OFF");
}

void getDapurLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void getTamuLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void getMakanLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void getToiletLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", toiletLedState ? "ON" : "OFF");
}

void handleOptions() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.send(204);
}
