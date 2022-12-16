#include <Arduino.h>
int in1 = 13 , in2 = 12 , in3 = 8  , in4 = 7 , state = 4 , del = 1000   ;
void forward(int in1 ,int in2){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
}
void backword(int in1 ,int in2 ){
    digitalWrite(in2,HIGH);
    digitalWrite(in1,LOW);
}
void STOP_MOTOR(int in1 ,int in2){
    digitalWrite(in2,LOW);
    digitalWrite(in1,LOW);
}
void setup() {
  // put your setup code here, to run once:
    pinMode(in1 , OUTPUT);
    pinMode(in2 , OUTPUT);
    pinMode(in3 , OUTPUT);
    pinMode(in4 , OUTPUT);
    pinMode(state,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(state)== 1){
        forward(in1,in2);
        forward(in3,in4);
        delay(del);
        STOP_MOTOR(in3,in4);
        STOP_MOTOR(in1,in2);
        delay(del);
        backword(in1,in2);
        backword(in3,in4);
        delay(del);
        STOP_MOTOR(in3,in4);
        STOP_MOTOR(in1,in2);
        delay(del);
        forward(in1,in2);
        backword(in3,in4);
        delay(del);
        STOP_MOTOR(in3,in4);
        STOP_MOTOR(in1,in2);
        delay(del);
    }
    else{
        STOP_MOTOR(in3,in4);
        STOP_MOTOR(in1,in2);
    }
}