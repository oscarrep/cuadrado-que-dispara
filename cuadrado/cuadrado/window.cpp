#include "window.h"
#include <iostream>
window::window(const std::string &title, int width, int height):
	_title(title), _width(width), _height(height)
{
	_close = !init();
}

window::~window() 
{
	SDL_DestroyRenderer(_renderer);
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
		std::cerr << "ERROR creating window.\n";
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr) {
		std::cerr << "ERROR creating window.\n";
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

void window::clear() const {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
	SDL_RenderClear(_renderer);
	
	SDL_Rect square;
	square.w = 120;
	square.h = 120;
	square.x = _width / 2;
	square.y = _height / 2;

	SDL_SetRenderDrawColor(_renderer , 255, 0, 0, 255);
	SDL_RenderFillRect(_renderer, &square);

	SDL_RenderPresent(_renderer);
}