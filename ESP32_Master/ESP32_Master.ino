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

uint8_t LED1pin = 4;
bool LED1status = LOW;
bool mstat = false;
bool mstat1 = false;
bool mstat2 = false;
bool mstat3 = false;
bool mstat4 = false;

void setup() {
  Wire.begin(21,22);
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/motoron", handle_motoron);
  server.on("/motoroff", handle_motoroff);
  server.on("/motoron1", handle_motoron1);
  server.on("/motoroff1", handle_motoroff1);
  server.on("/motoron2", handle_motoron2);
  server.on("/motoroff2", handle_motoroff2);
  server.on("/motoron3", handle_motoron3);
  server.on("/motoroff3", handle_motoroff3);
  server.on("/motoron4", handle_motoron4);
  server.on("/motoroff4", handle_motoroff4);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  mstat = false;
  mstat1 = false;
  mstat2 = false;
  mstat3 = false;
  mstat4 = false;
  
  Serial.println("GPIO4 Status: OFF | GPIO5 Status: OFF | GPIO6 Status: OFF | GPIO7 Status: OFF | GPIO8 Status: OFF");
  server.send(200, "text/html", SendHTML(mstat,mstat1,mstat2,mstat3,mstat4)); 
}

void handle_motoron() {
  mstat = true;
  Wire.beginTransmission(4); 
  Wire.write('F');  
  Serial.println("please work");       
  Wire.endTransmission();
  LED1status = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true,mstat1, mstat2, mstat3, mstat4)); 
}

void handle_motoroff() {
  mstat = false;
  Wire.beginTransmission(4);
  Wire.write('O');         
  Wire.endTransmission();
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false,mstat1, mstat2, mstat3, mstat4)); 
}

void handle_motoron1() {
  mstat1 = true;
  Wire.beginTransmission(4); 
  Wire.write('W');  
  Serial.println("please work");       
  Wire.endTransmission();
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML(mstat,true, mstat2, mstat3, mstat4)); 
}

void handle_motoroff1() {
  mstat1 = false;
  Wire.beginTransmission(4);
  Wire.write('R');         
  Wire.endTransmission();
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(mstat,false, mstat2, mstat3, mstat4)); 
}

void handle_motoroff2() {
  mstat2 = false;
  Wire.beginTransmission(4);
  Wire.write('E');         
  Wire.endTransmission();
  Serial.println("GPIO6 Status: OFF");
  server.send(200, "text/html", SendHTML(mstat,mstat1, false, mstat3, mstat4)); 
}


void handle_motoron2() {
  mstat2 = true;
  Wire.beginTransmission(4); 
  Wire.write('T');  
  Serial.println("please work");       
  Wire.endTransmission();
  Serial.println("GPIO6 Status: ON");
  server.send(200, "text/html", SendHTML(mstat,mstat1, true, mstat3, mstat4)); 
}

void handle_motoroff3() {
  mstat3 = false;
  Wire.beginTransmission(4);
  Wire.write('Y');         
  Wire.endTransmission();
  Serial.println("GPIO7 Status: OFF");
  server.send(200, "text/html", SendHTML(mstat,mstat1, mstat2, false, mstat4)); 
}


void handle_motoron3() {
  mstat3 = true;
  Wire.beginTransmission(4); 
  Wire.write('U');  
  Serial.println("please work");       
  Wire.endTransmission();
  Serial.println("GPIO7 Status: ON");
  server.send(200, "text/html", SendHTML(mstat,mstat1, mstat2, true, mstat4)); 
}


void handle_motoron4() {
  mstat4 = true;
  Wire.beginTransmission(4); 
  Wire.write('H');  
  Serial.println("please work");       
  Wire.endTransmission();
  Serial.println("GPIO8 Status: ON");
  server.send(200, "text/html", SendHTML(mstat,mstat1, mstat2, mstat3, true)); 
}

void handle_motoroff4() {
  mstat4 = false;
  Wire.beginTransmission(4);
  Wire.write('J');         
  Wire.endTransmission();
  Serial.println("GPIO8 Status: OFF");
  server.send(200, "text/html", SendHTML(mstat,mstat1, mstat2, mstat3, false)); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t motorstat, uint8_t motorstat1,uint8_t motorstat2,uint8_t motorstat3,uint8_t motorstat4){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>I2C Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{background-color: #222222;margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #2c3e50;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 40px;}\n";
  ptr +=".button-on {background-color: #27ae60;}\n";
  ptr +=".button-on:active {background-color: #219653;}\n";
  ptr +=".button-off {background-color: #ecf0f1; color: #2c3e50;}\n";
  ptr +=".button-off:active {background-color: #bdc3c7;}\n";
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

  if(motorstat1)
  {ptr +="<p>MOTOR1 Status: ON</p><a class=\"button button-off\" href=\"/motoroff1\">OFF</a>\n";}
  else
  {ptr +="<p>MOTOR1 Status: OFF</p><a class=\"button button-on\" href=\"/motoron1\">ON</a>\n";}

  if(motorstat2)
  {ptr +="<p>MOTOR2 Status: ON</p><a class=\"button button-off\" href=\"/motoroff2\">OFF</a>\n";}
  else
  {ptr +="<p>MOTOR2 Status: OFF</p><a class=\"button button-on\" href=\"/motoron2\">ON</a>\n";}

  if(motorstat3)
  {ptr +="<p>MOTOR3 Status: ON</p><a class=\"button button-off\" href=\"/motoroff3\">OFF</a>\n";}
  else
  {ptr +="<p>MOTOR3 Status: OFF</p><a class=\"button button-on\" href=\"/motoron3\">ON</a>\n";}

  if(motorstat4)
  {ptr +="<p>MOTOR4 Status: ON</p><a class=\"button button-off\" href=\"/motoroff4\">OFF</a>\n";}
  else
  {ptr +="<p>MOTOR4 Status: OFF</p><a class=\"button button-on\" href=\"/motoron4\">ON</a>\n";}
  
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
