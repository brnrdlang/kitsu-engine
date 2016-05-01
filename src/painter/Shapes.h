#ifndef KITSUNE_SHAPES_H
#define KITSUNE_SHAPES_H

#include "GraphicsObject.h"
#include "SceneTree.h"

class Rectangle : public GraphicsObject {
public:
    Rectangle(SDL_Rect r, SDL_Color c, SceneNode* n);
    Rectangle(SDL_Rect r, SDL_Color c, int z, SceneNode* n);
    ~Rectangle();

    void next(unsigned int time);
    void draw(SDL_Renderer *rndr);

private:
    SDL_Color clr_;
    SDL_Renderer *renderer_;
};

#endif
