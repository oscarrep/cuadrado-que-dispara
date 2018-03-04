#include "window.h"
#include <iostream>
window::window(const std::string &title, int width, int height):
	_title(title), _width(width), _height(height)
{
	if (!init()) {
		_close = true;
	}
}

window::~window() 
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) !=0){
		std::cerr << "ERROR initialize.\n";
		return 0;
	}

	_window=SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		//SDL_WINDOW_RESIZABLE
		0
	);

	if(_window == nullptr) {
		std::cerr << "ERROR create window.\n";
		return 0;
	}

	return true;
}

void window::pollEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_close = true;
			break;
		default:
			break;
		}
}
}