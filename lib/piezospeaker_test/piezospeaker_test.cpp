

//  # 4
//
//  PIEZO SPEAKER BEEPING AND LED BLINKING
//
//  Well, the used speaker procuces a mind-numbing shrilling sound...




#include <Arduino.h>

const int LED = 4;
const int PIEZOSPK = 5;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(PIEZOSPK, OUTPUT);    

}


void loop() {
    digitalWrite(LED, HIGH);
    digitalWrite(PIEZOSPK, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    digitalWrite(PIEZOSPK, LOW);
    delay(1500);


}
