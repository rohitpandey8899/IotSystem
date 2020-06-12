#include<SoftwareSerial.h>
#include <Wire.h>

const int trigPin = 3;
const int echoPin = 2;
long duration;
int distanceCm;
SoftwareSerial bt(2,3);
int c=0;
void setup() {
  bt.begin(9600);
  Serial.begin(9600);
  pinMode(6,OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  if (bt.available()) 
    {
     c= bt.read();

     if(c=='1')
     {
     //Door Lock
      }else if(c=='0'){
        //Door Open
        }else{

          //Auto Mode (UltraSonic)
            auto_mode();
          }
    
    }
}

void auto_mode(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0340 / 2;
  delay(1000);
  if (distanceCm == 20){

      //spray of sanitizer

            
    }
  }
