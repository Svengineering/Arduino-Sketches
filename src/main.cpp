#include <Arduino.h>

//  TWO BLINKING LEDS
//
//connect LEDs to two output pins, let them alternately blink
const int LED1 = 10;
const int LED2 = 11;


//use pin 10 and 11 for a LED
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

/*
  toggle a digital pin on and then off with a given duration
*/
void toggle_on_off_pin(int pin_id, int duration) {
  digitalWrite(pin_id, HIGH);
  delay(duration);
  digitalWrite(pin_id, LOW); 
}


void pulsate_on_off_pin(int pin_id, int duration){

  //TODO: auch für duration < 512 einen sinnvollen Algorithmus schreiben...
  if(duration < 512){
    duration = 512;
  }

  Serial.println(duration / 512);

  //turning on
  for(int i = 0; i <= 200;) {
    analogWrite(pin_id, i);
    delay(1);
    i += 2;
  }
  
  //turning off
  for(int i = 200; i >= 0; i--) {
    analogWrite(pin_id, i);
    delay(4);
  }

}


void loop() {
  pulsate_on_off_pin(LED1, 1000);
  pulsate_on_off_pin(LED2, 700);
}