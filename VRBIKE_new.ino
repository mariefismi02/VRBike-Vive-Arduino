#include<Servo.h>
#include "CMPS12.h"
#include "Speed.h"

CMPS12 AngleSensor(2, 3);
Speed speed(6);//Sensor kecepatan
Servo servo;
int val = 0;

float lastSpeed = 0;
float lastAngle = 0;

unsigned long start_time = 0;
unsigned long end_time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AngleSensor.begin(9600);
  speed.init();
  servo.attach(7);

   //Delay for sensor
  start_time=millis();
  end_time=start_time+1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  AngleSensor.update();

  //Move speed
  if(millis()<end_time)//Tambah step selama kurang dari setiap 1 detik
  {
    //speed.addStep();
    //Serial.println("agl:"+String(AngleSensor.getFullAngle()));
  } else {//Set ulang RPS setiap 1 detik

    //speed.setRPS();

    float rps = 0;//speed.getRPS();
    
    Serial.println("rps:"+String(rps));
    
    //Delay for sensor
    start_time=millis();
    end_time=start_time+1000;
  }
  
  if(AngleSensor.getFullAngle()!=lastAngle){
    Serial.println("agl:"+String(AngleSensor.getFullAngle()));
    lastAngle = AngleSensor.getFullAngle();
  }

  //ambil sudut
  if(Serial.available()){
    val =  Serial.readString().toInt();
    val = max(0, min(180, val));
    servo.write(val);
  }
}
