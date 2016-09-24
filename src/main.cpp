#include <iostream>
#include "painter.h"
#include "controller.h"
#include "Shapes.h"

int main(int argc, char* argv[]) {

    Painter painter(1024, 768, false, "kitsu-ENGIne");
    Controller ctrl;

    bool quit = false;

/*    SDL_Rect rct;
    rct.x = 100; rct.y = 100;rct.w = 200; rct.h = 200;
    SDL_Color clr_red;
    clr_red.r = 255; clr_red.g = 0; clr_red.b = 0; clr_red.a = 255;
    
    Rectangle robj(rct, clr_red, 3, painter.get_scene());
    
    SDL_Rect rct2;
    rct2.x = 600; rct2.y = 500; rct2.w = 200; rct2.h = 200;
    SDL_Color clr_green;
    clr_green.r = 0; clr_green.g = 255; clr_green.b = 0; clr_green.a = 255;
    Rectangle gobj(rct2, clr_green, 5, painter.get_scene());

    painter.queue(0, &robj);
    painter.queue(3000, &gobj);
*/
    ctrl.on_quit = [&](SDL_Event ev){quit = true;};
    ctrl.on_key_down = [&](SDL_Event ev){quit = ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE;};

    while(not quit) {
	    painter.update();

        ctrl.poll_events();
    }

    return 0;
}
