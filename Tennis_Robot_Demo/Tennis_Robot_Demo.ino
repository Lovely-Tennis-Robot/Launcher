#define step_pin 2
#define direction_pin 3
#define enable_pin 4
#define feeder_en 6
#define feeder_in3 5
#define feeder_in4 4
#define MAX_POSITION 500
#define forward_direction 0
#define reverse_direction 1

#include <ezButton.h>
#include <Wire.h>

ezButton limitSwitch(7);


void setup() {
  
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
int pwm;

void loop() {
  // put your main code here, to run repeatedly:
  limitSwitch.loop();
  while(Serial.available()){
  char bruh = Serial.read();
    switch(bruh){

    case '0':
      pwm = 0; //turn off motor
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      
      FeedOff(); //turn off feeder
      
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

      pwm = 25;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      delay(100);
      FeedOn();
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

      pwm = 50;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      delay(100);
      FeedOn();
      break;
      
    case '3':
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
      while(limitSwitch.getState()){  //Home 
        limitSwitch.loop();
        digitalWrite(direction_pin, reverse_direction);
        digitalWrite(step_pin, HIGH);
        digitalWrite(step_pin, LOW);
        delay(1);
        Serial.println("reversing");
      }
      

      pwm = 0;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      delay(100);
      FeedOn();
      break;

    default:
      digitalWrite(enable_pin, HIGH);
      break;
   }
  }
  delay(10);
}

void FeedOn(){
  digitalWrite(feeder_en, 150);
  digitalWrite(feeder_in3, LOW);
  digitalWrite(feeder_in4, HIGH);
}
void FeedOff(){
  digitalWrite(feeder_en, 0);
  digitalWrite(feeder_in3, LOW);
  digitalWrite(feeder_in4, LOW);
}
