//#define SDL_MAIN_HANDLED

#include <iostream>
#include "painter.h"
#include "controller.h"
//#include "SDL/SDL.h"

int main(int argc, char* argv[]) {
//	SDL_SetMainReady();

	Painter painter(1024, 768, false, "kitsu-ENGIne");
    Controller ctrl;

    bool quit = false;

    ctrl.on_quit = [&](SDL_QuitEvent ev){quit = true;};
    while(not quit) {
	    painter.draw();

        ctrl.poll_events();
    }

    return 0;
}
