

//  # 1
//
//  TWO BLINKING LEDS
//  let two leds alternately blink




#include <Arduino.h>


//use pin 7 and 8 for a LED
void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

//
//toggle a digital pin on and then off with a given duration
//
void toggle_on_off_pin(int pin_id, int duration) {
  digitalWrite(pin_id, HIGH);
  delay(duration);
  digitalWrite(pin_id, LOW); 
}


void loop() {
  toggle_on_off_pin(7, 600);
  toggle_on_off_pin(8, 200);
}
