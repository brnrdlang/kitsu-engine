#define SDL_MAIN_HANDLED

#include <iostream>
#include "painter.h"
#include "SDL.h"
int main(int argc, char* argv[]) {
	SDL_SetMainReady();

	Painter painter(1024, 800, false, "kitsu-ENGIne");
	painter.draw();
    return 0;
}
