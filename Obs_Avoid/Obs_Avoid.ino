#include <Servo.h>
#include <NewPing.h>
#

#define TRIGGER_PIN  13
#define ECHO_PIN     11
#define MAX_DISTANCE 200
 // Servo pin 9 
// Combining servo control with sensor ping
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;

int pos = 90; // pos for position and set a 0 degrees

void setup() 
{
  Serial.begin (9600);
  myservo.attach(9);
  myservo.write(90);
  delay(1000);  
}

void loop() 
{ 
    myservo.write(36);  // check distance to the right
    delay(500);
    int rightDistance = sonar.ping_cm(); //set right distance
    delay(500);
    myservo.write(144);  // check distace to the left
    delay(700);
    int leftDistance = sonar.ping_cm(); //set left distance
    delay(500);
    myservo.write(90); //return to center
    delay(100);
    
  //Serial.print("Right: ");
  //Serial.print(rightDistance);
  //Serial.print(" cm  ");
  //Serial.print("Left: ");
  //Serial.print(leftDistance);
  //Serial.println(" cm");
}
