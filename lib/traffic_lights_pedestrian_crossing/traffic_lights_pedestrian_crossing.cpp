

//  # 5
//
//  A TRAFFIC LIGHT AND A PEDESTRIAN CROSSING LIGHT ARE CONTROllED BY A PUSH BUTTON
//
//  Without pushing the button the traffic lights always show green. After button push the pedestrian crossing lights
//  will turn green and the traffic lights will turn red.
//  Finally, after the traffic lights have turned green again, the traffic lights are going to ignore a button push for some seconds.




#include <Arduino.h>


const int RED = 4;
const int GREEN = 2;
const int YELLOW = 3;
const int BUTTON = 5;
const int PEDESTRIAN_RED = 6;
const int PEDESTRIAN_GREEN = 7;

// defining some times in milliseconds:

const int button_reaction_delay = 2000; //the button push shouldn't cause instant reaction

const int button_dead_time = 10000; //the button won't trigger anything for a certain period after a traffic lights cycle just has finished

//for traffic lights
const int yellow_time = 2000;      //traffic lights switching from green to red
const int yellow_red_time = 1000;  //traffic lights swithcing from red to green

//for pedestrian crossing lights
const int ped_green_time = 8000;
const int ped_before_green_delay = 2000;  //delay after traffic lights turned red before pedestrian lights turns green
const int ped_after_green_delay = 3000;   //delay after pedestrian lights turned red before traffic lights turn green 

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(BUTTON, INPUT);
    pinMode(PEDESTRIAN_RED, OUTPUT);
    pinMode(PEDESTRIAN_GREEN, OUTPUT);

    //init traffic lights with green phase and pedestrian lights with red phase
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(PEDESTRIAN_GREEN, LOW);
    digitalWrite(PEDESTRIAN_RED, HIGH);

}

//
// one full cycle for a set of traffic lights with a pedestrian crossing:
// - traffic lights turning red and staying red while ...
// - pededstrian lights turning green and staying green for a while ...
// - ... then pedestrian lights turning red and then traffic lights turning green again
//
// begins with yellow phase of traffic lights
//
void traffic_light_with_pedestrian_crossing_cycle() {

    //traffic lights turns yellow
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    
    delay(yellow_time);

    //traffic lights turns red
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);

    //traffic lights and pedestrian lights are red
    delay(ped_before_green_delay);

    //pedestrian lights turns green
    digitalWrite(PEDESTRIAN_GREEN, HIGH);
    digitalWrite(PEDESTRIAN_RED, LOW);
    delay(ped_green_time);

    //pedestrian lights turns red
    digitalWrite(PEDESTRIAN_GREEN, LOW);
    digitalWrite(PEDESTRIAN_RED, HIGH);

    //traffic lights and pedestrian light are red
    delay(ped_after_green_delay);

    //traffic lights turns red-yellow and then green
    digitalWrite(YELLOW, HIGH);
    delay(yellow_red_time);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
}


void loop(){

    //time until a button push is blocked ( = pushing won't have any reaction)
    static unsigned long button_push_blocked_time = 0;

    //default behaviour: traffic lights green on, red off, yellow off;  pedestrian lights green off and red on
    ;

    //Switch traffic lights to red and pedestrian to green?
    //check if: 1. button dead time is over
    //          2. button is pushed
    if( button_push_blocked_time < millis() && digitalRead(BUTTON) == HIGH ) {
      
        //after button push wait a bit...
        delay(button_reaction_delay);

        //start the cycle for the traffic lights
        traffic_light_with_pedestrian_crossing_cycle();

        //cycle is over: save time until a button push gets ignored
        button_push_blocked_time = millis() + button_dead_time;
    }


}
