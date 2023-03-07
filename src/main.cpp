#include <Arduino.h>


const int RED = 4;
const int GREEN = 2;
const int YELLOW = 3;
const int BUTTON = 5;

const int button_reaction_delay = 2000; //the button push shouldn't cause instant reaction

const int button_dead_time = 10000; //the button won't trigger anything for a certain period after a red cycle just has finished

const int red_time = 10000;
const int yellow_time = 2000;
const int yellow_red_time = 1000;

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(BUTTON, INPUT);

    //init traffic light with green phase
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);


}

//
// one full cycle for a traffic light turning red, staying red and then turning green
// begins with yellow phase
//
void traffic_light_red_cycle() {

    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    
    delay(yellow_time);

    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);

    delay(red_time - yellow_red_time);

    digitalWrite(YELLOW, HIGH);
    
    delay(yellow_red_time);

    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
}

void loop(){

    //time until a button push is blocked ( = pushing won't have any reaction)
    static unsigned long button_push_blocked_time = 0;

    //default behaviour: green on, red off, yellow off
    ;

    //turn on the red cycle?
    //check if: 1. button dead time is over
    //          2. button is pushed
    if( button_push_blocked_time < millis() && digitalRead(BUTTON) == HIGH ) {
      
        //after button push wait a bit...
        delay(button_reaction_delay);

        //start the red cycle for the traffic light
        traffic_light_red_cycle();

        //red cycle is over: save time until a button push gets ignored
        button_push_blocked_time = millis() + button_dead_time;
    }


}