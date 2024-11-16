#include "AABBCollider.h"
#include <iostream>

void AABBCollider::updatePosition(Vector2d position) {
    Vector2d delta = position - this->position;
    ul += delta;
    lr += delta;
    this->position = position;
}

bool AABBCollider::checkCollision(AABBCollider other) {
    /* FloatRect rect(ul.x, ul.y, 40, 40);
    FloatRect rect2(other.ul.x, other.ul.y, 40, 40);
    return rect.intersects(rect2); */

    // ul.x minX
    // lr.x maxX

    // ul.y minY
    // lr.y maxY

    if (ul.x <= other.lr.x && lr.x >= other.ul.x && ul.y <= other.lr.y && lr.y >= other.ul.y) {
        return true;
    }
    //if (lr.x >= other.ul.x && lr.x <= other.lr.x && lr.y >= other.ul.y && lr.y <= other.lr.y) {
    //    std::cout << "Square collision detected!" << std::endl;
    //    return true;
    //}
    //std::cout << "Square collision undetected!" << std::endl;
    return false;
}
