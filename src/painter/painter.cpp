#include "painter.h"
#include "SDL.h"
#include "SDL_video.h"

/**
 * Painter constructor. Initializes SDL2 and creates a window with given coordinates and title.
 */
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

    SDL_Rect scrn;
    scrn.x = 0; scrn.y = 0; scrn.w = width; scrn.h = height;

    this->scene_ = new SceneNode(nullptr, scrn);
}

/**
 *
 */
Painter::~Painter() {
	SDL_DestroyWindow(this->window_);
	SDL_Quit();
}

SceneNode* Painter::add_object_to_scene(GraphicsObject* obj) {
    return this->scene_->insert(obj);
}

void Painter::remove_object_from_scene(GraphicsObject* obj) {
    this->scene_->remove(obj);
}

unsigned int Painter::next_event_time() {
    return queue_.top().time_;
}

/**
 * Update the window screen by  
 */
void Painter::draw() {
    SDL_Surface *screen = SDL_GetWindowSurface(this->window_);

    if (screen == nullptr) {
  		throw PainterError("Could not retrieve SDL surface: " + std::string(SDL_GetError()) + "\n");
    }

    unsigned int time = SDL_GetTicks();

	while (not queue_.empty() and next_event_time() <= time) {
        queue_.top().sprite_->draw(screen);
        queue_.pop();
    }

    SDL_UpdateWindowSurface(this->window_);
}
