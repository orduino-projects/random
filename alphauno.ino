#include "Servo.h"
#include "IRremote.h"
int RECEIVE_PIN = 2;
IRrecv irrecv(RECEIVE_PIN);
decode_results results;
Servo servoMain;
int servPoz = 42; //Начальное положение сервы
int lastPoz = 359;
void setup()
{
  irrecv.enableIRIn();
  Serial.begin(9600);
  servoMain.attach(11); // Servo присоединен к 11 выводу
  servoMain.write(42);
}
 
void loop() {
  if (irrecv.decode(&results)) 
  {
    int res = results.value;
    Serial.println(res);
    if(res==0x16754775)// Если нажата кнопка "+"
    {
      lastPoz=res;
      servPoz++;  
      servoMain.write(servPoz);
    }
    else if(res==0x16748655)// Если нажата кнопка "-" 
    {
      servPoz--;
      lastPoz=res;
      servoMain.write(servPoz);
    }
  }
  delay(50);
}
