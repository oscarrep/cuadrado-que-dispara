#include <iostream>
#include "../deps/include/SDL.h"
#include "window.h"
#include "square.h"

#pragma comment(lib,"../deps/lib/SDL2.lib")
#pragma comment(lib,"../deps/lib/SDL2main.lib")

using namespace std;

void pollEvents(window &window, rect &rect) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		rect.pollEvents(event);
		window.pollEvents(event);
	}
}


int main(int argv, char *argc[])
{	
	window window("Shooting Square", 750, 600);
	rect rect(window, 325, 250, 100, 100, 0, 255, 255, 255);
	while (!window.isClosed()) {
		pollEvents(window, rect);
		rect.draw();
		window.clear();
	}
	return 0;
}