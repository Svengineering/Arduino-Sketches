

//  #6
//
//  A RGB LED SHOWING DIFFERENT COLORS
//
//  test a rgb led, let it shine in six different colours (red, green, blue, yellow, turquoise and purple)




#include <Arduino.h>

const int RED = 6;
const int GREEN = 5;
const int BLUE = 3;

const int brightness_red = 140;
const int brightness_green = 70;
const int brightness_blue = 140;

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

}

void loop() {

    //red
    analogWrite(RED, brightness_red);
    analogWrite(BLUE, 0);
    analogWrite(GREEN, 0);

    delay(1000);

    //green
    analogWrite(RED, 0);
    analogWrite(GREEN, brightness_green);

    delay(1000);

    //blue
    analogWrite(GREEN, 0);
    analogWrite(BLUE, brightness_blue);

    delay(1000);

    //yellow
    analogWrite(BLUE, 0);
    analogWrite(RED, 130);
    analogWrite(GREEN, 40);

    delay(1000);

    //turquoise, cyan
    analogWrite(BLUE, 80);
    analogWrite(RED, 0);
    analogWrite(GREEN, 120);

    delay(1000);

    //purple
    analogWrite(BLUE, 90);
    analogWrite(RED, 140);
    analogWrite(GREEN, 0);

    delay(3000);    

}
