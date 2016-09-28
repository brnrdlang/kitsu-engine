#ifndef KITSUNE_CONTROLLER_H
#define KITSUNE_CONTROLLER_H

#include <functional>
#include "SDL_events.h"

struct Controller {
    std::function<void(SDL_Event)> on_every_event;

    std::function<void(SDL_Event)> on_common_event;

    std::function<void(SDL_Event)> on_window_event;

    std::function<void(SDL_Event)> on_key_up;
    std::function<void(SDL_Event)> on_key_down;

    std::function<void(SDL_Event)> on_text_editing_event;

    std::function<void(SDL_Event)> on_text_input_event;

    std::function<void(SDL_Event)> on_mouse_motion;

    std::function<void(SDL_Event)> on_mouse_button_down;
    std::function<void(SDL_Event)> on_mouse_button_up;

    std::function<void(SDL_Event)> on_mouse_wheel;

    std::function<void(SDL_Event)> on_joystick_axis;
    std::function<void(SDL_Event)> on_joystick_hat;
    std::function<void(SDL_Event)> on_joystick_ball;
    std::function<void(SDL_Event)> on_joystick_button_up;
    std::function<void(SDL_Event)> on_joystick_button_down;    
    std::function<void(SDL_Event)> on_joystick_device_added;
    std::function<void(SDL_Event)> on_joystick_device_removed;

    std::function<void(SDL_Event)> on_quit;

    std::function<void(SDL_Event)> on_user_event;

    std::function<void(SDL_Event)> on_sys_wm_event;

    std::function<void(SDL_Event)> on_touch_motion;
    std::function<void(SDL_Event)> on_touch_down;
    std::function<void(SDL_Event)> on_touch_up;

    std::function<void(SDL_Event)> on_multi_gesture;

    std::function<void(SDL_Event)> on_drop;

    std::function<void(SDL_Event)> on_audio_device_added;
    std::function<void(SDL_Event)> on_audio_device_removed;

    std::function<void(SDL_Event)> on_controller_axis_motion;
    std::function<void(SDL_Event)> on_controller_button_down;
    std::function<void(SDL_Event)> on_controller_button_up;
    std::function<void(SDL_Event)> on_controller_device_added;
    std::function<void(SDL_Event)> on_controller_device_removed;
    std::function<void(SDL_Event)> on_controller_device_remapped;

    std::function<void(SDL_Event)> on_dollar_gesture;
    std::function<void(SDL_Event)> on_dollar_record;

Controller() {
    on_every_event = [](SDL_Event ev) {return;};

    on_common_event = [](SDL_Event ev) {return;};

    on_window_event = [](SDL_Event ev) {return;};

    on_key_up = [](SDL_Event ev) {return;};
    on_key_down = [](SDL_Event ev) {return;};

    on_text_editing_event = [](SDL_Event ev) {return;};

    on_text_input_event = [](SDL_Event ev) {return;};

    on_mouse_motion = [](SDL_Event ev) {return;};

    on_mouse_button_down = [](SDL_Event ev) {return;};
    on_mouse_button_up = [](SDL_Event ev) {return;};

    on_mouse_wheel = [](SDL_Event ev) {return;};

    on_joystick_axis = [](SDL_Event ev) {return;};
    on_joystick_hat = [](SDL_Event ev) {return;};
    on_joystick_ball = [](SDL_Event ev) {return;};
    on_joystick_button_up = [](SDL_Event ev) {return;};
    on_joystick_button_down = [](SDL_Event ev) {return;};    
    on_joystick_device_added = [](SDL_Event ev) {return;};
    on_joystick_device_removed = [](SDL_Event ev) {return;};

    on_quit = [](SDL_Event ev) {return;};

    on_user_event = [](SDL_Event ev) {return;};

    on_sys_wm_event = [](SDL_Event ev) {return;};

    on_touch_motion = [](SDL_Event ev) {return;};
    on_touch_down = [](SDL_Event ev) {return;};
    on_touch_up = [](SDL_Event ev) {return;};

    on_multi_gesture = [](SDL_Event ev) {return;};

    on_drop = [](SDL_Event ev) {return;};

    on_audio_device_added = [](SDL_Event ev) {return;};
    on_audio_device_removed = [](SDL_Event ev) {return;};

    on_controller_axis_motion = [](SDL_Event ev) {return;};
    on_controller_button_down = [](SDL_Event ev) {return;};
    on_controller_button_up = [](SDL_Event ev) {return;};
    on_controller_device_added = [](SDL_Event ev) {return;};
    on_controller_device_removed = [](SDL_Event ev) {return;};
    on_controller_device_remapped = [](SDL_Event ev) {return;};

    on_dollar_gesture = [](SDL_Event ev) {return;};
    on_dollar_record = [](SDL_Event ev) {return;};
};

    void poll_events() {
        SDL_Event ev;

        while(SDL_PollEvent(&ev)) {
            eval_event(ev);
        }
    };

    void eval_event(SDL_Event ev) {
        on_every_event(ev);

        switch(ev.type) {
        case SDL_MOUSEMOTION:
            on_mouse_motion(ev);
            break;
        case SDL_MOUSEBUTTONDOWN:
            on_mouse_button_down(ev);
            break;
        case SDL_MOUSEBUTTONUP:
            on_mouse_button_up(ev);
            break;
        case SDL_MOUSEWHEEL:
            on_mouse_wheel(ev);
            break;
        case SDL_KEYDOWN:
            on_key_down(ev);
            break;
        case SDL_KEYUP:
            on_key_up(ev);
            break;
        case SDL_FINGERMOTION:
            on_touch_motion(ev);
            break;
        case SDL_FINGERDOWN:
            on_touch_down(ev);
            break;
        case SDL_FINGERUP:
            on_touch_up(ev);
            break;
        case SDL_MULTIGESTURE:
            on_multi_gesture(ev);
            break;
        case SDL_DOLLARGESTURE:
            on_dollar_gesture(ev);
            break;
        case SDL_DOLLARRECORD:
            on_dollar_record(ev);
            break;
        case SDL_TEXTEDITING:
            on_text_editing_event(ev);
            break;
        case SDL_TEXTINPUT:
            on_text_input_event(ev);
            break;
        case SDL_DROPFILE:
            on_drop(ev);
            break;
        case SDL_WINDOWEVENT:
            on_window_event(ev);
            break;
        case SDL_SYSWMEVENT:
            on_sys_wm_event(ev);
            break;
        case SDL_QUIT:
            on_quit(ev);
            break;
        case SDL_CONTROLLERAXISMOTION:
            on_controller_axis_motion(ev);
            break;
        case SDL_CONTROLLERBUTTONDOWN:
            on_controller_button_down(ev);
            break;
        case SDL_CONTROLLERBUTTONUP:
            on_controller_button_up(ev);
            break;
        case SDL_CONTROLLERDEVICEADDED:
            on_controller_device_added(ev);
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            on_controller_device_removed(ev);
            break;
        case SDL_CONTROLLERDEVICEREMAPPED:
            on_controller_device_remapped(ev);
            break;
        case SDL_JOYAXISMOTION:
            on_joystick_axis(ev);
            break;
        case SDL_JOYBALLMOTION:
            on_joystick_ball(ev);
            break;
        case SDL_JOYHATMOTION:
            on_joystick_hat(ev);
            break;
        case SDL_JOYBUTTONDOWN:
            on_joystick_button_down(ev);
            break;
        case SDL_JOYBUTTONUP:
            on_joystick_button_up(ev);
            break;
        case SDL_JOYDEVICEADDED:
            on_joystick_device_added(ev);
            break;
        case SDL_JOYDEVICEREMOVED:
            on_joystick_device_removed(ev);
            break;
        case SDL_AUDIODEVICEADDED:
            on_audio_device_added(ev);
            break;
        case SDL_AUDIODEVICEREMOVED:
            on_audio_device_removed(ev);
            break;
        case SDL_USEREVENT:
            on_user_event(ev);
            break;
        default:
            on_common_event(ev);
        }
    };
};

#endif
