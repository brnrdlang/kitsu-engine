#ifndef KITSUNE_CONTROLLER_H
#define KITSUNE_CONTROLLER_H

#include <functional>
#include "SDL_events.h"

struct Controller {
    std::function<void(SDL_CommonEvent)> on_common_event;

    std::function<void(SDL_WindowEvent)> on_window_event;

    std::function<void(SDL_KeyboardEvent)> on_key_up;
    std::function<void(SDL_KeyboardEvent)> on_key_down;

    std::function<void(SDL_TextEditingEvent)> on_text_editing_event;

    std::function<void(SDL_TextInputEvent)> on_text_input_event;

    std::function<void(SDL_MouseMotionEvent)> on_mouse_motion;

    std::function<void(SDL_MouseButtonEvent)> on_mouse_button_down;
    std::function<void(SDL_MouseButtonEvent)> on_mouse_button_up;

    std::function<void(SDL_MouseWheelEvent)> on_mouse_wheel;

    std::function<void(SDL_JoyAxisEvent)> on_joystick_axis;
    std::function<void(SDL_JoyHatEvent)> on_joystick_head;
    std::function<void(SDL_JoyBallEvent)> on_joystick_ball;
    std::function<void(SDL_JoyButtonEvent)> on_joystick_button_up;
    std::function<void(SDL_JoyButtonEvent)> on_joystick_button_down;    
    std::function<void(SDL_JoyDeviceEvent)> on_joystick_device_added;
    std::function<void(SDL_JoyDeviceEvent)> on_joystick_device_removed;

    std::function<void(SDL_QuitEvent)> on_quit;

    std::function<void(SDL_UserEvent)> on_user_event;

    std::function<void(SDL_SysWMEvent)> on_sys_wm_event;

    std::function<void(SDL_TouchFingerEvent)> on_touch_motion;
    std::function<void(SDL_TouchFingerEvent)> on_touch_down;
    std::function<void(SDL_TouchFingerEvent)> on_touch_up;

    std::function<void(SDL_MultiGestureEvent)> on_multi_gesture;

    std::function<void(SDL_DropEvent)> on_drop;

    std::function<void(SDL_AudioDeviceEvent)> on_audio_device_added;
    std::function<void(SDL_AudioDeviceEvent)> on_audio_device_removed;

    std::function<void(SDL_ControllerAxisEvent)> on_controller_axis_motion;
    std::function<void(SDL_ControllerButtonEvent)> on_controller_button_down;
    std::function<void(SDL_ControllerButtonEvent)> on_controller_button_up;
    std::function<void(SDL_ControllerDeviceEvent)> on_controller_device_added;
    std::function<void(SDL_ControllerDeviceEvent)> on_controller_device_removed;
    std::function<void(SDL_ControllerDeviceEvent)> on_controller_device_remapped;

    std::function<void(SDL_DollarGestureEvent)> on_dollar_gesture;
    std::function<void(SDL_DollarGestureEvent)> on_dollar_record;

    void poll_events() {
        SDL_Event ev;

        while(SDL_PollEvent(&ev)) {
            eval_event(ev);
        }
    };

    void eval_event(SDL_Event ev) {
        switch(ev.type) {
        case SDL_MOUSEMOTION:
            on_mouse_motion(reinterpret_cast<SDL_MouseMotionEvent>(ev));
            break;
/**        case SDL_MOUSEBUTTONDOWN:
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
        case SDL_JOYBUTTONDOWN:
            on_joystick_button_down(ev);
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
            on_common_event(ev);*/
        }
    };
};

#endif
