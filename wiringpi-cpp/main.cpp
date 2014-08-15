/*
 * Main file, you shouldn't need to change this.
 *
 */
#include "App.h"

int main()
{
	App app;
	app.setup();
	for (;;)
	{
		app.loop();
	}
	return 0;
}