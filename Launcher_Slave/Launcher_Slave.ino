//This is the slave code for controlling the Launcher motor controller. 

#include <Wire.h>

int PWM1 = 9;
int PWM2 = 10;
int pwm;

void setup()
{
  Wire.begin(4);                // join i2c bus with address #5
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
  if(penis == 'O'){
    Serial.print("On");
    pwm = 50;
    analogWrite(PWM1,pwm);
    analogWrite(PWM2,pwm);
    Serial.println("PWM:");  
    Serial.print(pwm);

  }
  else if(penis == 'F'){
    Serial.print("Off");
    pwm = 50;
    analogWrite(PWM1,0);
    analogWrite(PWM2,0);
    Serial.println("PWM:");  
    Serial.print(pwm);

  }
  
  Serial.println("");
  // receive byte as an integer       // print the integer
}
