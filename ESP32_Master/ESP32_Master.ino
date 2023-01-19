#include <Wire.h>
 
void setup() {
  Wire.begin(21,22);
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}
 
byte x = 0;

void loop()
{
 
  if(Serial.available()){
    char bruh = Serial.read();
    
    if(bruh == 'F'){ //Fast
      Wire.beginTransmission(4); 
      Wire.write(bruh);  
      Serial.println("please work");       
      Wire.endTransmission(); 
    }else if (bruh == 'S'){ //Slow
      Wire.beginTransmission(4);
      Wire.write(bruh);         
      Wire.endTransmission();  
    }else if (bruh == 'O'){ //Off
      Wire.beginTransmission(4);
      Wire.write(bruh);         
      Wire.endTransmission(); 
    }else if (bruh == 'o'){ //Other slave
      Wire.beginTransmission(5);
      Wire.write(bruh);         
      Serial.write("Arduino 5");
      Wire.endTransmission(); 
    }


    
      
    
     // stop transmitting
  }
  delay(500);
}
