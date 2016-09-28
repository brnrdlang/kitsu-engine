#include <iostream>
#include "painter.h"
#include "controller.h"
#include "Shapes.h"

bool on_key_press(SDL_Event ev, Triangle* t) {
    switch(ev.key.keysym.scancode) {
    case SDL_SCANCODE_ESCAPE:
        return true;
    case SDL_SCANCODE_DOWN:
        t->color_ -= 0.05f;
        break;
    case SDL_SCANCODE_UP:
        t->color_ += 0.05f;
        break;
    }
    if (t->color_ > 1.0f) {
        t->color_ = 1.0f;
    } else if (t->color_ < 0.0f) {
        t->color_ = 0.0f;
    }
    return false;
}

int main(int argc, char* argv[]) {

    Painter painter(1024, 768, false, "kitsu-ENGIne");
    Controller ctrl;

    bool quit = false;

    Triangle* tri = new Triangle();

    ObjectID id = painter.scene_->add(tri);
    
    painter.queue_.push(0);

    ctrl.on_every_event = [&](SDL_Event ev){painter.queue_.push(0);};
    ctrl.on_quit = [&](SDL_Event ev){quit = true;};
    ctrl.on_key_down = [&](SDL_Event ev){quit = on_key_press(ev, tri);};

    while(not quit) {
	    painter.update();

        ctrl.poll_events();
    }

    return 0;
}
