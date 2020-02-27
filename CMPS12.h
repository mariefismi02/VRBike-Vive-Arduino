#ifndef cmps12_h
#define cmps12_h

#include "Arduino.h"
#include <SoftwareSerial.h>

#define CMPS_GET_ANGLE8 0x12
#define CMPS_GET_ANGLE16 0x13
#define CMPS_GET_PITCH 0x14
#define CMPS_GET_ROLL 0x15

//Menggunakan modul CMPS12

class CMPS12
{
private:
  uint8_t pinTX;
  uint8_t pinRX;
	unsigned char high_byte, low_byte, angle8;
  char pitch, roll;
  unsigned int angle16;
	SoftwareSerial* cmps12;

public:
	CMPS12(uint8_t pinTX, uint8_t pinRX);
	void begin(int speed);
  void update();
	int getPitch();
  int getRoll();
  unsigned int getFullAngle();
  int getAngle8Bit();
};

#endif

//begin => inisialisasi modul
//update => perbarui nilai rotasi (harus dipanggil setiap update)
//getPitch => mengambil nilai rotasi y
//getRoll => mengambil nilai rotasi x
//getFullAngle => mengambil nilai rotasi 16 bit
//getAngle8Bit => mengambil nilai rotasi 8 bit
