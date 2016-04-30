#include <iostream>
#include "painter.h"
#include "controller.h"

int main(int argc, char* argv[]) {

	Painter painter(1024, 768, false, "kitsu-ENGIne");
    Controller ctrl;

    bool quit = false;

    ctrl.on_quit = [&](SDL_Event ev){quit = true;};
    while(not quit) {
	    painter.draw();

        ctrl.poll_events();
    }

    return 0;
}
