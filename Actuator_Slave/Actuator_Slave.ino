#define step_pin 2
#define direction_pin 3
#define enable_pin 4
#define MAX_POSITION 600
#define forward_direction 0
#define reverse_direction 1

#include <ezButton.h>
#include <Wire.h>

ezButton limitSwitch(7);


void setup() {
  
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);
  
  limitSwitch.setDebounceTime(50);

  pinMode(direction_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
  pinMode(4, OUTPUT);
  
  digitalWrite(enable_pin, HIGH);
  digitalWrite(direction_pin, reverse_direction);
  
  while(limitSwitch.getState()){
    digitalWrite(direction_pin, reverse_direction);
    limitSwitch.loop();
    digitalWrite(step_pin, HIGH);
    digitalWrite(step_pin, LOW);
    delay(1);
    Serial.println("reversing");
  }
 digitalWrite(direction_pin, forward_direction);
  
}
int step_position = 0;
int steps;

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
}
void receiveEvent(int howMany)
{
  
    char bruh = Wire.read();
    switch(bruh){

    case '0':
      digitalWrite(enable_pin, HIGH); //enable stepper motor 
      while(limitSwitch.getState()){  //Home 
        limitSwitch.loop();
        digitalWrite(direction_pin, reverse_direction);
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        delay(1);
        Serial.println("reversing");
      }
      Serial.println("home");
      step_position = 0;    //Reset stepper position
      break;
    
    case '1':
      digitalWrite(direction_pin, forward_direction);
      digitalWrite(enable_pin, HIGH);
      steps = 100;
      if((step_position+steps)<=MAX_POSITION){
        step_position+=steps;
        for(int i=1;i<=steps;i++){
          digitalWrite(step_pin, HIGH);
          digitalWrite(step_pin, LOW);
          Serial.print("stepping: ");
          Serial.println(i);
          delay(1);
        }
      }else{
        Serial.println("Position limit exceeded");
      }
      break;
      
    case '2':
      digitalWrite(direction_pin, forward_direction);
      digitalWrite(enable_pin, HIGH);
      steps = 200;
      if((step_position+steps)<=MAX_POSITION){
        step_position+=steps;
        for(int i=1;i<=steps;i++){
          digitalWrite(step_pin, HIGH);
          digitalWrite(step_pin, LOW);
          Serial.print("stepping: ");
          Serial.println(i);
          delay(1);
        }
      }else{
        Serial.println("Position limit exceeded");
      }
      break;
      
    case '3':
      digitalWrite(direction_pin, forward_direction);
      digitalWrite(enable_pin, HIGH);
      steps = 300;
      if((step_position+steps)<=MAX_POSITION){
        step_position+=steps;
        for(int i=1;i<=steps;i++){
          digitalWrite(step_pin, HIGH);
          digitalWrite(step_pin, LOW);
          Serial.print("stepping: ");
          Serial.println(i);
          delay(1);
        }
      }else{
        Serial.println("Position limit exceeded");
      }
      break;
      
    case '4':
      digitalWrite(direction_pin, forward_direction);
      digitalWrite(enable_pin, HIGH);
      steps = 400;
      if((step_position+steps)<=MAX_POSITION){
        step_position+=steps;
        for(int i=1;i<=steps;i++){
          digitalWrite(step_pin, HIGH);
          digitalWrite(step_pin, LOW);
          Serial.print("stepping: ");
          Serial.println(i);
          delay(1);
        }
      }else{
        Serial.println("Position limit exceeded");
      }
      break;
      
    case '5':
      digitalWrite(direction_pin, forward_direction);
      digitalWrite(enable_pin, HIGH);
      steps = 500;
      if((step_position+steps)<=MAX_POSITION){
        step_position+=steps;
        for(int i=1;i<=steps;i++){
          digitalWrite(step_pin, HIGH);
          digitalWrite(step_pin, LOW);
          Serial.print("stepping: ");
          Serial.println(i);
          delay(1);
        }
      }else{
        Serial.println("Position limit exceeded");
      }
      break;

    default:
      digitalWrite(enable_pin, HIGH);
      break;
   }
  }
  
