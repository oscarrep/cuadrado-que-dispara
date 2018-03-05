#pragma once
#include"window.h"

class rect : public window{
public:
	rect(const window &window ,int x, int y, int w, int h, int r, int g, int b, int a);
	void draw() const;
	void pollEvents(SDL_Event &event);

private:
	int _x, _y;
	int _w, _h;
	int _r, _g, _b, _a;
};