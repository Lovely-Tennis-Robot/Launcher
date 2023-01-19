//This is the slave code for controlling the Launcher motor controller. 

#include <Wire.h>

int PWM1 = 9;
int PWM2 = 10;
int pwm;

void setup()
{
  Wire.begin(5);                // join i2c bus with address #5
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
  
    char penis = Wire.read();
      /*
    switch (penis){

        case 'h': //high power mode
          Serial.print("High power mode");
          pwm = 200;
          analogWrite(PWM1,pwm);
          analogWrite(PWM2,pwm);
          Serial.println("PWM:");  
          Serial.print(pwm);
          break;

        case 'm': //medium power mode 
          Serial.print("Medium power mode");
          pwm = 100;
          analogWrite(PWM1,pwm);
          analogWrite(PWM2,pwm);
          Serial.println("PWM:");  
          Serial.print(pwm);
          break;
        
        case 'l': //low power mode 
          Serial.print("Low power mode");
          pwm = 50;
          analogWrite(PWM1,pwm);
          analogWrite(PWM2,pwm);
          Serial.println("PWM:");  
          Serial.print(pwm);
          break;
        

        case 'o': //off 
          Serial.print("OFF");
          pwm = 0;
          analogWrite(PWM1,pwm);
          analogWrite(PWM2,pwm);
          Serial.println("PWM:");  
          Serial.print(pwm);
          break;     

        default: 
          Serial.println("Invalid value. Use 'h', 'm', 'l' or 'o'");    
    }
*/

  if(penis == 'o'){
    Serial.print("On");
    pwm = 50;
    analogWrite(PWM1,pwm);
    analogWrite(PWM2,pwm);
    Serial.println("PWM:");  
    Serial.print(pwm);
  }
  else if(penis == 'f'){
    Serial.print("Off");
    pwm = 50;
    analogWrite(PWM1,0);
    analogWrite(PWM2,0);
    Serial.println("PWM:");  
    Serial.print(pwm);
  }
  
  
  
  Serial.println("");
}
