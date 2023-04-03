#define step_pin 2
#define direction_pin 3
#define enable_pin 4

#include <ezButton.h>
#include <Wire.h>

ezButton limitSwitch(7);


void setup() {
  
  Wire.begin(6);                // join i2c bus with address #6
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);
  
  limitSwitch.setDebounceTime(50);

  pinMode(direction_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
  pinMode(4, OUTPUT);
  
  digitalWrite(enable_pin, HIGH);
  digitalWrite(direction_pin, HIGH);
  
  while(limitSwitch.getState()){
    digitalWrite(direction_pin, HIGH);
    limitSwitch.loop();
    digitalWrite(step_pin, HIGH);
    digitalWrite(step_pin, LOW);
    delay(1);
    Serial.println("reversing");
  }
 digitalWrite(direction_pin, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
}
void receiveEvent(int howMany)
{
  
    char bruh = Wire.read();
    switch(bruh){

    case '0':
      digitalWrite(enable_pin, HIGH);
    
      while(limitSwitch.getState()){
      digitalWrite(direction_pin, HIGH);
      limitSwitch.loop();
      digitalWrite(step_pin, HIGH);
      digitalWrite(step_pin, LOW);
      delay(1);
      Serial.println("reversing");
      }
      
      break;
    
    case '1':
      digitalWrite(direction_pin, LOW);
      digitalWrite(enable_pin, HIGH);
      for(int i=0;i<100;i++){
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        Serial.println("stepping: ");
        Serial.print(i);
        delay(1);
      }
      break;
      
    case '2':
      digitalWrite(direction_pin, LOW);
      digitalWrite(enable_pin, HIGH);
      for(int i=0;i<200;i++){
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        Serial.println("stepping: ");
        Serial.print(i);
        delay(1);
      }
      break;
    case '3':
      digitalWrite(direction_pin, LOW);
      digitalWrite(enable_pin, HIGH);
      for(int i=0;i<300;i++){
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        Serial.println("stepping: ");
        Serial.print(i);
        delay(1);
      }
      break;
    case '4':
      digitalWrite(direction_pin, LOW);
      digitalWrite(enable_pin, HIGH);
      for(int i=0;i<400;i++){
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        Serial.println("stepping: ");
        Serial.print(i);
        delay(1);
      }
      break;
    case '5':
      digitalWrite(direction_pin, LOW);
      digitalWrite(enable_pin, HIGH);
      for(int i=0;i<500;i++){
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        Serial.println("stepping: ");
        Serial.print(i);
        delay(1);
      }
      break;

    default:
      digitalWrite(enable_pin, HIGH);
      break;
   }

}
