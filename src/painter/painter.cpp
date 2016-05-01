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

    this->renderer_ = SDL_CreateRenderer(this->window_, -1, SDL_RENDERER_ACCELERATED);

    if (this->renderer_ == nullptr) {
        throw PainterError("Could not create renderer: " + std::string(SDL_GetError()) + "\n");
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
    SDL_DestroyRenderer(this->renderer_);
	SDL_Quit();
}

void Painter::add_object_to_scene(GraphicsObject* obj) {
    this->scene_->insert(obj);
}

void Painter::remove_object_from_scene(GraphicsObject* obj) {
    obj->node_->remove(obj);
}

unsigned int Painter::next_event_time() {
    return queue_.top().time_;
}

SDL_Renderer* Painter::get_renderer() {
    return renderer_;
}

SceneNode* Painter::get_scene() {
    return scene_;
}

void Painter::queue(unsigned int time, GraphicsObject* sprite) {
    queue_.push(AnimationEvent(time, sprite));
}

/**
 * Update the window screen by  
 */
void Painter::update() {
    unsigned int time = SDL_GetTicks();

    if (queue_.empty()) {
        SDL_Delay(50);
        return;
    }

    unsigned int next = queue_.top().time_;

    if (time+50 < next) {
        SDL_Delay(50);
        return;
    }

    std::set<GraphicsObject*, compGOP> to_draw;

    while (not queue_.empty() and queue_.top().time_ <= time) {
        queue_.top().sprite_->next(time);
        queue_.top().sprite_->node_->draw(renderer_, &to_draw);
        queue_.pop();
    }
    this->draw(to_draw);
}

void Painter::draw(std::set<GraphicsObject*, compGOP>& to_draw) {
	for(auto obj: to_draw) {
        obj->draw(renderer_);
    }
    SDL_RenderPresent(renderer_);

}
