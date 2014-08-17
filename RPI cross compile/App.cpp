#include "App.h"

//————————————————————————————————————————————————
App::App(){
	wiringPiSetup();
}

//————————————————————————————————————————————————
void App::setup(){
	pinMode(LEDPIN, OUTPUT);
}


//————————————————————————————————————————————————
void App::loop(){
	digitalWrite(LEDPIN, HIGH);
	delay(100);
	digitalWrite(LEDPIN, LOW);
	delay(500);
}

