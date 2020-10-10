#include <Servo.h>

Servo myservo;

void setup(){
myservo.attach(11);
Serial.begin(9600);
}

void loop(){
int val=random(500,1500);
Serial.println(val);
myservo.write(42);
delay(val);
myservo.write(359);
val=random(500,1500);
Serial.println(val);
delay(val);
}
