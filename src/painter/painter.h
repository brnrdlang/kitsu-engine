#ifndef KITSUNE_PAINTER_H
#define KITSUNE_PAINTER_H

#include <string>
#include <exception>
#include <queue>
#include <vector>
#include <functional>

#include "SDL.h"
#include "GraphicsObject.h"
#include "Scene.h"

class PainterError : public std::exception {
public:
	PainterError() {};
	PainterError(const std::string& s) : msg(s) {};
	virtual ~PainterError() throw() {};
	virtual const char* what() const throw() { return msg.c_str(); };
private:
	std::string msg;
};

class AnimationEvent {
public:
    AnimationEvent(unsigned int time, ObjectID objid) : time_(time), id_(objid) {};
    virtual ~AnimationEvent() {};

    friend bool operator<(const AnimationEvent& ev1, const AnimationEvent& ev2) {
        return ev1.time_ < ev2.time_;
    };
    friend bool operator>(const AnimationEvent ev1, const AnimationEvent& ev2) {
        return ev1.time_ > ev2.time_;
    };

    unsigned int time_;
    ObjectID id_;
};

typedef std::priority_queue<AnimationEvent, std::vector<AnimationEvent>, std::greater<AnimationEvent>> AnimationQueue;

class Painter {
public:
	Painter(int width, int height, bool fs, std::string title);
	virtual ~Painter();

    void update();

    Scene* scene_;

    AnimationQueue queue_;
private:
    unsigned int next_event_time();
    SDL_GLContext gl_context_;
	SDL_Window *window_;
};

#endif
