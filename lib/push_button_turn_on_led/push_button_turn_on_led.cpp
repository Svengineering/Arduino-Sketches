

//  # 3
//
//  TURN ON LED WITH BUTTON PRESS FOR A CERTAIN TIME
//
//  pushing a button will turn on a led for a fixed time, 
//  repeating the button push (before led has turned out) will extend the lighting time




#include <Arduino.h>


const int BUTTON = 7;
const int LED = 6;

//how long should the led being turned on?
const int led_timeout_ms = 5000;


void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}


void loop() {
  unsigned long led_start; //time of button push

  //read button status
  if(digitalRead(BUTTON) == HIGH) {
    led_start = millis();
    //always turn on led after button push
    digitalWrite(LED, HIGH);
  }

  //Check if led should be turned out:
  //has (time of the button push + led lighting time) expired?
  if( (led_start + led_timeout_ms) < millis() ) {
    digitalWrite(LED, LOW);
  }

  delay(10);
}
