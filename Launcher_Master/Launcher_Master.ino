#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}

byte x = 0;

void loop()
{
  if(Serial.available()){
    char bruh = Serial.read();

    if(bruh == 'h'){ //high
      Wire.beginTransmission(4); 
      Wire.write(bruh);         
      Wire.endTransmission(); 
    }else if (bruh == 'm'){ //Slow
      Wire.beginTransmission(4);
      Wire.write(bruh);         
      Wire.endTransmission();  
    }else if (bruh == 'l'){ //Low 
      Wire.beginTransmission(4);
      Wire.write(bruh);         
      Wire.endTransmission(); 
    }else if (bruh == 'o'){ //Off
      Wire.beginTransmission(4);
      Wire.write(bruh);
      Wire.endTransmission();
    }
    
      
    
     // stop transmitting
  }
  delay(500);
}
