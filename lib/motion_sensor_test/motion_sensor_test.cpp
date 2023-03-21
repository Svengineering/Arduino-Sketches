

//  # 7
//
//  TESTING THE MOTION SENSOR PIR HC-SR501 
//  




#include <Arduino.h>

const int LED = 7;
const int PIRSEN = 9;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(PIRSEN, INPUT);    

}


void loop() {

    if(digitalRead(PIRSEN) == HIGH){
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }

    //sensor reaction time seems to vary between about 500 ms up to 3000 ms...
    //so we don't need to run the loop more than 10 times a second in order to react "immediately" in terms of sensor time
    delay(100);


}
