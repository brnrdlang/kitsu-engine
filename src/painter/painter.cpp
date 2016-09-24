#include "painter.h"
#include "SDL.h"
#include "SDL_video.h"
#include <GL/glew.h>
#include "SDL_opengl.h"

/**
 * Painter constructor. Initializes SDL2 and creates a window with given coordinates and title.
 */
Painter::Painter(int width, int height, bool fs, std::string title) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		throw PainterError("Initialization of SDL Video failed\n");

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	Uint32 flags = SDL_WINDOW_OPENGL;
	
	if (fs)
		 flags = flags | SDL_WINDOW_FULLSCREEN_DESKTOP;

	this->window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

	if (this->window_ == nullptr) {
		throw PainterError("Could not create window: " + std::string(SDL_GetError()) + "\n");
	}

    SDL_GLContext gl_context_ = SDL_GL_CreateContext(this->window_);

    glewExperimental = GL_TRUE;
    glewInit();

    SDL_Rect scrn;
    scrn.x = 0; scrn.y = 0; scrn.w = width; scrn.h = height;

    this->scene_ = new StandardScene(&gl_context_);
}

/**
 *
 */
Painter::~Painter() {
    delete scene_;

	SDL_DestroyWindow(this->window_);
    SDL_GL_DeleteContext(this->gl_context_);
	SDL_Quit();
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

    scene_->drawall();
    SDL_GL_SwapWindow(this->window_);
}
