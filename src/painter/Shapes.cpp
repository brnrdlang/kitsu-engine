#include "Shapes.h"

Rectangle::Rectangle(SDL_Rect r, SDL_Color c, SceneNode* node) : GraphicsObject(r), clr_(c) {
    this->node_ = node;
}

Rectangle::Rectangle(SDL_Rect r, SDL_Color c, int z, SceneNode* node) : GraphicsObject(r, Position(r.x, r.y, z)), clr_(c) {
    this->node_ = node;
}

Rectangle::~Rectangle() {}

void Rectangle::next(unsigned int time) {
    this->node_->insert(this);
}

void Rectangle::draw(SDL_Renderer* rndr) {
    SDL_SetRenderDrawColor(rndr, clr_.r, clr_.g, clr_.b, clr_.a);
    SDL_RenderFillRect(rndr, &hitbox_);
}
