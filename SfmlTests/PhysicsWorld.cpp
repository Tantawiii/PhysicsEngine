#include "PhysicsWorld.h"

const Vector2d PhysicsWorld::gravity = Vector2d(0, 9.81f);

void PhysicsWorld::addParticle(Particle* particle) {
    particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
    for (Particle* particle : particles) {
        particle->addForce(gravity *particle->mass);

        particle->Update(deltaTime);
    }
}
