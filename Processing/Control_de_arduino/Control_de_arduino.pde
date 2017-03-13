import processing.serial.*;
import cc.arduino.*;
Arduino arduino;
int ledPin = 13;

void setup()
{
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(ledPin, Arduino.OUTPUT);
  arduino.pinMode(4, Arduino.SERVO);
}

void draw()
{
  arduino.digitalWrite(ledPin, Arduino.HIGH);
  delay(500);
  arduino.servoWrite(4,0);
  arduino.digitalWrite(ledPin, Arduino.LOW);
  delay(1000);
  arduino.servoWrite(4,90);
}