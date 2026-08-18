#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  a=sr04.Distance();
  Serial.println(a);
  if (a<10) { // adjust the min distance for the fan to turn on here
    digitalWrite(ENABLE,HIGH); 
    digitalWrite(DIRA,LOW); 
    digitalWrite(DIRB,HIGH);
    delay(500);
  } else{
    digitalWrite(ENABLE,LOW);
    delay(500);
  }
}
