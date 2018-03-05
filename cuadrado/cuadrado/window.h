#pragma once
#include <string>
#include "../deps/include/SDL.h"


class window
{
public:
	window(const std::string &title, int width, int height);
	~window();

	void pollEvents(SDL_Event &event);
	void clear() const;

	inline bool isClosed() const { return _close; }
private:
	bool init();
private:
	std::string _title;
	int _width = 900;
	int _height= 900;

	bool _close = false;

	SDL_Window *_window = nullptr;

protected:
	SDL_Renderer *_renderer = nullptr;
};