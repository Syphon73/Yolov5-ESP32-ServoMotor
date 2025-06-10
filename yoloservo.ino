#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "DefaultWifi"; #your wifi ssid
const char* password = "12345678"; #your wifi password


WebServer server(80);
Servo myServo;

void handleBanana() {
  Serial.println("Banana Detected. Moving Servo.");
  myServo.write(90);  // Move servo to 90 degrees
  delay(2000);
  myServo.write(0);   // Return to original position
  server.send(200, "text/plain", "Servo Moved");
}

void setup() {
  Serial.begin(115200);
  myServo.attach(13);  // GPIO5 (D5), change as needed
  myServo.write(0);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi.");
  Serial.println(WiFi.localIP()); #get your localIP adress from here

  
  server.on("/banana_detected", handleBanana);
  server.on("/detect", HTTP_POST, handleBanana);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
