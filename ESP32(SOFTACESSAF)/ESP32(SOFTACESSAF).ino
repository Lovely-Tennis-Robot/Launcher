#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>

/* Put your SSID & Password */
const char* ssid = "ESP32";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

uint8_t motorpin = 4;
bool motorstatus = LOW;

void setup() {
  Wire.begin(21,22);
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/motoron", handle_motoron);
  server.on("/motoroff", handle_motoroff);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(motorstatus)
  {digitalWrite(motorpin, HIGH);}
  else
  {digitalWrite(motorpin, LOW);}
}

void handle_OnConnect() {
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_motoron() {
  Wire.beginTransmission(4); 
  Wire.write('F');  
  Serial.println("please work");       
  Wire.endTransmission();
  motorstatus = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true)); 
}

void handle_motoroff() {
  Wire.beginTransmission(4);
  Wire.write('O');         
  Wire.endTransmission();
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t motorstat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>I2C Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP32 Web Server</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";
  
   if(motorstat)
  {ptr +="<p>MOTOR Status: ON</p><a class=\"button button-off\" href=\"/motoroff\">OFF</a>\n";}
  else
  {ptr +="<p>MOTOR Status: OFF</p><a class=\"button button-on\" href=\"/motoron\">ON</a>\n";}
  
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
