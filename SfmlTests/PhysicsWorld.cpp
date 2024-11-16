#include "PhysicsWorld.h"


const Vector2d PhysicsWorld::gravity = Vector2d(0,0);

void PhysicsWorld::addParticle(Particle* particle) {
    particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
    for (Particle* particle : particles) {
        particle->addForce(gravity *particle->mass);

        particle->Update(deltaTime);
    }
}

void PhysicsWorld::checkTwoCircleCollision() {
    list<Particle*>::iterator it;
    list<Particle*>::iterator begin = particles.begin();
    list<Particle*>::iterator beforeEnd = particles.end();
    beforeEnd--;

    for (it = particles.begin(); it != beforeEnd; it++) {
        Particle* p1 = *it;
        Collider c1 = p1->collider;

        list<Particle*>::iterator itt;
        itt = particles.begin();
        itt++;
        for (; itt != particles.end(); itt++) {
            Particle* p2 = *itt;
            Collider c2 = p2->collider;

            if (c1.checkCollision(c2)) {
                cout << "collision" << endl;
            }
        }
    }
}

void PhysicsWorld::checkAABBCollision() {
    auto it = particles.begin();
    auto beforeEnd = particles.end();
    beforeEnd--;
    for (; it != beforeEnd; ++it) {
        Particle* p1 = *it;

        auto itt = it;
        ++itt;

        for (; itt != particles.end(); ++itt) {
            Particle* p2 = *itt;
            if (p1->collider.checkCollision(p2->collider)) {
                std::cout << "AABB collision detected between particles!" << std::endl;
            }
        }
    }
}