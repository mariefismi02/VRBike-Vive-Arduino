#ifndef Speed_h
#define Speed_h

#include "Arduino.h"

//Menggunakan modul LM393 - Optocoupler Speed Sensor

class Speed
{
private:
	int pinNumber;
	int steps;
	float steps_old;
	float temp;
	float rps;

public:
	Speed(int pinNumber);
	void addStep();
	int getSteps();
	void setRPS();
	float getRPS();
	void init();
};

#endif

//addStep - menambahkan 1 step jika sensor membaca inputan > 0
//getSteps - mengambil total step dari awal dijalankan
//setRPS - perbarui nilai RPS (Radian per sekon)
//getRPS - ambil nilai RPS terakhir
//init - inisialisasi modul