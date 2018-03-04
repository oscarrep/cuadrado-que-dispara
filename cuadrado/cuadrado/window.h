#pragma once
#include <string>
#include "../deps/include/SDL.h"

class window
{
public:
	window(const std::string &title, int width, int height);
	~window();

	void pollEvents();
	void clear() const;

	inline bool isClosed() const { return _close; }
private:
	bool init();
private:
	std::string _title;
	int _width = 600;
	int _height= 600;

	bool _close = false;

	SDL_Window *_window = nullptr;
	SDL_Renderer *_renderer = nullptr;
};