#include <iostream>
#include <unistd.h>
using namespace std;

#include "App.h"

int main ()
{
	cout << " ——— Rpi App cross compiled ons OSX ———" << endl ;
	 App app;
	app.setup();
	for (;;)
	{
		app.loop();
		//usleep(1); // to cool down a bit
	}
	return 0 ;
}