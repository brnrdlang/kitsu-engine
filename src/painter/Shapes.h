#ifndef KITSUNE_SHAPES_H
#define KITSUNE_SHAPES_H

#include "GraphicsObject.h"

class Rectangle : public GraphicsObject {
public:
    Rectangle(SDL_Rect r, SDL_Color c);
    Rectangle(SDL_Rect r, SDL_Color c, int z);
    ~Rectangle();

    void draw();

private:
    SDL_Color clr_;
};

#endif
