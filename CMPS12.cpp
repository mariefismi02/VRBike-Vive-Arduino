#include "CMPS12.h"

CMPS12::CMPS12(uint8_t pinTX, uint8_t pinRX){
	this->pinTX = pinTX;
	this->pinRX = pinRX;

}

void CMPS12::begin(int speed){
	cmps12 = new SoftwareSerial(pinTX, pinRX);

	cmps12->begin(speed);
}

void CMPS12::update(){
  cmps12->write(CMPS_GET_ANGLE16);  // Request and read 16 bit angle
  while(cmps12->available() < 2);
  high_byte = cmps12->read();
  low_byte = cmps12->read();
  angle16 = high_byte;                // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;
  
  cmps12->write(CMPS_GET_ANGLE8);  // Request and read 8 bit angle
  while(cmps12->available() < 1);
  angle8 = cmps12->read();
  
  cmps12->write(CMPS_GET_PITCH);   // Request and read pitch value
  while(cmps12->available() < 1);
  pitch = cmps12->read();
  
  cmps12->write(CMPS_GET_ROLL);    // Request and read roll value
  while(cmps12->available() < 1);
  roll = cmps12->read();
}

unsigned int CMPS12::getFullAngle(){
  return angle16 / 10;
}

int CMPS12::getAngle8Bit(){
  return angle8;
}

int CMPS12::getPitch(){
  return pitch;
}

int CMPS12::getRoll(){
  return roll;
}
