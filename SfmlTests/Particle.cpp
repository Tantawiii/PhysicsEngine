#include "Particle.h"

Particle::Particle(Vector2d position, float mass, float drag): postion(position), mass(mass), drag(drag), velocity(0, 0), acceleration(0, 0), forces(0, 0) {}

void Particle::Update(float dt) {
    velocity.x *= (1 - drag);
    velocity.y *= (1 - drag);

    acceleration = forces * (1.0f / mass);

    velocity += acceleration * dt;

    postion += velocity * dt;

    forces = Vector2d(0, 0);
}

void Particle::addForce(Vector2d force) {
    forces += force;
}
