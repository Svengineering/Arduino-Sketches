#include <Arduino.h>
/*
//  TWO PULSATING LEDS
//
//connect LEDs to two output pins, let them alternately blink
const int LED1 = 10;
const int LED2 = 11;


//use pin 10 and 11 for a LED
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.begin(9600);
}

//
//toggle a digital pin on and then off with a given duration
//
void toggle_on_off_pin(int pin_id, int duration) {
  digitalWrite(pin_id, HIGH);
  delay(duration);
  digitalWrite(pin_id, LOW); 
}


//
// let the analog voltage pulsate over a period of 'duration' milliseconds,
// 
//
void pulsate_on_off_pin(int pin_id, int duration) {
  int delay_time = 10;  //for how long should the analog pin stay on the same voltage level (minimum time)

  // 0.5 * (duration/delay_time) = Soll-Anzahl der "Schaltvorgänge" vom Minimum zum Maximum
  //                               (die tatsächliche Anzahl der "Schaltvorgänge" kann darunter liegen, da es nur 256 Spannungslevel gibt)
  //
  // (256 / Anzahl "Schaltvorgänge" ) = Schrittweite
  double increment_size = 256.0 / (0.5 * duration/delay_time);

  //turning on
  for(double f = 0; f < 256; ) {

    analogWrite(pin_id, floor(f));
    delay(delay_time);
    f += increment_size;
  }
  
  //turning off
  for(double f = 255; f >= 0; ) {
    analogWrite(pin_id, floor(f));
    delay(delay_time);
    f -= increment_size;
  }
  analogWrite(pin_id, 0); //the previous loop doesn't ensure that the final level is 0
}


void loop() {

  unsigned long start = millis();
  pulsate_on_off_pin(LED1, 3000);
  pulsate_on_off_pin(LED2, 2000);
  unsigned long stop = millis();
  Serial.println(stop - start);
}

*/