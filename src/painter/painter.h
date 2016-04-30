#ifndef KITSUNE_PAINTER_H
#define KITSUNE_PAINTER_H

#include <string>
#include <exception>
#include <queue>
#include <functional>

#include "SDL.h"
#include "GraphicsObject.h"
#include "SceneTree.h"

class PainterError : public std::exception {
public:
	PainterError() {};
	PainterError(const std::string& s) : msg(s) {};
	virtual ~PainterError() throw() {};
	virtual const char* what() const throw() { return msg.c_str(); };
private:
	std::string msg;
};

class Painter {
public:
	Painter(int width, int height, bool fs, std::string title);
	virtual ~Painter();

    SceneNode* add_object_to_scene(GraphicsObject* go);
    void remove_object_from_scene(GraphicsObject* obj);

	void draw();
private:
    unsigned int next_event_time();

	SDL_Window *window_;
    SceneNode *scene_;
    std::priority_queue<AnimationEvent, std::vector<AnimationEvent>, std::greater<AnimationEvent>> queue_;
};

#endif
