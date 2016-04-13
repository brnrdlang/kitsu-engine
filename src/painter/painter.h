#ifndef KITSUNE_PAINTER_H
#define KITSUNE_PAINTER_H

#include <string>
#include <exception>
#include "SDL.h"

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
	~Painter();

	void draw();
private:
	SDL_Window *window_;
};
#endif
