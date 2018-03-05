#include "square.h"

rect::rect(const window &window, int x, int y, int w, int h, int r, int g, int b, int a) :
window(window), _x(x), _y(y), _w(w), _h(h), _r(r), _g(g), _b(b), _a(a) 
{

}

void rect::draw() const {
	SDL_Rect rect;
	rect.w = _w;
	rect.h = _h;
	rect.x = _x;
	rect.y = _y;

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(_renderer, &rect);
}

void rect::pollEvents(SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			_y -= 10;
			break;
		case SDLK_DOWN:
			_y += 10;
			break;
		case SDLK_LEFT:
			_x -= 10;
			break;
		case SDLK_RIGHT:
			_x += 10;
			break;
		}
	}
}