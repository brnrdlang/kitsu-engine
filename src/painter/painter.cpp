#include "painter.h"
#include "SDL.h"
#include "SDL_video.h"

Painter::Painter(int width, int height, bool fs, std::string title) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		throw PainterError("Initialization of SDL Video failed\n");

	Uint32 flags = 0;
	
	if (fs)
		 flags = SDL_WINDOW_FULLSCREEN_DESKTOP;

	this->window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

	if (this->window_ == nullptr) {
		throw PainterError("Could not create window: " + std::string(SDL_GetError()) + "\n");
	}
}

Painter::~Painter() {
	SDL_DestroyWindow(this->window_);
	SDL_Quit();
}

void Painter::draw() {
	SDL_Delay(3000);
}
