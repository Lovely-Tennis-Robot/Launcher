//This is the slave code for controlling the Launcher motor controller. 

#include <Wire.h>

int PWM1 = 9;
int PWM2 = 10;
int pwm;

void setup()
{
  Wire.begin(1);                // join i2c bus with address #5
  Wire.onReceive(receiveEvent); // register event
  pinMode(PWM1,OUTPUT);
  Serial.begin(9600);           // start serial for output
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(500);
}
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  
    char bruh = Wire.read();
    switch(bruh){
    
    case '0':
      pwm = 0;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
    
    case '1':
      pwm = 10;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
    
    case '2':
      pwm = 25;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
      
    case '3':
      pwm = 50;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
    
    case '4':
      pwm = 75;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
    
    case '5':
      pwm = 100;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
      
    case '6`':
      pwm = 125;
      analogWrite(9, pwm); // set the PWM value to the specified pin
      analogWrite(10, pwm);
      Serial.print("PWM Value set to: ");
      Serial.println(pwm);
      break;
      

    default: 
      Serial.println("Invalid value. Use 'h', 'm', 'l' or 'o'");    
    }

  
  Serial.println("");
}
