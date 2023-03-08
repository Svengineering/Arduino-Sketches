#include <Arduino.h>

/*

// EINE AMPEL UND EINE FUSSGÄNGERAMPEL WERDEN ÜBER EINEN TASTER GESTEUERT
//
// ohne Tastendruck zeigt die Verkehrsampel grün und die Fußgängerampel rot, nach dem Tastendruck schaltet die Fußgängerampel
// auf grün und die Verkehrsampel auf rot, nachdem die Verkehrsampel wieder grün geworden ist, reagiert die Ampelanlage für einige
// Zeit nicht auf einen Tastendruck


const int RED = 4;
const int GREEN = 2;
const int YELLOW = 3;
const int BUTTON = 5;
const int PEDESTRIAN_RED = 6;
const int PEDESTRIAN_GREEN = 7;

const int button_reaction_delay = 2000; //the button push shouldn't cause instant reaction

const int button_dead_time = 10000; //the button won't trigger anything for a certain period after a red cycle just has finished

//for traffic light (vehicles)
const int yellow_time = 2000;      //traffic light switching from green to red
const int yellow_red_time = 1000;  //traffic light swithcing from red to green

//for pedestrian crossing
const int ped_green_time = 8000;
const int ped_before_green_delay = 2000;  //delay after traffic light turned red before pedestrian light turns green
const int ped_after_green_delay = 3000;   //delay after pedestrian light turned red before traffic light turn green 

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(BUTTON, INPUT);
    pinMode(PEDESTRIAN_RED, OUTPUT);
    pinMode(PEDESTRIAN_GREEN, OUTPUT);

    //init traffic light with green phase and pedestrian light with red phase
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(PEDESTRIAN_GREEN, LOW);
    digitalWrite(PEDESTRIAN_RED, HIGH);

}

//
// one full cycle for a traffic light with a pedestrian crossing:
// - traffic light turning red and staying red while ...
// - pededstrian light turning green and staying green for a while ...
// - ... then pedestrian light turning red and then traffic light turning green again
//
// begins with yellow phase of traffic light
//
void traffic_light_with_pedestrian_crossing_cycle() {

    //traffic light turns yellow
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    
    delay(yellow_time);

    //traffic light turns red
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);

    //traffic light and pedestrian light are red
    delay(ped_before_green_delay);

    //pedestrian light turns green
    digitalWrite(PEDESTRIAN_GREEN, HIGH);
    digitalWrite(PEDESTRIAN_RED, LOW);
    delay(ped_green_time);

    //pedestrian light turns red
    digitalWrite(PEDESTRIAN_GREEN, LOW);
    digitalWrite(PEDESTRIAN_RED, HIGH);

    //traffic light and pedestrian light are red
    delay(ped_after_green_delay);

    //traffic light turns red-yellow and then green
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
        traffic_light_with_pedestrian_crossing_cycle();

        //red cycle is over: save time until a button push gets ignored
        button_push_blocked_time = millis() + button_dead_time;
    }


}


*/