#include "Shapes.h"

Rectangle::Rectangle(SDL_Rect r, SDL_Color c) : GraphicsObject(r), clr_(c) {
}

Rectangle::Rectangle(SDL_Rect r, SDL_Color c, int z) : GraphicsObject(r, Position(r.x, r.y, z)), clr_(c) {}

Rectangle::~Rectangle() {}

void Rectangle::draw() {}
