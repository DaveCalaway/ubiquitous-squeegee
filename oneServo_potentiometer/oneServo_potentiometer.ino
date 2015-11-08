/* 
 Controlling a servo position using a potentiometer (variable resistor).
 While the potentiomenter is not at zero positions, the program not start, led 13 still OFF.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val=1;    
int startpos=0;

void setup()
{
  pinMode(13, OUTPUT); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);   // servo's start positions
}

void loop(){
  
  while(val=!startpos){
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  }
  
  digitalWrite(13,HIGH);
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 

