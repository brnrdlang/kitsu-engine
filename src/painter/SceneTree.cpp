#include "SceneTree.h"

SceneNode::SceneNode(SceneNode* parent, SDL_Rect rect) : parent_(parent), hitbox_(rect) {
    children_[0] = nullptr;
    children_[1] = nullptr;
    children_[2] = nullptr;
    children_[3] = nullptr;
}

SceneNode::~SceneNode() {
    delete[] children_;
}

template <typename T>
bool PComp(const T * const & a, const T * const & b)
{
   return *a < *b;
}

SceneNode* SceneNode::insert(GraphicsObject* obj) {
    int q = quadrant(obj->hitbox_, this->hitbox_);

    if (q == 4) {
        this->sprites_.push_front(obj);
        this->sprites_.sort(PComp<GraphicsObject>);

        return this;
    } else {
        return this->children_[q]->insert(obj);
    }
}

void SceneNode::remove(GraphicsObject* obj) {
    this->sprites_.remove(obj);
}

void SceneNode::draw(SDL_Surface* surf) {
    if (this->children_[0] != nullptr) {
        this->children_[0]->draw(surf);
    }
    if (this->children_[1] != nullptr) {
        this->children_[1]->draw(surf);
    }
    if (this->children_[2] != nullptr) {
        this->children_[2]->draw(surf);
    }
    if (this->children_[3] != nullptr) {
        this->children_[3]->draw(surf);
    }
    for(auto obj : this->sprites_) {
        obj->draw(surf);
    }
}

/**
 * Find out if A is included in a specific quadrant of B
 * Returns 0, 1, 2, or 3 if A is included in a quadrant,
 * returns -1 if A isn't included in B, returns 4 if A is included in B
 * but not in one of its quadrants.
 */
int quadrant(SDL_Rect& A, SDL_Rect& B) {
    int xA = A.x - B.x;
    int yA = A.y - B.y;
    int wA = A.w - xA;
    int hA = A.h - yA;
    int res = 0;

    if (xA < 0 or yA < 0 or wA > B.w or hA > B.h) {
        return -1;
    } else {
        if (xA + wA <= B.w) {
            res += 0;
        } else if (xA > B.w/2) {
            res += 1;
        } else {
            return 4;
        }
        if (yA + hA <= B.h) {
            res += 0;
        } else if (yA > B.h/2) {
            res += 2;
        } else {
            return 4;
        }
        return res;
    }
}
