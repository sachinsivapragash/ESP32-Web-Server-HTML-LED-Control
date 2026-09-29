// task1_esp32_webserver.ino
#include <WiFi.h>
#include <WebServer.h>

// ================================
// WiFi Credentials
// ================================
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// ================================
// LED Configuration
// ================================
#define LED_PIN 2

WebServer server(80);
bool ledState = false;

// ================================
// Create Web Page
// ================================
String htmlPage() {
  String html = "";
  html += "<!DOCTYPE html><html><head><title>ESP32 LED Control</title>";
  html += "<style>body{background:#000;color:#fff;text-align:center;font-family:Arial;padding-top:80px;}";
  html += "h1{font-size:28px;} .switch{position:relative;display:inline-block;width:60px;height:34px;}";
  html += ".switch input{display:none;} .slider{position:absolute;top:0;left:0;right:0;bottom:0;background:#555;border-radius:34px;transition:.3s;cursor:pointer;}";
  html += ".slider:before{position:absolute;content:'';height:26px;width:26px;left:4px;bottom:4px;background:white;border-radius:50%;transition:.3s;}";
  html += "input:checked + .slider{background:#4CAF50;} input:checked + .slider:before{transform:translateX(26px);}</style></head><body>";
  html += "<h1>ESP32 LED Control</h1>";
  html += "<label class='switch'><input type='checkbox' id='ledSwitch' onchange='toggleLED()' " + String(ledState ? "checked" : "") + "><span class='slider'></span></label>";
  html += "<p id='status'>LED is " + String(ledState ? "ON" : "OFF") + "</p>";
  html += "<script>function toggleLED(){var xhr=new XMLHttpRequest();var state=document.getElementById('ledSwitch').checked;";
  html += "xhr.open('GET', state ? '/on' : '/off', true);xhr.onload=function(){document.getElementById('status').innerText='LED is '+(state?'ON':'OFF');};xhr.send();}</script>";
  html += "</body></html>";
  return html;
}

// ================================
// Route Handlers
// ================================
void handleRoot() { server.send(200, "text/html", htmlPage()); }

void handleOn()  { ledState = true;  digitalWrite(LED_PIN, HIGH); server.send(200, "text/plain", "LED is ON"); }
void handleOff() { ledState = false; digitalWrite(LED_PIN, LOW);  server.send(200, "text/plain", "LED is OFF"); }

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("================================");
  Serial.println("ESP32 WiFi LED Control");
  Serial.println("================================");

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();

  Serial.println("Web server started!");
  Serial.println("Open the IP address in your browser.");
}

void loop() {
  server.handleClient();
}
