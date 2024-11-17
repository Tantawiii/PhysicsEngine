#include "Particle.h"

Particle::Particle(Vector2d position, float mass, float drag, string type): postion(position), mass(mass), drag(drag), type(type), velocity(0, 0), acceleration(0, 0), forces(0, 0) {
    this->postion = position;
    satSquareCollider.updatePosition(postion);
    satSquareCollider.points.push_back(postion);
    satSquareCollider.points.push_back(Vector2d(postion.x + 40, postion.y));
    satSquareCollider.points.push_back(Vector2d(postion.x + 40, postion.y + 40));
    satSquareCollider.points.push_back(Vector2d(postion.x, postion.y + 40));
}

void Particle::Update(float dt) {
    velocity.x *= (1 - drag);
    velocity.y *= (1 - drag);

    acceleration = forces * (1.0f / mass);

    velocity += acceleration * dt;

    postion += velocity * dt;

    forces = Vector2d(0, 0);

    if (type == "Circle") {
        collider.center = postion;
    }
    else if (type == "Square") {
        squareCollider.updatePosition(postion);
        squareCollider.ul = postion - Vector2d(20, 20);
        squareCollider.lr = postion + Vector2d(20, 20);
    }
    else if (type == "satSquare") {
        satSquareCollider.updatePosition(postion);
    }
    else{
        std::cout << "I got nothing fam!" << std::endl;
    }
}


//void Particle::Update(float dt) {
//    velocity.x *= (1 - drag);
//    velocity.y *= (1 - drag);
//
//    postion += velocity * dt;
//
//    forces = Vector2d(0, 0);
//}

void Particle::addForce(Vector2d force) {
    forces += force;
}
