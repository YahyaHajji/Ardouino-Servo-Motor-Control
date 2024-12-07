
// ----------------------  servo Motor with Bluetoth ------------------------

#include <Servo.h>
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
  
} 

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    int angle = Serial.parseInt();
    if(angle >= 0 && angle <= 180){
      myServo.write(angle);
      Serial.println("It works");
    }    
    else Serial.println("Angle out of the range");
    
  }

}




// ---------------- Auto Servo Motor with library --------------------

#include <Servo.h>

Servo myServo;

void setup(){
  myServo.attach(9);
}

void loop(){
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);
}

// ----------------- Control Servo Motor with joystick  ------------

#include <Servo.h>

Servo myServo;
int servoPos;
int xPin = A0;
int xValue;

void setup(){
  myServo.attach(9);
  pinMode(xPin, INPUT);
}

void loop(){
  xValue = analogRead(xPin);
  servoPos = map(xValue, 0, 1023, 0, 180);
  myServo.write(servoPos);
}



