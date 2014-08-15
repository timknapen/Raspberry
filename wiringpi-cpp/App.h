#ifndef _APP_H_
#define _APP_H_

#include <wiringPi.h>
#include <iostream>
#include <string>
using namespace std;

/*** RPI PINS ***
 
	TOP OF BOARD, SD CARD
 
	3.3V	5v
	8		5v
	9		GND
	7		15
	GND		16
	0		1
	2		GND
	3		4
	3.3V	5
	12		GND
	13		6
	14		10
	GND		11
 
	VIDEO OUT, RCA JACK
 
 *******************/

// Define PINS
#define LEDPIN 15

class App {

public:
	App();
	void setup();
	void loop();
};


#endif