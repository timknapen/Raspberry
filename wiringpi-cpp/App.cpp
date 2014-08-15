#include "App.h"

//————————————————————————————————————————————————
App::App(){
	wiringPiSetup(); // do not remove if you want to use wiringPi!
}

//————————————————————————————————————————————————
void App::setup(){
	
	// Setup pin
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);
    
    // Show some info
    cout << " WiringPi c++ test app " << endl;
	delay(500);
    
 }

//——————————————————————————————————————————————————————————
void App::loop(){
	
	// switch on the LED
	digitalWrite(LEDPIN, HIGH);
	delay(100);
	// switch it off again
	digitalWrite(LEDPIN, LOW);
	delay(100);
	
}
