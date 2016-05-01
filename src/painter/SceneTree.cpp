#include <iostream>

#include "painter.h"
#include "SceneTree.h"

SceneNode::SceneNode(SceneNode* parent, SDL_Rect rect) : parent_(parent), hitbox_(rect) {
    children_[0] = nullptr;
    children_[1] = nullptr;
    children_[2] = nullptr;
    children_[3] = nullptr;
}

SceneNode::~SceneNode() {
    delete children_[0];
    delete children_[1];
    delete children_[2];
    delete children_[3];
}

void SceneNode::insert(GraphicsObject* obj) {
    int q = quadrant(obj->hitbox_, this->hitbox_);

    if (q == 4 or q == -1) {
        this->sprites_.insert(obj);
        obj->node_ = this;

        return;
    } else {
        if (this->children_[q] == nullptr) {
            SDL_Rect rct;
            switch(q) {
            case 0:
                rct.x = hitbox_.x;
                rct.y = hitbox_.y;
                rct.w = hitbox_.w/2 + hitbox_.w % 2;
                rct.h = hitbox_.h/2 + hitbox_.h % 2;
                break;
            case 1:
                rct.x = hitbox_.x + hitbox_.w/2 + hitbox_.w % 2;
                rct.y = hitbox_.y;
                rct.w = hitbox_.w/2;
                rct.h = hitbox_.h/2 + hitbox_.h % 2;
                break;
            case 2:
                rct.x = hitbox_.x;
                rct.y = hitbox_.y + hitbox_.h/2 + hitbox_.h % 2;
                rct.w = hitbox_.w/2 + hitbox_.w % 2;
                rct.h = hitbox_.h/2;
                break;
            case 3:
                rct.x = hitbox_.x + hitbox_.w/2 + hitbox_.w % 2;
                rct.y = hitbox_.y + hitbox_.h/2 + hitbox_.h % 2;
                rct.w = hitbox_.w/2;
                rct.h = hitbox_.h/2;
                break;
            default:
                std::cerr << "assigned quadrant" << q << "\n";
                throw PainterError("Error inserting graphics object");
            }

            this->children_[q] = new SceneNode(this, rct);
        }

        this->children_[q]->insert(obj);
    }
}

void SceneNode::remove(GraphicsObject* obj) {
    this->sprites_.erase(obj);
}

void SceneNode::draw(SDL_Renderer* rndr, std::set<GraphicsObject*, compGOP>* draw_set) {
    if (this->children_[0] != nullptr) {
        this->children_[0]->draw(rndr, draw_set);
    }
    if (this->children_[1] != nullptr) {
        this->children_[1]->draw(rndr, draw_set);
    }
    if (this->children_[2] != nullptr) {
        this->children_[2]->draw(rndr, draw_set);
    }
    if (this->children_[3] != nullptr) {
        this->children_[3]->draw(rndr, draw_set);
    }

    if (not this->sprites_.empty()) {
        SDL_SetRenderDrawColor(rndr, 0, 0, 0, 255);
        SDL_RenderDrawRect(rndr, &this->hitbox_);

        draw_set->insert(this->sprites_.begin(), this->sprites_.end());
    }
}

/**
 * Find out if A is included in a specific quadrant of B
 * Returns 0, 1, 2, or 3 if A is included in a quadrant,
 * returns -1 if A isn't included in B, returns 4 if A is included in B
 * but not in one of its quadrants.
 */
int quadrant(SDL_Rect& A, SDL_Rect& B) {
    if (A.x < B.x or A.y < B.x or A.x + A.w > B.x + B.w or A.y + A.h > B.y + B.h) {
        return -1;
    }
    if (A.x + A.w < B.x + B.w / 2 and A.y + A.h < B.y + B.h / 2) {
        return 0;
    }
    if (A.x + A.w >= B.x + B.w / 2 and A.y + A.h < B.y + B.h / 2) {
        return 1;
    }
    if (A.x + A.w < B.x + B.w / 2 and A.y + A.h >= B.y + B.h / 2) {
        return 2;
    }
    if (A.x + A.w >= B.x + B.w / 2 and A.y + A.h >= B.y + B.h / 2) {
        return 3;
    }
    return 4;
}
