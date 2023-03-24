

//  # 8
//
//  TESTING A PHOTORESISTOR
//  




#include <Arduino.h>

const int PHOTOSEN = A0;

void setup() {
    Serial.begin(9600);

}


void loop() {
    int uph = analogRead(PHOTOSEN);
    Serial.println(uph);
    
    delay(100);


}
