#include "Speed.h"
#include "Arduino.h"

Speed::Speed(int pinNumber){
	this->pinNumber = pinNumber;
	steps=0;
	steps_old=0;
	temp=0;
	rps=0;

}

void Speed::init(){
	pinMode(pinNumber, INPUT_PULLUP);
}

void Speed::addStep(){
	if(digitalRead(pinNumber))
	{
		steps=steps+1; 
	    while(digitalRead(pinNumber));
	}
}

void Speed::setRPS(){
	temp=steps-steps_old;
	steps_old=steps;
	rps=(temp/20);
}

int Speed::getSteps(){
	return steps;
}

float Speed::getRPS(){
	return rps;
}